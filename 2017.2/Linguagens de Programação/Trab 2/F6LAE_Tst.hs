{-	Trabalho 2
	Resp.:	Rodrigo Ferreira Guimarães
	Disc.:	Linguaguem de Programação
	Orie.:	Rodrigo Bonifácio
	Func.:	Corpo de prova para a linguaguem F6LAE desenvolvida.
-}
module F6LAE_Tst where
    {-  Módulos necessários para a realização dos testes -}
    import Test.HUnit
    import F6LAE

    {-  Traduções semânticas para o desenvolvimento do teste -}
    inter e1 = interp e1 [] []
    inter1 e1 r1 = interp e1 r1 []

    eval e1 = avaliar e1 [] []
    eval1 e1 r1 = avaliar e1 r1 []

    check e1 = checkTipo e1 [] []
    check1 e1 r1 = checkTipo e1 r2 []
        where r2 = map v2e r1

    ref_0 = [("y", NumV 2)]
    ref_1 = [("y", NumV 2), ("x", NumV 5)]

    let_0 = Let "x" (Add (Num 2) (Num 3))
    let_1 = Let "y" (Add (Ref "x") (Ref "x"))
    let_2 = Let "z" (Sub (Ref "y") (Num 4))
    let_3 = Let "w" (Num 3)
    let_4 = Let "x" (Add (Num 10) (Num 5))
    let_5 = Let "y" (Add (Ref "x") (Num 20))
    let_6 = Let "x" (Num 5)

    {-  Retornos desejados para os testes a serem realizados -}
    ret_0 = (NumV 3)
    ava_0 = (Num 3)

    ret_1 = (NumV 500)
    ava_1 = (Add (Num 200) (Num 300))

    ret_2 = (NumV 100)
    ava_2 = (Sub (Num 300) (Num 200))

    ret_3 = error "variable x not found"
    ret_4 = (NumV 5)
    ava_3 = (Ref "x")

    ret_5 = NumV 8
    ava_4 = let_0 (Num 8)

    ret_6 = NumV 5
    -- let x = 2 + 3 in x
    ava_5 = let_0 (Ref "x")

    ava_6 = let_0 (let_1 (Num 8))

    ret_7 = NumV 10
    ava_7 = let_0 (let_1 (Ref "y"))

    ava_8 = let_0 (let_1 (let_2 (let_3 (Add (Ref "w") (Num 2)))))
    ava_9 = let_0 (let_1 (let_2 (let_3 (Add (Ref "w") (Ref "x")))))

    ava_10 = (IfZero (Num 0) (Num 8) (Num 5))
    ret_8 = error "Erro de tipo"
    ava_11 = (IfZero (Num 2) (Num 8) (Bool True))
    ava_12 = (IfZero (Add (Num 200) (Bool True)) (Num 8) (Num 5))

    ret_35 = NumV 40
    ava_13 = let_4 (let_5 (let_6 (Add (Ref "y") (Ref "x"))))

    {-  Testes a serem realizados -}
    tc_0 = TestCase (assertEqual "Num 003" ret_0 (inter ava_0))
    tc_1 = TestCase (assertEqual "Num 500" ret_1 (inter ava_1))
    tc_2 = TestCase (assertEqual "Num 100" ret_2 (inter ava_2))
    tc_3 = TestCase (assertEqual "Err Ref" ret_3 (inter ava_3))
    tc_4 = TestCase (assertEqual "Err Ref" ret_3 (inter1 ava_3 ref_0))
    tc_5 = TestCase (assertEqual "Ref Num" ret_4 (inter1 ava_3 ref_1))
    tc_6 = TestCase (assertEqual "Let Laz" ret_5 (inter ava_4))
    tc_7 = TestCase (assertEqual "Let Laz" ret_6 (inter ava_5))
    tc_8 = TestCase (assertEqual "Let Laz" ret_5 (inter ava_6))
    tc_9 = TestCase (assertEqual "Let Laz" ret_7 (inter ava_7))
    tc_10 = TestCase (assertEqual "Let Laz" ret_6 (inter ava_8))
    tc_11 = TestCase (assertEqual "Let Laz" ret_5 (inter ava_9))
    tc_12 = TestCase (assertEqual "IfZ Zer" ret_5 (inter ava_10))
    tc_13 = TestCase (assertEqual "IfZ NZe" ret_8 (inter ava_11))
    tc_14 = TestCase (assertEqual "IfZ NZe" ret_8 (inter ava_12))
    tc_15 = TestCase (assertEqual "Let Laz" ret_8 (inter ava_13))

    {-  Compilação dos testes a serem executados -}
    tc_todos = TestList (map (\tc -> (TestLabel "" tc)) [tc_0, tc_1,
                                                         tc_2, tc_3,
                                                         tc_4, tc_5,
                                                         tc_6, tc_7,
                                                         tc_8, tc_9,
                                                         tc_10, tc_11,
                                                         tc_12, tc_13,
                                                         tc_14, tc_15])

    --  Realização dos testes
    exeTst = runTestTT tc_todos
