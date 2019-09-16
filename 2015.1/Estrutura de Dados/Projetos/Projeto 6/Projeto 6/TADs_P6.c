/*  Descritivo das funções para andamento do Projeto */

/*  Bibliotecas requisitada */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funcoes_P6.h"

/*  Lista das funcoes de manipulacao */

/*  1 - Secao de Criacao de Estruturas */
/*  1.1 - Funcao 'cria_ref', realiza a criacao de uma nova referencia */
Referencia * cria_ref (){
    /*  'nova' armazena a nova referencia a ser criada */
    Referencia *nova = NULL;

    /*  Alocacao da referencia */
    do{
        nova = (Referencia *) malloc (sizeof(Referencia));
    }while (nova == NULL);

    /*  Inicializacao das variaveis de controle */
    nova->city = NULL;
    nova->distancia = 0;
    nova->proximo = NULL;

    return nova;
}

/*  1.2 - Funcao 'cria_city', realiza a criacao de uma nova Cidade */
Cidade * cria_city (){
    /*  'nova' armazena a nova cidade a ser criada */
    Cidade *nova = NULL;

    /*  Alocacao da referencia */
    do{
        nova = (Cidade *) malloc (sizeof(Cidade));
    }while (nova == NULL);

    /*  Inicializacao das variaveis de controle */
    nova->inicio = NULL;
    nova->proximo = NULL;
    nova->status = 'L';
    nova->quantref = 0;
    zera_string (nova->nome, 0, MAX);

    return nova;
}

/*  1.3 - Funcao 'cria_grafo', realiza a criacao de um novo Grafo */
Grafo * cria_grafo (){
    /*  'novo' armazena o novo grafo a ser criada */
    Grafo *novo = NULL;

    /*  Alocacao da referencia */
    do{
        novo = (Grafo *) malloc (sizeof(Grafo));
    }while (novo == NULL);

    /*  Inicializacao das variaveis de controle */
    novo->quant = novo->livres = 0;
    novo->inicio = NULL;

    return novo;
}

/*  1.4 - Criacao de um novo Elemento */
Elemento * cria_elemento (){
    /*  'novo' armazena o novo grafo a ser criada */
    Elemento *novo = NULL;

    /*  Alocacao da referencia */
    do{
        novo = (Elemento *) malloc (sizeof(Elemento));
    }while (novo == NULL);

    /*  Inicializacao das variaveis de controle */
    novo->distancia = 0;
    zera_string(novo->nome, 0, MAX);
    novo->proximo = NULL;

    return novo;
}

/*  1.5 - Funcao 'inicia_roteiro', realiza a inicializacao das variaveis
**  de controle de um Roteiro */
void inicia_roteiro (Grafo *grafo, Roteiro *roteiro){
    /*  'grafo' armazena o grafo que inicializara o roteiro; 'roteiro' armazena
    **  o roteiro a ser inicializado; 'auxcity' auxilia a percorrer a lista de
    **  cidades do grafo; 'indice' armazena o indice a ser manipulado */
    Cidade *auxcity = NULL;
    char indice;

    /*  Criacao dos elementos e Inicializacao das variaveis de controle */
    for (indice = 65, auxcity = grafo->inicio; indice < grafo->quant + 65; indice++, auxcity = auxcity->proximo){
        Elemento *novo = cria_elemento ();

        strcpy (novo->nome, auxcity->nome);

        roteiro[indice - 65].inicio = roteiro[indice - 65].fim = novo;
        roteiro[indice - 65].kilometragem = 0;
    }
}




/*  2 - Secao de Liberacao */
/*  2.1 - Funcao 'libera_ref', realiza a liberacao do espaco
**  alocado para uma referencia */
void libera_ref (Referencia *ref){
    /*  'ref' armazena a referencia a ser liberada */
    free (ref);
}

/*  2.2 - Funcao 'libera_city', realiza a liberacao do espaco
**  alocado para uma cidade */
void libera_city (Cidade *city){
    /*  'city' armazena a cidade a ser liberada */
    if (city == NULL) return;

    /*  'aux' auxilia a percorrer a lista de referencias */
    Referencia *aux;

    /*  Enquanto houver lista de referencia */
    while (city->inicio != NULL){
        aux = city->inicio;
        city->inicio = aux->proximo;
        libera_ref (aux);
    }

    free (city);
}

