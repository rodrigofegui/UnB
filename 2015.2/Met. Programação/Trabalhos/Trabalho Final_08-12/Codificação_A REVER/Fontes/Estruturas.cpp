/*****************************************************************
**      Inclusão das bibliotecas
*****************************************************************/
    #include "../Bibliotecas/Estruturas.hpp"

/*****************************************************************
**      Definição das Funções
*****************************************************************/
	/*	Função 'cria_elemento', aloca espaço de memória para um
	**	elemento e inicializa suas variáveis de controle */
	Elem* cria_elemento(void){
		/*	'novo' armazena o novo elemento a ser criado */
		Elem* novo;
		
		/*	Alocação de memória para 1 elemento */
		novo = (Elem *) malloc (sizeof(Elem));

		/*	Inicialização das variáveis de controle */
		novo->tipo_el = '\0';
		novo->nome_el = NULL;
		novo->lin = novo->col = -1;
		novo->recurso = novo->custo = 0;
		novo->conex_adapt = novo->conex = NULL;
		novo->ger = novo->proximo = NULL;

		return novo;
	}

	/*	Função 'insere_elemento', insere um novo elemento ao conjunto de Elementos */
	Elem* insere_elemento(Elem *inicio, FILE *arq, char *dado, int p_x, int p_y, int rec, int cust){
		/*	'inicio' armazena o inicio do conjunto de elementos; 'arq' armazena o arquivo de origem;
		**	'dado' armazena o nome do elemento, sem refinamento, a ser inserido; 'p_x' e 'p_y'
		**	armazenam a coordenada do elemento na malha; 'rec' armazena o recurso; 'cust' armazena
		**	o custo; 'tipo' armazena o tipo do elemento a ser inserido; 'nome' armazena o nome,
		**	após o refinamento, do elemento; 'ind' armazena um índice a ser manipulado;
		**	'tam' armazena o tamanho de 'nome' durante a criação do mesmo */
		char tipo = dado[0], *nome=NULL;
		int numero, ind, tam = 0, contador = 0;
		Elem *aux, *ant, *atual; /*possibilitam realizar insercoes no meio da lista */


		/*	Percorrendo toda a string 'dado' e retirando os espaços, '\0' e '\n' que podem
		**	eventualmente existir */
		for(ind = 1; i <= strlen(dado); i++){
			/*	Refinando a string 'dado' */
		    if( (dado[i]!='Space') && (dado[i]!='\0') && (dado[i]!='\n') ){
		            nome = (char *) realloc (nome, tam + 1);
		            nome[tam] = dado[i];
		            tam++;
		    }
		}
	    
		/*	Inserindo o elemento na lista */
		/*	Caso não exista um conjunto previamente criado */
		if(inicio == NULL){
			/*	Criando um novo elemento para o início */
	        inicio = cria_elemento();

			/*	Configurando o nome elemento */
	        inicio->tipo_el = tipo;
	        inicio->nome_el = (char *) malloc (sizeof(char) * tam);
	        strcpy(inicio->nome_el, nome);
	        inicio->lin = p_x;
	        inicio->col= p_y;

			/*	Analisando o tipo de elemento criado */
			/*	Sendo um adaptador */
	        if(tipo!='A')
	            inicio->recurso = rec;
			/*	Sendo um gerador */			
			if(tipo== 'G')
                inicio->custo = cust;

		/*	Caso contrário, já existindo um conjunto formado */
	    }else{
			/*	Busca o elemento atual dado o anterior */
	        atual = busca_elemento(inicio,&ant,p_x,p_y);

			/*	Sendo o primeiro elemento */
	        if ((ant == NULL) && (atual != NULL)){
	            ant = insere_elemento(ant,arq,dado,p_x,p_y,rec,cust);
	            ant->proximo = atual->proximo;
	            atual->proximo = ant;

			/*
	        }else if(ant==NULL && atual ==NULL){// criacao de uma nova linha
	            aux= NULL;
	            aux = insere_elemento(aux,arq,dado,p_x,p_y,rec,cust);
	            aux->ger = inicio;
	            inicio = aux;
			*/
			/*	Estando no meio do conjunto */
	        }else{
	            aux = NULL;
	            aux = insere_elemento(aux,arq,dado,p_x,p_y,rec,cust);
	            ant->proximo = aux;
	            aux->proximo = atual;
	        }
	    }

		/*	Libera a memória alocada para o nome refinado */
		free(nome);

    	return inicio;
	}

	/*	Função 'libera_elementos', desaloca a memória para todos os 
	**	elementos que existem no conjunto */
	void libera_elementos (Elem* inicio){
		/*	'inicio' armazena o inicio do conjunto de elementos */

		/*	Havendo conjunto a ser liberado */
		while (inicio != NULL){
			/*	'aux' auxilia a percorrer uma linha do conjunto */
			Elem *aux = inicio;

			/*	Configurando para próxima linha */
		    inicio = inicio->ger;

			/*	Liberação de toda uma linha */
		    while (aux != NULL){
				/*	'libera' armazena o elemento a ser liberado */
				Elem *libera = aux;

				/*	Configurando para o próximo elemento */
		        aux = aux->proximo;

				/*	Liberando a memória */
		        free(libera);
		    }
		}
    }


	/*	Função 'busca_elemento', retorna o elemento atual dado um anterior */
	Elem* busca_elemento (Elem *inicio, Elem **anterior, int p_x, int p_y){
		/*	'inicio' armazena o inicio do conjunto a ser considerado; 'anterior' armazena o elemento anterior
		**	em relação ao elemento de interesse; 'p_x' e 'p_y' armazenam a coordenada do elemento a ser buscado;
		**	'ant' armazena o elemento anterior em relação ao elemento corrente; 'atual' armazena o elemento corrente;
		**	'aux' auxilia a navegação no conjunto do elementos */
		Elem *ant, *atual, *aux;

		/*	Navegando no conjunto de Elementos */
		for (aux = inicio; aux != NULL; aux = aux->ger){
			/*	Configuração do 'ant' e do 'atual' */
		    ant = NULL;
		    atual = aux;

			/*	Procura a localizacao do elemento ou o fim da lista, percorrendo todos os elementos */
		    while ((atual != NULL) && (p_x != atual->lin) && (p_y != atual->col)){
		        ant = atual;
		        atual = atual->proximo;
		    }

			/*	Encontrando o Elemento de interesse */
		    if (atual != NULL){
				/*	Configura o anterior e retorna o de interesse */
		        *(anterior) = ant;
		        return atual;
		    }
		}
	
		/*	Caso não tenha encontrado o Elemento, tando o anterior como o de interesse são nulos */
		*(anterior) = NULL;
		return NULL;
	}

	/*	Função 'imprime_El', exibi na saída padrão o conjunto de elementos */
	void imprime_El(Elem* inicio){
		/*	'inicio' armazena o início do conjunto a ser exibido */

		/*	Havendo conjunto a ser exibido */
		while (inicio != NULL){
			/*	Percorre toda uma linha de Elementos */
		    for (Elem *aux = inicio; aux != NULL; aux = aux->proximo){
		        printf ("%c ", aux->tipo_el);

				/*	Havendo nome a ser exibido */
		        if(aux->nome_el!=NULL)
		            printf ("%s ", aux->nome_el);

		        printf ("(%d, %d) ", aux->lin, aux->col);

				/*	Sendo um Adaptador */
		        if(aux->tipo_el == 'A')
		            printf ("%d  ", aux->recurso);

				/*	Sendo um Gerador */
	            if(aux->tipo_el == 'G')
	                printf ("%d\n", aux->custo);

				/*	Acabando a linha de Elementos */
		        if(aux->proximo == NULL)
		            printf ("\n\n");
		    }

			/*	Configurando para a próxima linha */
		    inicio = inicio->ger;
		}
	}
