/*  Inclusão das bibliotecas requisitadas: */
#include "../Bibliotecas/Grafo.hpp"



/*  Definições das funções a serem manipuladas por este arquivo: */
/*  Função 'dados_limpa', configura todos os dados para 0 */
void dados_limpa (DadosImagem *registro){
    /*  'registro' armazena os dados da paleta a serem inicializados */

    /*  Percorrendo todas os dados da paleta */
    for (int ind = 0; ind < PLANOS_YCBCR; ind++){
        for (int ind2 = 0; ind2 < PLANOS_YCBCR; ind2++){
            /*  Inicialização para 0 de todas as estatísticas */
            registro[ind].media_planos[ind2] = 0;
            registro[ind].desvio_planos[ind2] = 0;
        }
    }
}

/*  Função 'imagem_carrega_paleta', realiza o levantamento dos dados da paleta de cores */
void imagem_carrega_paleta (char *dirpaleta, DadosImagem *dados){
    /*  'dirpaleta' armazena o nome da imagem a ser aberta, incluindo o caminho; 'dados' armazenam os dados
    **  levantados sobre a paleta de cores; 'paleta' armazena a imagem da paleta de cores */
    Mat paleta = imread (dirpaleta, CV_LOAD_IMAGE_COLOR);

    /*  Conseguindo abri a imagem */
    if (!paleta.empty()){
        /*  'espacodecor' armazena os planos separados da paleta; 'ind' armazena um indice a ser manipulado */
        Mat espacodecor[IMG_CAMADAS];
        int ind;

        /*  Conversão de RGB para YCbCr da paleta; e sua separação dos planos */
        cvtColor (paleta, paleta, CV_BGR2YCrCb);
        split (paleta, espacodecor);

        /*  Levantamento das médias e desvios padrões dos planos Cb e Cr */
        for (ind = 0; ind < PLANOS_YCBCR; ind++){
            dados->media_planos[ind] = imagem_media(&espacodecor[ind + 1]);
            dados->desvio_planos[ind] = imagem_desvpad (&espacodecor[ind + 1], dados->media_planos[ind]);
        }

        /*  Liberação da memória */
        paleta.release ();
        for (ind = 0; ind < IMG_CAMADAS; ind++)
            espacodecor[ind].release ();
    }
}

/*  Função 'imagem_calibragem', realiza a calibragem dos dados das classes */
void imagem_calibragem (FILE *arqnavega, FILE *arqregistro, FMeasure *estatisticas, string *nomesdir){
    /*  'arqnavega' e 'arqregistro' armazena os arquivos lógicos que armazenam as saídas sobre a navegação
    **  nos diretórios e o levantamento das informações das imagens; 'estatisticas' armazenam as estatísticas
    **  importantes para o projeto; 'nomesdir' armazena os nomes do diretórios a serem navegados */

    /*  Carregamento da paleta */
    imagem_carrega_paleta (&nomesdir[3][0], &estatisticas->paleta);

    /*  Escrita do aviso num dos arquivos resultado */
    arq_escreve_resize (arqregistro);

    /*  Calibrando o sistema para as classes */
    /*  Configuração do status para calibragem */
    estatisticas->classes.status = VERDADE;

    /*  Percorrendo os diretorios de calibragem */
    for (int ind = 0; ind < PLANOS_YCBCR; ind++){
        /*  Configuração da classe a ser calibrada */
        estatisticas->classes.classe = ind;

        /*  Leitura do diretório da classe */
        fprintf (arqnavega, "Navegando a partir de:\n\t%s\n\n", &nomesdir[ind][0]);
        dir_ler (arqnavega, arqregistro, &nomesdir[ind][0], 0, estatisticas);
    }

    /*  Média das médias */
    estatisticas->classes.medias[2] = (estatisticas->classes.medias[0] + estatisticas->classes.medias[1])/2;
    estatisticas->classes.medias[2] *= CORRECAO_MED_CLASSE;

}

