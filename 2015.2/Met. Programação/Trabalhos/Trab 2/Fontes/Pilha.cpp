/*	Inclusão das Bibliotecas Requesitadas: */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../Bibliotecas/Pilha.hpp"


/*	Definição das classes a serem utilizadas: */

/* Especialização das funções para uma pilha como vetor */
namespace vetor{
    /*	Função 'criar' realiza a criação da pilha como vetor */
    bool Pilha::criar (int tam){
        /*	'tam' armazenam o tamanho da pilha como vetor */
        assert (tam >= 1);

        /*	Alocação do cabeçalho da pilha */
		short int contador = 0;
        do{
            vetor::Pilha::elementos = (Elemento *) calloc (tam, sizeof(Elemento));
			contador++;
        }while (vetor::Pilha::elementos == NULL && contador < LIMITE);

		/*	Havendo atingido o limite de tentativas e não tendo conseguido
		**	alocar a memória */
		assert (contador < LIMITE && vetor::Pilha::elementos != NULL);

        /*	Inicialização das variáveis de controle */
        vetor::Pilha::top = 0;
        vetor::Pilha::tamanho = tam;

        return VERDADE;
    }

    /*	Função 'liberar' realiza a desalocação da memória */
    Elemento * Pilha::liberar (){
        /*  Enquanto houver pilhar a liberar */
        while (!vazia ()){
            /*	'aux' auxilia o manuseio da pilha, recebendo o topo da pilha */
            remover ();
        }

        /*	Liberação da pilha em si */
        free (vetor::Pilha::elementos);

        return vetor::Pilha::elementos;
    }

    /*	Função 'inserir' realiza a inserção de um novo elemento na pilha */
    int Pilha::inserir (int info){
        /*	'info' armazena a informação do novo elemento a ser inserida na pilha */

        /*	Verificando se é possível inserir */
        if (cheia() || vetor::Pilha::top > LIXO_INICIAL){
            //printf ("A pilha está cheia, não foi possível adicionar o %d!\n", info->dados);
            return MENTIRA;
        }

        /*	Configuração da pilha */
        vetor::Pilha::elementos[vetor::Pilha::top].dados = info;
        vetor::Pilha::top++;

        return info;
    }

    /*	Função 'remover' realiza a remoção do elemento do topo da pilha */
    int Pilha::remover (){
        /*	Não havendo pilha, não tem o que retirar */
        if (vazia () || vetor::Pilha::top > LIXO_INICIAL){
            //printf ("A pilha está vazia!\n");
            return MENTIRA;
        }

        /*	'retirado' recebe o topo da pilha */
        int retirado = vetor::Pilha::elementos[vetor::Pilha::top - 1].dados;

        /*	Configuração da pilha */
        vetor::Pilha::top--;

        return retirado;
    }

    /*	Função 'topo' retorna o elemento que está no topo da pilha */
    int Pilha::topo(){
        /*	Não havendo pilha, não tem o que retirar */
        if (vazia () || vetor::Pilha::elementos == MENTIRA){
            //printf ("A pilha está vazia!\n");
            return MENTIRA;
        }

        return vetor::Pilha::elementos[vetor::Pilha::top - 1].dados;
    }

    /*	Função 'cheia' verifica se a pilha corrente está cheia ou não */
    bool Pilha::cheia (){
		/*	Não havendo vetor a ser analisado */
		if (vetor::Pilha::elementos == MENTIRA){
            return MENTIRA;
        }

        /*	Caso o topo esteja no máximo*/
        if (vetor::Pilha::top == vetor::Pilha::tamanho){
            return VERDADE;
        }

        /*	Caso contrário */
        return MENTIRA;
    }

    /*	Função 'vazia' verifica se a pilha corrente está vazia ou não */
    bool Pilha::vazia (){
		/*	Não havendo vetor a ser analisado */
		if (vetor::Pilha::elementos == MENTIRA){
            return MENTIRA;
        }

		/*	Não havendo topo; não existe pilha */
        if (vetor::Pilha::top == MENTIRA){
            return VERDADE;
        }

        /*	Caso contrário */
        return MENTIRA;
    }

    /*	Função 'exibir' realiza a exibição da pilha na tela */
    void Pilha::exibir (){
		/*	Não havendo vetor a ser analisado */
		if (vetor::Pilha::elementos == MENTIRA){
            return;
        }

        printf ("\nExibição da Pilha até o momento...\n");
        printf ("Existem %d elemento(s) registrado(s)", vetor::Pilha::top);
        if (vetor::Pilha::top > MENTIRA){
            printf(", sendo ele(s):\n");
            /*	Enquanto houver pilha a imprimir */
            for (int posicao = 0; posicao < vetor::Pilha::top; posicao++){
                /*	Exibição do elemento corrente */
                elemento_exibe (&(vetor::Pilha::elementos[posicao]));

                /*  Exibição do caracter de continuação ou fim da linha */
                if (posicao < vetor::Pilha::top - 1)
                    printf (", ");
                else
                    printf (".\n\n");
            }

        }else
            printf(".\n\n");
    }

