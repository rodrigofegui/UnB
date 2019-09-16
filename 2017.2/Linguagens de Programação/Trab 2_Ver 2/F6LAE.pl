/**
 *  Trabalho 2
 *  Resp.:  Rodrigo Ferreira Guimarães
 *  Disc.:  Linguagem de Programação
 *  Orie.:  Rodrigo Bonifácio
 *  Func.:  Expansão da linguaguem F4LAE, que já implementa
            avaliação outermost, para comportar a Lazy
            Evaluation de forma completa, ou seja, com a
            estratégia de compartilhamento; ou o máximo disso,
            numa linguaguem lógica, no caso ProLog
 *  Ling.:  Embora o ProLog não permita a definição de tipos,
            serão aceitas as seguintes expressões:
                * num(e)              =: Número Inteiro;
                * bool(e)             =: Booleano;
                * add(e1, e2)         =: e1 + e2;
                * sub(e1, e2)         =: e1 - e2;
                * and(e1, e2)         =: e1 && e2;
                * or(e1, e2)          =: e1 || e2;
                * not(e1, e2)         =: !e1;
                * ref(var)            =: Referência a uma Expressão;
                * let(var, e1, e2)    =: Atribuição de uma  Expressão;
                * app(nome, e1)       =: Execução de uma Função Nomeada;
                * lambda((e1, t), e2) =: Desenvolvimento Função Anônima;
                * appLambda(e1, e2)   =: Execução de uma Função Anônima;
                * ifZero(e1, e2, e3   =: Execução condicional, controlada
                                         pelo 0)
 */

/**
 *  Interpretador da linguagem: verifica se o tipo da expressão
 *  fornecida está correto, caso esteja, computa-se o valor
 *  da mesma. Observa-se a sintaxe:
 *  param Exp       Expressão candidata a avaliação
 *  param Registro  Ambiente prévio com as substituições
 *                  postergadas
 *  param Valor     Valor extraído da expressão fornecida
 */
interp(E1, Registro, Val) :-
    reg2tipo(Registro, Gamma),
    checkTipo(E1, Gamma, 0, _),
    avaliar(E1, Registro, 0, _, Val).

/**
 *  Determinação do valor computado de uma dada expressão,
 *  garantindo a abordagem outermost e sempre fornecendo um
 *  num(N) ou um bool(B) como tal valor. Observa-se a sintaxe:
 *  param Exp       Expressão a ser avaliada
 *  param Gamma     Ambiente com as substituições postergadas
 *  param Nivel     Camada de avaliação atual
 *  param NGamma    Ambiente potencialmente atualizado com as
 *                  substituições postergadas
 *  param Valor     Valor extraído da expressão fornecida
 */
avaliar(num(N), _, _, _, num(N)).

avaliar(bool(B), _, _, _, bool(B)).

avaliar(add(Esq, Dir), Gamma, Nivel, NGamma2, num(Val)) :-
    reduzir(Esq, Gamma, Nivel, NGamma,  num(VEsq)),
    reduzir(Dir, NGamma, Nivel, NGamma2, num(VDir)),
    Val is +(VEsq, VDir).

avaliar(sub(Esq, Dir), Gamma, Nivel, NGamma2, num(Val)) :-
    reduzir(Esq, Gamma, Nivel, NGamma, num(VEsq)),
    reduzir(Dir, NGamma, Nivel, NGamma2, num(VDir)),
    Val is -(VEsq, VDir).

avaliar(and(Esq, Dir), Gamma, Nivel, NGamma2, bool(true)) :-
    reduzir(Esq, Gamma, Nivel, NGamma, bool(true)),
    reduzir(Dir, NGamma, Nivel, NGamma2, bool(true)), !.
avaliar(and(_, _), Gamma, _, Gamma, bool(false)).

avaliar(or(Esq, _), Gamma, Nivel, NGamma, bool(true)) :-
    reduzir(Esq, Gamma, Nivel, NGamma, bool(true)), !.
avaliar(or(_, Dir), Gamma, Nivel, NGamma, bool(true)) :-
    reduzir(Dir, Gamma, Nivel, NGamma, bool(true)), !.
avaliar(or(_, _), Gamma, _, Gamma, bool(false)).

avaliar(not(Exp), Gamma,  Nivel, NGamma, bool(true)) :-
    reduzir(Exp, Gamma, Nivel, NGamma, bool(false)), !.
avaliar(not(_), Gamma, _, Gamma, bool(false)).

