/*****************************************************************
**      Inclusão das bibliotecas
*****************************************************************/
#include "../Bibliotecas/Arquivos.hpp"
#include "../Bibliotecas/Basica.hpp"
#include <stdio.h>
#include <stdlib.h>


/*****************************************************************
**      Definição das Funções
*****************************************************************/


/***********************************************************************************
* Funcao: ler dados do arquivo
* Descricao
*    Abre o arquivo texto "teste.txt" e comeca a leitura do arquivo atraves de blocos de 100 caracteres ate
*    que o fim do arquivo seja atingido. A cada bloco lido, analisa o primeiro caracter e verifica se ele
*    indica interconexao, adaptador, cidade ou gerador. Apos copiar os dados equivalentes de cada estrutura,
*    chama as funcoes de inserir para realizar a insercao dos dados nas listas corretas.
* Parametros
*    rede -  ponteiro para estrutura do tipo Rede. Consulte o arquivo Estruturas.hpp para mais
*    detalhes sobre o tipo Rede
* Valor retornado
*    Ponteiro para o tipo Rede
* Assertivas de entrada
*    rede!=NULL
*    teste.txt existente na mesma pasta onde sera realizada a leitura
* Asserivas de saida
*    SE arquivo != NULL ENTAO
*    a funcao retorna o ponteiro do tipo Rede que entrou na funcao contendo informacoes do cabecalho
*    de todas as listas (geradores,adaptadores, interconexoes, posicao e cidades)
*    SENAO
*    o ponteiro enviado para a funcao nao e modificado
*    FIMSE
*
*
*
*
*
*
*
***********************************************************************************/

