/*  Inclusão das bibliotecas requisitadas para o projeto: */
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <math.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

/*  Definições de constantes necessárias a varios arquivos:
**  utilizadas */
/*  'VERDADE' armazena o estado de verdade para qualquer função */
#define VERDADE 1
/*  'IGUAL' armazena o estado específico de comparação verdadeira */
#define IGUAL 0
/*  'DIR_PASTA' armazena a codificação para identificação para diretórios */
#define DIR_PASTA 4
/*  'ARQ_EXTENSAO' armazena a quantidade de caracteres para determinação da
**  extensão de um arquivo */
#define ARQ_EXTENSAO 3
/*  'DIR_DIVISAO' armazena o caracter divisor de  diretorio */
#define DIR_DIVISAO "/"
/*  'QNT_FORMATOS' armazena a quantidade de formatos para imagens possíveis
**  nos diretorios alvos */
#define QNT_FORMATOS 2
/*  'PLANOS_YCBCR' armazena a quantidade de planos importantes a serem analisados
**  no espaço de cores YCbCr */
#define PLANOS_YCBCR 2
/*  'IMG_CAMADAS' armazena a quantidade de planos existentes no espaço de cores RGB */
#define IMG_CAMADAS 3
/*  'PLANO_Cb' e 'PLANO_Cr' armazenam os indices para o plano Cb e o plano Cr,
**  respectivamente, de uma imagem */
#define PLANO_Cb 1
#define PLANO_Cr 2
/* 'BRANCO' armazena o valor para que o pixel seja branco */
#define BRANCO 255
/* 'PRETO' armazena o valor para que o pixel seja preto */
#define PRETO IGUAL
/*  'LIN_ALVO' e 'COL_ALVO' armazenam as dimensoes para o resize da imagem a ser analisada */
#define LIN_ALVO 400
#define COL_ALVO 400
/*  'CORRECAO_DES_CB' e 'CORRECAO_DES_CR' armazenam os fatores de correção para os desvios padrões
**  nos respectivos planos de imagem; enquanto que 'CORRECAO_MED_CB' e 'CORRECAO_MED_CR' armazenam
**  os fatores para as médias */
#define CORRECAO_DES_CB 1.16
#define CORRECAO_DES_CR 1.16
#define CORRECAO_MED_CB 1.02
#define CORRECAO_MED_CR 1
/*  'CORRECAO_MED_CLASSE' armazena o fator de correção para o limiar das classes */
#define CORRECAO_MED_CLASSE 0.8
/*  'Diretorios' define a estrutura utilizada para varredura dos diretorios */
typedef struct dirent Diretorios;
/*  'std' e 'cv' definem as classes utilizadas */
using namespace cv;
using namespace std;



/*  Protótipos das funções da biblioteca */
/*  Função 'arq_abre', abre um arquivo lógico */
FILE * arq_abre (char *, char, char);

/*  Função 'inicio_geral', apresentação breve do projeto */
bool inicio_geral ();

/*  Função 'ler_simounao', verifica resposta positiva ou não */
bool ler_simounao ();

/*  Função 'limpa_tela', limpa o terminal de execução */
void limpa_tela();

/*  Descobrir a n-ultima ocorrencia de um caracter numa string */
int n_ultima_ocorrencia (char *, char, int);

/*  Função 'pausa', realiza uma pausa por ENTER no processamento */
void pausa ();

/*  Função 'string_compara_n', compra duas strings */
int string_compara_n (char *, std::string, int, int, int);

/*  Função 'string_concat_n', concatena strings, a partir de um ponto ate outro */
void string_concat_n (char *, char *, int, int);

/*  Função 'string_zera', anula os caracteres de uma string, de um ponto a outro */
void string_zera (char *, int, int);

/*  Função 'temporizador', realiza uma pausa por TEMPO no processamento */
void temporizador (float);