avaliar(ref(Var), Gamma, Nivel, NGamma, Valor) :-
    buscarRef(Var, Nivel, Gamma, NivelReg, ValReg),
    reduzir(ValReg, Gamma, NivelReg, NGamma, Valor).

avaliar(let(Var, Atri, Corpo), Gamma, Nivel, NGamma2, Valor) :-
    incList(Var, Atri, Nivel, Gamma, NGamma),
    inc(Nivel, NNivel),
    avaliar(Corpo, NGamma, NNivel, NGamma2, Valor).

avaliar(lambda((Var, _), Corpo), Gamma, _, Gamma, lambda((Var, _), Corpo)).

avaliar(appLambda(ExpLmd, Arg), Gamma, Nivel, NGamma3, Valor) :-
    avaliar(ExpLmd, Gamma, Nivel, _, lambda((Var, _), Corpo)),
    avaliar(Arg, Gamma, Nivel, NGamma, ValArg),
    incList(Var, ValArg, Nivel, NGamma, NGamma2),
    avaliar(Corpo, NGamma2, Nivel, NGamma3, Valor).

avaliar(ifZero(Cond, AAvaliar, _), Gamma, Nivel, NGamma2, Valor) :-
    reduzir(Cond, Gamma, Nivel, NGamma, ValCond),
    ValCond = num(0),
    avaliar(AAvaliar, NGamma, Nivel, NGamma2, Valor), !.
avaliar(ifZero(_, _, AAvaliar), Gamma, Nivel, NGamma, Valor) :-
    avaliar(AAvaliar, Gamma, Nivel, NGamma, Valor).


/**
 *  Verificação da corretude quanto ao tipo de uma expressão
 *  fornecida, podendo haver, apenas, 3 tipos:
 *      - tInt => Números, restritos a inteiros;
 *      - tBool => Booleanos (true, false);
 *      - tFunc => Funções que levam de um tipo a outro.
 *  Para tanto, observa-se a sintaxe:
 *  param Exp   Expressão sujeita a analise
 *  param Gamma Ambiente com os tipos analisados
 *  param Nivel Camada de avaliação atual
 *  param Tipo  Tipo extraído da expressão fornecida
 */
checkTipo(num(_), _, _, tInt).

checkTipo(bool(_), _, _, tBool).

checkTipo(add(Esq, Dir), Gamma, Nivel, tInt) :-
    checkTipo(Esq, Gamma, Nivel, tInt),
    checkTipo(Dir, Gamma, Nivel, tInt).

checkTipo(sub(Esq, Dir), Gamma, Nivel, tInt) :-
    checkTipo(Esq, Gamma, Nivel, tInt),
    checkTipo(Dir, Gamma, Nivel, tInt).

checkTipo(and(Esq, Dir), Gamma, Nivel, tBool) :-
    checkTipo(Esq, Gamma, Nivel, tBool),
    checkTipo(Dir, Gamma, Nivel, tBool).

checkTipo(or(Esq, Dir), Gamma, Nivel, tBool) :-
    checkTipo(Esq, Gamma, Nivel, tBool),
    checkTipo(Dir, Gamma, Nivel, tBool).

checkTipo(not(Exp), Gamma, Nivel, tBool) :-
    checkTipo(Exp, Gamma, Nivel, tBool).

checkTipo(ref(Var), Gamma, Nivel, Tipo) :-
    buscarRef(Var, Nivel, Gamma, _, Tipo).

checkTipo(let(Var, Atri, Corpo), Gamma, Nivel, Tipo) :-
    checkTipo(Atri, Gamma, Nivel, TipoAtri),
    incList(Var, TipoAtri, Nivel, Gamma, NGamma),
    inc(Nivel, NNivel),
    checkTipo(Corpo, NGamma, NNivel, Tipo).

checkTipo(lambda((Var, T1), Corpo), Gamma, Nivel, tFunc(T1, T2)) :-
    incList(Var, T1, Nivel, Gamma, NGamma),
    inc(Nivel, NNivel),
    checkTipo(Corpo, NGamma, NNivel, T2).

checkTipo(appLambda(ExpLmd, Arg), Gamma, Nivel, T2) :-
    checkTipo(ExpLmd, Gamma, Nivel, tFunc(T1, T2)),
    checkTipo(Arg, Gamma, Nivel, T1).

checkTipo(ifZero(Cond, LadoP, LadoN), Gamma, Nivel, Tipo) :-
    checkTipo(Cond, Gamma, Nivel, tInt),
    checkTipo(LadoP, Gamma, Nivel, Tipo),
    checkTipo(LadoN, Gamma, Nivel, Tipo).


