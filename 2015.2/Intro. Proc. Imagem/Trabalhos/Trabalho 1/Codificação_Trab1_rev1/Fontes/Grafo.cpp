/*  Inclusão das bibliotecas requisitadas: */
#include "../Bibliotecas/Grafo.hpp"


/*  Definições das funções a serem manipuladas por este arquivo */
/*  Função 'conectado_cria', realiza a criação de uma novo elemento conectado numa
**  região da imagem */
Conectado * conectado_cria (Ponto posicao){
    /*  'novo' armazena o elemento conectado a ser criado */
    Conectado *novo = NULL;

    /*  Alocação do pixel */
    do{
        novo = (Conectado *) malloc (sizeof(Conectado));
    }while (novo == NULL);

    /*  Configuração das variáveis de controle */
    novo->pixel.lin = posicao.lin;
    novo->pixel.col = posicao.col;
    novo->proximo = NULL;

    return novo;
}

/*  Função 'regiao_cria', realiza a criação de uma nova região na imagem */
Regiao * regiao_cria(Ponto novopivo){
    /*  'nova' armazena a região a ser criada */
    Regiao *nova = NULL;

    /*  Alocação da Região */
    do{
        nova = (Regiao *) malloc (sizeof(Regiao));
    }while (nova == NULL);

    /*  Inicialização das variáveis de controle */
    nova->quantconec = 0;
    nova->pivo.lin = novopivo.lin;
    nova->pivo.col = novopivo.col;
    nova->quantconec = 1;
    nova->proximo = NULL;

    return nova;
}

/*  Função 'grafo_cria', realiza a criação do grafo que gerenciará as regiões da imagem */
Grafo * grafo_cria(){
    /*  'novo' armazena o grafo a ser criado */
    Grafo *novo = NULL;

    /*  Alocação do Grafo */
    do{
        novo = (Grafo *) malloc (sizeof(Grafo));
    }while (novo == NULL);


    /*  Inicialização das variáveis de controle */
    novo->quantreg = novo->areabranca = novo->areamaior = 0;
    novo->inicio = NULL;

    return novo;
}

/*  Função 'conectado_libera', realiza a liberação da memória alocada para um elemento */
void conectado_libera (Conectado *pixel){
    /*  'pixel' armazena o elemento a ser desalocado */

    /*  Havendo o que desalocar */
    if (pixel != NULL){
        free (pixel);
		pixel = NULL;
	}
}

/*  Função 'regiao_libera', realiza a liberação da memória alovada para uma regiao */
void regiao_libera (Regiao *regiao){
    /*  'regiao' armazena a regiao a ser desalocada */

    /*  Havendo região a ser desalocada */
    if (regiao != NULL){
        Conectado *auxiliar;

        /*  Enquanto houver lista de elemento conectados na regiao *
        while (regiao->inicio != NULL){
        /*  'auxiliar' auxilia na liberação dos elementos conectados da região *
            auxiliar = regiao->inicio;
            regiao->inicio = auxiliar->proximo;
            conectado_libera (auxiliar);
        }
		//*/

        /*  Liberação da regiao em si */
        free (regiao);
		regiao = NULL;
    }
}

/*  Função 'grafo_libera', realiza a liberação da memória alocada para um grafo */
void grafo_libera (Grafo *grafo){
    /*  'grafo' armazena o grafo a ser desalocado */

    /*  Havendo grafo a ser liberado */
    if (grafo != NULL){
        /*  'auxiliar' auxilia na liberação das regiões do grafo */
        Regiao *auxiliar;

        /*  Enquanto houver lista de regiões */
        while (grafo->inicio != NULL){
            auxiliar = grafo->inicio;
            grafo->inicio = auxiliar->proximo;
            regiao_libera (auxiliar);
            grafo->quantreg--;
        }

        /*  Liberação do grafo em si */
        free (grafo);
		grafo = NULL;
    }

}

