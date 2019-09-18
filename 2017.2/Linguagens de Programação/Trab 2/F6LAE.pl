/*  Sintaxe abstrata para a atual linguagem, com as suas
        expressões reconhecidas:
            * Números inteiros;
            * Operações aritméticas:
                + Adição;
                + Subtração.
            * Atribuição de valor num contexto;
            * Referência uma expressão;
            ★ Aplicação de uma função nomeada;
            * Expressão lambda;
            * Aplicação de expressão lambda;
            ★ Condição de controle, se for 0

Exp ::= Num
	| Bool
	| Var
	| Add Exp Exp
	| Sub Exp Exp
	| And Exp Exp
	| Or Exp Exp
	| Not Exp Exp
	| Let Var Exp Exp
	| Lambda Var Exp
	| AppLambda Exp Exp
	| App Var Exp
	| IfZero Exp Exp Exp
*/
/* avaliar (Exp, Ambiente, Resultado) */
avaliar(num(N), _, num(N)).

avaliar(bool(B), _, bool(B)).

avaliar(add(Esq, Dir), Amb, num(Valor)) :-
    avaliar(Esq, Amb, num(NumE)),
    avaliar(Dir, Amb, num(NumD)),
    Valor is NumE + NumD.

avaliar(sub(Esq, Dir), Amb, num(Valor)) :-
    avaliar(Esq, Amb, num(NumE)),
    avaliar(Dir, Amb, num(NumD)),
    Valor is NumE - NumD.

avaliar(and(Esq, Dir), Amb, bool(true)) :-
    avaliar(Esq, Amb, bool(true)),
    avaliar(Dir, Amb, bool(true)), !.
avaliar(and(_, _), _, bool(false)).

avaliar(or(Esq, _), Amb, bool(true)) :-
    avaliar(Esq, Amb, bool(true)), !.
avaliar(or(_, Dir), Amb, bool(true)) :-
    avaliar(Dir, Amb, bool(true)), !.
avaliar(or(_, _), _, bool(false)).

avaliar(not(Exp), Amb, bool(true)) :-
    avaliar(Exp, Amb, bool(false)), !.
avaliar(not(_), _, bool(false)).

avaliar(ref(Var), Amb, Valor) :-
    buscar(Var, Amb, Val),
    avaliar(Val, Amb, Valor).

avaliar(let(Var, Val, Corpo), Amb, Valor) :-
    incAmb(Var, Val, Amb, NovoAmb),
    avaliar(Corpo, NovoAmb, Valor).

avaliar(app(Nome, Arg), Amb, Valor) :-
    avaliar(Nome, Amb, lambda(arg(Var, _), Corpo)),
    avaliar(Arg, Amb, Arg2),
    incAmb(Var, Arg2, Amb, NovoAmb),
    avaliar(Corpo, NovoAmb, Valor).

avaliar(lambda(Var, Corpo), Amb, Valor) :-

avaliar(appLambda(ELmd, Arg), Amb, Valor) :-

avaliar(ifZero(Val, IfT, IfF), Amb, Valor) :-


incAmb(Var, Term, Gamma, [map(Var, Term)|Gamma]).


buscar(Var, [map(Var, Term)|_], Term) :- !.
buscar(Var, [map(_, _)|Gamma], Term) :-
    buscar(Var, Gamma, Term).