    /*	Função 'elemento_exibe' realiza a exibição de um elemento na tela */
    void Pilha::elemento_exibe (Elemento *elemento){
		if (elemento != NULL)
	        printf ("%d", elemento->dados);
    }
}

/* Especialização das funções para uma pilha como lista encadeada */
namespace listaenc{
    /*	Função 'criar' realiza a criação da pilha como lista encadaeada */
    bool Pilha::criar (){
        /*	Inicialização das variáveis de controle */
        listaenc::Pilha::quant = MENTIRA;
        listaenc::Pilha::top = NULL;

        if (listaenc::Pilha::top == NULL)
            return VERDADE;

        return MENTIRA;
    }

    /*	Função 'elemento_cria' realiza a criação de um novo elemento a ser
    **	inserido na pilha */
    Elemento * Pilha::elemento_cria (int info){
        /*	'novo' armazena o novo elemento a ser criado */
        Elemento *novo = NULL;

        /*	Alocação do novo elemento */
		short int contador = 0;
        do{
            novo = (Elemento *) malloc (sizeof(Elemento));
			contador++;
        }while (novo == NULL && contador < LIMITE);

		/*	Havendo atingido o limite de tentativas e não tendo conseguido
		**	alocar a memória */
		if (contador >= LIMITE && novo == NULL)
			return NULL;

        /*	Iniciação das variáveis de controle */
        novo->dados = info;
        novo->proximo = NULL;

        return novo;
    }

    /*	Função 'liberar' realiza a desalocação da memória */
    Elemento * Pilha::liberar (){
        /*  Enquanto houver pilhar a liberar */
        while (!vazia ()){
            /*	'aux' auxilia o manuseio da pilha, recebendo o topo da pilha */
            remover ();
        }

        if (listaenc::Pilha::top != NULL)
            free(listaenc::Pilha::top);

        return listaenc::Pilha::top;
    }

    /*	Função 'inserir' realiza a inserção de um novo elemento na pilha */
    int Pilha::inserir (int info){
        /*	'info' armazena a informação do novo elemento a ser inserida na pilha; 'novo'
        **  armazena o novo elemento a ser inserido na pilha */
        Elemento *novo = elemento_cria (info);

		if (novo == NULL)
			return MENTIRA;

        /*	Já havendo uma pilha formanda */

        /*	Configuração da pilha */
		novo->proximo = listaenc::Pilha::top;
        listaenc::Pilha::top = novo;
        listaenc::Pilha::quant++;

        return listaenc::Pilha::top->dados;
    }

    /*	Função 'remover' realiza a remoção do elemento do topo da pilha */
    int Pilha::remover (){
        /*	Não havendo pilha, não tem o que retirar */
        if (vazia () || listaenc::Pilha::quant > LIXO_INICIAL || listaenc::Pilha::top == NULL){
            //printf ("A pilha está vazia!\n");
            return MENTIRA;
        }

        /*	'retirado' recebe o topo da pilha */
        Elemento *retirado = listaenc::Pilha::top;
        int valor_retirado = retirado->dados;

        /*	Configuração da pilha */
        listaenc::Pilha::top = retirado->proximo;
        free (retirado);
        listaenc::Pilha::quant--;

        return valor_retirado;
    }

    /*	Função 'remover' realiza a remoção do elemento do topo da pilha */
    int Pilha::topo (){
        /*	Não havendo pilha, não tem o que retirar */
        if (vazia () || listaenc::Pilha::top == NULL){
            //printf ("A pilha está vazia!\n");
            return MENTIRA;
        }

        return listaenc::Pilha::top->dados;
    }

    /*	Função 'vazia' verifica se a pilha corrente está vazia ou não */
    bool Pilha::vazia (){
        /*	Não havendo topo; não existe pilha */
        if (listaenc::Pilha::top == NULL || listaenc::Pilha::quant == MENTIRA)
            return VERDADE;

        /*	Caso contrário */
        return MENTIRA;
    }

    /*	Função 'exibir' realiza a exibição da pilha na tela */
    void Pilha::exibir(){
		/*	Não havendo vetor a ser analisado */
		if (listaenc::Pilha::top == NULL){
            return;
        }
        printf ("\nExibição da Pilha até o momento...\n");
        printf ("Existem %d elemento(s) registrado(s)", listaenc::Pilha::quant);
        if (listaenc::Pilha::quant > MENTIRA){
            printf(", sendo ele(s):\n");
            Elemento *aux;

            /*	Enquanto houver pilha a imprimir */
            for (aux = listaenc::Pilha::top; aux != NULL; aux = aux->proximo){
                /*	Exibição do elemento corrente */
                elemento_exibe (aux);

                /*  Exibição do caracter de continuação ou fim da linha */
                if (aux->proximo != NULL)
                    printf (", ");
                else
                    printf (".\n\n");
            }

        }else
            printf(".\n\n");
    }

    /*	Função 'elemento_exibe' realiza a exibição de um elemento na tela */
    void Pilha::elemento_exibe (Elemento *elemento){
		if (elemento != NULL)
			printf ("%d", elemento->dados);
    }
}
