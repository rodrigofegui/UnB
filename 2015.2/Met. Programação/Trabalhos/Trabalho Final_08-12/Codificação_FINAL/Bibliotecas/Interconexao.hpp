/*! struct auxiliar
    vai conter os parametros a serem retornados pela funcao busca_posicao
    no arquivo Interconexao.cpp
 */
#define Anterior 2
#define Proximo 3
#define verificada 1
#define n_verificada 0
#define falhou -1
#define isolada -2
struct auxiliar{
    City *cidade;
    Adaptador *adapt;
    Gerador *gera;
    Conexao *con;

};
typedef struct auxiliar Aux;
void Monta_rede(Rede*,Conexao *,Posicao*);
Posicao* busca_pos(Conexao*,Posicao*,int*,Posicao**,int*);
void verifica_gerador(Rede *,float*,int);
void verifica_rede(Rede*,int,float*);
int menor(int,int);
//void busca_ger(Conexao*, Gerador*);
void busca_adapt(Rede*, Adaptador*,int);
/*! A reinicia_status vai tornar tudo que era verificada para n_verificada, a fim de poder realizar a simulacao repetidas vezes*/
void reinicia_status(Conexao*);