/* Lê o arquivo txt base e gera as listas com os elementos contidos */
Rede* arq_ler (Rede *rede){

	std::string nome2 = "../ARQUIVOS/teste.txt";
    FILE* arquivo = arq_abre (nome2, "r", 'l');
    Info info;
    char texto[100],nome[50],aux[5];
    int i,j;
    if(arquivo){

        while(fgets(texto,100,arquivo) != NULL){/* Enquanto não for o final do arquivo */
            /*    if (strcmp(texto, "I inter_3 2 3 15 47 100 0.394383 1 20") == 0){
                    printf("chegou\n");
                }*/
                printf("%s\n",texto);
                if(arquivo==NULL){
                    printf("NULO!");

                }
            if(texto[0] == 'C'){/* Se for uma linha de cidade*/

                info.tipo_info = texto[0];

                for(i=2;texto[i]!=' ';i++){/* Copia o nome da cidade */
                    nome[i-2] = texto[i];
                }
                nome[i-2]='\0';
                strcpy(info.nome_info,nome);
                i++;

                for(j=i;texto[j]!=' ';j++){/* Copia a linha inicial */
                    aux[j-i] = texto[j];
                }
                aux[j-i]='\0';
                info.lin_i=atoi(aux);
                j++;

                for(i=j;texto[i]!=' ';i++){/* Copia a coluna inicial */
                    aux[i-j] = texto[i];
                }
                aux[i-j] = '\0';
                info.col_i=atoi(aux);
                i++;

                for(j=i;texto[j]!='\n';j++){/* Copia a capacidade */
                    aux[j-i] = texto[j];
                }
                info.cpcd=atoi(aux);

                rede->in_city->inicio = city_insere(rede->in_city->inicio, info);
                info.enderecoC = rede->in_city->inicio;
                rede->inicio = pos_insere (rede->inicio,info);

                /*atualiza os contadores*/
                rede->in_city->qnt++;
                rede->in_city->rec += info.cpcd;

            }
            else if(texto[0] == 'G'){/* Se for uma linha de gerador*/

                info.tipo_info = texto[0];

                for(i=2;texto[i]!=' ';i++){/* Copia o nome do gerador */
                    nome[i-2] = texto[i];
                }
                nome[i-2]='\0';
                strcpy(info.nome_info,nome);
                i++;

                for(j=i;texto[j]!=' ';j++){/* Copia a linha inicial */
                    aux[j-i] = texto[j];
                }
                aux[j-i]='\0';
                info.lin_i=atoi(aux);
                j++;

                for(i=j;texto[i]!=' ';i++){/* Copia a coluna inicial */
                    aux[i-j] = texto[i];
                }
                aux[i-j] = '\0';
                info.col_i=atoi(aux);
                i++;

                for(j=i;texto[j]!=' ';j++){/* Copia a capacidade */
                    aux[j-i] = texto[j];
                }
                info.cpcd=atoi(aux);
                j++;

                for(i=j;texto[i]!='\n';i++){/* Copia o custo */
                    aux[i-j] = texto[i];
                }
                aux[i-j] = '\0';
                info.custo=atoi(aux);


                rede->in_ger->inicio = gerador_insere(rede->in_ger->inicio,info);
                info.enderecoG = rede->in_ger->inicio;
                rede->inicio = pos_insere (rede->inicio,info);

                /*atualiza os contadores*/
                rede->in_ger->custo += info.custo;
                rede->in_ger->qnt++;
                rede->in_ger->rec += info.cpcd;

            }
            else if(texto[0] == 'I'){/* Se for uma linha de interconexão */

                info.tipo_info = texto[0];

                for(i=2;texto[i]!=' ';i++){/* Copia o nome da interconexão*/
                    nome[i-2] = texto[i];
                }
                nome[i-2]='\0';
                strcpy(info.nome_info,nome);
                i++;

                for(j=i;texto[j]!=' ';j++){/* Copia a linha inicial */
                    aux[j-i] = texto[j];
                }
                aux[j-i]='\0';
                info.lin_i=atoi(aux);
                j++;

                for(i=j;texto[i]!=' ';i++){/* Copia a coluna inicial */
                    aux[i-j] = texto[i];
                }
                aux[i-j] = '\0';
                info.col_i=atoi(aux);
                i++;

                for(j=i;texto[j]!=' ';j++){/* Copia a linha final */
                    aux[j-i] = texto[j];
                }
                aux[j-i]='\0';
                info.lin_f=atoi(aux);
                j++;

                for(i=j;texto[i]!=' ';i++){/* Copia a coluna final */
                    aux[i-j] = texto[i];
                }
                aux[i-j] = '\0';
                info.col_f=atoi(aux);
                i++;

                for(j=i;texto[j]!=' ';j++){/* Copia a capacidade */
                    aux[j-i] = texto[j];
                }
                aux[j-i]='\0';
                info.cpcd=atoi(aux);
                j++;

                for(i=j;texto[i]!=' ';i++){/* Copia a chance de falha */
                    aux[i-j] = texto[i];
                }
                aux[i-j] = '\0';
                info.falha=(float)atof(aux);
                i++;

                for(j=i;texto[j]!=' ';j++){/* Copia o tempo */
                    aux[j-i] = texto[j];
                }
                aux[j-i]='\0';
                info.tempo=atoi(aux);
                j++;

                for(i=j;texto[i]!='\n';i++){/* Copia o custo */
                    aux[i-j] = texto[i];
                }
                aux[i-j] = '\0';
                info.custo=atoi(aux);
                i++;

                rede->in_conex->inic = conexao_insere (rede->in_conex->inic, info);

                /*atualiza os contadores*/
                rede->in_conex->tam_tot += pitagoras(info);
                rede->in_conex->total++;

            }
            else if(texto[0] == 'A'){/* Se for uma linha de adaptador */

                info.tipo_info = texto[0];

                for(i=2;texto[i]!=' ';i++){/* Copia o nome do adaptador */
                    nome[i-2] = texto[i];
                }
                nome[i-2]='\0';
                strcpy(info.nome_info,nome);
                i++;

                for(j=i;texto[j]!=' ';j++){/* Copia a linha inicial */
                    aux[j-i] = texto[j];
                }
                aux[j-i]='\0';
                info.lin_i=atoi(aux);
                j++;

                for(i=j;texto[i]!='\0';i++){/* Copia a coluna inicial */
                    aux[i-j] = texto[i];
                }
                aux[i-j] = '\0';
                info.col_i=atoi(aux);
                i++;

                rede->in_adap->inicio = adaptador_insere(rede->in_adap->inicio,info);
                info.enderecoA = rede->in_adap->inicio;
                rede->inicio = pos_insere (rede->inicio,info);

                /*atualiza os contadores*/
                rede->in_adap->qnt++;

            }
        }
    }else{
        printf("Nao ha arquivo");
    }
    return rede;
}

