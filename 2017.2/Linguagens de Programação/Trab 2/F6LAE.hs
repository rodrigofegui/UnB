{-	Trabalho 2
	Resp.:	Rodrigo Ferreira Guimarães
	Disc.:	Linguaguem de Programação
	Orie.:	Rodrigo Bonifácio
	Func.:	Expansão da linguaguem F4LAE, que já implementa avaliação
			outermost, para comportar a Lazy Evaluation de forma completa,
			ou seja, com a estratégia de compartilhamento.
-}
module F6LAE where
    {-  Módulos necessários para a construção deste módulo -}
    import Prelude


    {-  Traduções semânticas para o desenvolvimento do módulo -}
    type Nome = String
    type ArgFormal = String
    type ID = String


    {-  Caracterização das eventuais funções nomeadas -}
    data Func = Func Nome ArgFormal Exp
        deriving (Show, Eq)
    type Funcs = [Func]


    {-  Sintaxe abstrata para a atual linguagem, com as suas
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
            ★ Condição de controle, se for 0 -}
    data Exp    = Num Integer
                | Bool Bool
                | Add Exp Exp | Sub Exp Exp
                | And Exp Exp | Or Exp Exp | Not Exp
                | Let ID Exp Exp
                | Ref ID
                | App Nome Exp
                | Lambda ArgFormal Exp
                | AppLambda Exp Exp
                | IfZero Exp Exp Exp
        deriving (Show, Eq)


    {-  Tipos possíveis de serem interpretados na linguagem
        em desenvolvimento -}
    data Tipo   = TInt
                | TBool
                | TFunc Tipo Tipo
                | TError
        deriving (Show, Eq)


    --  Ambiente com a lista das substituições postergadas
    type SubsPost = [(ID, Valor)]
    type TipoPost = [(ID, Exp)]
    {-  Retorno de uma avaliação:
            * Valor calculado
            * Ambiente potencialmente atualizado -}
    type RetAvaliar = (Valor, SubsPost)


    {-  Valores aceitos como resultado das operações realizadas:
        * Números inteiros;
        * Ambiente atual de uma expressão:
            + Com identificação (Closure);
            + Sem identificação -}
    data Valor  = NumV Integer
                | BoolV Bool
                | Closure ArgFormal Exp SubsPost
                | ExpV Exp SubsPost
        deriving (Show, Eq)


    {-  Interpretador da linguagem desenvolvida -}
    interp :: Exp -> SubsPost -> Funcs -> Valor
    interp e1 sbsP fc
        | (tipoE1 == TError) = error $ "Tipo incoerente em:\n\t" ++ show(e1) ++ "\n"
        | otherwise = fst $ avaliar e1 sbsP fc
            where tipoE1 = checkTipo e1 (map v2e sbsP) fc


    {-	Obs sobre as interpretaões:
    	* Num => Deve ser retornar o próprio número
    	* Add => Deve somar ambas as interpretações
    	* Sub => Deve subtrair a segunda interpretação da primeira
    	* Ref => Não pode haver referências livres
    	* Let => Deve-se adicionar (var, val) à DefrdSub e avaliar o corpo
    	* App => Deve-se buscar a função desejada na lista de funções
    	declaradas
    	* Lambda => Deve-se gerar o Closure com as declarações prévias
    	* LambdaApp =>
    -}
    avaliar :: Exp -> SubsPost -> Funcs -> RetAvaliar
    avaliar (Num num) sbsP _ = (NumV num, sbsP)

    avaliar (Bool bool) sbsP _ = (BoolV bool, sbsP)

    avaliar (Add esq dir) sbsP funcs = (binOp (+) esq dir sbsP funcs, sbsP)

    avaliar (Sub esq dir) sbsP funcs = (binOp (-) esq dir sbsP funcs, sbsP)

    avaliar (And esq dir) sbsP funcs =
        let esq1 = reduzir (interp esq sbsP funcs) funcs
            in if (esq1 == BoolV False) then
                (esq1, sbsP)
            else let dir1 = reduzir (interp dir sbsP funcs) funcs
                in if (dir1 == BoolV False) then
                    (dir1, sbsP)
                else (BoolV True, sbsP)

    avaliar (Or esq dir) sbsP funcs =
        let esq1 = reduzir (interp esq sbsP funcs) funcs
            in if (esq1 == BoolV True) then
                (esq1, sbsP)
            else let dir1 = reduzir (interp dir sbsP funcs) funcs
                in if (dir1 == BoolV True) then
                    (dir1, sbsP)
                else (BoolV False, sbsP)

    avaliar (Not e) sbsP funcs =
        let exp1 = reduzir (interp e sbsP funcs) funcs
            in if (exp1 == BoolV True) then
                (BoolV False, sbsP)
            else (BoolV True, sbsP)

    avaliar (Ref var) sbsP funcs =
        let valor = buscar var fst sbsP
            in case valor of
                (Nothing) -> error $ "variable '" ++ var ++ "' not found"
                (Just (_, v)) -> (val, nSbsP)
                    where
                        val = reduzir v funcs
                        nSbsP = (var, val):sbsP

    avaliar (Let var val corpo) sbsP funcs = avaliar appLmd subsP funcs
        where
            appLmd = (AppLambda (Lambda var corpo) val)
            expV = ExpV val sbsP
            subsP = (var, expV):sbsP

    avaliar (App nome args) sbsP funcs =
        let fun = buscar nome (\(Func nome _ _) -> nome) funcs
            in case fun of
                (Nothing) -> error $ "funtion '" ++ nome ++ "' not found"
                (Just (Func _ argFor corpo)) -> avaliar corpo subsP funcs
                    where
                        expV = ExpV args sbsP
                        subsP = [(argFor, expV)]

    avaliar (Lambda var corpo) sbsP funcs = (Closure var corpo sbsP, sbsP)

    avaliar (AppLambda eLmd arg) sbsP funcs = avaliar corpo subsP funcs
        where
            Closure argFor corpo sbs = reduzir (interp eLmd sbsP funcs) funcs
            expV = ExpV arg sbsP
            subsP = (argFor, expV):sbs

    avaliar (IfZero val ifT ifF) sbsP funcs =
        let cond = reduzir (interp val sbsP funcs) funcs
            in if (cond == NumV 0) then
                avaliar ifT sbsP funcs
            else avaliar ifF sbsP funcs


    checkTipo :: Exp -> TipoPost -> Funcs -> Tipo
    checkTipo (Num _) _ _ = TInt

    checkTipo (Bool _) _ _ = TBool

    checkTipo (Add esq dir) tipoP funcs =
        if (tEsq == TInt) && (tDir == TInt) then TInt
        else TError
            where
                tEsq = checkTipo esq tipoP funcs
                tDir = checkTipo dir tipoP funcs

    checkTipo (Sub esq dir) tipoP funcs =
        if (tEsq == TInt) && (tDir == TInt) then TInt
        else TError
            where
                tEsq = checkTipo esq tipoP funcs
                tDir = checkTipo dir tipoP funcs

    checkTipo (And esq dir) tipoP funcs =
        if (tEsq == TBool) && (tDir == TBool) then TBool
        else TError
            where
                tEsq = checkTipo esq tipoP funcs
                tDir = checkTipo dir tipoP funcs

    checkTipo (Or esq dir) tipoP funcs =
        if (tEsq == TBool) && (tDir == TBool) then TBool
        else TError
            where
                tEsq = checkTipo esq tipoP funcs
                tDir = checkTipo dir tipoP funcs

    checkTipo (Not val) tipoP funcs =
        if (tVal == TBool) then TBool
        else TError
            where
                tVal = checkTipo val tipoP funcs

    checkTipo (Ref var) tipoP funcs =
        let valor = buscar var fst tipoP
            in case valor of
                (Nothing) -> TError
                (Just (_, e)) -> checkTipo e tipoP funcs

    checkTipo (Let var val corpo) tipoP funcs =
        let tipoVal = checkTipo val tipoP funcs
            in case tipoVal of
                TError -> TError
                otherwise -> checkTipo corpo tipoPst funcs
                    where tipoPst = (var, val):tipoP

    checkTipo (App nome args) tipoP funcs = undefined

    checkTipo (Lambda var corpo) tipoP funcs = checkTipo corpo tipoP funcs

    checkTipo (AppLambda eLmd arg) tipoP funcs =
        let tipoExp = checkTipo eLmd tipoP funcs
            in case tipoExp of
                TError -> TError
                otherwise -> checkTipo arg tipoP funcs

    checkTipo (IfZero val ifT ifF) tipoP funcs =
        let tipoVal = checkTipo val tipoP funcs
            in case tipoVal of
                TError -> TError
                TInt -> if (tipoTrue == tipoFalse) then tipoTrue
                        else TError
                            where
                                tipoTrue = checkTipo ifT tipoP funcs
                                tipoFalse = checkTipo ifF tipoP funcs


    --	Operação aplicável a dois argumentos inteiros
    binOp :: (Integer -> Integer -> Integer) -> Exp -> Exp -> SubsPost -> Funcs -> Valor
    binOp op e1 e2 sbsP funcs = NumV (op n1 n2)
        where
            (NumV n1) = reduzir (interp e1 sbsP funcs) funcs
            (NumV n2) = reduzir (interp e2 sbsP funcs) funcs


    {-  Redução de um valor para um número inteiro ou um closure -}
    reduzir :: Valor -> Funcs -> Valor
    reduzir num@(NumV n) _ = num
    reduzir bol@(BoolV b) _ = bol
    reduzir clo@(Closure argFor corpo sbsP) _ = clo
    reduzir (ExpV e1 sbsP) decs = reduzir inter decs
        where
            inter = interp e1 sbsP decs





    v2e :: (ID, Valor) -> (ID, Exp)
    v2e (t, NumV num) = (t, Num num)
    v2e (t, BoolV num) = (t, Bool num)
    v2e (t, ExpV e1 sbs) = (t, e1)
    v2e (t, val) = error $ "Chegou outro tipo [" ++ show(val) ++ "]"