/*  2.3 - Funcao 'libera_grafo', realiza a liberacao do espaco
**  alocado para um grafo */
void libera_grafo (Grafo *graph){
    /*  'graph' armazena o grafo a ser liberado */
    if (graph == NULL)  return;

    /*  'aux' auxilia a percorrer a lista de cidade registradas */
    Cidade *aux;

    /*  Enquanto houver lista */
    while (graph->inicio != NULL){
        aux = graph->inicio;
        graph->inicio = aux->proximo;
        libera_city (aux);
    }

    free (graph);
}

/*  2.4 - Funcao 'libera_elemento', realiza a liberacao do espaco
**  alocado para um elemento */
void libera_elemento (Elemento *elemento){
    /*  'elemento' armazena os elementos a serem liberados; 'auxelem' auxilia a percorre
    **  a lista de elementos */
    Elemento *auxelem = NULL;

    /*  Enquanto houver lista de elementos a serem liberados */
    while (elemento != NULL){
        auxelem = elemento;
        elemento = auxelem->proximo;
        free(auxelem);
    }
}

/*  2.5 - Funcao 'libera_roteiro', realiza a liberacao do espaco
**  alocado para o roteiro  */
void libera_roteiro (Roteiro *roteiro){
    /*  'roteiro' armazena os roteiros de viagem a serem liberados */

    /*  Tendo roteiro a ser liberado */
    if (roteiro != NULL){
        /*  'ind' armazena o indice a ser manipulado */
        char ind;

        /*  Liberando todos os roteiros */
        for (ind = 65; ind < MAXC + 65; ind++){
            libera_elemento (roteiro[ind - 65].inicio);
        }
    }
}




/*  3 - Secao de Construcao, Insercao e Busca */
/*  3.1 - Funcao 'constroi_grafo', realiza a construcao do Grafo nao direcionado */
void constroi_grafo (Grafo *graph, char *cidade, char *cidade1, int dist){
    /*  'graph' armazena o grago a ser construido; 'cidade' e 'cidade1' armazenam os nomes das
    **  cidades a serem analisadas na construcao; 'dist' armazena a distancia entre as cidades */

    /*  Havendo grafo */
    if (graph != NULL){
        /*  Nao havendo cidades adicionadas */
        if (graph->inicio == NULL){
            /*  'nova' e 'nova1' armazenam as cidades a serem adicionadas ao grafo */
            Cidade *nova = NULL, *nova1 = NULL;

            /*  Criacao das cidades */
            nova = cria_city ();
            nova1 = cria_city ();

            /*  Configuracao dos nomes das cidades */
            strcpy (nova->nome, cidade);
            strcpy (nova1->nome, cidade1);

            /*  Insercao das cidades no grafo */
            nova->proximo = nova1;
            graph->inicio = nova;
            graph->quant += 2;

            /*  Configuracao das lista de referencias das cidades */
            constroi_ref (graph, nova, cidade1, dist);
            constroi_ref (graph, nova1, cidade, dist);
        }

        /*  Havendo cidades adicionadas */
        else{
            /*  'auxcity' auxilia a percorrer a lista de cidades do grafo; 'origem' e 'destino'
            **  armazenam as cidades a serem manipuladas */
            Cidade *auxcity = NULL, *origem = NULL, *destino = NULL;

            /*  Procurando as duas cidades no grafo */
            for (auxcity = graph->inicio; auxcity->proximo != NULL; auxcity = auxcity->proximo){
                if (strcmp (auxcity->nome, cidade) == 0)   origem = auxcity;
                if (strcmp (auxcity->nome, cidade1) == 0)   destino = auxcity;
                if (origem != NULL && destino != NULL)  break;
            }

            /*  Nao existindo a 'cidade' no grafo */
            if (origem == NULL && strcmp (auxcity->nome, cidade) != 0){
                /*  Criacao da cidade 'cidade' */
                origem = cria_city ();

                /*  Configuracao da cidade 'cidade' */
                strcpy (origem->nome, cidade);

                /*  Insercao da nova cidade ao grafo */
                auxcity->proximo = origem;
                graph->quant++;
            }
            /*  Existindo, mas na ultima posicao */
            else if (origem == NULL && strcmp (auxcity->nome, cidade) == 0)   origem = auxcity;

            /*  Nao existindo a 'cidade1' no grafo */
            if (destino == NULL && strcmp (auxcity->nome, cidade1) != 0){
                /*  Criacao da cidade 'cidade' */
                destino = cria_city ();

                /*  Configuracao da cidade 'cidade' */
                strcpy (destino->nome, cidade1);

                /*  Insercao da nova cidade ao grafo */
                if (auxcity->proximo == NULL)
                    auxcity->proximo = destino;

                else{
                    /*  'auxcity1' auxilia a percorrer a lista de cidades */
                    Cidade *auxcity1 = NULL;

                    /*  Percorrer a lista de cidades */
                    for (auxcity1 = auxcity; auxcity1->proximo != NULL; auxcity1 = auxcity1->proximo)

                    /*  Construcao da lista de cidades */
                    auxcity1->proximo = destino;
                }

                /*  Configuracao do grafo */
                graph->quant++;
            }
            /*  Existindo, mas na ultima posicao */
            else if (destino == NULL && strcmp (auxcity->nome, cidade1) == 0)   destino = auxcity;

            /*  Configuracao das lista de referencias das cidades */
            constroi_ref (graph, origem, cidade1, dist);
            constroi_ref (graph, destino, cidade, dist);
        }
    }
}

