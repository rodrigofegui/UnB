/*	Inclusão das Bibliotecas Requesitadas: */
#include "../Bibliotecas/Pilha.h"
#include <stdlib.h>
#include <stdio.h>


/*	Definição das Estruturas a serem utilizadas: */
/*	O cabeçalho da pilha, 'quant' armazena a quantidade de elementos na pilha
**	e 'topo' armazena o inicio da pilha propriamente dita */
struct pilha{
    int quant;
    Elemento *topo;
};

/*	Os dados a serem armazenados na pilha, 'info' armazena tal valor */
struct reg {
    int info;
};

/*	Um elemento da pilha, 'dados' armazena os dados armazenados no elementos corrente,
**	'proximo' armazena o end. do próximo elemento da pilha */
struct elemento {
    Registro dados;
    Elemento *proximo;
};


/*	Definição das Funções: */
/*	Função 'pilha_cria' realiza a criação da pilha */
Pilha * pilha_cria (){
	/*	'nova' armazena a nova pilha a ser criada */
    Pilha *nova = NULL;

	/*	Alocação do cabeçalho da pilha */
    do{
        nova = (Pilha *) malloc (sizeof(Pilha));
    }while (nova == NULL);

	/*	Inicialização das variáveis de controle */
    nova->quant = 0;
    nova->topo = NULL;

    return nova;
}

/*	Função 'elemento_cria' realiza a criação de um novo elemento a ser
**	inserido na pilha */
Elemento * elemento_cria (){
	/*	'novo' armazena o novo elemento a ser criado */
    Elemento *novo = NULL;

	/*	Alocação do novo elemento */
    do{
        novo = (Elemento *) malloc (sizeof(Elemento));
    }while (novo == NULL);

	/*	Iniciação das variáveis de controle */
    novo->dados.info = 0;
    novo->proximo = NULL;

    return novo;
}

/*	Função 'pilha_insere' realiza a inserção de um novo elemento na pilha */
void pilha_insere (Pilha *pilha, int info){
	/*	'pilha' armazena a pilha a ser manipulada; 'info' armazena a informação
	**	do novo elemento a ser inserida na pilha; 'novo' armazena o novo elemento
	**	a ser inserido na pilha */
    Elemento *novo = elemento_cria ();

	/*	Configuração dos dados para inserção na pilha */
    novo->dados.info = info;

	/*	Já havendo uma pilha formanda */
    if (pilha_vazia (pilha) == MENTIRA)
        novo->proximo = pilha->topo;

	/*	Configuração da pilha */
    pilha->topo = novo;
    pilha->quant++;
}

/*	Função 'pilha_remove' realiza a remoção do elemento do topo da pilha */
Elemento * pilha_remove (Pilha *pilha){
	/*	'pilha' armazena a pilha a ser manipulada */

	/*	Caso não tenha nem cabeçalho */
	if (pilha == NULL){
		printf ("Nao Existe PILHA!\n");

        return NULL;
	}

	/*	Não havendo pilha, não tem o que retirar */
    if (pilha_vazia (pilha) == VERDADE){
        printf ("A pilha está vazia!\n");

        return NULL;
    }

	/*	'retirado' recebe o topo da pilha */	
    Elemento *retirado = pilha->topo;

	/*	Configuração da pilha */
    pilha->topo = retirado->proximo;
	pilha->quant--;

    return retirado;
}

/*	Função 'pilha_topo' retorna o elemento que está no topo da pilha */
Elemento * pilha_topo (Pilha *pilha){
	/*	'pilha' armazena a pilha a ser manipulada */

	/*	Não havendo pilha, não tem o que retornar */
    if (pilha_vazia (pilha) == VERDADE){
        printf ("A pilha está vazia!\n");

        return NULL;
    }

	/*	'visualizar' armazena o elemento do topo da pilha */
    Elemento *visualizar = pilha->topo;

    return visualizar;
}

/*	Função 'pilha_vazia' verifica se a pilha corrente está vazia ou não */
char pilha_vazia (Pilha *pilha){
	/*	'pilha' armazena a pilha a ser manipulada */

	/*	Não havendo topo; não existe pilha */
	if (pilha->topo == NULL){
        return VERDADE;
    }

	/*	Caso contrário */
    return MENTIRA;
}

/*	Função 'pilha_libera' realiza a desalocação da memória */
Pilha * pilha_libera (Pilha *pilha){
	/*	'pilha' armazena a pilha a ser manipulada */

	/*	Enquanto houver pilha */
    while (pilha_vazia (pilha) == MENTIRA){
		/*	'aux' auxilia o manuseio da pilha, recebendo o topo da pilha */
        Elemento *aux = pilha_remove (pilha);

		/*	Liberação da memória do elemento corrente */
        elemento_libera (aux);
    }

	/*	Liberação do cabeçalho da pilha */
    free (pilha);

	return NULL;
}

/*	Função 'elemento_libera' realiza a desalocação de um elemento */
void elemento_libera (Elemento *campo){
	/*	'campo' armazena o elemento a ser desalocado */

    free (campo);
}

/*	Função 'pilha_exibe' realiza a exibição da pilha na tela */
void pilha_exibe (Pilha *pilha){
	/*	'pilha' armazena a pilha a ser manipulada; 'aux' auxilia o manuseio da
	**	pilha */
    Elemento *aux;

    printf ("\nExibição da Pilha até o momento...\n");

    printf ("Existem %d elemento(s) registrados, sendo ele(s):\n", pilha->quant);

	/*	Enquanto houver pilha a imprimir */
    for (aux = pilha->topo; aux != NULL; aux = aux->proximo){
		/*	Exibição do elemento corrente */
        elemento_exibe (aux);

		/*	Enquanto não for o último 
        if (aux->proximo != NULL)
            printf (", ");

		/*	Caso contrário
        else
            printf (".\n");
		*/
    }
}

/*	Função 'elemento_exibe' realiza a exibição de um elemento na tela */
void elemento_exibe (Elemento *campo){
	/*	'campo' armazena o elemento a ser exibido */    

	if (campo != NULL){
		/*	Exibição em si */
		printf ("%d\n", campo->dados.info);
	}
}
