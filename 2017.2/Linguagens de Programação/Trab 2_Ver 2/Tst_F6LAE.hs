{-	Trabalho 2
	Resp.:	Rodrigo Ferreira Guimarães
	Disc.:	Linguaguem de Programação
	Orie.:	Rodrigo Bonifácio
	Func.:	Testar a linguagem desenvolvida
-}
module Tst_F6LAE where
    --  Módulos necessários para a construção deste módulo
    import F6LAE
    import Test.HUnit

    --  Abstração das chamadas de função
    eval e1 = avaliar e1 [] [] nivelInit
    evalR e1 r1 = avaliar e1 r1 [] nivelInit
    inter e1 = interp e1 [] []
    interR e1 r1 = interp e1 r1 []


    --  Referências para inicialização
    ref_0 = [("x", NumV 42, nivelInit)]
    ref_1 = [("x", NumV 42, 1),
             ("x", ExpV (Add (Num 3) (Num 8)), nivelInit)]
    ref_dbl = (Func "dobra" "x" (Add (Ref "x") (Ref "x")))
    ref_inc = (Func "inc" "x" (Add (Ref "x") (Num 1)))
    funcs = [ref_inc, ref_dbl]

    --  Lets arbitrários
    let_0 = Let "x" (Num 88)
    let_1 = Let "y" (Add (Ref "x") (Num 17))
    let_2 = Let "x" (Add (Num 39) (Num 72))
    let_3 = Let "y" (Add (Num 4) (Num 2))


    --  Resultados esperados
    ret_0 = NumV 42
    ret_1 = NumV 24
    ret_2 = BoolV True
    ret_3 = BoolV False

    ret_4 = NumV 48
    ret_5 = NumV 512

    ret_6 = NumV 49
    ret_7 = NumV (-24)

    ret_8 = BoolV True
    ret_9 = BoolV False
    ret_10 = BoolV False
    ret_11 = BoolV False

    ret_12 = BoolV True
    ret_13 = BoolV True
    ret_14 = BoolV True
    ret_15 = BoolV False

    ret_16 = BoolV False
    ret_17 = BoolV True

    ret_18 = error $ msgErro ava_18 cod_Tipo
    ret_19 = NumV 42
    ret_20 = NumV 11

    ret_21 = NumV 88
    ret_22 = NumV 193
    ret_23 = NumV 216

    ret_24 = ExpV (Lambda ("f", TInt) (Add (Ref "f") (Num 1)))

    ret_25 = NumV 52
    ret_26 = NumV 117

    ret_27 = NumV 129
    ret_28 = NumV 27
    ret_29 = NumV 3
    ret_30 = BoolV True

    ret_31 = NumV 91
    ret_32 = NumV 12


    --  Expressões a serem avaliadas
    ava_0 = Num 42
    ava_1 = Num 24

    ava_2 = Bool True
    ava_3 = Bool False

    ava_4 = Add (Num 24) (Num 24)
    ava_5 = Add (Num 12) (Num 500)
    ava_6 = Sub (Num 74) (Num 25)
    ava_7 = Sub (Num 21) (Num 45)

    ava_8 = And (Bool True) (Bool True)
    ava_9 = And (Bool True) (Bool False)
    ava_10 = And (Bool False) (Bool True)
    ava_11 = And (Bool False) (Bool False)

    ava_12 = Or (Bool True) (Bool True)
    ava_13 = Or (Bool True) (Bool False)
    ava_14 = Or (Bool False) (Bool True)
    ava_15 = Or (Bool False) (Bool False)

    ava_16 = Not (Bool True)
    ava_17 = Not (Bool False)

    ava_18 = Ref "x"

    ava_19 = let_0 (Ref "x")
    ava_20 = let_0 (let_1 (Add (Ref "y") (Ref "x")))
    ava_21 = let_2 (let_1 (let_0 (Add (Ref "y") (Ref "x"))))

    ava_22 = Lambda ("f", TInt) (Add (Ref "f") (Num 1))

    ava_23 = AppLambda ava_22 (Num 51)
    ava_24 = let_0 (let_1 (let_2 (let_3 (Add (Ref "y") (Ref "x")))))

    ava_25 = IfZero (Num 0) (Add (Num 92) (Num 37)) (Add (Num 25) (Num 19))
    ava_26 = IfZero (Bool False) (Num 27) (Num 78)
    ava_27 = IfZero (Bool True) (Num 12) (Num 3)
    ava_28 = IfZero (Num 87) (Bool False) (Bool True)

    ava_29 = App "inc" (Num 90)
    ava_30 = App "dobra" (Num 6)


    --  Testes Unitários
    tc_0 = TestCase (assertEqual "int: 42" ret_0 (inter ava_0))
    tc_1 = TestCase (assertEqual "int: 24" ret_1 (inter ava_1))

    tc_2 = TestCase (assertEqual "int: True" ret_2 (inter ava_2))
    tc_3 = TestCase (assertEqual "int: False" ret_3 (inter ava_3))

    tc_4 = TestCase (assertEqual "int: 24 + 24" ret_4 (inter ava_4))
    tc_5 = TestCase (assertEqual "int: 12 + 500" ret_5 (inter ava_5))

    tc_6 = TestCase (assertEqual "int: 74 - 25" ret_6 (inter ava_6))
    tc_7 = TestCase (assertEqual "int: 21 - 45" ret_7 (inter ava_7))

    tc_8 = TestCase (assertEqual "int: T && T" ret_8 (inter ava_8))
    tc_9 = TestCase (assertEqual "int: T && F" ret_9 (inter ava_9))
    tc_10 = TestCase (assertEqual "int: F && T" ret_10 (inter ava_10))
    tc_11 = TestCase (assertEqual "int: F && F" ret_11 (inter ava_11))

    tc_12 = TestCase (assertEqual "int: T || T" ret_12 (inter ava_12))
    tc_13 = TestCase (assertEqual "int: T || F" ret_13 (inter ava_13))
    tc_14 = TestCase (assertEqual "int: F || T" ret_14 (inter ava_14))
    tc_15 = TestCase (assertEqual "int: F || F" ret_15 (inter ava_15))

    tc_16 = TestCase (assertEqual "int: ~T" ret_16 (inter ava_16))
    tc_17 = TestCase (assertEqual "int: ~F" ret_17 (inter ava_17))

    tc_18 = TestCase (assertEqual "int: Ref Vazia" ret_18 (inter ava_18))
    tc_19 = TestCase (assertEqual "int: Ref Val 42" ret_19 (interR ava_18 ref_0))
    tc_20 = TestCase (assertEqual "int: Ref Val (3 + 8)" ret_20 (interR ava_18 ref_1))

    tc_21 = TestCase (assertEqual "int: Let x = 88 in x" ret_21 (inter ava_19))
    tc_22 = TestCase (assertEqual "int: Let x = 88 in Let y = x + 17 in y + x" ret_22 (inter ava_20))
    tc_23 = TestCase (assertEqual "int: Let x = 39 + 72 in Let y = x + 17 in Let x = 88 in y + x" ret_23 (inter ava_21))

    tc_24 = TestCase (assertEqual "int: *x -> x + 1" ret_24 (inter ava_22))

    tc_25 = TestCase (assertEqual "int: (*x -> x + 1) 51" ret_25 (inter ava_23))
    tc_26 = TestCase (assertEqual "int: Let x = 88 in Let y = x + 17 in Let x = 39 + 72 in Let y = 4 + 2 in x + y" ret_26 (inter ava_24))

    tc_27 = TestCase (assertEqual "int: ifZ 0 then 92 + 37 else 25 + 19" ret_27 (inter ava_25))
    tc_28 = TestCase (assertEqual "int: ifZ F then 27 else 78" ret_28 (inter ava_26))
    tc_29 = TestCase (assertEqual "int: ifZ T then 12 else 3" ret_29 (inter ava_27))
    tc_30 = TestCase (assertEqual "int: ifZ 87 then F else T" ret_30 (inter ava_28))

    tc_31 = TestCase (assertEqual "int: inc(90)" ret_31 (interp ava_29 [] funcs))
    tc_32 = TestCase (assertEqual "int: dobra(6)" ret_32 (interp ava_30 [] funcs))


    --  Testes Compilados
    tc_todos = TestList (map (\tc -> (TestLabel "" tc)) [tc_0, tc_1,
                                                         tc_2, tc_3,
                                                         tc_4, tc_5,
                                                         tc_6, tc_7,
                                                         tc_8, tc_9, tc_10, tc_11,
                                                         tc_12, tc_13, tc_14, tc_15,
                                                         tc_16, tc_17,
                                                         tc_18, tc_19, tc_20,
                                                         tc_21, tc_22, tc_23,
                                                         tc_24,
                                                         tc_25, tc_26,
                                                         tc_27, tc_28, tc_29, tc_30,
                                                         tc_31, tc_32])

    --  Execução de todos os testes
    exeTst = runTestTT tc_todos