/*  3.2 - Funcao 'constroi_ref', realiza a construcao da lista de referencias */
void constroi_ref (Grafo *graph, Cidade *origem, char *destino, int dist){
    /*  'graph' armazena o grafo com todas as cidades; 'origem' armazena a cidade
    **  a ser feita a configuracao; 'destino' armazena o nome da cidade de destino;
    **  'dist' armazena a distancia entre as cidades */

    /*  Havendo cidade de origem */
    if (origem != NULL){
        /*  'auxcity' auxilia a percorrer a lista de cidades */
        Cidade *auxcity = NULL;

        /*  Procura a cidade destino dentre todas as cidades */
        for (auxcity = graph->inicio; auxcity != NULL; auxcity = auxcity->proximo){
                if (strcmp(auxcity->nome, destino) == 0) break;
        }

        /*  Encontrando a cidade no registro */
        if (auxcity != NULL && (strcmp(auxcity->nome, destino) == 0)){
            /*  'nova' armazena uma possicel referencia a ser adicionada */
            Referencia *nova = NULL;

            /*  Nao tendo ligacao ainda */
            if (origem->inicio == NULL){
                /*  Criacao da nova referencia */
                nova = cria_ref ();

                /*  Configuracao da referencia */
                nova->city = auxcity;
                nova->distancia = dist;

                /*  Insercao da referencia no registro */
                origem->inicio = nova;
                origem->quantref++;
            }

            /*  Havendo */
            else{
                /*  'ant' e 'auxref' auxiliam a percorrer a lista de referencia */
                Referencia *ant = origem->inicio, *auxref = ant->proximo;

                /*  Percorrendo a lista */
                while (auxref != NULL && auxref->proximo != NULL){
                    /*  Procurar para insercao ordenada por distancia */
                    if (dist < ant->distancia) break;
                    if (dist > ant->distancia && dist < auxref->distancia) break;

                    /*  Procura pela ja existencia */
                    if (strcmp (auxref->city->nome, destino) == 0) break;

                    ant = ant->proximo;
                    auxref = ant->proximo;
                }

                if (auxref == NULL){
                    /*  Estando no inicio da lista e o valor da distancia a ser inserido
                    **  for menor */
                    if (ant == origem->inicio && dist < ant->distancia){
                        /*  Criacao da nova referencia */
                        nova = cria_ref ();

                        /*  Configuracao da referencia */
                        nova->city = auxcity;
                        nova->distancia = dist;

                        /*  Insercao da referencia no registro */
                        nova->proximo = ant;
                        origem->inicio = nova;
                        origem->quantref++;
                    }

                    /*  Procurou em toda a lista e nao encontrou a cidade no registro */
                    else if (strcmp (ant->city->nome, destino) != 0){
                        /*  Criacao da nova referencia */
                        nova = cria_ref ();

                        /*  Configuracao da referencia */
                        nova->city = auxcity;
                        nova->distancia = dist;

                        /*  Insercao da referencia no registro */
                        ant->proximo = nova;
                        origem->quantref++;
                    }

                }
                else {
                    /*  Estando no inicio da lista e o valor da distancia a ser inserido
                    **  for menor */
                    if (ant == origem->inicio && dist < ant->distancia){
                        /*  Criacao da nova referencia */
                        nova = cria_ref ();

                        /*  Configuracao da referencia */
                        nova->city = auxcity;
                        nova->distancia = dist;

                        /*  Insercao da referencia no registro */
                        nova->proximo = ant;
                        origem->inicio = nova;
                        origem->quantref++;
                    }

                    /*  O valor a ser inserido esta num intervalo entre duas jah existentes */
                    if (dist > ant->distancia && dist < auxref->distancia){
                        /*  Criacao da nova referencia */
                        nova = cria_ref ();

                        /*  Configuracao da referencia */
                        nova->city = auxcity;
                        nova->distancia = dist;

                        /*  Insercao da referencia no registro */
                        nova->proximo = auxref;
                        ant->proximo = nova;
                        origem->quantref++;
                    }

                    /*  Maior do que o ultimo valor */
                    else if (dist > auxref->distancia && (strcmp (auxref->city->nome, destino) != 0)){
                        /*  Criacao da nova referencia */
                        nova = cria_ref ();

                        /*  Configuracao da referencia */
                        nova->city = auxcity;
                        nova->distancia = dist;

                        /*  Insercao da referencia no registro */
                        auxref->proximo = nova;
                        origem->quantref++;
                    }
                }
            }
        }
    }
}