/***********************************************************************************
* Funcao: inserir na lista de adaptadores
* Descricao
*    Copia todas as informacoes referentes a um adaptador presentes na estrutura do tipo Info para a lista
*    encadeada de adaptadores. O encadeamento ocorre no inicio da lista.
* Parametros
*    lista - ponteiro para inicio de estrutura do tipo Adaptador. Consulte o arquivo Estruturas.hpp para
*    mais detalhes sobre o tipo Rede
*    info - estrutura do tipo Info. Contem as informcaoes necessarias para inserir em qualquer uma das
*    listas  utilizadas (geradores,adaptadores, interconexoes e cidades).
* Valor retornado
*    Ponteiro para o tipo Adaptador
* Assertivas de entrada
*    lista!=NULL
*    info contendo todas as informacoes presentes no arquivo texto relacionadas ao adaptador
* Asserivas de saida
*    SE lista != NULL ENTAO
*    a funcao retorna o ponteiro do tipo Adaptador que entrou na funcao contendo informacoes do novo
*    elemento inserido de lista de adaptadores. Esse elemento se torna o novo inicio da lista
*    SENAO
*    funcao cria um novo elemento e o torna o inicio da lista
*    FIMSE
***********************************************************************************/

/* Insere elemento lido na lista de adaptadores */
Adaptador* adaptador_insere (Adaptador* lista, Info info){
    Adaptador* novo = (Adaptador*) malloc (sizeof(Adaptador));
    strcpy(novo->nome,info.nome_info);
    novo->entrada = 0;
    novo->lin_i = info.lin_i;
    novo->col_i = info.col_i;
    novo->prox = lista;
    lista = novo;
return lista;
}



/***********************************************************************************
* Funcao: inserir na lista de geradores
* Descricao
*    Copia todas as informacoes referentes a um gerador presentes na estrutura do tipo Info para a lista
*    encadeada de geradores. O encadeamento ocorre no inicio da lista.
* Parametros
*    lista - ponteiro para inicio de estrutura do tipo Gerador. Consulte o arquivo Estruturas.hpp para
*    mais detalhes sobre o tipo Rede
*    info - estrutura do tipo Info. Contem as informcaoes necessarias para inserir em qualquer uma das
*    listas  utilizadas (geradores,adaptadores, interconexoes e cidades).
* Valor retornado
*    Ponteiro para o tipo Gerador
* Assertivas de entrada
*    lista!=NULL
*    info contendo todas as informacoes presentes no arquivo texto relacionadas ao gerador
* Asserivas de saida
*    lista != NULL
***********************************************************************************/
Gerador* gerador_insere (Gerador* lista, Info info){
    Gerador* novo = (Gerador*) malloc (sizeof(Gerador));
    strcpy(novo->nome,info.nome_info);
    novo->lin_i = info.lin_i;
    novo->col_i = info.col_i;
    novo->rec = info.cpcd;
    novo->custo = info.custo;
    novo->prox = lista;
    lista = novo;
return lista;
}


