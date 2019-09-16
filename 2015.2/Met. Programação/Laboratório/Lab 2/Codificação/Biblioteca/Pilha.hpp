#ifndef Pilha_hpp
    /*  Definição da biblioteca na tabela de símbolos */
	#define Pilha_hpp


	/********************************************************
	**	Constantes GLOBAIS:
	**		'VERDADE'		- define o estado verdadeiro para
	**						as manipulações;
	**		'MENTIRA'		- define o estado falso para as
	**						manipulações;
	**		'LIMITE'		- define o limite de tentativas
	**						para alocação de memória
	********************************************************/
    #define VERDADE 1
    #define MENTIRA 0
	#define LIMITE 5
	#define LIXO_INICIAL 400000

    /*  Definição do tipo de dados a serem manipulados na pilha */
	typedef int info;

    /* Especialização das funções para uma pilha como vetor */
	namespace vetor{
		/********************************************************
		**	Estrutura:
		**		Elemento da pilha
		**	Descrição:
		**		Estrutura, nomeada como 'Elemento', responsável
		**		por armazenar os campos a serem manipulados na
		**		pilha, assim como suas declarações de tipo de
		**		dados;
		**	Campos:
		**		'dados'	- armazena as informações inteiras a serem
		**				manipuladas
		********************************************************/
		typedef struct elfen {
            info dados;
            int indice;
        }
        Elemento;

        /*  Definição do tipo de variável a ser utilizada */
        typedef Elemento tpDado;


		/********************************************************
		**	Classe:
		**		Pilha
		**	Descrição:
		**		Classe, nomeada como 'Pilha', responsável
		**		por implementar, como vetor, e manipular a
		**		estrutura de dados pilha atráves dos métodos
		**		descritos abaixo;
		********************************************************/
		class Pilha{
			public:
				/********************************************************
				**	Função:
				**		Criação da Pilha como Vetor
				**	Descrição:
				**		Aloca espaço na memória para um vetor de tamanho
				**		'tam' fixo.
				**	Parâmetros:
				**		'tam'	- tamanho da pilha, após alocação
				**	Assertivas de entrada:
				**		tam > 1
				**  Assertivas de controle:
                **      contador_tentativa_alocacao >= LIMITE
                **         && não alocou memória
				**	Valor retornado:
				**		Retorna VERDADE, conseguindo alocar a memoria.
				**	Assertivas de saida:
				**		Não possui assertivas desse tipo
				********************************************************/
				bool criar (int tam);

				/********************************************************
				**	Função:
				**		Liberação da memória alocada
				**	Descrição:
				**		Libera o espaço alocado na memória
				**	Parâmetros:
				**		Não exige parâmetros de entrada
				**	Assertivas de entrada:
				**		Não possui assertivas desse tipo
				**	Valor retornado:
				**		Retorna o endereço de memória do topo liberado
				**	Assertivas de saida:
				**		Não possui assertivas desse tipo
				********************************************************/
                Elemento * liberar ();

				/********************************************************
				**	Função:
				**		Inserção de um novo elemento na pilha
				**	Descrição:
				**		Insere um número inteiro no topo da pilha e incre-
				**		menta o número de elementos na pilha
				**	Parâmetros:
				**		'dado' - armazena a informação a ser inserida na
				**				pilha
				**	Assertivas de entrada:
				**		pilha.cheia() == MENTIRA
				**		pilha::elementos != MENTIRA
				**	Valor retornado:
				**		Retorna-se o valor armazena no topo da pilha, es-
				**		pera-se que seja o mesmo que 'info'.
				**	Assertivas de saida:
				**		Se retorna MENTIRA
				**		Então
				**			O vetor está cheio ou
				**			A pilha não foi alocada
				**		Senão
				**			Inserção realizada com sucesso
				**		FimSe
				********************************************************/
                info inserir (info dado);

				/********************************************************
				**	Função:
				**		Retirada de um elemento da pilha
				**	Descrição:
				**		Remove o elemento situado no topo da pilha
				**	Parâmetros:
				**		Não exige parâmetros de entrada
				**	Assertivas de entrada:
				**		pilha.vazia() == MENTIRA
				**		pilha::elementos != MENTIRA
				**	Valor retornado:
				**		Retorna-se o valor armazena no topo da pilha,
				**		removendo-o da pilha, então espera-se que o topo
				**		seja o elemento seguinte.
				**	Assertivas de saida:
				**		Se retorna MENTIRA
				**		Então
				**			O vetor está cheio ou
				**			A pilha não foi alocada
				**		Senão
				**			Remoção realizada com sucesso
				**		FimSe
				********************************************************/
                tpDado remover ();

				/********************************************************
				**	Função:
				**		Sinalizar topo
				**	Descrição:
				**		Sinaliza qual o elemento que está situado no topo
				**		da pilha
				**	Parâmetros:
				**		Não exige parâmetros de entrada
				**	Assertivas de entrada:
				**		pilha.vazia() == MENTIRA
				**		pilha::elementos != MENTIRA
				**	Valor retornado:
				**		Retorna-se o valor armazena no topo da pilha,
				**		sem retirá-lo da pilha, caso haja pilha;
				**		Retorna-se MENTIRA, caso contrário.
				**	Assertivas de saida:
				**		Se retorna MENTIRA
				**		Então
				**			O vetor está vazio ou
				**			A pilha não foi alocada
				**		Senão
				**			Disponibilização do topo está correta
				**		FimSe
				********************************************************/
                tpDado topo ();

                tpDado procura (info);

                tpDado primeiro ();

                bool terminou (tpDado);

                info obtervalor (tpDado);

                bool compara (info, info);

                tpDado definirproximo (tpDado);

                tpDado estadonulo ();

				/********************************************************
				**	Função:
				**		Verificar pilha cheia
				**	Descrição:
				**		Sinaliza se há espaço disponíveis no vetor alocado
				**	Parâmetros:
				**		Não exige parâmetros de entrada
				**	Assertivas de entrada:
				**		pilha::elementos != MENTIRA
				**	Valor retornado:
				**		Não tendo um vetor alocado ou ainda havendo espa-
				**		ço no vetor a ser utilizado, retorna-se MENTIRA
				**		Caso contrário, retorna-se VERDADE
				********************************************************/
                bool cheia ();

				/********************************************************
				**	Função:
				**		Verificar pilha vazia
				**	Descrição:
				**		Sinaliza se já foi utilizado algum espaço no vetor
				**	Parâmetros:
				**		Não exige parâmetros de entrada
				**	Assertivas de entrada:
				**		pilha::elementos != MENTIRA
				**	Valor retornado:
				**		Não tendo um vetor alocado ou já tendo pelo menos um
				**		elemento inserido, retorna-se MENTIRA
				**		Caso contrário, retorna-se VERDADE
				********************************************************/
                bool vazia ();

				/********************************************************
				**	Função:
				**		Exibição da pilha na tela
				**	Descrição:
				**		Escreve na saída padrão o estado atual da pilha
				**	Parâmetros:
				**		Não exige parâmetros de entrada
				**	Assertivas de entrada:
				**		pilha::elementos != MENTIRA
				**	Valor retornado:
				**		Não é retornado nenhum valor
				********************************************************/
                void exibir ();

				/********************************************************
				**	Função:
				**		Exibição do elemento
				**	Descrição:
				**		Escreve na saída padrão o estado atual de apenas
				**		um elemento na pilha
				**	Parâmetros:
				**		Não exige parâmetros de entrada
				**	Assertivas de entrada:
				**		elemento != MENTIRA
				**	Valor retornado:
				**		Não é retornado nenhum valor
				********************************************************/
                void elemento_exibe (Elemento *);

			private:
				/********************************************************
				**	Variáveis Privadas:
				**		'top'		- armazena o índice correspondente ao
				**					topo da pilha;
				**		'tamanho'	- armazena o tamanho do vetor alocado
				**		'elementos'	- armazena o vetor de elementos
				**					da pilha
				********************************************************/
				int top;
				int tamanho;
				Elemento *elementos;
		};
	}

    /* Especialização das funções para uma pilha como lista encadeada */
	namespace listaenc{
		/********************************************************
		**	Estrutura:
		**		Elemento da pilha
		**	Descrição:
		**		Estrutura, nomeada como 'Elemento', responsável
		**		por armazenar os campos a serem manipulados na
		**		pilha, assim como suas declarações de tipo de
		**		dados;
		**	Campos:
		**		'dados'		- armazena as informações inteiras serem
		**					a serem manipuladas
		**		'proximo' 	- armazena o endereço de memória do
		**					próximo elemento da pilha
		********************************************************/
	    typedef struct elfen {
            info dados;
            struct elfen *proximo;
        }
        Elemento;

        /*  Definição do tipo de variável a ser utilizada */
        typedef Elemento * tpDado;

		/********************************************************
		**	Classe:
		**		Pilha
		**	Descrição:
		**		Classe, nomeada como 'Pilha', responsável
		**		por implementar, como lista encadeaca, e manipular
		**		a estrutura de dados pilha atráves dos métodos
		**		escritos abaixo;
		********************************************************/
		class Pilha{
            public:
				/********************************************************
				**	Função:
				**		Criação da Pilha como Lista Encadeada
				**	Descrição:
				**		Inicializa as variáveis privadas da pilha, a fim
				**		de evitar que informações incorretas sejam mani-
				**		puladas durante a execução do programa
				**	Parâmetros:
				**		Não exige parâmetros de entrada
				**	Assertivas de entrada:
				**		Não exige assertivas de entrada
				**	Valor retornado:
				**		Ao garantir que as variáveis foram inicializadas
				**		corretamente, retorna-se VERDADE;
				**		caso contrário, retorna-se MENTIRA.
				********************************************************/
				bool criar ();

				/********************************************************
				**	Função:
				**		Criação de um Elemento da Pilha
				**	Descrição:
				**		Aloca memória para um novo elemento a ser inserido
				**		na pilha
				**	Parâmetros:
				**		'dado'	- armazena o dado inteiro a ser inserido
				**				na pilha, atráves do novo elemento
				**	Assertivas de entrada:
				**		Não exige assertivas de entrada
				**	Valor retornado:
				**		Após a correta configuração do novo elemento a
				**		ser inserido na pilha, retorna-se o novo valor.
				********************************************************/
				Elemento * elemento_cria (info dado);

				/********************************************************
				**	Função:
				**		Liberação da memória alocada
				**	Descrição:
				**		Libera o espaço alocado na memória para toda a
				**		a pilha; enquanto houver elemento na pilha,
				**		libera-se a memória para cada elemento;
				**	Parâmetros:
				**		Não exige parâmetros de entrada
				**	Assertivas de entrada:
				**		vazia() == MENTIRA
				**	Valor retornado:
				**		Retorna o endereço de memória do topo liberado
				********************************************************/
                Elemento * liberar ();

				/********************************************************
				**	Função:
				**		Inserção de um novo elemento na pilha
				**	Descrição:
				**		Insere um número inteiro no topo da pilha e incre-
				**		menta o número de elementos na pilha; caso a pilha
				**		não esteja vazia, o próximo elemento do novo é o
				**		topo da pilha
				**	Parâmetros:
				**		'info' - armazena a informação a ser inserida na
				**				pilha
				**	Assertivas de entrada:
				**		Não exige assertivas de entrada
				**	Valor retornado:
				**		Retorna-se o valor armazena no topo da pilha, es-
				**		pera-se que seja o mesmo que 'info'
				********************************************************/
                info inserir (info dado);

				/********************************************************
				**	Função:
				**		Retirada de um elemento da pilha
				**	Descrição:
				**		Remove a informação armazena no topo da pilha,
				**		liberando a memória para o elemento que estava
				**		no topo;
				**	Parâmetros:
				**		Não exige parâmetros de entrada
				**	Assertivas de entrada:
				**		pilha.vazia() == MENTIRA
				**		pilha::elementos != MENTIRA
				**	Valor retornado:
				**		Retorna-se o valor armazena no topo da pilha,
				**		removendo-o da pilha, então espera-se que o topo
				**		seja o elemento seguinte
				********************************************************/
                tpDado remover ();

				/********************************************************
				**	Função:
				**		Sinalizar topo
				**	Descrição:
				**		Sinaliza qual o elemento que está situado no topo
				**		da pilha
				**	Parâmetros:
				**		Não exige parâmetros de entrada
				**	Assertivas de entrada:
				**		pilha.vazia() == MENTIRA
				**		pilha::top != MENTIRA
				**	Valor retornado:
				**		Retorna-se o valor armazena no topo da pilha,
				**		sem retirá-lo da pilha, caso haja pilha;
				**		ou retorna-se MENTIRA, caso não haja.
				********************************************************/
                tpDado topo ();

                tpDado procura (info);

                tpDado primeiro ();

                bool terminou (tpDado);

                info obtervalor (tpDado);

                bool compara (info, info);

                tpDado definirproximo (tpDado);

                tpDado estadonulo ();

				/********************************************************
				**	Função:
				**		Verificar pilha vazia
				**	Descrição:
				**		Sinaliza se já foi inserido algum elemento na pilha
				**	Parâmetros:
				**		Não exige parâmetros de entrada
				**	Assertivas de entrada:
				**		pilha::top != MENTIRA
				**		pilha::quant == 0
				**	Valor retornado:
				**		Não tendo memória alocada ou já tendo pelo menos um
				**		elemento inserido, retorna-se MENTIRA;
				**		Caso contrário, retorna-se VERDADE
				********************************************************/
                bool vazia ();

				/********************************************************
				**	Função:
				**		Exibição da pilha na tela
				**	Descrição:
				**		Escreve na saída padrão o estado atual da pilha
				**	Parâmetros:
				**		Não exige parâmetros de entrada
				**	Assertivas de entrada:
				**		pilha::top != MENTIRA
				**	Valor retornado:
				**		Não é retornado nenhum valor
				********************************************************/
                void exibir ();

				/********************************************************
				**	Função:
				**		Exibição do elemento
				**	Descrição:
				**		Escreve na saída padrão o estado atual de apenas
				**		um elemento na pilha
				**	Parâmetros:
				**		Não exige parâmetros de entrada
				**	Assertivas de entrada:
				**		elemento != MENTIRA
				**	Valor retornado:
				**		Não é retornado nenhum valor
				********************************************************/
                void elemento_exibe (Elemento *);


            private:
				/********************************************************
				**	Variáveis Privadas:
				**		'quant'		- armazena a quantidade de elementos
				**					existentes na pilha
				**		'elementos'	- armazena o endereço de memória para
				**					o topo da pilha;
				********************************************************/
                int quant;
                Elemento *top;
		};
	}

#endif