/*  3.3 - Funcao 'insere_roteiro', realiza a insercao nos registros */
void insere_roteiro (Roteiro *roteiro, char *nome, int dist){
    /*  'roteiro' armazena o roteiro a ser construido; 'nome' armazena o nome da
    **  cidade a ser inserida; 'dist' armazena a distancia da cidade a ser inserida
    **  para a anterior; 'novo' armazena o novo elemento a ser inserido */
    Elemento *novo = cria_elemento ();

    /*  Configuracao do novo elemento a ser inserido */
    strcpy (novo->nome, nome);
    novo->distancia = dist;

    /*  Configuracao e construcao do roteiro */
    roteiro->kilometragem += dist;
    roteiro->fim->proximo = novo;
    roteiro->fim = novo;
}

/*  3.4 - Funcao 'monta_roteiros', realiza a contrucao dos roteiros de viagem */
void monta_roteiros (Grafo *grafo, Roteiro *roteiro, char *atual){
    /*  'grafo' armazena o grafo que servira de base para a construcao dos roteiros de viagem;
    **  'roteiro' armazena o roteiro a ser construido; 'atual' armazena o nome da cidade que
    **  o viagem se encontra */

    /*  Existindo grafo a ser lido e roteiro a ser construido */
    if (grafo != NULL && roteiro != NULL){
        /*  'auxcity' armazena a cidade atual; 'auxref' auxilia a percorrer a lista de referencias */
        Cidade *auxcity = NULL;
        Referencia *auxref = NULL;

        /*  Procurando a cidade corrente */
        for (auxcity = grafo->inicio; auxcity != NULL; auxcity = auxcity->proximo){
            if (strcmp (auxcity->nome, atual) == 0) break;
        }

        /*  Estando classificada como Livre, sera configurada como Visitada e
        **  configurando o grafo para tal troca */
        if (auxcity->status == 'L'){
            auxcity->status = 'V';
            grafo->livres--;
        }

        /*  Procurando uma cidade ainda nao visitada, a partir da atual */
        for (auxref = auxcity->inicio; auxref != NULL; auxref = auxref->proximo){
            if (auxref->city->status == 'L') break;
        }

        /*  Encontrando uma cidade vaga */
        if (auxref != NULL && auxref->city->status == 'L'){
            /*  Insere-a no caminhon da viagem */
            insere_roteiro (roteiro, auxref->city->nome, auxref->distancia);

            /*  Configuracao para Visitada e
            **  configurando o grafo para tal troca */
            auxref->city->status = 'V';
            grafo->livres--;

            /*  Continua o caminho a partir da nova cidade */
            return monta_roteiros (grafo, roteiro, auxref->city->nome);
        }

        /*  Nao encontrando cidade vaga */
        else if ((auxref == NULL) && (grafo->livres > 0)){
            /*  'busca' armazena o nome de uma cidade que possue conexao livre dentre
            **  as conexoes de 2º ou 3º grau */
            char busca[MAX];

            /*  Inicializacao da string */
            zera_string (busca, 0, MAX);

            /*  Procurando cidade vaga dentre o 2º e 3º grau de conexao */
            for (auxref = auxcity->inicio; auxref != NULL; auxref = auxref->proximo){
                busca_ref (auxref, busca);

                /*  Encontrando uma possibilidade */
                if (strlen (busca) != 0){
                    int dist = 0;

                    /*  Configuracao da distancia para a cidade intermediaria, que possibilitou o
                    **  retorno para continuacao da viagem */
                    for (auxref = auxcity->inicio; auxref != NULL; auxref = auxref->proximo){
                        if (strcmp (auxref->city->nome, busca) == 0){
                            dist = auxref->distancia;
                            break;
                        }
                    }

                    /*  Insere-a no caminhon da viagem */
                    insere_roteiro (roteiro, busca, dist);

                    /*  Continua o caminho a partir da cidade intermediaria */
                    return monta_roteiros (grafo, roteiro, busca);
                }
            }

        }

        return;
    }
}

