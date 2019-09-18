/*	Inclusão das Bibliotecas Requesitadas: */
#include <gtest/gtest.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <time.h>
#include <ncurses.h>
#include "../Bibliotecas/Arquivos.hpp"
#include "../Bibliotecas/Rede.hpp"
#include "../Bibliotecas/Interconexao.hpp"
#include "../Bibliotecas/Massa_teste.hpp"

TEST (Simulacao, Gtest){
	Rede *teste = rede_cria ();

	//EXPECT_NE(NULL,teste);
	EXPECT_NE(Falha,Testa_alocacao(teste));
	
}
