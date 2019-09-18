/*	Inclusão das Bibliotecas Requesitadas: */
#include "../Bibliotecas/Pilha.h"
#include <stdlib.h>
#include <stdio.h>

/*	Definição das Estruturas a serem utilizadas: */
/*	O cabeçalho da pilha, 'quant' armazena a quantidade de elementos na pilha
**	e 'topo' armazena o inicio da pilha propriamente dita */
struct pilha{
    int topo;
	int tamanho;
    Elemento *pilha;
};

/*	Os dados a serem armazenados na pilha, 'info' armazena tal valor */
struct reg {
    int info;
};

/*	Um elemento da pilha, 'dados' armazena os dados armazenados no elementos corrente */
struct elemento {
    Registro dados;
};


/*	Definição das Funções: */
/*	Função 'pilha_cria_vet' realiza a criação da pilha como vetor */
Pilha * pilha_cria_vet (int tamanho){
	/*	'nova' armazena a nova pilha a ser criada */
    Pilha *nova = NULL;

	/*	Alocação do cabeçalho da pilha */
    do{
        nova = (Pilha *) malloc (sizeof(Pilha));
    }while (nova == NULL);

	/*	Inicialização das variáveis de controle */
    nova->topo = 0;
	nova->tamanho = tamanho;
    nova->pilha = NULL;

	/*	Alocação da pilha */
    do{
        nova->pilha = (Elemento *) malloc (tamanho * sizeof(Elemento));
    }while (nova->pilha == NULL);

    return nova;
}

/*	Função 'pilha_insere' realiza a inserção de um novo elemento na pilha */
void pilha_insere (Pilha *pilha, int info){
	/*	'pilha' armazena a pilha a ser manipulada; 'info' armazena a informação
	**	do novo elemento a ser inserida na pilha */

	/*	Verificando se é possível inserir */
	if (pilha_cheia(pilha) == VERDADE){
		printf ("A pilha está cheia, não foi possível adicionar o %d!\n", info);
		return;
	}

	/*	Configuração da pilha */
	pilha->pilha[pilha->topo].dados.info = info;
	pilha->topo++;
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
    Elemento *retirado = &(pilha->pilha[pilha->topo]);

	/*	Configuração da pilha */
    pilha->topo--;

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
    return &(pilha->pilha[pilha->topo - 1]);
}

/*	Função 'pilha_vazia' verifica se a pilha corrente está vazia ou não */
char pilha_vazia (Pilha *pilha){
	/*	'pilha' armazena a pilha a ser manipulada */

	/*	Não havendo topo; não existe pilha */
	if (pilha->topo == VERDADE){
        return VERDADE;
    }

	/*	Caso contrário */
    return MENTIRA;
}

/*	Função 'pilha_cheia' verifica se a pilha corrente está cheia ou não */
char pilha_cheia (Pilha *pilha){
	/*	'pilha' armazena a pilha a ser manipulada */

	/*	Caso o topo esteja no máximo*/
	if (pilha->topo == pilha->tamanho){
        return VERDADE;
    }

	/*	Caso contrário */
    return MENTIRA;
}

/*	Função 'pilha_libera' realiza a desalocação da memória */
Pilha * pilha_libera (Pilha *pilha){
	/*	'pilha' armazena a pilha a ser manipulada */

	/*	Liberação da pilha em si */
	free (pilha->pilha);

	/*	Liberação do cabeçalho da pilha */
    free (pilha);

	return NULL;
}

/*	Função 'pilha_exibe' realiza a exibição da pilha na tela */
void pilha_exibe (Pilha *pilha){
	/*	'pilha' armazena a pilha a ser manipulada; 'aux' auxilia o manuseio da
	**	pilha */
	int posicao;

    printf ("\nExibição da Pilha até o momento...\n");
    printf ("Existem %d elemento(s) registrados, sendo ele(s):\n", pilha->topo);

	/*	Enquanto houver pilha a imprimir */
    for (posicao = 0; posicao < pilha->topo; posicao++){
		/*	Exibição do elemento corrente */
        elemento_exibe (&(pilha->pilha[posicao]));
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
