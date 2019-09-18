/** Inclusão das bibliotecas requisitadas: **/
    #include "../Bibliotecas/Arquivos.h"
    #include "../Bibliotecas/Lista.h"

/**  Definições da funções da biblioteca **/
    /*  Função 'arq_abre', realiza a abertura e teste de alocacao de um arquivo */
    FILE * arq_abre (char *nome, char *modo, char extra){
        /*  'nome' armazena o nome do arquivo a ser manipulado; 'modo' armazena o modo
        **  de abertura do mesmo; 'extra' armazena a condicao extra, se for para
        **  leitura ou escrita; 'auxiliar' armazena o arquivo lógico a ser manipulado */
        FILE *auxiliar = NULL;

        /* Abertura do arquivo lógico */
        auxiliar = fopen (nome, modo);

        /* Teste de abertura do arquivo */
        if (auxiliar == NULL && extra == 'l')
            printf ("\nERRO ABERTURA ARQUIVO %s\n", nome);

        return auxiliar;
    }

    /*  Função 'arq_le', realiza a leitura do arquivo lógico
    **  armazenando o resultado na lista de preferência */
    void arq_le (FILE *arq, Lista *lista){
        /*  'arq' armazena o ponteiro para o arquivo lógico a ser lido; 'lista' armazena a
        **  lista a ser manipulada; 'informacoes' armazena os dados lidos de cada aluno;
        **  'leitura' armazena o caracter lido no arquivo; 'lido' armazena a palavra
        **  lida; 'contador' armazena a contagem de bytes entre cada registro */
        Registros informacoes;
        char leitura, lido[TAM_MAX];
        int contador = 0;

        /*  Enquanto houver arquivo a ser lido */
        while (!feof(arq)){
            /*  Limpeza de todas as informações, para garantir que apenas informaçoes
            **  verdadeiras sejam guardadas */
            reg_zera(&informacoes);
            /*  Configuração do byte onde se inicia o registro */
            int contanterior = contador;
            /*  Configuração inicial para o separador dos campos de informações */
            int campo = -1;

            /*  Enquanto houver arquivo e estiver na mesma linha de informações */
            do{
                /*  Inicialização do indice manipulador de 'lido' */
                int ind = 0;
                /*  Limpeza da palavra 'lido', para garantir que apenas palavras
                **  reais sejam gravadas */
                string_zera (lido, 0, TAM_MAX);

                /*  Enquanto ler caracteres válidos */
                do{
                    /*  Leitura de caracter a caracter */
                    leitura = fgetc (arq);
                    /*  Contagem de bytes */
                    contador++;

                    /*  Sendo um caracter válido eh realizada a sua inserçao na palavra */
                    if ((leitura != ESPACO) && (leitura != TAB1) && (leitura != TAB2) && (leitura != ENTER) && (leitura != FIM)){
                        lido[ind] = leitura;
                        ind++;
                    }

                }while (!feof(arq) && (leitura != ESPACO) && (leitura != TAB1) && (leitura != TAB2) && (leitura != ENTER));

                /*  Controle do campo das informações */
                if (((campo != 1) && (strlen(lido) > 0))
                    || ((campo == 1) && (strlen(lido) == 0)))
                    campo++;

                /*  Configuração das informações, dependendo de qual campo de interesse
                **  a nova informação pertença */
                switch (campo){
                    /*  Com respeito a Matricula */
                    case 0:
                            /*  Copia da Matricula */
                            informacoes.Matricula = atoi (lido);
                            break;
                    /*  Com respeito ao Nome */
                    case 1:
                            /*  Copia do Nome */
                            strcat (informacoes.Nome, lido);
                            informacoes.Nome[strlen(informacoes.Nome)] =  ESPACO;
                            break;
                    /*  Com respeito ao Operador */
                    case 3:
                            /*  Sendo um operador válido, o mesmo eh copiado */
                            if (strlen(lido) > 1)
                                informacoes.OP = atoi (lido);
                            break;
                    /*  Com respeito ao Curso */
                    case 4:
                            /*  Sendo um curso válido, o mesmo eh copiado */
                            if (strlen(lido) > 1)
                                strcpy(informacoes.Curso, lido);
                            break;
                    /*  Com respeito à Turma */
                    case 5:
                            /*  Copia da Turma */
                            informacoes.Turma = lido[0];
                            break;

                }

            }while (!feof(arq) && (leitura != ENTER));

            /*  Retirando o espaço final, anteriormente adicionado */
            informacoes.Nome[strlen(informacoes.Nome) - 1] =  '\0';
            /*  Inserção das informações recolhidas na lista de registros */
            lista_insere (lista, informacoes, contanterior);
        }
    }