/*  Função 'imagem_classificacao', classifica as imagens alvo */
void imagem_classificacao (FILE *arqnavega, FILE *arqregistro, FMeasure *estatisticas, string *nomesdir, string nomearq){
    /*  'arqnavega' e 'arqregistro' armazena os arquivos lógicos que armazenam as saídas sobre a navegação
    **  nos diretórios e o levantamento das informações das imagens; 'estatisticas' armazenam as estatísticas
    **  importantes para o projeto; 'nomesdir' armazena os nomes do diretórios a serem navegados */

    /*  Configuração do status para classificação */
    estatisticas->classes.status = !VERDADE;
    limpa_tela ();

    /*  Percorrendo os diretórios de classificação */
    fprintf (arqnavega, "Navegando a partir de:\n\t%s\n\n", &nomesdir[2][0]);
    dir_ler (arqnavega, arqregistro, &nomesdir[2][0], 0, estatisticas);

    /*  Cálculo e registro da F-Measure */
    f1_calcula (estatisticas, &nomearq[0]);
}

/*  Função 'imagem_cria_nomesaida', realiza a criação do nome do arquivo de saída da imagem */
char * imagem_cria_nomesaida (string *nomesbase, char *dirimagem, int codigo){
    /*  'nomesbase' armazena os prefixos para o nome da imagem; 'dirimagem' armazena o caminho da imagem;
    **  'codigo' controla o prefixo a ser utilizado; 'nomeimagem' armazena o nome da imagem de saída */
    char *nomeimagem = NULL;

    /*  Alocação da memória */
    do{
        nomeimagem = (char *) calloc ((static_cast<int>(nomesbase[0].size()) + (strlen(dirimagem) - n_ultima_ocorrencia(dirimagem, '/', 1)) +  static_cast<int>(nomesbase[codigo].size()) + 2), sizeof(char));
    }while (nomeimagem == NULL);

    /*  Construção do nome de saída */
    strcat(nomeimagem, &nomesbase[0][0]);
    strcat(nomeimagem, &nomesbase[codigo][0]);
    string_concat_n (nomeimagem, dirimagem, n_ultima_ocorrencia(dirimagem, '/', 1) + 1, strlen(dirimagem));

    return nomeimagem;
}

/*  Função 'imagem_media', realiza a conta de média de uma dada Matriz */
int imagem_media (Mat *imagem){
    /*  'imagem' armazena a matriz a ser calculada a média; 'media' armazena
    **  a média resultante */
    int media = 0;

    /*  Percorrendo toda a matriz */
    for (int linha = 0; linha < imagem->rows; linha++){
        for (int coluna = 0; coluna < imagem->cols; coluna++){
            /*  Somatório das intensidades */
            media += imagem->at<uchar>(linha, coluna);
        }
    }

    /*  Média resultante */
    media /= (imagem->rows * imagem->cols);

    return media;
}

/*  Função 'imagem_desvpad', realiza a conta do desvio-padrão de uma
**  dada Matriz */
int imagem_desvpad (Mat *imagem, int media){
    /*  'imagem' armazena a matriz a ser calculada a média; 'media' armazena
    **  a média resultante; 'desvpad' armazena o desvio-padrão */
    int desvpad = 0;

    /*  Percorrendo toda a matriz */
    for (int linha = 0; linha < imagem->rows; linha++){
        for (int coluna = 0; coluna < imagem->cols; coluna++){
            /*  Somatório das parcelas do desvio */
            desvpad += pow((imagem->at<uchar>(linha, coluna) - media), 2);
        }
    }

    /*  Desvio resultante */
    desvpad /= (imagem->rows * imagem->cols);
    desvpad = sqrt(desvpad);

    return desvpad;
}

