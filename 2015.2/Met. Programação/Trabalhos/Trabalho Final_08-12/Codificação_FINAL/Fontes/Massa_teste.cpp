#include "../Bibliotecas/Massa_teste.hpp"
#include "../Bibliotecas/Interconexao.hpp"
#include <string.h>
/*!Casos de teste
   Verificar se o arquivo corresponde as especificacoes consideradas pelo grupo

   Verificar se a funcao Adaptador* adaptador_insere (Adaptador*, Info) retorna todos os parametros
necessarios requisitados pelo roteiro paras um adaptador

   Verificar se a funcao Gerador* gerador_insere (Gerador*, Info) retorna todos os parametros
necessarios requisitados pelo roteiro paras um gerador

   Verificar se a funcao city_insere (City*, Info); retorna todos os parametros
necessarios requisitados pelo roteiro paras uma cidade

   Verificar se a funcao Conexao* conexao_insere(Conexao*, Info); retorna todos os parametros
necessarios requisitados pelo roteiro paras uma interconexao, bem como os parametros de controle dela (status)

   Verificar se a funcao Posicoes* pos_insere(Posicoes*, Info); retorna todos os parametros
necessarios requisitados pela estrutura do tipo Posicoes

   Verificar se a funcao reinicia_status(Conexao* inicio); possui todos o elementos da lista de interconexoes com suas variaveis status possuindo os seguintes valores possiveis: n_verificada, isolada, falhou. As variaveis foram definidas no arquivo Interconexoes.hpp
   Verificar se a lista de interconexoes esta ordenada pela ordem de leitura do arquivo texto
   Verificar se todas as alocacoes dinamicas deram certo


*/

/*! Funcao vai testar se os status da lista de interconexoes foram reiniciados corretamente*/
int Testa_status(Conexao *inicio){
	FILE *arq_log = fopen("../Textos/log.txt","a+");

	if(arq_log==NULL){
		printf("Sistema nao conseguiu abrir arquivo de registros de erros./n");
		printf("Cuidado pois algo pode estar errado ou computador sem memoria disponivel");
	}
	while(inicio!=NULL){
		if( inicio->status!=n_verificada || inicio->status!=falhou || inicio->status!=isolada){
			if(arq_log!=NULL)
				fprintf(arq_log,"Interconexao de nome %s tem status diferente do padrao. Por favor, verifique o funcionamento das funcoes conexao_insere  e reinicia_status/n",inicio->nome);
			return Falha;
		}
	}
	return sucesso;
}
/*! Chamar esta funcao logo apos fazer qualquer alocacao*/
int Testa_alocacao (void *ptr){
	FILE *arq_log = fopen("../Textos/log.txt","a+");

	if(arq_log==NULL){
		printf("Sistema nao conseguiu abrir arquivo de registros de erros./n");
		printf("Cuidado pois algo pode estar errado ou computador sem memoria disponivel");
	}
	if(ptr==NULL){
		if(arq_log!=NULL)
			fprintf(arq_log,"Alocacao de memoria falhou/n");
		return Falha;
	}
	return sucesso;
}


/*!Verificar se a funcao Adaptador* adaptador_insere (Adaptador*, Info) retorna todos os parametros
necessarios requisitados pelo roteiro paras um adaptador*/

int adaptador_verifica (Adaptador* lista, Info info){
    if(lista != NULL){
        if(lista->lin_i==info.lin_i && lista->col_i==info.col_i && strcmp(lista->nome,info.nome_info)==0)
            return sucesso;
        else
            return Falha;
    }else{
        return Falha;
    }
}

/*!Verificar se a funcao Gerador* gerador_insere (Gerador*, Info) retorna todos os parametros
necessarios requisitados pelo roteiro paras um gerador*/
int gerador_verifica (Gerador* lista, Info info){
    if (lista != NULL){
        if(lista->lin_i==info.lin_i && lista->col_i==info.col_i && lista->custo==info.custo && lista->rec==info.cpcd && strcmp(lista->nome,info.nome_info)==0)
            return sucesso;
        else
            return Falha;
    }
    else
        return Falha;
}

/*! Verificar se a funcao city_insere (City*, Info); retorna todos os parametros
necessarios requisitados pelo roteiro paras uma cidade */

int cidade_verifica (City* lista, Info info){
    if (lista != NULL){
        if(lista->lin_i==info.lin_i && lista->col_i==info.col_i && lista->rec==info.cpcd && strcmp(lista->nome,info.nome_info)==0)
            return sucesso;
        else
            return Falha;
    }else{
        return Falha;
    }
}

/*! Verificar se a funcao Conexao* conexao_insere(Conexao*, Info); retorna todos os parametros
necessarios requisitados pelo roteiro paras uma interconexao, bem como os parametros de controle dela (status)*/

int conexao_verifica (Conexao* lista, Info info){
    if(lista!=NULL){
        if(lista->status == 0 && lista->lin_i == info.lin_i && lista->col_i == info.col_i && lista->lin_f == info.lin_f && lista->col_f == info.col_f && lista->cpc == info.cpcd && lista->custo == info.custo && lista->prob_falha == info.falha && lista->temp==info.tempo && strcmp(lista->nome,info.nome_info) == 0)
            return sucesso;
        else
            return Falha;
    }else{
        return Falha;
    }
}
