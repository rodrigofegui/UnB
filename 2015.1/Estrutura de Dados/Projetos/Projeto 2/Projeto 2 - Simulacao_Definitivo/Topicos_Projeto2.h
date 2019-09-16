/* Topicos sobre o Projeto 2 - Simulacao de Controle de Aeroporto */

    // 1 - Objetivo Geral:
{
/*
        Escrever um programa de simulacao que gerencie o uso das pistas de um grande aeroporto.
*/
}

    // 2 - Requisitos e Condicoes:
{
/*
        * 3 pistas, sendo que a pista 3 deve ser usada apenas em emergência e as pistas 1 e 2
servem para pousos e decolagens;
        * A cada 1hr, contando de 5 a 5min, 0 a 42 voos requerem pouso ou decolagem;
        * Status possíveis do aviao:
            ** A - Aproximacao, seguido de um valor inteiro de 1 a 13 para o nivel de combustivel;
            ** D - Decolagem, sem marcacao de combustivel;
            ** P - Pouso, somente apos a autorizacao na fila de pouso.
        * Sortear aleatoriamente:
            ** Numero de Voos - 0 a 42;
            ** Numero de Aproximacoes - 0 a 28;
                *** Nivel de Combustivel - 1 a 13.
            ** Numero de Decolagens - 0 a 28.
        * Determinar os tempos de controle:
            ** Tempo medio para aterrissagem;
            ** Tempo medio em solo;
            ** Tempo medio para aproximacoes.
*/
}

    // 3 - Possiveis Caracteristicas:
{
/*
        * O Aviao:
            ** Nome do Voo = AA0000 -> char [];
            ** Status = 'A' ou 'D' ou 'P' -> char;
            ** Combustivel = 1 a 13 -> int;
        * Cada Pista:
            ** Status = Livre, 0, ou Ocupada, 1 -> int;
        * O Aeroporto:
            ** Numero de Voos = 0 a 42 -> int;
            ** Numero de Requisicoes = 0 a 56 = Aproximacoes + Decolagens -> int;
            ** Status de operacao = 0 a 100% = Requisicoes/Voos -> float;
            ** Fila de Aproximacao = Ordenacao pelo nivel de combustivel -> struct aproximacao;
            ** Fila de Decolagem = Ordenacao por ordem de chegada -> struct decolagens;
*/
}

    // 4 - Eventos da Simulacao:
{
/*
        Na aproximacao e aterrissagem há o consumo de combustivel;
        * Aproximacao:
            ** Montagem da Fila;
            ** Ordenacao da Fila;
            ** Se a pista estiver livre = bloquear a pista e preparar a aterrissagem.
        * Aterrissagem;
            ** Retirar voo da aproximacao;
            ** Inserir este voo na decolagem.
        * Decolagem;
            ** Retirar voos da fila de decolagem.

*/
}
}