/*  Função 'imagem_processa', realiza o processamento sobre a imagem */
void imagem_processa (FILE *arq, Mat imagembase, char * dirimagem, FMeasure *estatistica){
    /*  'arq' armazena o arquivo lógico a ser gravado as informações sobre a imagem; 'imagembase'
    **  armazena a imagem a ser processada; 'dirimagem' armazena o caminho da imagem; 'estatistica'
    **  armazena as estatísticas a serem construídas a partir da imagem; 'segmentada' armazena o
    **  resultado da segmentação; 'regioes' armazena as regiões detectadas na imagem segmentada;
    **  'nomesbase' armazena os nomes básicos para a construção do nome da imagem de saída;
    **  'nomesaida_seg' armazena o nome gerado para a imagem segmentada a ser salva */
    Mat segmentada = Mat::zeros (LIN_ALVO, COL_ALVO, CV_8UC1);
    Grafo *regioes = grafo_cria ();
    string nomesbase[] = {"Segmentações/", "seg_", "canny_", "juncao_"};
    char *nomesaida_seg = imagem_cria_nomesaida (nomesbase, dirimagem, 1);

    /*  Segmentação da imagem base */
    imagem_segmen_ycbcr (imagembase, &segmentada, estatistica->paleta);

    /*  Mapeamento das regiões */
    imagem_mapea_regioes (segmentada, regioes);

    /*  Cálculo das áreas: total e maior */
    grafo_calcula_areas (regioes);

    /*  Construção das estatísticas*/
    /*  Para as imagens de calibragem */
    if (estatistica->classes.status == VERDADE){
        /*  Levantamento das areas brancas totais das classes */
        estatistica->classes.medias[estatistica->classes.classe] += regioes->areabranca;

    /*  Para as imagens de analise */
    }else{
        printf ("\nProcessou a imagem: %s\n", nomesaida_seg);
        imwrite (nomesaida_seg, segmentada);

        /*  Escrita no arquivo das informações da imagem */
        levantamento_escreve (arq, regioes, nomesaida_seg);

        /*  Classificação da imagem, dentre as duas classes */
        imagem_classifica (regioes, estatistica, nomesaida_seg);
    }

    /*  Liberando a memória */
    segmentada.release ();
    grafo_libera (regioes);
    free (nomesaida_seg);
}

/*  Função 'imagem_segmen_ycbcr', realiza a segmentação em relação ao espaço de cor
**  YCbCr */
void imagem_segmen_ycbcr (Mat origem, Mat *segmentada, DadosImagem dados){
    /*  'origem' armazena a imagem original a ser segmentada; 'segmentada' armazena o resultado
    **  da segmentação; 'dados' armazena as informações da paleta, base para a binarização;
    **  'baseycbcr' armazena a imagem original no espaço de cores YCbCr; 'planosanalisar'
    **  armazena os planos do espaço de cores YCbCr da imagem original; 'pixel' armazena
    **  as coordenas dos pixels a serem manipulados; 'linha' e 'coluna' auxiliam a navegação
    **  na imagem */
    Mat baseycbcr, planosanalisar[IMG_CAMADAS];
    Ponto pixel;
    int linha, coluna;

    /*  Conversão do espaço de cores RGB para o YCbCr */
    cvtColor (origem, baseycbcr, CV_BGR2YCrCb);

    /*  Separação dos planos do espaço de cores YCbCr */
    split (baseycbcr, planosanalisar);

    /*  Redimensionamento dos planos */
    for (linha = 0; linha < IMG_CAMADAS; linha++)
        resize (planosanalisar[linha], planosanalisar[linha], segmentada->size(), VERDADE, VERDADE, INTER_CUBIC);

    /*  Percorrendo toda a imagem */
    for (linha = 0; linha < segmentada->rows; linha++){
        for (coluna = 0; coluna < segmentada->cols; coluna++){
            /*  Configuração do pixel */
            pixel.lin = linha;
            pixel.col = coluna;

            /*  Validação do pixel, quanto tom de pele */
            if (imagem_valida_bin(planosanalisar, dados, pixel) == VERDADE)
                segmentada->at<uchar>(linha, coluna) = BRANCO;
        }
    }

    /*  Liberação da memória */
    baseycbcr.release ();
    for (linha = 0; linha < IMG_CAMADAS; linha++)
        planosanalisar[linha].release ();
}