/*  3.5 - Funcao 'zera_grafo', realiza a reinicializacao do status das cidades do grafo */
void zera_grafo (Grafo *graph){
    /*  'graph' armazena o grafo a ser reinicializado; 'auxcity' auxilia a percorrer a
    **  a lista de cidades */
    Cidade *auxcity = NULL;

    /*  Percorrendo toda a lista de cidades do grafo */
    for (auxcity = graph->inicio; auxcity != NULL; auxcity = auxcity->proximo){
        auxcity->status = 'L';
    }
}

/* 3.6 - Funcao 'busca_ref', realiza a busca por um elemento ainda nao visitado */
void busca_ref (Referencia *ref, char *busca){
    /*  'ref' armazena a cidade a ser busca uma conexao livre dentre as conexoes de 2º
    **  e 3º grau; 'busca' armazena o nome da cidade de interesse; 'auxref' auxilia
    **  a percorrer a lista de conexoes de 1º grau */
    Referencia *auxref = NULL;

    /*  Procurando conexoes livre */
    for (auxref = ref; auxref != NULL; auxref = auxref->proximo){
        /*  Conexoes de 1º grau */
        if (auxref->city->status == 'L'){
            strcpy (busca, auxref->city->nome);
            return;
        }
        else{
            /*  'auxref2' auxilia a percorrer a lista de conexoes de 2º grau */
            Referencia *auxref2 = NULL;

            /*  Procurando conexoes livre */
            for (auxref2 = auxref->city->inicio; auxref2 != NULL; auxref2 = auxref2->proximo){
                /*  Conexoes de 2º grau */
                if(auxref2->city->status == 'L'){
                    strcpy (busca, auxref->city->nome);
                    return;
                }
                else{
                    /*  'auxref3' auxilia a percorrer a lista de conexoes de 3º grau */
                    Referencia *auxref3 = NULL;

                    /*  Procurando conexoes livre */
                    for (auxref3 = auxref2->city->inicio; auxref3 != NULL; auxref3 = auxref3->proximo){
                        /*  Conexoes de 3º grau */
                        if(auxref3->city->status == 'L'){
                            strcpy (busca, auxref2->city->nome);
                            return;
                        }
                    }
                }
            }
        }
    }
}



/*  4 - Secao de Exibicao na Tela e Escrita em Documentos */
/*  4.1 - Funcao 'exibe_ref', exibe a lista das referencias na tela */
void exibe_ref (Referencia *ref){
    /*  'ref' armazena lista de referencias a ser exibida; 'aux' auxilia a percorrer
    **  a lista */
    Referencia *aux = ref;

    /*  Enquanto houver lista */
    for (aux = ref; aux != NULL; aux = aux->proximo){
        printf ("%s (%d km)", aux->city->nome, aux->distancia);

        if (aux->proximo != NULL)
            printf (", ");
        else
            printf (";\n\n");
    }
}

/*  4.2 - Funcao 'exibe_city', exibe uma cidade na tela */
void exibe_city (Cidade *cidade){
    /*  'cidade' armazena a cidade a ser exibida */

    /*  Havendo cidade */
    if (cidade != NULL){
        printf ("%s esta conectada a %d outras cidades, sendo elas:\n", cidade->nome, cidade->quantref);
        exibe_ref (cidade->inicio);
    }
}

