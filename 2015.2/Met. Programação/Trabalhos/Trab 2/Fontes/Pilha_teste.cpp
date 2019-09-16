/*	Inclusão das Bibliotecas Requesitadas: */
#include "../Bibliotecas/Pilha.hpp"
#include <gtest/gtest.h>

TEST (Pilha_Vetor, Validade){
	vetor::Pilha teste;

	EXPECT_EQ(MENTIRA, teste.inserir(63));
	EXPECT_EQ(MENTIRA, teste.remover ());
	EXPECT_EQ(VERDADE, teste.criar (2));
	EXPECT_EQ(MENTIRA, teste.remover ());
	EXPECT_EQ(teste.topo(), teste.inserir (2));
	EXPECT_EQ(teste.topo(), teste.inserir (81));
	EXPECT_EQ(MENTIRA, teste.inserir (150));
	EXPECT_EQ(81, teste.remover ());
	teste.liberar ();
	EXPECT_EQ(MENTIRA, teste.topo());
}

TEST (Pilha_ListaEnc, Validade){
	listaenc::Pilha teste2;
	EXPECT_EQ(MENTIRA, teste2.remover ());
	EXPECT_EQ(VERDADE, teste2.criar ());
	EXPECT_EQ(MENTIRA, teste2.remover ());
	EXPECT_EQ(teste2.topo(), teste2.inserir (2));
	EXPECT_EQ(teste2.topo(), teste2.inserir (81));
	EXPECT_EQ(teste2.topo(), teste2.inserir (150));
	EXPECT_EQ(150, teste2.remover ());
	teste2.liberar ();
	EXPECT_EQ(MENTIRA, teste2.topo());
}