/*  Função 'grafo_constroi', realiza o controle sobre a criação, incremento ou
**  nenhuma ação sobre as regioes */
void grafo_constroi (Grafo *grafo, Ponto pivo, Ponto interior){
    /*  'grafo' armazena o grafo a ser construído; 'pivo' armazena o pixel pivo da região;
    **  'interior' armazena o ponto atual a ser inserido */

    /*  Havendo grafo válido */
    if (grafo != NULL){
        /*  Não havendo regiões cadastradas */
        if (grafo->inicio == NULL){
            /*  'nova' armazena a nova região a ser inserida no grafo */
            Regiao *nova = regiao_cria (pivo);

            /*  Configuração do grafo */
            grafo->inicio = nova;
            grafo->quantreg = VERDADE;

        /*  Caso contrário */
        }else{
            /*  'auxreg' auxilia a percorrer a lista de regiões cadastradas */
            Regiao *auxreg = grafo->inicio;

            /*  Enquanto houver lista e não for encontrada a região */
            while ((auxreg->proximo != NULL) && (ponto_compara(auxreg->pivo, pivo) != VERDADE))
                auxreg = auxreg->proximo;

            /*  Encontrando uma região já cadastrada, incrementar quantidade de elementos conectados */
            if ((ponto_compara(auxreg->pivo, pivo) == VERDADE)
                || ((auxreg->proximo == NULL) && (ponto_compara(auxreg->pivo, pivo) == VERDADE))){
                auxreg->quantconec++;

            /*  Não encontrando, criar uma nova região */
            }else if ((auxreg->proximo == NULL) && (ponto_compara(auxreg->pivo, pivo) != VERDADE)){
                /*  'nova' armazena a nova região a ser inserida no grafo */
                Regiao *nova = regiao_cria (pivo);

                /*  Configuração do grafo */
                auxreg->proximo = nova;
                grafo->quantreg++;
            }
        }
    }
}

/*  Função 'conectado_escreve', escreve num arquivo um dado elemento de uma regiao */
void conectado_escreve (FILE *arq, Conectado *pixel){
    /*  'arq' armazena o arquivo a ser escrito as informações; 'pixel' armazena o pixel
    **  a ser escrito */

    fprintf (arq, "[%d][%d]", pixel->pixel.lin, pixel->pixel.col);
}

/*  Função 'regiao_escreve', escreve num arquivo uma dada regiao */
void regiao_escreve (FILE *arq, Regiao *reg){
    /*  'arq' armazena o arquivo a ser escrito as informações; 'reg' armazena a região
    **  a ser escrita */

    fprintf (arq, "Coordena do pivo = [%d][%d]\n", reg->pivo.lin, reg->pivo.col);
    fprintf (arq, "Quantidade de elementos conectados a partir do pivo = %d.\n\n", reg->quantconec - 1);
	/*
	if (reg->quantconec - 1 <= 0){
        fprintf (arq, ".\n\n");

    }else{
        Conectado *aux;
        fprintf (arq, ", sendo ele(s):\n");
        for (aux = reg->inicio; aux != NULL; aux = aux->proximo){
            conectado_escreve (arq, aux);

            if (aux->proximo != NULL)
                fprintf (arq, ", ");
            else
                fprintf (arq, ";\n\n");
        }
    }
	//*/
}

/*  Função 'grafo_escreve', escreve num arquivo o grafo formado */
void grafo_escreve (Grafo *grafo){
    /*  'grafo' armazena o grafo a ser escrito no arquivo; 'nomearq' armazena o nome
    **  do arquivo de saida; 'arq' armazena o arquivo lógico para a gravação do grafo
    **  'aux' auxilia a percorrer a lista de regiões cadastradas */
    char nomearq[] = "Dados do Grafo Gerado.txt";
    FILE *arq = arq_abre (nomearq, 'w', 'e');
    Regiao *aux = grafo->inicio;

    fprintf (arq, "Inicio do Grafo Gerado:\n\n");

    fprintf (arq, "Maior area registrada = %d\n", grafo->areamaior);
    fprintf (arq, "Area branca registrada = %d\n", grafo->areabranca);
    fprintf (arq, "Foram detectadas %d regioes", grafo->quantreg);
    if (grafo->quantreg <= 0){
        fprintf (arq, ".\n\n");

    }else{
        fprintf (arq, ", sendo ela(s):\n");
        while (aux != NULL){
            regiao_escreve (arq, aux);
            aux = aux->proximo;
        }
    }

    fclose (arq);
}

/*  Função 'grafo_escreve_resumo', escreve num arquivo o cabeçalho de um grafo formado */
void grafo_escreve_resumo (FILE *arq, Grafo *grafo){
    /*  'arq' armazena o arquivo a ser escrito as informações; 'grafo' armazena o grafo
    **  a ser escrito */

    fprintf (arq, "\tCom %d regioes detectadas, temos:\n", grafo->quantreg);
    fprintf (arq, "\tA maior area de pele com %d pixels;\n", grafo->areamaior);
    fprintf (arq, "\tUma area total de %d pixels como tons de pele.", grafo->areabranca);
}