/*  4.3 - Funcao 'exibe_grafo', exibe o grafo na tela */
void exibe_grafo (Grafo *grafo){
    /*  'grafo' armazena o grafo a ser exibido */

    /*  Havendo grafo */
    if (grafo != NULL){
        /*  'auxcity' auxilia a percorrer a lista de cidades; 'contador' conta as cidades */
        Cidade *auxcity = NULL;
        char contador = 65;
        float tempo = 0.0;

        /*  Questionamento sobre o modo de exibicao */
        limpa_tela ();
        printf ("Para a exibicao do Grafo construido\n");
        tempo = questiona_tempo ();
        temporizador(0.8);
        limpa_tela ();

        if (tempo >= 0)
            exibe_tempo (tempo);

        printf ("Temos %d registradas, sendo elas:\n\n", grafo->quant);

        for (auxcity = grafo->inicio; auxcity != NULL; auxcity = auxcity->proximo){
            printf ("%dº Cidade:\n", contador - 64);
            exibe_city (auxcity);
            contador++;

            if (tempo >= 0)
                exibe_tempo (tempo);
        }

        pausa ();
    }
}

/*  4.4 - Funcao 'exibe_elemento', exibe a lista de elementos do roteiro
**  na tela */
void exibe_elemento (Elemento *elemento){
    /*  'elemento' armazena lista de elementos a ser exibida; 'auxelem' auxilia a percorrer
    **  a lista */
    Elemento *auxelem = NULL;

    /*  Enquanto houver lista */
    for (auxelem = elemento; auxelem != NULL; auxelem = auxelem->proximo){
        printf ("%s", auxelem->nome);

        if (auxelem->proximo != NULL)
            printf (" -> ");
        else
            printf (";\n\n");
    }
}

/*  4.5 - Funcao 'exibe_roteiro', exibe um roteiro na tela */
void exibe_roteiro (Roteiro *roteiro){
    /*  'roteiro' armazena o roteiro a ser exibido */

    /*  Havendo roteiro */
    if (roteiro != NULL){
        /* 'interesse' armazena o retorno sobre a nova exibicao de outro roteiro */
        char escolha = 'N';

        /*  Enquanto quiser exibir apenas um roteiro especifico */
        do{
            /*  'leitura' armazena a leitura sobre os roteiros a serem exibidos */
            char leitura[MAX];

            /*  Inicializacao e Configuracao de 'leitura' */
            zera_string (leitura, 0, MAX);
            questiona_roteiro (roteiro, leitura);

            /*  Sendo escolhido a exibicao de todos os roteiros */
            if(leitura[0] == 33){
                /*  'ind' armazena o indice a ser manipulado */
                char ind;
                float tempo = 0.0;

                /*  Questionamento sobre o modo de exibicao */
                limpa_tela ();
                printf ("Para a exibicao de todos os roteiros\n");
                tempo = questiona_tempo ();
                temporizador(0.8);
                limpa_tela ();

                if (tempo >= 0)
                    exibe_tempo (tempo);

                for (ind = 65; ind < MAXC + 65; ind++){
                    printf ("Partindo de %s, rota de %d km:\n", roteiro[ind - 65].inicio->nome, roteiro[ind - 65].kilometragem);
                    exibe_elemento (roteiro[ind -65].inicio->proximo);

                    if (tempo >= 0)
                        exibe_tempo (tempo);
                }
            }
            /*  Um roteiro especifico */
            else{
                /*  'ind' armazena o indice a ser manipulado */
                char ind;

                /*  Procurando a cidade para exibicao do roteiro */
                for (ind = 65; ind < MAXC + 65; ind++)
                    if (strcmp (roteiro[ind -65].inicio->nome, leitura) == 0) break;

                printf ("\nA rota para %s sera exibida...", roteiro[ind - 65].inicio->nome);
                temporizador(0.8);

                printf ("A rota tem um total de %d km:\n", roteiro[ind - 65].kilometragem);
                    exibe_elemento (roteiro[ind -65].inicio->proximo);

                /*  Questionamento sobre a exibicao de outro roteiro */
                printf ("Tem interesse de exibir outra rota? S/N ou s/n\n");
                escolha = ler_simounao ();
            }
            pausa ();

        }while (escolha == 's' || escolha == 'S');
    }
}

