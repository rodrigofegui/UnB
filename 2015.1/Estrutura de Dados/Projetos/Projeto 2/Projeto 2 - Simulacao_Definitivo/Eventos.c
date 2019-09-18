/*  Descritivo das funções relacionadas aos eventos e as passagens */

/*  Biblioteca dinamica requisitada */
#include "Eventos.h"

/*  Lista das funcoes de manipulacao sobre os eventos e as passagens */

/*  1 - Funcao inicia_simu, controla a inicializacao das variaveis do Aeroporto a cada hora
**  de simulacao */
void inicia_simu (Aeroporto *aero){
    /*  'aero' armazena o Aeroporto; 'numaprox' e 'numdeco' armazenam os numeros
    **  de aproximacoes e decolagens para a proxima 1 hora de simulacao; 'quant'
    **  armazena quantidades a serem variadas na funcao; 'temp' armazena a identificacao
    **  do voo a ser inserido em alguma fila */
    int numaprox, numdeco, quant;
    char *temp = (char *) malloc (TAMp * sizeof(char));

    /*  Teste de alocacao */
    if (temp == NULL){
        printf ("\nERRO ALOCACAO DE STRING\n");
        exit (-6);
    }

    /*  Determinacao do numero de voos para aproximacao e decolagem para a proxima
    **  hora de simulacao */
    numaprox = gera_aleatorio (0, 28);
    numdeco = gera_aleatorio (0, 28);

    /*  Inicializacao do Aeroporto para trabalho na proxima hora */
    inicia_aero (aero, numaprox+numdeco);

    /*  Montagem e Ordenacao da fila Aproximacao */
    for(quant = 0; quant < numaprox; quant++){
        zera_string (temp, TAMp);
        temp = monta_nome ();
        add_aprox (aero->filaap, temp);
    }
    ordena_aprox (aero->filaap);

    /*  Montagem da fila Decolagem */
    for(quant = 0; quant < numdeco; quant++){
        zera_string (temp, TAMp);
        temp = monta_nome ();
        add_deco (aero->filade, temp);
    }
}

/*  2 - Funcao aproxima_aero, realiza o consumo do combustivel dos voos da fila Aproximacao */
void aproxima_aero (Aeroporto *aero){
    /*  'aero' armazena o Aeroporto; 'voo' armazena o elemento da fila Aproximacao a ser manipulado;
    **  'ind' armazena o indice para o elemento 'voo' */
    Aviao *voo;
    int ind;

    /*  Havendo fila Aproximacao */
    if (aero->filaap->inicio != NULL){
        voo = aero->filaap->inicio;
        /*  Percorrer toda a fila Aproximacao */
        for (ind = aero->filaap->quant; ind > 0; ind--){
            voo->comb--;
            voo = voo->proximo;
        }
    }
}

/*  3 - Funcao aterrissa_aero, realiza o procedimento de pouso para o primeiro voo da fila
**  Aproximacao */
void aterrissa_aero (Aeroporto *aero, int ind){
    /*  'aero' armazena o Aeroporto; 'ind' armazena o indice para manuseio de uma pista especifica;
    **  'pista' armazena a pista a ser manipulada; 'voo' armazena o voo a ser manipulado */
    Pista *pista = (aero->pista + ind);
    Aviao *voo = retira_aprox (aero->filaap);

    /*  Configuracao do voo para pouso */
    voo->status = 'P';
    voo->comb--;

    /*  Configuracao da pista manipulada */
    pista->status = 'O';
    pista->voo = voo;
}

/*  4 - Funcao decola_aero, realiza o procedimento de decolagem para o primeiro voo da fila
**  Decolagem */
void decola_aero (Aeroporto *aero, int ind){
    /*  'aero' armazena o Aeroporto; 'ind' armazena o indice para manuseio de uma pista especifica;
    **  'pista' armazena a pista a ser manipulada; 'voo' armazena o voo a ser manipulado */
    Pista *pista = (aero->pista + ind);
    Aviao *voo = retira_deco (aero->filade);

    /*  Configuracao da pista manipulada, caso haja voo */
    if (voo != NULL){
        pista->status = 79;
        pista->voo = voo;
    }
}