/***********************************************************************************
* Funcao: inserir na lista de cidades
* Descricao
*    Copia todas as informacoes referentes a uma cidade presentes na estrutura do tipo Info para a lista
*    encadeada de cidades. O encadeamento ocorre no inicio da lista.
* Parametros
*    lista - ponteiro para inicio de estrutura do tipo Cidades. Consulte o arquivo Estruturas.hpp para
*    mais detalhes sobre o tipo Rede
*    info - estrutura do tipo Info. Contem as informcaoes necessarias para inserir em qualquer uma das
*    listas  utilizadas (geradores,adaptadores, interconexoes e cidades).
* Valor retornado
*    Ponteiro para o tipo City
* Assertivas de entrada
*    lista!=NULL
*    info contendo todas as informacoes presentes no arquivo texto relacionadas a cidade
* Asserivas de saida
*    lista != NULL
***********************************************************************************/
City* city_insere (City* lista, Info info){
    City* novo = (City*) malloc (sizeof(City));
    strcpy(novo->nome,info.nome_info);
    novo->recebida = 0;
    novo->lin_i = info.lin_i;
    novo->col_i = info.col_i;
    novo->rec = info.cpcd;
    novo->prox = lista;
    novo->t_s_rec = 0;
    novo->t_30_rec = 0;
    lista = novo;

return lista;
}

/***********************************************************************************
* Funcao: inserir na lista de conexoes
* Descricao
*    Copia todas as informacoes referentes a uma conexão presentes na estrutura do tipo Info para a lista
*    encadeada de conexões. O encadeamento ocorre no inicio da lista.
* Parametros
*    lista - ponteiro para inicio de estrutura do tipo Conexoes. Consulte o arquivo Estruturas.hpp para
*    mais detalhes sobre o tipo Rede
*    info - estrutura do tipo Info. Contem as informcaoes necessarias para inserir em qualquer uma das
*    listas  utilizadas (geradores,adaptadores, interconexoes e cidades).
* Valor retornado
*    Ponteiro para o tipo Conexao
* Assertivas de entrada
*    lista!=NULL
*    info contendo todas as informacoes presentes no arquivo texto relacionadas a cidade
* Asserivas de saida
*    lista != NULL
***********************************************************************************/
Conexao* conexao_insere (Conexao* lista, Info info){
    Conexao* novo = (Conexao*) malloc (sizeof(Conexao));
    if(novo){


        strcpy(novo->nome,info.nome_info);
        novo->status = 0;
        novo->lin_i = info.lin_i;
        novo->col_i = info.col_i;
        novo->lin_f = info.lin_f;
        novo->col_f = info.col_f;
        novo->cpc = info.cpcd;
        novo->custo = info.custo;
        novo->prob_falha = info.falha;
        novo->temp=info.tempo;
        novo->prox_i = lista;
        lista = novo;
    }else{
         printf("novo NULO\n");
    }
return lista;
}

/***********************************************************************************
* Funcao: inserir na lista de posiçoes
* Descricao
*    Copia todas as informacoes referentes a uma cidade, um gerador, um adaptador ou uma conexão
*    presentes na estrutura do tipo Info para a lista encadeada de posições.
*    O encadeamento ocorre no inicio da lista.
* Parametros
*    lista - ponteiro para inicio de estrutura do tipo Posições. Consulte o arquivo Estruturas.hpp para
*    mais detalhes sobre o tipo Rede
*    info - estrutura do tipo Info. Contem as informcaoes necessarias para inserir em qualquer uma das
*    listas  utilizadas (geradores,adaptadores, interconexoes e cidades).
* Valor retornado
*    Ponteiro para o tipo Posicao
* Assertivas de entrada
*    lista!=NULL
*    info contendo todas as informacoes presentes no arquivo texto relacionadas a estrutura
* Asserivas de saida
*    lista != NULL
***********************************************************************************/
Posicoes* pos_insere(Posicoes* lista, Info info){
    Posicoes* novo = (Posicoes*) malloc(sizeof(Posicoes));

    novo->tipo = info.tipo_info;
    if (info.tipo_info == 'C'){
        novo->cid = info.enderecoC;
    }else if(info.tipo_info == 'G'){
        novo->gera = info.enderecoG;
    }else if(info.tipo_info == 'A'){
        novo->adapt = info.enderecoA;
    }
    novo->x = info.lin_i;
    novo->y = info.col_i;
    novo->prox = lista;
    lista = novo;
return lista;
}