/*  4.6 - Escreve as referencias no arquivo */
void escreve_ref (FILE *arq, Referencia *ref){
    /*  'arq' armazena o arquivo a ser escrito as referencias; 'ref' armazena lista
    **  de referencias a ser exibida; 'aux' auxilia a percorrer a lista */
    Referencia *aux = ref;

    /*  Enquanto houver lista */
    for (aux = ref; aux != NULL; aux = aux->proximo){
        fprintf (arq, "%s (%d km)", aux->city->nome, aux->distancia);

        if (aux->proximo != NULL)
            fprintf (arq, ", ");
        else
            fprintf (arq, ";\n\n");
    }
}

/*  4.7 - Escreve a cidade no arquivo */
void escreve_city (FILE *arq, Cidade *cidade){
    /*  'arq' armazena o arquivo a ser escrito as referencias; 'cidade' armazena
    **  a cidade a ser exibida */

    /*  Havendo cidade */
    if (cidade != NULL){
        fprintf (arq, "%s esta conectada a %d outras cidades, sendo elas:\n", cidade->nome, cidade->quantref);
        escreve_ref (arq, cidade->inicio);
    }
}

/*  4.8 - Escreve o grafo no arquivo */
void escreve_grafo (Grafo *grafo, Roteiro *roteiro){
    /*  'grafo' armazena o grafo a ser exibido; 'roteiro' armazena os roteiros
    **  a serem escritos no arquivo */

    /*  Havendo grafo */
    if (grafo != NULL){
        /*  'auxcity' auxilia a percorrer a lista de cidades; 'contador' conta as cidades */
        Cidade *auxcity = NULL;
        char contador = 65, nomearq[MAXC * 2];
        FILE *arq = NULL;


        /*  Leitura dinaminca do documento para escrita e configuraca de 'arq' */
        ler_nome_doc (nomearq);
        arq = abre_arquivo (nomearq, 'w', 'l');

        if (roteiro != NULL){
            fprintf (arq, "As rotas encontradas foram essas:\n");
            escreve_roteiro (arq, roteiro);
        }

        fprintf (arq, "\n\nTemos %d registradas, apresentando-as e suas ligacoes diretas:\n\n", grafo->quant);

        for (auxcity = grafo->inicio; auxcity != NULL; auxcity = auxcity->proximo){
            fprintf (arq, "%dº Cidade:\n", contador - 64);
            escreve_city (arq, auxcity);
            contador++;
        }

        fclose (arq);
    }

}

/*  4.9 - Escreve a lista de elementos do roteiro
**  no arquivo */
void escreve_elemento (FILE *arq, Elemento *elemento){
    /*  'arq' armazena o arquivo a ser escrito as referencias; 'elemento' armazena
    **  lista de elementos a ser exibida; 'auxelem' auxilia a percorrer a lista */
    Elemento *auxelem = NULL;

    /*  Enquanto houver lista */
    for (auxelem = elemento; auxelem != NULL; auxelem = auxelem->proximo){
        fprintf (arq, "%s", auxelem->nome);

        if (auxelem->proximo != NULL)
            fprintf (arq, " -> ");
        else
            fprintf (arq, ";\n\n");
    }
}

/*  4.10 - Escreve os roteiros de viagem no arquivo */
void escreve_roteiro (FILE *arq, Roteiro *roteiro){
    /*  'arq' armazena o arquivo a ser escrito as referencias; 'roteiro' armazena
    **  o roteiro a ser exibido */

    /*  Havendo roteiro */
    if (roteiro != NULL){
        /*  'ind' armazena o indice a ser manipulado */
        char ind;

        pausa ();
        limpa_tela ();
        for (ind = 65; ind < MAXC + 65; ind++){
            fprintf (arq, "%dº Partindo de %s, rota de %d km:\n", ind - 64, roteiro[ind - 65].inicio->nome, roteiro[ind - 65].kilometragem);
            escreve_elemento (arq, roteiro[ind -65].inicio->proximo);
        }
    }
}

/*  4.11 - Funcao 'exibe_tempo', realiza a pausa escolhida pelo usuario */
void exibe_tempo (float tempo){
    /*  'tempo' armazena o tempo de espera entre as atualizacao das informacoes */

    /*  Sendo por ENTER */
    if (tempo == 0.0)
        pausa ();

    /*  Sendo por tempo */
    else
        temporizador (tempo);
}
