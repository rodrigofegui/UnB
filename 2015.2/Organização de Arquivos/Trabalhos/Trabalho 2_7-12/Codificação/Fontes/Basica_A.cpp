/*****************************************************************
**      Inclusão das bibliotecas
*****************************************************************/
    #include "../Bibliotecas/Basica_A.hpp"

/*****************************************************************
**      Definição das Funções
*****************************************************************/
    /*  Função 'arq_abre', realiza a abertura e teste de alocacao de um arquivo */
    FILE * arq_abre (char *nome, string modo, char extra){
        /*  'nome' armazena o nome do arquivo a ser manipulado; 'modo' armazena o modo
        **  de abertura do mesmo; 'extra' armazena a condicao extra, se for para
        **  leitura ou escrita; 'auxiliar' armazena o arquivo lógico a ser manipulado */
        FILE *auxiliar = NULL;

        /* Abertura do arquivo lógico */
        auxiliar = fopen (nome, modo.c_str());

        /* Teste de abertura do arquivo */
        if (auxiliar == NULL && extra == 'l')
            printf ("\nERRO ABERTURA ARQUIVO %s\n", nome);

        return auxiliar;
    }

    /*  Função 'ler_simounao', verifica a validade da resposta para uma pergunta de
    **  "sim ou nao" */
    bool ler_simounao (){
        /*  'resp' armazena a resposta do usuario para a pergunta */
        char resp;

        /*  Enquanto for invalida */
        do{
            scanf ("%c", &resp);
            getchar ();

            /*  Sendo invalido, mensagem correspondente */
            if ((resp != 's') && (resp != 'S') && (resp != 'n') && (resp != 'N')){
                printf ("Resposta invalida, digite novamente!\n");
                resp = '\0';
            }

        }while ((resp != 's') && (resp != 'S') && (resp != 'n') && (resp != 'N'));

        if ((resp == 's') ||(resp == 'S'))
            return VERDADE;

        return !VERDADE;
    }

    /*  Funcao 'ler_intervalo', realiza a leitura e verifica a validade da coordenada do tabuleiro */
    int ler_intervalo (int min, int max){
        /*  'max' armazena o valor maximo para o intervalo de validade; 'num' armazena a coordenada
        **  a ser lida */
        int num;

        /*  Enquanto for invalido */
        do{
            scanf ("%d", &num);

            /*  Sendo invalido, mensagem correspondente */
            if (num < min || num > max)
                printf ("\nO valor fornecido eh invalido! Digite novamente!\n");
            getchar();

        }while (num < min || num > max);

        return num;
    }

    /*  Função 'limpa_tela', realiza a limpeza da tela durante a execução */
    void limpa_tela(){
        #ifdef LINUX
            system ("clear");
        #elif defined WIN32
            system ("cls");
        #else
            printf ("\e[H\e[2J");
        #endif
            return;
    }

    /*  Função 'pausa', realiza a pausa do programa ate pressionar o ENTER */
    void pausa (){
        printf ("\nPressione ENTER para continuar.\n");
        getchar ();
    }

    /*  Função 'temporizador', realiza a pausa do programa por um periodo de tempo
    **  definido pelo usuario */
    void temporizador (float pausa){
        /*  'pausa' armazena o tempo de espera escolhido pelo usuario; 'tempoin' e
        **  'tempofim' armazenam os tempos inicial e final do temporizador, respec. */
        if (pausa < 0.0) return;

        /*	Inicialização do temporizador */
        float tempoin = 0.0, tempofim = 0.0;

        /*	Conversão para segundos */
        tempoin = ((float) clock()) / ((float) CLOCKS_PER_SEC);

        /*  Enquanto nao der o tempo desejado */
        while ((tempofim - tempoin) < pausa){
            tempofim = ((float) clock()) / ((float) CLOCKS_PER_SEC);
        };
    }

    /*	Função 'stringcompara_n', realiza a comparação entre duas strings, com inicios ajustaveis
    **	e quantidade de caracteres a serem comparados */
    int string_compara_n (char *palavra1, char *palavra2, int inicio1, int inicio2, int quant){
        /*	'palavra1' e 'palavra2' armazenam as palavras a serem comparadas; 'inicio1' e 'inicio2'
        **	armazenam os respectivos inicios das strings; 'quant' armazena a quantide de caracteres
        **	a serem comparados; 'ind1' e 'ind2' armazenam indices a serem manipulados pelas respectivas
        **	strings */
        int ind1, ind2 = inicio2;


        /*	Percorrendo as strings pela quantidade de caracteres desejados */
        for (ind1 = inicio1; ind1 < (inicio1 + quant); ind1++){
            /*	'letra1' e 'letra2' armazenam os caracteres corrente da duas strings */
            char letra1 = palavra1[ind1], letra2 = palavra2[ind2];

            /*	Estando como minuscula, transforma em maiuscula */
            if (letra1 > 'a')   letra1 -= 32;
            if (letra2 > 'a')   letra2 -= 32;

            /*	Sendo diferente, retorna a diferença */
            if (letra1 != letra2){
                return palavra1[ind1] - palavra2[ind2];
            }
            /*  Terminando uma das strings */
            if (letra1 == '\0' || letra2 == '\0')
                break;
            ind2++;
        }

        /*	Estando tudo IGUAL */
        return VERDADE;
    }

    /*  Função 'string_completa', realiza a configuração dos caracteres desejados para um caracter
    **  escolhido */
    void string_completa (char *alvo, char caracter, int inicio, int fim){
        /*  'alvo' armazena a string a ser manipulada; 'inicio' e 'fim' armazena as posições do primeiro
        **  e do último caracter a ser inicializado, respectivamente */

        int ind;
        /*  Percorrendo a string de caracter em caracter */
        for (ind = inicio; ind < fim; ind++)
            /*  Inicializando o caracter específico */
            alvo[ind] = caracter;

        alvo[ind - 1] = '\0';
    }

    /*  Funcao 'string_concat_n', realiza a juncao de duas strings */
    void string_concat_n (char* destino, char* fonte, int iniciof, int fimf){
        /*  'destino' armazena a string resultado da juncao; 'fonte' armazena o trecho a ser juntado;
        **  'ind' e 'ind2' armazenam indices a serem manipulados */
        int ind = strlen(destino);
        int contador = 0;

        /*  Juncao das strings */
        for (int ind2 = iniciof; contador < fimf; ind2++){
            if (fonte[ind2] != ESPACO){
                destino[ind] = fonte[ind2];
                ind++;
                contador++;
            }
        }

        destino[ind] = '\0';
    }

    /*  Função 'string_n_ult_ocorrencia', descobre a n-última ocorrencia de um caracter numa string */
    int string_n_ult_ocorrencia (string avaliar, char alvo, int quant){
        /*  'avaliar' armazena a string a ser avaliada; 'alvo' armazena o caracter buscado
        **  na string; 'quant' armazena o minimo de vezes que o 'alvo' deve ser encontrado */

        /*  Tendo uma quantidade válida */
        if (quant > 0){
            /*  'ind' armazena indices a serem manipulados; 'ocorrencia' armazena a posição em
            **  que ocorre o 'alvo'; 'vezes' armazena a quantidade de vezes que o 'alvo' aparece
            **  até atingir a 'quant' pré-estabelecida */
            int ind, ocorrencia = 0, vezes = 0;

            /*  Procurando do final para o início da string */
            for (ind = avaliar.length(); ind > -1; ind--){
                /*  Encontrando um caracter desejado */
                if (avaliar[ind] == alvo){
                    ocorrencia = ind;
                    vezes++;
                }
                /*  Atingindo a quantidade desejada */
                if (vezes >= quant) return ocorrencia;
            }

            /*  Caso não tenha sido encontrado */
            return ind;
        }

        /*  Caso contrário */
        return -2;
    }

    /*  Função 'string_zera', realiza a inicialização dos caracteres desejados para um caracter
    **  nulo, '\0' */
    void string_zera (char *alvo, int inicio, int fim){
    /*  'alvo' armazena a string a ser manipulada; 'inicio' e 'fim' armazena as posições do primeiro
    **  e do último caracter a ser inicializado, respectivamente */

    /*  Percorrendo a string de caracter em caracter */
    for (int ind = inicio; ind < fim; ind++)
        /*  Inicializando o caracter específico */
        alvo[ind] = '\0';
}

