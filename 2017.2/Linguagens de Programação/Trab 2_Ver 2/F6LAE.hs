{-	Trabalho 2
	Resp.:	Rodrigo Ferreira Guimarães
	Disc.:	Linguaguem de Programação
	Orie.:	Rodrigo Bonifácio
	Func.:	Expansão da linguaguem F4LAE, que já implementa
            avaliação outermost, para comportar a Lazy
            Evaluation de forma completa, ou seja, com a
            estratégia de compartilhamento.
-}
module F6LAE where
    --  Módulos necessários para a construção deste módulo
    import Prelude


    {-  Traduções semânticas simples e úteis para o
        desenvolvimento do módulo
    -}
    type Nome       = String
    type ArgFormal  = String
    type ID         = String
    type Nivel      = Integer
    type Cod        = Integer
    cod_Tipo        = 1
    cod_Exp         = 2
    cod_Ref         = 3
    cod_Func        = 4
    nivelInit       = 0


    --  Caracterização das Funções Nomeada
    data Func = Func Nome ArgFormal Exp
        deriving (Show, Eq)
    --  Lista de Funções Nomeadas na linguagem desenvolvida
    type Funcs = [Func]


    {-  Caracterização dos Tipos reconhecidos na linguagem
            ★   Números, restritos a inteiros;
            ★   Booleanos (true, false);
            ★   Funções (seta '->');
            ★   Não identificado.
    -}
    data Tipo   = TInt
                | TBool
                | TFunc Tipo Tipo
                | TError
        deriving (Show, Eq)


    {-  Caracterização da sintaxe abstrata da linguaguem,
        com as seguintes expressões:
            ★   Números Inteiros;
            ★   Expressão lógica;
            ★   Operações Aritméticas:
                +   Adição;
                +   Subtração.
            ★   Operações Lógicas:
                +   And;
                +   Or;
                +   Not.
            ★   Referência a uma Expressão;
            ★   Atribuição de uma Expressão;
            ★   Execução de uma Função Nomeada;
            ★   Desenvolvimento Função Anônima;
            ★   Execução de uma Função Anônima;
            ★   Execução condicional, controlada pelo 0.
    -}
    data Exp    = Num Integer
                | Bool Bool
                | Add Exp Exp | Sub Exp Exp
                | And Exp Exp | Or Exp Exp | Not Exp
                | Ref ID
                | Let ID Exp Exp
                | App Nome Exp
                | Lambda (ArgFormal, Tipo) Exp
                | AppLambda Exp Exp
                | IfZero Exp Exp Exp
        deriving (Show, Eq)


    {-  Caracterização dos Valores aceitos como resultado
        das operações realizadas:
            ★   Números Inteiros;
            ★   Booleanos;
            ★   Expressões postergadas.
    -}
    data Valor  = NumV Integer
                | BoolV Bool
                | ExpV Exp
        deriving (Show, Eq)


    {-  Traduções semânticas de tuplas e de listas úteis para
        o desenvolvimento deste módulo
    -}
    type PesqReg    = (ID, Nivel)
    type RetPesqReg = (Valor, Nivel)
    type RetPesqTipo = (Tipo, Nivel)
    type CelReg     = (ID, Valor, Nivel)
    type Registros  = [CelReg]
    type CelTipo    = (ID, Tipo, Nivel)
    type Tipos      = [CelTipo]
    type RetAvaliar = (Valor, Registros)
    type RetTipos   = (Tipo, Tipos)


    --  Interpretador da linguagem
    interp :: Exp -> Registros -> Funcs -> Valor
    interp e1 subPst funcs
        | (tipoE1 == TError) = error $ "\n" ++ msgErro e1 cod_Tipo ++ "\n"
        | otherwise = fst $ avaliar e1 subPst funcs nivelInit
            where
                tipoE1 = fst $ checkTipo e1 (reg2tipo subPst funcs) funcs nivelInit


    {-  Determinação do valor de uma expressão aprovada para a
        interpretação
    -}
    avaliar :: Exp -> Registros -> Funcs -> Nivel -> RetAvaliar
    avaliar (Num num) reg _ _ = (NumV num, reg)

    avaliar (Bool bool) reg _ _ = (BoolV bool, reg)

    avaliar (Add esq dir) reg funcs nvl = binOp (+) esq dir reg funcs nvl

    avaliar (Sub esq dir) reg funcs nvl = binOp (-) esq dir reg funcs nvl

    avaliar (And esq dir) reg funcs nvl =
        if (valEsq == BoolV True) && (valDir == BoolV True)
        then (BoolV True, snd $ avaDir2)
        else (BoolV False, snd $ avaDir2)
            where
                avaEsq = avaliar esq reg funcs nvl
                avaDir = avaliar dir (snd $ avaEsq) funcs nvl
                vEsq = fst $ avaEsq
                vDir = fst $ avaDir
                rDir = snd $ avaDir
                avaEsq2 = reduzir vEsq rDir funcs nvl
                valEsq = fst $ avaEsq2
                avaDir2 = reduzir vDir rDir funcs nvl
                valDir = fst $ avaDir2

    avaliar (Or esq dir) reg funcs nvl =
        if (valEsq == BoolV True) || (valDir == BoolV True)
        then (BoolV True, snd $ avaDir2)
        else (BoolV False, snd $ avaDir2)
            where
                avaEsq = avaliar esq reg funcs nvl
                avaDir = avaliar dir (snd $ avaEsq) funcs nvl
                vEsq = fst $ avaEsq
                vDir = fst $ avaDir
                rDir = snd $ avaDir
                avaEsq2 = reduzir vEsq rDir funcs nvl
                valEsq = fst $ avaEsq2
                avaDir2 = reduzir vDir rDir funcs nvl
                valDir = fst $ avaDir2

    avaliar (Not e) reg funcs nvl =
        if (valE == BoolV True)
        then (BoolV False, snd $ avaE2)
        else (BoolV True, snd $ avaE2)
            where
                avaE = avaliar e reg funcs nvl
                vE = fst $ avaE
                rE = snd $ avaE
                avaE2 = reduzir vE rE funcs nvl
                valE = fst $ avaE2

    avaliar (Ref var) reg funcs nvl =
        let val = buscarReg (var, nvl) reg
            in case val of
                (Nothing) -> error $ msgErro (Ref var) cod_Ref ++ show (reg) ++ " nvl: " ++ show(nvl)
                (Just (valReg, nvlReg)) -> (valor, novoReg)
                    where
                        valExp = v2e valReg
                        retorno = avaliar valExp reg funcs nvlReg
                        valExp2 = fst $ retorno
                        regExp = snd $ retorno
                        retorno2 = reduzir valExp2 regExp funcs nvlReg
                        valor = fst $ retorno2
                        novoReg = atuReg (var, valor, nvl) (snd $ retorno2)

    avaliar (Let var atri corpo) reg funcs nvl = avaliar corpo novoReg funcs novonvl
        where
            novoReg = (var, ExpV atri, nvl):reg
            novonvl = (nvl + 1)

    avaliar (App nome arg) reg funcs nvl =
        let fun = buscarFunc nome funcs
            in case fun of
                (Nothing) -> error $ msgErro (Ref nome) cod_Func
                (Just (Func nomeReg argF corpo)) -> avaliar corpo novoReg funcs novonvl
                    where
                        novoReg = (argF, ExpV arg, nvl):reg
                        novonvl = nvl + 1

    avaliar e@(Lambda (var, t) corpo) reg funcs nvl = (ExpV e, reg)

    avaliar (AppLambda expLmd arg) reg funcs nvl =
        case expLmd of
            (Lambda (var, _) corpo) -> avaliar corpo novoReg funcs nvl
                where
                    valor = avaliar arg reg funcs nvl
                    novoReg = (var, fst $ valor, nvl):(snd $ valor)

    avaliar (IfZero cond ladoPos ladoNeg) reg funcs nvl =
        let analisar = reduzir valor novoReg funcs nvl
            in let condValor = fst $ analisar
                in if (condValor == NumV 0)
                    then avaliar ladoPos (snd $ analisar) funcs nvl
                    else avaliar ladoNeg (snd $ analisar) funcs nvl
                    where
                        avaliado = avaliar cond reg funcs nvl
                        valor = fst $ avaliado
                        novoReg = snd $ avaliado


    {-  Verificação do tipo de uma expressão candidata a ser
        interpretada, caso tenha um tipo definido consistente
        a mesma poderá ser avaliada, enfim
    -}
    checkTipo :: Exp -> Tipos -> Funcs -> Nivel -> RetTipos
    checkTipo (Num _) tipos _ _ = (TInt, tipos)

    checkTipo (Bool _) tipos _ _ = (TBool, tipos)

    checkTipo (Add esq dir) tipos funcs nvl =
        if (tEsq == TInt) && (tDir == TInt)
        then (TInt, snd $ checkDir)
        else (TError, snd $ checkDir)
            where
                checkEsq = checkTipo esq tipos funcs nvl
                tEsq = fst $ checkEsq
                checkDir = checkTipo dir (snd $ checkEsq) funcs nvl
                tDir = fst $ checkDir

    checkTipo (Sub esq dir) tipos funcs nvl =
        if (tEsq == TInt) && (tDir == TInt)
        then (TInt, snd $ checkDir)
        else (TError, snd $ checkDir)
            where
                checkEsq = checkTipo esq tipos funcs nvl
                tEsq = fst $ checkEsq
                checkDir = checkTipo dir (snd $ checkEsq) funcs nvl
                tDir = fst $ checkDir

    checkTipo (And esq dir) tipos funcs nvl =
        if (tEsq == TBool) && (tDir == TBool)
        then (TBool, snd $ checkDir)
        else (TError, snd $ checkDir)
            where
                checkEsq = checkTipo esq tipos funcs nvl
                tEsq = fst $ checkEsq
                checkDir = checkTipo dir (snd $ checkEsq) funcs nvl
                tDir = fst $ checkDir

    checkTipo (Or esq dir) tipos funcs nvl =
        if (tEsq == TBool) && (tDir == TBool)
        then (TBool, snd $ checkDir)
        else (TError, snd $ checkDir)
            where
                checkEsq = checkTipo esq tipos funcs nvl
                tEsq = fst $ checkEsq
                checkDir = checkTipo dir (snd $ checkEsq) funcs nvl
                tDir = fst $ checkDir

    checkTipo (Not e) tipos funcs nvl =
        if ((fst $ checkExp) == TBool)
        then (TBool, snd $ checkExp)
        else (TError, snd $ checkExp)
            where
                checkExp = checkTipo e tipos funcs nvl

    checkTipo (Ref var) tipos funcs nvl =
        let val = buscarTipo (var, nvl) tipos
            in case val of
                (Nothing) -> (TError, tipos)
                (Just (tReg, _)) -> (tReg, tipos)

    checkTipo (Let var atri corpo) tipos funcs nvl = checkTipo corpo novoTipo funcs novonvl
        where
            tipoAtri = fst $ checkTipo atri tipos funcs nvl
            novoTipo = (var, tipoAtri, nvl):tipos
            novonvl = nvl + 1

    checkTipo (App nome arg) tipos funcs nvl =
        let fun = buscarFunc nome funcs
            in case fun of
                (Nothing) -> (TError, tipos)
                (Just (Func nomeReg argF corpo)) -> checkTipo corpo novoReg funcs novonvl
                    where
                        tipoArg = fst $ checkTipo arg tipos funcs nvl
                        novoReg = (argF, tipoArg, nvl):tipos
                        novonvl = nvl + 1

    checkTipo (Lambda (var, t) corpo) tipos funcs nvl =
        if (tCorpo /= TError)
        then (TFunc t tCorpo, snd $ checkCorpo)
        else (TError, snd $ checkCorpo)
            where
                novoTipo = (var, t, nvl):tipos
                novonvl = nvl + 1
                checkCorpo = checkTipo corpo novoTipo funcs novonvl
                tCorpo = fst $ checkCorpo

    checkTipo (AppLambda expLmd arg) tipos funcs nvl =
        let checkExp = checkTipo expLmd tipos funcs nvl
            in case checkExp of
                (TError, _) -> (TError, tipos)
                (TFunc t1 t2, tipos1) -> let checkArg = checkTipo arg tipos1 funcs nvl
                    in if ((fst $ checkArg) == t1)
                        then (t2, snd $ checkArg)
                        else (TError, snd $ checkArg)

    checkTipo (IfZero cond ladoPos ladoNeg) tipos funcs nvl =
        if ((tCond == TInt) && (tLP == tLN))
        then (tLP, snd $ checkLN)
        else (TError, snd $ checkCond)
            where
                checkCond = checkTipo cond tipos funcs nvl
                tCond = fst $ checkCond
                checkLP = checkTipo ladoPos (snd $ checkCond) funcs nvl
                checkLN = checkTipo ladoNeg (snd $ checkLP) funcs nvl
                tLP = fst $ checkLP
                tLN = fst $ checkLN


    --	Operação aplicável a dois argumentos inteiros
    binOp :: (Integer -> Integer -> Integer) -> Exp -> Exp -> Registros -> Funcs -> Nivel -> RetAvaliar
    binOp op e1 e2 reg funcs nvl = (NumV (op n1 n2), snd $ reduz2)
        where
            avaE1 = avaliar e1 reg funcs nvl
            avaE2 = avaliar e2 (snd $ avaE1) funcs nvl
            regE2 = snd $ avaE2
            reduz1 = reduzir (fst $ avaE1) (regE2) funcs nvl
            reduz2 = reduzir (fst $ avaE2) (snd $ reduz1) funcs nvl
            (NumV n1) = fst $ reduz1
            (NumV n2) = fst $ reduz2


    --  Reduzir Valores complexos aos tipos básicos: número ou bool
    reduzir :: Valor -> Registros -> Funcs -> Nivel -> RetAvaliar
    reduzir num@(NumV n) reg _ _ = (num, reg)
    reduzir bool@(BoolV b) reg _ _ = (bool, reg)
    reduzir (ExpV e) reg funcs nvl = reduzir valor novoReg funcs nvl
        where
            avaliado = avaliar e reg funcs nvl
            valor = fst $ avaliado
            novoReg = snd $ avaliado


    --  Atualizador de registro na pilha de compartilhamento
    atuReg :: CelReg -> Registros -> Registros
    atuReg _ [] = []
    atuReg (i1, v1, n1) ((i2, v2, n2):rabo) =
        if (i1 == i2) && (n1 >= n2)
        then ent:rabo
        else cab:(atuReg ent rabo)
            where
                ent = (i1, v1, n2)
                cab = (i2, v2, n2)


    {-  Busca de um dado Valor e seu Nível de origem,
        conhecendo-se seu identificador e seu nível atual,
        no registro de valores cadastrados
    -}
    buscarReg :: PesqReg -> Registros -> Maybe RetPesqReg
    buscarReg _ [] = Nothing
    buscarReg ent@(i1, n1) ((iReg, vReg, nReg):rabo) =
        if (i1 == iReg) && (n1 >= nReg)
        then Just (vReg, nReg)
        else buscarReg ent rabo

    {-  Busca de uma Função Nomeada, conhecendo-se
        o seu nome, no registro das funções nomeadas
    -}
    buscarFunc :: Nome -> Funcs -> Maybe Func
    buscarFunc _ [] = Nothing
    buscarFunc f (fun@(Func n a b):fs)
        | f == n = Just fun
        | otherwise = buscarFunc f fs

    {-  Busca de um dado Tipo e seu Nìvel de origem,
        conhecendo-se o seu identificador e seu nível atual,
        no registro de tipos cadastrados
    -}
    buscarTipo :: PesqReg -> Tipos -> Maybe RetPesqTipo
    buscarTipo _ [] = Nothing
    buscarTipo ent@(i1, n1) ((iReg, tReg, nReg):rabo) =
        if (i1 == iReg) && (n1 >= nReg)
        then Just (tReg, nReg)
        else buscarTipo ent rabo


    --  Conversão de um Valor para uma Expressão
    v2e :: Valor -> Exp
    v2e (NumV num) = (Num num)
    v2e (BoolV num) = (Bool num)
    v2e (ExpV e1) = e1


    --  Transformação de um registro de expressões para o de tipos
    reg2tipo :: Registros -> Funcs -> Tipos
    reg2tipo [] _ = []
    reg2tipo ((i, val, nvl):regs) funcs = (i, tVal, nvl):(reg2tipo regs funcs)
        where
            e = v2e val
            tVal = fst $ checkTipo e [] funcs nvl


    {-  Mensagem de Erro Padrão na avaliação de tipo de uma
        expressão
    -}
    msgErro :: Exp -> Cod -> String
    msgErro e1 cod
        | (cod == cod_Tipo) = "Tipo inconsistente em: " ++ show(e1)
        | (cod == cod_Ref) = "Variavel não encontrada: " ++ show(e1) ++ " em "
        -- | (cod == cod_Exp) = "Chegou outro tipo"
        | (cod == cod_Func) = "Função não encontrada: " ++ show (e1)
        | otherwise = "Erro não catalogado"
