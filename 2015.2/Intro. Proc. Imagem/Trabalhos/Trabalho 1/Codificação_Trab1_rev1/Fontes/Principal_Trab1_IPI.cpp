/*  Introdução a Processamento de Imagem - Turma A - 117242
**  Professor:  Alexandre Zaghetto
**  Autor:      Rodrigo F. Guimarães - 140170740
**  Última mod: 14/09/2015
**  Finalidades:
                *   Binarizaração de imagens, em relação
                    a cor de pele;
                *   Rotularizar a quantidade de elementos
                    conectados;
                *   Determinação da maior área conectada;
                *   Classificar em qual classe a imagem
                    pertence:
                        - Classe1:  Maior parte do corpo
                                    descoberta;
                        - Classe2:  Pessoa vestida.
*/

/*  Inclusão das bibliotecas requisitadas para o projeto: */
#include "../Bibliotecas/Principal.hpp"

int main (){
    /*  Questionamento quanto ao início do projeto */
    if (inicio_geral() == VERDADE){
        /*  'estatisticas' armazena os dados intrinsecos para o grupo de imagens a serem classificadas;
        **  'nomearqs' armazena os nomes dos arquivos principais a serem gerados pelo projeto;
        **  'nomesdir' armazena os nomes dos diretórios a serem manipulados pelo projeto; 'arqnavega'
        **  armazena o arquivo lógico com o resultado da navegação nos diretorios; 'arqregistro'
        **  armazena o arquivo lógico com os resultados do projeto */
        FMeasure estatisticas;
        string nomearqs[] = {"Resultado Navegação.txt", "Levantamento de Informações.txt", "F-Measure.txt"};
        string nomesdir[] = {"../Base de Dados/Calibragem do Sistema/Treinamento Elementos Conectados/Classe 1/",
                             "../Base de Dados/Calibragem do Sistema/Treinamento Elementos Conectados/Classe 2/",
                             "../Base de Dados/Execução e Análise/",
                             "./Paleta/Paleta.jpg"};
        FILE *arqnavega = arq_abre (&nomearqs[0][0], 'w', 'e');
        FILE *arqregistro = arq_abre (&nomearqs[1][0], 'w', 'e');


        /*  Inicialização das configurações do projeto */
        f1_inicializa (&estatisticas);

        /*  Calibra os dados para a classificação */
        printf ("Realizando a calibragem do sistema. Por favor, aguarde...\n");
        imagem_calibragem (arqnavega, arqregistro, &estatisticas, nomesdir);

        /*  Executando a classificação das imagens-alvo */
        imagem_classificacao (arqnavega, arqregistro, &estatisticas, nomesdir, nomearqs[2]);

        /*  Liberação dos documentos lógicos */
        fclose (arqnavega);
        fclose (arqregistro);
    }
    return 0;
}