/*  Função 'ponto_compara', realiza a comparação entre dois pontos */
bool ponto_compara (Ponto primeiro, Ponto segundo){
    /*  'primeiro' e 'segundo' armazenam os pontos a serem comparados */

    /*  Tendo todas as coordenas iguais, retorna como VERDADE */
    if ((primeiro.lin == segundo.lin) && (primeiro.col == segundo.col))
        return VERDADE;

    /*  Caso contrário */
    return !VERDADE;
}

/*  Função 'grafo_calcula_areas', realiza a determinaçao das informaçoes com respeito as áreas */
void grafo_calcula_areas (Grafo *grafo){
    /*  'grafo' armazena o grafo a ser avaliado; 'auxreg' auxilia a percorrer a lista de regiões */
    Regiao *auxreg = grafo->inicio;

    /*  Enquanto houver regiões a serem analisadas */
    while (auxreg != NULL){
        /*  Sendo maior que a área maior registrada, registra esta nova área */
        if (auxreg->quantconec > grafo->areamaior)
            grafo->areamaior = auxreg->quantconec;

        /*  Somatório das áreas */
        grafo->areabranca += auxreg->quantconec;

        auxreg = auxreg->proximo;
    }
}



/*  Função 'imagem_mapea_regioes', realiza o mapeamento da imagem para determinação
**  das regiões da mesma, em relação ao BRANCO */
void imagem_mapea_regioes (Mat segmentada, Grafo *grafo){
    /*  'segmentada' armazena a imagem segmentada a ser procura as regiões; 'grafo' armazena as regioes
    **  encontradas; 'mapeada' armazena as visitas nos pixeis visitados; 'linha' e 'coluna' armazenam
    **  coordenadas a serem manipuladas; 'pixel' armazena um pixel encontrado */
    Mat mapeada = Mat::zeros (LIN_ALVO, COL_ALVO, CV_8UC1);
    int linha, coluna;
    Ponto pixel;

    /*  Percorrendo da linha 1 a TOTAL - 1, analogo para a coluna; pois ao avaliar a 8-vizinhança não
    **  haja problema de borda */
    for (linha = 1; linha < mapeada.rows - 1; linha++){
        for (coluna = 1; coluna < mapeada.cols - 1; coluna++){
            /*  Sendo um pixel válido e não visitado */
            if ((segmentada.at<uchar>(linha, coluna) == BRANCO) && (mapeada.at<uchar>(linha, coluna) == PRETO)){
                /*  Configuração do pixel e da matriz de visitas */
                pixel.lin = linha;
                pixel.col = coluna;
                mapeada.at<uchar>(linha, coluna) = BRANCO;

                /*  Inserção deste ponto no grafo, com uma nova região */
                grafo_constroi (grafo, pixel, pixel);

                /*  Mapeando a região encontrada a partir da sua 8-vizinhança */
                imagem_percorre_regioes (grafo, segmentada, &mapeada, pixel, pixel);
            }
        }
    }

    mapeada.release ();
}

