/*  Inclusão das bibliotecas requisitadas: */
#include "Comum.hpp"



/*  Definição e construção de estruturas uteis: */
/*  'Ponto' define a estrutura utilizada para a armazenagem das coordenadas
**  de um pixel */
typedef struct point Ponto;
/*  'DadosImagem' define a estrutura que armazena das informações da paleta
**  de tons de pele */
typedef struct dados DadosImagem;
/*  'Calibragem' define a estrutura que armazena os dados para a calibragem;
**  e controle na operação */
typedef struct calibragem Calibragem;
/*  'FMeasure' define a estrutura que armazena as estatísticas para o cálculo
**  da F-Measure do projeto */
typedef struct f1 FMeasure;

/*  'lin' e 'col' armazenam as coordenas do pixel */
struct point{
    int lin;
    int col;
};

/*  'media_planos' armazena a média aritmética dos planos Cb e Cr; 'desvio_planos'
**  armazena os desvios padrões dos planos Cb e Cr; ambos em relação a paleta de referência */
struct dados{
    int media_planos[PLANOS_YCBCR];
    int desvio_planos[PLANOS_YCBCR];
};

/*  'medias' armazena as médias aritméticas para as duas classes de classificação; 'status'
**  controla a ativação da calibragem das classes; 'classe' controla a classe a ser calibrada */
struct calibragem{
    int medias[IMG_CAMADAS];
    bool status;
    bool classe;
};

/*  'paleta' armazena as informações referente à paleta de cores; 'classes' armazena os dados da calibração
**  'positivos' armazena os resultados verdadeiros ou falsos; 'metrica' armazena a F-Measure em si; 'status'
**  controla a classe que está sendo lida no diretório */
struct f1{
    DadosImagem paleta;
    Calibragem classes;
    int positivos[PLANOS_YCBCR];
    float metrica;
    bool status;
};



/*  Protótipos das funções da biblioteca */
/*  Função 'dados_limpa', configura todos os dados para 0 */
void dados_limpa (DadosImagem *);

/*  Função 'imagem_carrega_paleta', realiza o levantamento dos dados da paleta de cores */
void imagem_carrega_paleta (char *, DadosImagem *);

/*  Função 'imagem_calibragem', realiza a calibragem dos dados das classes */
void imagem_calibragem (FILE *, FILE *, FMeasure *, string *);

/*  Função 'imagem_classificacao', classifica as imagens alvo */
void imagem_classificacao (FILE *, FILE *, FMeasure *, string *, string);

/*  Função 'imagem_cria_nomesaida', realiza a criação do nome do arquivo de saída da imagem */
char * imagem_cria_nomesaida (string *, char *, int);

/*  Função 'imagem_media', realiza a conta da media numa matriz */
int imagem_media (Mat *);

/*  Função 'imagem_desviopadrao', realiza a conta do desvio padrao de uma matriz */
int imagem_desvpad (Mat *, int);

/*  Função 'imagem_processa', realiza o processamento sobre a imagem */
void imagem_processa (FILE *, Mat, char *, FMeasure *);

/*  Função 'imagem_segmen_ycbcr', realiza a segmentação em relação ao espaço de cor
**  YCbCr */
void imagem_segmen_ycbcr (Mat, Mat *, DadosImagem);

/*  Função 'imagem_valida_bin', verifica se o pixel esta dentro do intervalo de aceitação */
bool imagem_valida_bin (Mat *, DadosImagem, Ponto);

/*  Função 'dados_exibe', exibe na tela os dados da imagem */
void dados_exibe (DadosImagem);

/*  Função 'f1_inicializa', inicializa os campos da FMeasure */
void f1_inicializa (FMeasure *);

/*  Função 'f1_calcula', calcula a F-measure para as imagens classificadas */
void f1_calcula (FMeasure *, char *);
