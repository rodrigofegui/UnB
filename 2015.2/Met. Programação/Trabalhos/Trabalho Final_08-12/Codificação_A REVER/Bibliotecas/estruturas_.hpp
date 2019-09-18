#include<stdio.h>
#include<stdlib.h>
/*PLANO B

struct gerador{//G nome_gerador pos_x pos_y recurso_produzido custo_gerador
    char *nome;
    int recurso,
};
struct cidade{ //C nome_cidade pos_x pos_y recurso_necessario

};
struct intercon{// I nome_interconexao pos_inic_x pos_inic_y pos_final_x pos_final_y
//capacidade_max chance_falha tempo_conserto custo_do_conserto

};

struct adapt{//A nome_adaptador pos_x pos_y

};
*/

struct intercon{//para interconexoes
    char tipo;// indica que e interconexao
    char *nome;// vai guardar o nome da conexao
    int linha_inicio,coluna_inicio;// linha = pos_x e coluna = pos_y
    int linha_fim, coluna_fim;
    int capacidade;
    float falha;
    int ordem;
    int tempo_cons, custo_cons; // custo e tempo de conserto
    struct intercon *linha, *coluna;//vai ser uma matriz de interconexoes. Cada linha, representa interconexoes
    // ligadas. A juncao de todas as ligacoes reulta na matriz
};


struct elementos{// tem informacoes de apadtadores, cidades e geradores por todos terem parametros semelhantes
    char tipo_el;//indica se eh cidade, gerador ou adaptador
    char *nome_el;// guarda o nome forecido
    int lin, col;// lin = pos_x e col = pos_y
    int recurso;// para cidade serah o consumido. Para gerdaor serah o produzido
    int custo;// aplicavel apenas para reparo de geradores
    struct elementos *proximo,*ger;// ger conecta a matriz com todos os geradores. Proximo segue a linha de conexao entre um gerador e a casa
    //int lin_inter,col_inter;//indica onde a interconexao termina
    struct intercon **conex_adapt,*conex;/*vai guardar a trilha de interconexoes. Conex_adapt representa todas as interconexoes
    //que saem de um adaptador*/
};
struct rede{// vai permitir retornar as duas estrututas para a main
    struct elementos *comeco;
    struct intercon *inic;
};
struct info{//para mandar as informacoes para as funcoes de insercao
    char tipo_info;// indica que e interconexao
    char *nome_info;// vai guardar o nome da conexao
    int linha_inicio_info,coluna_inicio_info;// linha = pos_x e coluna = pos_y
    int linha_fim_info, coluna_fim_info;
    int capacidade_info;
    int custo_info;
    float falha_info;
    int tempo_info;// tempo de conserto da interconexao
};
typedef struct intercon Conexao;
typedef struct elementos Elem;
typedef struct rede Rede;
Elem* insere_elemento(Elem*,FILE*,char*,int,int,int,int);// char* serah usado apenas para testes iniciais
Elem* cria_elemento(void);