/*  Busca de um valor para um dado ID, dentro de um contexto */
buscarRef(Var, Nivel, [(Var, Val, NNivel)|_], NNivel, Val) :-
    Nivel >= NNivel, !.
buscarRef(Var, Nivel, [(_, _, _)|Gamma], NNivel, Val) :-
    buscarRef(Var, Nivel, Gamma, NNivel, Val).


/*  Atualização de um registro no ambiente */
atualizar(Var, Val, Nivel, [(Var, _, NivelReg) | Gamma], NGamma2) :-
    Nivel >= NivelReg,
    incList(Var, Val, NivelReg, Gamma, NGamma2), !.
atualizar(Var, Val, Nivel, [(Var2, Val2, N2) | Gamma], NGamma2) :-
    atualizar(Var, Val, Nivel, Gamma, NGamma),
    incList(Var2, Val2, N2, NGamma, NGamma2).

atualizar(Exp, Valor, [(VarReg, ExpReg, NivelReg) | Gamma], NGamma) :-
    Exp = ExpReg,
    incList(VarReg, Valor, NivelReg, Gamma, NGamma), !.
atualizar(Exp, Valor, [(Var, Val, Niv)|Gamma], NGamma2) :-
    atualizar(Exp, Valor, Gamma, NGamma),
    incList(Var, Val, Niv, NGamma, NGamma2).

/**
 *  Redução de valores potencialmente complexos aos
 *  valores básicos: num ou bool
 */
reduzir(num(N), Gamma, _, Gamma, num(N)) :- !.
reduzir(bool(B), Gamma, _, Gamma, bool(B)) :- !.
reduzir(E1, Gama, Nivel, NGamma3, Valor) :-
    avaliar(E1, Gama, Nivel, NGamma2, Val),
    reduzir(Val, NGamma2, Nivel, NGamma3, Valor).


/** Transformação de um registro de expressões para o de tipos */
reg2tipo([], []) :- !.
reg2tipo([(X1, X2, X3)|Gamma], GammaTipo) :-
    checkTipo(X2, [], X3, TipoX2),
    reg2tipo(Gamma, Tipos),
    incList(X1, TipoX2, X3, Tipos, GammaTipo).


/** Incremento de listas com tripla Tupla */
incList(D1, D2, D3, Lista, NovaLista) :-
    NovaLista = [(D1, D2, D3) | Lista].


inc(Val, NVal) :-
    NVal is Val + 1.

/*  Zona de testes */
% interp(num(42), [], X).
% interp(num(24), [], X).

% interp(bool(true), [], X).
% interp(bool(false), [], X).

% interp(add(num(24), num(24)), [], X).
% interp(add(num(12), num(500)), [], X).

% interp(sub(num(74), num(25)), [], X).
% interp(sub(num(21), num(45)), [], X).

% interp(and(bool(true), bool(true)), [], X).
% interp(and(bool(true), bool(false)), [], X).
% interp(and(bool(false), bool(true)), [], X).
% interp(and(bool(false), bool(false)), [], X).

% interp(or(bool(true), bool(true)), [], X).
% interp(or(bool(true), bool(false)), [], X).
% interp(or(bool(false), bool(true)), [], X).
% interp(or(bool(false), bool(false)), [], X).

% interp(not(bool(true)), [], X).
% interp(not(bool(false)), [], X).

% interp(ref(x), [], X).
% interp(ref(x), [(x, num(2), 0)], X).
% interp(ref(x), [(x, num(42), 1),(x, add(num(3), num(8)), 0)], X).
% interp(let(x, num(88), ref(x)), [], X).
% interp(let(x, num(88), let(y, add(num(20), num(17)), add(ref(y), ref(x)))), [], X).
% interp(let(x, num(88), let(y, add(ref(x), num(17)), add(ref(y), ref(x)))), [], X).

% interp(lambda((f, tInt), add(ref(f), num(1))), [], X).
% interp(lambda((f, tInt), bool(true)), [], X).

% interp(appLambda(lambda((f, tInt), add(ref(f), num(1))), num(51)), [], X).

% interp(ifZero(num(0), num(4), num(8)), [], X).
% interp(ifZero(num(0), add(num(92), num(37)), add(num(25), num(19))), [], X).
% interp(ifZero(bool(false), num(27), num(78)), [], X).
% interp(ifZero(num(87), bool(false), bool(true)), [], X).