/*  Função 'imagem_valida_bin', realiza a verificação da região de aceitação para a segmentação e
**  posteriori binarização */
bool imagem_valida_bin (Mat *planos, DadosImagem dados, Ponto coordenada){
    /*  'planos' armazena os planos a serem analisados; 'dados' armazena as informações da paleta a serem comparados; 'coordenada'
    **  armazena a localização a ser avaliada */

    /*  Estando dentro de um intervalo (MEDIA +/- DESVIO) para os dois planos de cores é classificada como posição válida */
    if((planos[PLANO_Cb].at<uchar>(coordenada.lin, coordenada.col) >= (dados.media_planos[PLANO_Cb - 1]*CORRECAO_MED_CB - dados.desvio_planos[PLANO_Cb - 1]*CORRECAO_DES_CB)
            && planos[PLANO_Cb].at<uchar>(coordenada.lin, coordenada.col) <= (dados.media_planos[PLANO_Cb - 1]*CORRECAO_MED_CB + dados.desvio_planos[PLANO_Cb - 1]*CORRECAO_DES_CB))
       && (planos[PLANO_Cr].at<uchar>(coordenada.lin, coordenada.col) >= (dados.media_planos[PLANO_Cr - 1]*CORRECAO_MED_CR - dados.desvio_planos[PLANO_Cr - 1]*CORRECAO_DES_CR)
            && planos[PLANO_Cr].at<uchar>(coordenada.lin, coordenada.col) <= (dados.media_planos[PLANO_Cr - 1]*CORRECAO_MED_CR + dados.desvio_planos[PLANO_Cr - 1]*CORRECAO_DES_CR)))
            return VERDADE;

    /*  Caso contrário */
    return !VERDADE;
}

/*  Função 'dados_exibe', exibe na tela os dados da imagem */
void dados_exibe (DadosImagem dados){
    printf ("Media do Cb = %d\n", dados.media_planos[0]);
    printf ("Desvio do Cb = %d\n\n", dados.desvio_planos[0]);
    printf ("Media do Cr = %d\n", dados.media_planos[1]);
    printf ("Desvio do Cr = %d\n\n", dados.desvio_planos[1]);
}

/*  Função 'f1_inicializa', inicializa os campos da FMeasure */
void f1_inicializa (FMeasure *f1){
    /*  'f1' armazena as estatísticas do projeto; 'ind' armazena o indice a ser manipulado */
    int ind;

    /*  Inicialização dos vetores de controle de tamanho PLANOS_YCBCR */
    for (ind = 0; ind < PLANOS_YCBCR; ind++){
        f1->paleta.media_planos[ind] = 0;
        f1->paleta.desvio_planos[ind] = 0;
        f1->positivos[ind] = 0;
    }

    /*  Inicialização das variaveis de controle */
    f1->status = !VERDADE;
    f1->classes.status = !VERDADE;
    f1->classes.classe = !VERDADE;
    f1->metrica = 0.0;

    /*  Inicialização dos vetores de controle de tamanho IMG_CAMADAS */
    for (ind = 0; ind < IMG_CAMADAS; ind++)
        f1->classes.medias[ind] = 0;
}

/*  Função 'f1_calcula', calcula a F-measure para as imagens classificadas */
void f1_calcula (FMeasure *estatisticas, char *nomearq){
    /*  'estatisticas' armazena as estatísticas do projeto; 'nomearq' armazena o nome do arquivo
    **  a ser gravado as informações; 'arqregistro' armazena o arquivo lógico a ser gravado o
    **  resultado */
    FILE *arqregistro = arq_abre (nomearq, 'w', 'e');

    /*  Cálculo da F-Measure */
    estatisticas->metrica = (float) (2*estatisticas->positivos[0]) / (2*estatisticas->positivos[0] + estatisticas->positivos[1]);

    /*  Escrita do resultado no arquivo */
    fprintf (arqregistro, "O F-Measure calculado eh -> %f\n", estatisticas->metrica);
    fprintf (arqregistro, "Com %d verdadeiros positivos e %d falsos positivos", estatisticas->positivos[0], estatisticas->positivos[1]);

    /*  Liberação da memória */
    fclose (arqregistro);
    arqregistro = NULL;
}
