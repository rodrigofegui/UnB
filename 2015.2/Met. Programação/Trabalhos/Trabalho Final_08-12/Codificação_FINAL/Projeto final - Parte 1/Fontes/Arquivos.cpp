/*****************************************************************
**      Inclusão das bibliotecas
*****************************************************************/
#include "../Bibliotecas/Arquivos.hpp"


/*****************************************************************
**      Definição das Funções
*****************************************************************/

/* Lê o arquivo txt base e gera as listas com os elementos contidos */
Rede* arq_ler (Rede *rede){

    FILE* arquivo = fopen("teste.txt","r");
    Info info;
    char texto[100],nome[50],aux[5];
    int i,j;

    while(fgets(texto,100,arquivo) != NULL){/* Enquanto não for o final do arquivo */
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

    return rede;
}

/* Insere elemento lido na lista de adaptadores */
Adaptador* adaptador_insere (Adaptador* lista, Info info){
    Adaptador* novo = (Adaptador*) malloc (sizeof(Adaptador));
    strcpy(novo->nome,info.nome_info);
    novo->lin_i = info.lin_i;
    novo->col_i = info.col_i;
    novo->prox = lista;
    lista = novo;
return lista;
}

/* Insere elemento lido na lista de geradores */
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

/* Insere elemento lido na lista de cidades */
City* city_insere (City* lista, Info info){
    City* novo = (City*) malloc (sizeof(City));
    strcpy(novo->nome,info.nome_info);
    novo->lin_i = info.lin_i;
    novo->col_i = info.col_i;
    novo->rec = info.cpcd;
    novo->prox = lista;
    lista = novo;

return lista;
}

/* Insere elemento lido na lista de interconexoes */
Conexao* conexao_insere (Conexao* lista, Info info){
    Conexao* novo = (Conexao*) malloc (sizeof(Conexao));
    strcpy(novo->nome,info.nome_info);
    novo->lin_i = info.lin_i;
    novo->col_i = info.col_i;
    novo->lin_f = info.lin_f;
    novo->col_f = info.col_f;
    novo->cpc = info.cpcd;
    novo->custo = info.custo;
    novo->prob_falha = info.falha;
    novo->prox_i = lista;
    lista = novo;
return lista;
}

/* Insere elemento lido na lista de posições */
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