/*  5 - Funcao aborta_voo, realiza o alerta de emergencia conflitante para o Aeroporto,
**  redirecionando o voo para o aeroporto mais proximo */
void aborta_voo (Aeroporto *aero){
    /*  'aero' armazena o Aeroporto; 'voo' armazena o voo a ser manipulado; 'ind' o indice da
    **  identificacao do voo; 'arq' armazena o ponteiro do arquivo a ser escrito o alerta */
    Aviao *voo = retira_aprox (aero->filaap);
    int ind;
    FILE *arq = fopen ("Simulacao Aeroporto_Lucas e Rodrigo.txt", "a");

    /*  Teste de alocacao */
    if (arq == NULL){
        printf ("\nERRO AO ABRIR ARQUIVO\n");
        exit (-8);
    }

    /*  Exibicao na tela da manobra de redirecionamento de voo */
    printf ("\nALERTA!!!!\n");
    printf ("Nao ha pistas disponiveis, e o voo ");
    for (ind = 0; ind < TAMp; ind++) printf ("%c", voo->nome[ind]);
    printf (" esta em emergencia!\n");
    printf ("Logo foi redirecionado para outro aeroporto!\n\n");

    /* Escrita no arquivo da manobra de redirecionamento de voo */
    fprintf (arq, "\nALERTA!!!!\n");
    fprintf (arq, "Nao ha pistas disponiveis, e o voo ");
    for (ind = 0; ind < TAMp; ind++) fprintf (arq, "%c", voo->nome[ind]);
    fprintf (arq, " esta em emergencia!\n");
    fprintf (arq, "Logo foi redirecionado para outro aeroporto!\n\n");

    /*  Liberacao da responsabilidade do Aeroporto sobre o dado voo */
    libera_aviao (voo);
    fclose (arq);
}

/*  6 - Funcao verifica_pista, verifica o status da pista */
int verifica_pista (Pista *pista){
    /*  'pista' armazena a Pista a ser verificada */
    /*  Estando livre */
    if (pista->status == 76) return 0;

    /*  Estando ocupada */
    else return 1;
}

/*  7 - Funcao hora_atual, configura o tempo de simulacao para o horario real */
struct tm * hora_atual (){
    /* 'tempo_atual' armazena a hora local do computador;
    ** 'info_tempo' e' uma struct do tipo tm, que possui informacoes sobre o tempo local */
    time_t tempo_atual;
    struct tm *info_tempo;

    /* obtendo a hora atual e guardando-a em uma struct tm
    ** definida na biblioteca <time.h> */
    time(&tempo_atual);
    info_tempo = localtime(&tempo_atual);

    return info_tempo;
}

/*  8 - Funcao incre_tempo, realiza o incremento da hora atual em relacao aos ciclos, de 5 min */
void incre_tempo (struct tm *tempo){
    /*  'tempo' armazena a hora corrente da simulacao */
    tempo->tm_min += TEMPO;

    /*  Verificacao dos minutos equivalentes a hora posterior */
    if(tempo->tm_min >= 60){
        tempo->tm_min -= 60;
        tempo->tm_hour++;
    }
}

/*  9 - Funcao imprime_hora, exibe na tela a hora na simulacao */
void imprime_hora (struct tm *tempo){
    /*  'tempo' armazena a hora corrente da simulacao */
    printf("Data: %.2d/%.2d/%.2d\n", tempo->tm_mday,
           tempo->tm_mon+1, tempo->tm_year+1900);
    printf("Hora na simulacao: %.2d:%.2d:%.2d\n", tempo->tm_hour,
           tempo->tm_min, tempo->tm_sec);
}

/*  10 - Funcao imprime_hora_arq, escreve num arquivo a hora na simulacao */
void imprime_hora_arq (FILE *arq, struct tm *tempo){
    /*  'arq' armazena o arquivo a escrito; 'tempo' armazena a hora corrente da simulacao */
    fprintf(arq, "Data: %.2d/%.2d/%.2d\n", tempo->tm_mday,
           tempo->tm_mon+1, tempo->tm_year+1900);
    fprintf(arq, "Hora na simulacao: %.2d:%.2d:%.2d\n", tempo->tm_hour,
           tempo->tm_min, tempo->tm_sec);
}

/*  11 - Funcao gera_aleatorio, gera numero inteiro aleatorio dado um intervalo */
int gera_aleatorio (int minimo, int maximo){
    /*  'minimo' e 'maximo' armazenam o valor minimo e o valor maximo, respectivamente,
    **  para o intervalo de geracao; 'gerado' armazena o numero gerado no corrente intervalo */
    int gerado;

    /*  Geracao do numero aleatorio */
    gerado = minimo + (rand()%(maximo-minimo+1));

    return gerado;
}

/*  12 - Funcao zera_string, inicializa a string com '\0' em todos os elementos*/
void zera_string (char *palavra, int tamanho){
    /*  'palavra' armazena a string a ser inicializada; 'tamanho' armazena
    **  o tamanho dentro da string a ser inicializada, podendo ser parcial ou integral;
    **  'indice' armazena o indice da string*/
    int indice;

    /*  Inicializar a string como NULL*/
	for(indice = 0 ; indice < tamanho; indice++)
		*(palavra+indice) = '\0';
}

/*  13 - Funcao ler_resposta, realiza a validacao da resposta para progresso da simulacao */
char ler_resposta (){
    /*  'resposta' armazena a resposta do usuario para a pergunta */
    char resposta;

    /*  Enquanto for invalida */
    do{
        scanf ("%c", &resposta);

        /*  Sendo uma resposta invalida */
        if ((resposta != 's') && (resposta != 'S') && (resposta != 'n') && (resposta != 'N'))
            printf ("Resposta invalida, digite novamente!\n");

    }while ((resposta != 's') && (resposta != 'S') && (resposta != 'n') && (resposta != 'N'));

    return resposta;
}