/*  Função 'imagem_percorre_regioes', realiza a detecção de toda uma região a partir de um pixel
**  pivo */
void imagem_percorre_regioes (Grafo *grafo, Mat segmentada, Mat *mapeada, Ponto pivo, Ponto atual){
    /*  'grafo' armazena o grafo a ser manipulado; 'segmentada' armazena a imagem binaria de base;
    **  'mapeada' armazena os pixels já visitados; 'pivo' armazena o primeiro ponto encontrado de uma
    **  região; 'atual' armazena o ponto atual a ser analisado; 'neighbor' armazena os 8-vizinhos do
    **  ponto atual; 'linha' e 'coluna' auxiliam a navegação nas matrizes; 'avaliar' armazena um ponto
    **  da 8-vizinhança candidato a entrar na região do 'pivo' */
    int vizinhanca[IMG_CAMADAS][IMG_CAMADAS];
    int linha, coluna;
    Ponto avaliar;

    /*  Inicialização da vizinhança */
    for (linha = 0; linha < IMG_CAMADAS; linha++){
        for (coluna = 0; coluna < IMG_CAMADAS; coluna++){
            vizinhanca[linha][coluna] = !VERDADE;
        }
    }

    /*  Buscando em toda a 8-vizinhança do pixel */
    for (linha = atual.lin - 1; linha < atual.lin + 2; linha++){
        for (coluna = atual.col - 1; coluna < atual.col + 2; coluna++){
            /*  Estando dentro da imagem */
            if ((linha >= 0 && linha <= segmentada.rows) && (coluna >= 0 && coluna <= segmentada.cols))
                /*  Tendo o mesmo valor que o pixel de referência, a vizinhança eh configurada
                **  assim como seus status */
                if (segmentada.at<uchar>(linha, coluna) == segmentada.at<uchar>(atual.lin, atual.col)){
                    vizinhanca[linha -  atual.lin + 1][coluna - atual.col + 1] = VERDADE;
                }
        }
    }

    /*  Percorrendo toda a vizinhança */
    for (linha = 0; linha < IMG_CAMADAS; linha++){
        for (coluna = 0; coluna < IMG_CAMADAS; coluna++){
            /*  Sendo um vizinho válido */
            if (vizinhanca[linha][coluna] == VERDADE){
                /*  Configuraçao do ponto candidato */
                avaliar.lin = atual.lin + linha - 1;
                avaliar.col = atual.col + coluna - 1;

                /*  Verificação do ponto cantidato, analisar se já foi cadastrado ou não; sendo a
                **  segundo opção continua */
                if (mapeada->at<uchar>(avaliar.lin, avaliar.col) == PRETO){
                    /*  Marcação como pixel já visitado */
                    mapeada->at<uchar>(avaliar.lin, avaliar.col) = BRANCO;

                    /*  Inserção do ponto no grafo */
                    grafo_constroi (grafo, pivo, avaliar);

                    /*  Mapeando a região encontrada a partir da sua 8-vizinhança */
                    imagem_percorre_regioes (grafo, segmentada, mapeada, pivo, avaliar);
                }
            }
        }
    }

    return;
}

/*  Função 'levantamento_escreve', escreve num documento as informações importantes sobre
**  as imagens */
void levantamento_escreve (FILE *arq, Grafo *grafo, char *nomeimg){
    /*  'arq' armazena o arquivo a ser escrito as informações; 'grafo' armazena o grafo
    **  a ser escrito; 'nomeimg' armazena o nome da imagem  dona das informações a serem escritas */

    fprintf (arq, "Levantamento das informações sobre:");
    fprintf (arq, "\t%s\n", nomeimg);

    /*  Escrita das informações básicas do grafo */
    grafo_escreve_resumo (arq, grafo);

    fprintf (arq, "\n\n");
}

/*  Funçao 'imagem_classifica', realiza a classificaçã da imagem de acordo como uma classe ou outra */
void imagem_classifica (Grafo *regioes, FMeasure *f1, char *nomeimg){
    /*  'regiões' armazena as informações referente a binarização da imagem; 'f1' armazena as estatísticas
    **  base para a classificação; 'nomeimg' armazena o nome da imagem a ser classificada; 'nomearq' armazena
    **  o nome do arquivo lógico a ser escrita a classificação; 'classificação' armazena o status da classificação */
    string nomearq = "Resultado classificação.txt";
    FILE *arq = arq_abre (&nomearq[0], 'a', 'e');
    bool classificacao;

    /*  Escrita da introdução */
    fprintf (arq, "Segue a classificação da imagem %s.\n", nomeimg);
    fprintf (arq, "Possui uma área total, classificada como tom de pele, de %d pixels; ", regioes->areabranca);
    fprintf (arq, "onde a maior região tem %d pixels.\n", regioes->areamaior);

    /*  Classificação da imagem */
    if (regioes->areabranca >= 0.8*(f1->classes.medias[2])){
        classificacao = VERDADE;
        fprintf (arq, "Por isso, foi classificada como sendo pertencente a categoria 1, ");
    }else{
        classificacao = !VERDADE;
        fprintf (arq, "Por isso, foi classificada como sendo pertencente a categoria 2, ");
    }

    /*  Sob-classificação como resultado verdadeiro ou falso */
    if (classificacao == f1->status){
        f1->positivos[0]++;
        fprintf (arq, "como um verdadeiro positivo.\n\n");

    }else{
        f1->positivos[1]++;
        fprintf (arq, "como um falso positivo.\n\n");
    }

    fclose(arq);
}
