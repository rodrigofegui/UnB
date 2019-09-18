/*****************************************************************
**  Criadores:
**          Pedro Aurélio Coelho Almeida
**          Rodrigo Ferreira Guimarães
**  Nome:
**          Arvore.hpp
**  Finalidade:
**          Armazenar as funções para a manipulação da árvore do
**          projeto, sendo estas disponíveis ao usuário:
**              -   Criação;
**              -   Liberação;
**              -   Inserção;
**              -   Busca;
*****************************************************************/

/*  Caso não tenha sido declarada na tabela de símbolos */
#ifndef ArvoreB_A_h
    #define ArvoreB_A_h

    /*****************************************************************
    **      Inclusão das bibliotecas auxiliares
    *****************************************************************/
        #include <stdio.h>
        #include <stdlib.h>
        #include <string.h>
        #include "Basica_A.hpp"

    /*****************************************************************
    **      Constantes Globais e Namespaces
    *****************************************************************/
        /*  'TAM_MAT' armazena a quantidade de caracteres reservado para a matrícula */
            #define TAM_MAT 8
        /*  'TAM_NOME' armazena a quantidade de caracteres reservado para o nome */
            #define TAM_NOME 42
        /*  'TAM_OP' armazena a quantidade de caracteres reservado para a opção */
            #define TAM_OP 5
        /*  'TAM_CURSO' armazena a quantidade de caracteres reservado para o curso */
            #define TAM_CURSO 10
        /*  'TAM_REG' armazena a quantidade de caracteres reservado para um registro completo */
            #define TAM_REG (TAM_MAT+TAM_NOME+TAM_OP+TAM_CURSO+1)
        /*  'TAM_CHAVE' armazena a quantidade de caracteres que constituem uma chave */
            #define TAM_CHAVE 10
        /*  'SAIR' armazena a resposta para a saída das tarefas sobre a árvore */
            #define SAIR 0
        /*  'EXIBIR' armazena a resposta para a exibição da árvore */
            #define EXIBIR 1
        /*  'BUSCA' armazena a resposta para a busca na árvore */
            #define BUSCA 2
        /*  'INSERIR' armazena a resposta para a inserção na árvore */
            #define INSERIR 3

    /*****************************************************************
    **      Estruturas
    *****************************************************************/
        /*  'Celula' define a estrutura 'cel' a ser declarada */
            typedef struct cel Celula;

        /*  'Pag' define a estrutura 'pag' a ser declarada */
            typedef struct pag Pagina;

        /********************************************************
        **	Estrutura:
        **		Dados
        **	Descrição:
        **		Estrutura, nomeada como 'Dados', responsável
        **		por armazenar os dados completos de um dado
        **      registro.
        **	Campos:
        **		'Mat'   - armazena a matrícula;
        **      'Nome'  - armazena o nome;
        **      'OP'    - armazena a opção;
        **      'Curso' - armazena o curso;
        **      'Turma' - armazena a turma.
        ********************************************************/
            typedef struct dados{
                char Mat[TAM_MAT];
                char Nome[TAM_NOME];
                char OP[TAM_OP];
                char Curso[TAM_CURSO];
                char Turma;
            }
            Dados;

        /********************************************************
        **	Estrutura:
        **		Info
        **	Descrição:
        **		Estrutura, nomeada como 'Info', responsável
        **		por armazenar os dados codificados de cada
        **      registro.
        **	Campos:
        **		'ID'    - armazena a chave gerada para um deter-
        **              minado registro lido;
        **      'seek'  - armazena o deslocamento realizado
        **              desde o início do arquivo até o corrente
        **              registro
        ********************************************************/
            typedef struct key{
                char ID[TAM_CHAVE];
                int seek;
            }
            Info;

        /********************************************************
        **	Estrutura:
        **		Pagina
        **	Descrição:
        **		Estrutura, nomeada como 'Pagina', responsável
        **		por armazenar as páginas que compõem a árvore
        **      a ser construída.
        **	Campos:
        **		'num'       - armazena o número da página
        **                  corrente;
        **      'qnt_cel'   - armazena a quantidade de células
        **                  cadastradas na página;
        **      'inicio'    - armazena o início da lista de
        **                  células;
        **      'pai'       - armazena a página pai da corrente;
        ********************************************************/
            struct pag{
                int num;
                int qnt_cel;
                Celula *inicio;
                Pagina *pai;
            };

        /********************************************************
        **	Estrutura:
        **		Celula
        **	Descrição:
        **		Estrutura, nomeada como 'Celula', responsável
        **		por armazenar um elemento de controle das chaves
        **      na árvore.
        **	Campos:
        **		'chave'     - armazena a informação essencial
        **                  de um registro
        **      'menores'   - armazena a primeira página com chaves
        **                  menores que a corrente
        **      'maiores'   - análogo a 'menores';
        **      'prox'      - armazena a próxima célula.
        ********************************************************/
            struct cel{
                Info chave;
                Pagina *menores, *maiores;
                Celula *prox;
            };

    /*****************************************************************
    **      Funções Avulsas Manipuladoras de dados do projeto
    *****************************************************************/
        /********************************************************
        **	Função:
        **		Limpeza de Dados
        **	Descrição:
        **		Limpa as informações sobre um aluno, para armazenar,
        **      sem erros, os dados do próximo
        **	Parâmetros:
        **		'registro' - armazena a estrutura a ser limpa
        **	Valor retornado:
        **		Não possui retorno especificado
        ********************************************************/
            void dados_limpa (Dados *registro);

        /********************************************************
        **	Função:
        **		Decisão de qual manipulação realizar
        **	Descrição:
        **		Caso tenha sido escolhido a inserção ou a busca
        **      de um registro é realizado o levantamento,
        **      personalizado, das informações necessárias
        **	Parâmetros:
        **		'registro' - armazena as informações brutas a
        **                  serem questionadas
        **      'nova_ch'   - armazena a codificação dos registros
        **      'codigo'    - armazena o código da operação
        **                  escolhida
        **	Valor retornado:
        **		Não possui retorno especificado
        ********************************************************/
            void dados_questiona (Dados *registro, Info *nova_ch, int codigo);

        /********************************************************
        **	Função:
        **		Complemento de espaços
        **	Descrição:
        **		Após o levantamento das informações, os espaços
        **      não preenchidos são então preenchidos com espaços
        **	Parâmetros:
        **		'registros' - armazena as informações a serem
        **                  preenchidas
        **	Valor retornado:
        **		Não possui retorno especificado
        ********************************************************/
            void dados_completa (Dados *registro);

        /********************************************************
        **	Função:
        **		Impressão no arquivo de manipulação
        **	Descrição:
        **		Escreve no arquivo de manipulação um novo registro
        **	Parâmetros:
        **		'registros' - armazena as informações a serem
        **                  escritas
        **	Valor retornado:
        **		Não possui retorno especificado
        ********************************************************/
            void dados_escreve (Dados *registro);

        /********************************************************
        **	Função:
        **		Montagem da Chave
        **	Descrição:
        **		A partir das informações adquiridas é realizada a
        **      codificação numa chave
        **	Parâmetros:
        **		'destino'   - armazena o resultado da codificação
        **      'origem'    - armazena as informações base para a
        **                  codificação
        **	Valor retornado:
        **		Não possui retorno especificado
        ********************************************************/
            void chave_monta (Info *destino, Dados *origem);

        /********************************************************
        **	Função:
        **		Comparação de Chaves
        **	Descrição:
        **		Compara dois registros através de suas respectivas
        **      chaves
        **	Parâmetros:
        **		'ch1'   - primeira chave;
        **      'ch2'   - segunda chave;
        **	Valor retornado:
        **		>0  - caso a primeira chave seja menor que
        **          a segunda
        **      =0  - caso sejam iguais
        **      <0  - caso a segunda seja maior
        ********************************************************/
            int chave_compara (char *ch1, char *ch2);

        /********************************************************
        **	Função:
        **		Comparação de Chaves
        **	Descrição:
        **		Compara três registros através de suas respectivas
        **      chaves
        **	Parâmetros:
        **		'anterior'  - primeira chave;
        **      'posterior' - terceira chave;
        **      'nova'      - uma nova chave a ser avaliada, entre
        **                  as duas já citadas
        **	Valor retornado:
        **		-1  - caso a 'nova' esteja realmente entre as duas
        **      =0  - caso 'nova' seja igual a alguma das duas
        **      +1  - caso contrário
        ********************************************************/
            int chave_compara_meio (char *anterior, char *posterior, char *nova);

    /********************************************************
    **	Classe:
    **		ArvB
    **	Descrição:
    **		Classe, nomeada como 'ArvB', responsável
    **		por implementar e manipular a estrutura de
    **      dados árvore-B atráves dos métodos descritos
    **      abaixo.
    ********************************************************/
        class ArvB{
            public:
                /*****************************************************************
                **      Funções Públicas
                *****************************************************************/
                    /********************************************************
                    **	Função:
                    **		Criação da Árvore-B
                    **	Descrição:
                    **		Inicializa a Árvore-B, de forma a garantir que
                    **      não haja dados incoerente com os esperados
                    **	Parâmetros:
                    **		'ordem'         - ordem das páginas a serem
                    **                      consideradas
                    **      'nome_arq_base' - nome do arquivo lógico base
                    **                      de manipulação
                    **	Valor retornado:
                    **		Não possui retorno especificado
                    ********************************************************/
                        void criar (int ordem, string nome_arq_base);

                    /********************************************************
                    **	Função:
                    **		Liberação da Árvore-B
                    **	Descrição:
                    **		Libera a memória da árvore-B
                    **	Parâmetros:
                    **		Não exige
                    **	Valor retornado:
                    **		Não possui retorno especificado
                    ********************************************************/
                        void libera ();

                    /********************************************************
                    **	Função:
                    **		Inicialização da Árvore-B
                    **	Descrição:
                    **		Faz a inicialização da árvore, lendo os registros
                    **      do arquivo-base
                    **	Parâmetros:
                    **		Não exige
                    **	Valor retornado:
                    **		Não possui retorno especificado
                    ********************************************************/
                        void inicializa ();

                    /********************************************************
                    **	Função:
                    **		Inserção de chaves na árvore
                    **	Descrição:
                    **		Insere uma nova chave na árvore, respeitando a
                    **      teoria sobre a manipulação sobre este tipo de
                    **      árvore
                    **	Parâmetros:
                    **		'nova_ch'   - armazena a nova chave a ser inserida
                    **	Valor retornado:
                    **		Não possui retorno especificado
                    ********************************************************/
                        void insere (Info *nova_ch);

                    /********************************************************
                    **	Função:
                    **		Inserção de chaves na árvore e no arquivo
                    **	Descrição:
                    **		Insere uma nova chave na árvore, respeitando a
                    **      teoria sobre a manipulação sobre este tipo de
                    **      árvore, assim como a inserção no arquivo base
                    **	Parâmetros:
                    **		'registro'  - armazena as informações brutas,
                    **                  a serem inseridas no arquivo
                    **      'nova_ch'   - armazena a chave a ser inserida
                    **                  na árvore
                    **	Valor retornado:
                    **		Não possui retorno especificado
                    ********************************************************/
                        void insere_dupla (Dados registro, Info *nova_ch);

                        int busca (Info *);

                    /********************************************************
                    **	Função:
                    **		Exibição da Árvore-B
                    **	Descrição:
                    **		Exibe a Árvore-B na saída padrão
                    **	Parâmetros:
                    **		Não exige
                    **	Valor retornado:
                    **		Não possui retorno especificado
                    ********************************************************/
                        void exibe ();

                    /********************************************************
                    **	Função:
                    **		Impressão da Árvore-B
                    **	Descrição:
                    **		Escreve a Árvore-B num arquivo .txt de preferência
                    **      do usuário
                    **	Parâmetros:
                    **		'nome_arq'  - nome do arquivo a ser registrada a
                    **                  árvore
                    **	Valor retornado:
                    **		Não possui retorno especificado
                    ********************************************************/
                        void escreve (char *nome_arq);

                    /********************************************************
                    **	Função:
                    **		Impressão da Árvore-B
                    **	Descrição:
                    **		Escreve a Árvore-B num arquivo .txt para a
                    **      realização da busca
                    **	Parâmetros:
                    **		Não exige
                    **	Valor retornado:
                    **		Não possui retorno especificado
                    ********************************************************/
                        void escreve_busca ();

            private:
                /********************************************************
                **	Variáveis Privadas:
                **		'raiz'		- armazena a página raiz de ArvB;
                **		'qntpag'	- armazena a quantidade de páginas
                **                  cadastradas em ArvB;
                **      'ordem'     - armazena a ordem de ArvB;
                **      'ult_reg'   - armazena o seek do último registro
                **      'arq_base'  - armazena o arquivo lógico base de
                **                  manipulação
                ********************************************************/
                    Pagina *raiz;
                    int qntpag, ordem, ult_reg;
                    char *arq_base;

                /*****************************************************************
                **      Funções Privadas
                *****************************************************************/
                    /*****************************************************************
                    **      Funções Simplificadoras da Árvore
                    *****************************************************************/
                        /*  'raiz' define o acesso à raiz da árvoreB */
                            #define raiz() ArvB::raiz
                        /*  'qnt_pg' define o acesso à quantidade de páginas registradas */
                            #define qnt_pg() ArvB::qntpag
                        /*  'ordem' define o acesso à ordem da árvoreB */
                            #define ordem() ArvB::ordem
                        /*  'ult_reg' define o acesso ao último seek */
                            #define ult_reg() ArvB::ult_reg
                        /*  'arq_base' define o acesso ao arquivo lógico base */
                            #define arq_base() (ArvB::arq_base)
                    /*****************************************************************
                    **      Funções Simplificadoras da Página
                    *****************************************************************/
                        /*  'Inicio' define o acesso ao início da lista de
                        **  células registradas na página */
                            #define Inicio(x) (x->inicio)
                        /*  'Pai' define o acesso à página-pai da página
                        **  corrente */
                            #define Pai(x) (x->pai)
                        /*  'Num' define o acesso ao número de identificação
                        **  da página */
                            #define Num(x) (x->num)
                        /*  'Qnt_cel' define o acesso ao número de células
                        **  da página */
                            #define Qnt_cel(x) (x->qnt_cel)
                    /*****************************************************************
                    **      Funções Simplificadoras da Célula
                    *****************************************************************/
                        /*  'ID' define o acesso ao ID da chave armazena na célula */
                            #define ID(x) (x->chave.ID)
                        /*  'Seek' define o acesso ao PRR da chave armazena na célula */
                            #define Seek(x) (x->chave.seek)
                        /*  'Info' define o acesso à chave armazena na célula */
                            #define Info(x) (x->chave)
                        /*  'Proximo' define o acesso à próxima célula conectada
                        **  como 'irmã' */
                            #define Proximo(x) (x->prox)
                        /*  'Menores' define o acesso à página que possui chaves
                        **  menores que a chave corrente */
                            #define Menores(x) (x->menores)
                        /*  'Maiores' define o acesso à página que possui chaves
                        **  maiores que a chave corrente */
                            #define Maiores(x) (x->maiores)
                    /*****************************************************************
                    **      Funções Simplificadoras da Info
                    *****************************************************************/
                        /*  'Chave' define o acesso à chave do registro */
                            #define Chave(x) (x->ID)
                        /*  'Deslocamento' define o acesso ao PRR do registro */
                            #define Deslocamento(x) (x->seek)

                    /********************************************************
                    **	Função:
                    **		Criação de uma Página de Árvore-B
                    **	Descrição:
                    **		Aloca a memória para uma página de ArvB
                    **	Parâmetros:
                    **		Não exige
                    **	Valor retornado:
                    **		A página criada
                    ********************************************************/
                        Pagina * pag_criar ();

                    /********************************************************
                    **	Função:
                    **		Criação de uma Célula de uma Página da Árvore-B
                    **	Descrição:
                    **		Aloca a memória para uma célula
                    **	Parâmetros:
                    **		Não exige
                    **	Valor retornado:
                    **		A célula criada
                    ********************************************************/
                        Celula * cel_criar ();

                    /********************************************************
                    **	Função:
                    **		Liberação da memória
                    **	Descrição:
                    **		Desaloca a memória para uma página completa
                    **	Parâmetros:
                    **		'pg_atual'  - armazena a página a ser excluída
                    **      'cont'      - armazena a contagem da identação
                    **                  para exibição na saída padrão
                    **	Valor retornado:
                    **		Não possui retorno especificado
                    ********************************************************/
                        void pag_libera (Pagina *pg_atual, int cont);

                    /********************************************************
                    **	Função:
                    **		Inserção de chaves na árvore
                    **	Descrição:
                    **		Insere uma nova chave na árvore, respeitando a
                    **      teoria sobre a manipulação sobre este tipo de
                    **      árvore
                    **	Parâmetros:
                    **		'pg_at'     - armazena a página corrente para
                    **                  a análise da inserção
                    **      'nova_ch'   - armazena a nova chave a ser inserida
                    **	Valor retornado:
                    **		Não possui retorno especificado
                    ********************************************************/
                        void pag_insere (Pagina *pg_at, Info *nova_ch);

                    /********************************************************
                    **	Função:
                    **		Inserção de chaves na árvore, entre as células
                    **	Descrição:
                    **		Insere uma nova chave na árvore, respeitando a
                    **      teoria sobre a manipulação sobre este tipo de
                    **      árvore, considerando que a chave a ser inserida
                    **      é menor do que uma referência
                    **	Parâmetros:
                    **		'pg_pai'    - armazena a página corrente para
                    **                  a análise da inserção
                    **      'cel_at'    - armazena a célula corrente para
                    **                  a análise da inserção
                    **      'nova_ch'   - armazena a nova chave a ser inserida
                    **	Valor retornado:
                    **		Não possui retorno especificado
                    ********************************************************/
                        void cel_insere_menores (Pagina *pg_pai, Celula *cel_at, Info *nova_ch);

                    /********************************************************
                    **	Função:
                    **		Inserção de chaves na árvore, entre as células
                    **	Descrição:
                    **		Insere uma nova chave na árvore, respeitando a
                    **      teoria sobre a manipulação sobre este tipo de
                    **      árvore, considerando que a chave a ser inserida
                    **      é maior do que uma referência
                    **	Parâmetros:
                    **		'pg_pai'    - armazena a página corrente para
                    **                  a análise da inserção
                    **      'cel_at'    - armazena a célula corrente para
                    **                  a análise da inserção
                    **      'nova_ch'   - armazena a nova chave a ser inserida
                    **	Valor retornado:
                    **		Não possui retorno especificado
                    ********************************************************/
                        void cel_insere_maiores (Pagina *pg_pai, Celula *cel_at, Info *nova_ch);

                    /********************************************************
                    **	Função:
                    **		Gerencia a promoção de chaves à raizes de outras
                    **	Descrição:
                    **		Dada uma chave e uma página, a chave é inserida
                    **      na página-pai desta página
                    **	Parâmetros:
                    **		'pg_at'     - armazena a página corrente para
                    **                  a promoção da chave
                    **      'cel_at'    - armazena a célula a ser promovida
                    **	Valor retornado:
                    **		Não possui retorno especificado
                    ********************************************************/
                        void pag_insere_pai (Pagina *pg_at, Celula *cel_at);

                        Celula * pag_busca (Pagina *, Info *, int *);

                    /********************************************************
                    **	Função:
                    **		Verifica a lotação de uma página
                    **	Descrição:
                    **		Verifica a necessidade de promoção de células
                    **      das páginas
                    **	Parâmetros:
                    **		'pg_at'     - armazena a página corrente para
                    **                  a promoção da chave
                    **	Valor retornado:
                    **		Não possui retorno especificado
                    ********************************************************/
                        void pag_avalia (Pagina *pg_at);

                    /********************************************************
                    **	Função:
                    **		Verifica referências
                    **	Descrição:
                    **		Verifica se todos os filhos referenciam os pais
                    **      corretos
                    **	Parâmetros:
                    **		'pg_pai'    - armazena a página-pai correta
                    **	Valor retornado:
                    **		Não possui retorno especificado
                    ********************************************************/
                        void pag_confere_pai (Pagina *pg_pai);

                    /********************************************************
                    **	Função:
                    **		Divide uma página
                    **	Descrição:
                    **		Divide uma página em duas, visto que a original
                    **      excedeu o limite
                    **	Parâmetros:
                    **		'pg_at'     - armazena a página original a ser
                    **                  dividida
                    **      'cel_at'    - armazena a chave pivô da separação
                    **      'cont'      - armazena a quantidade de chaves que
                    **                  permanecerão na 'pg_at'
                    **	Valor retornado:
                    **		Não possui retorno especificado
                    ********************************************************/
                        void cel_divide (Pagina *pg_at, Celula *cel_at, int cont);

                    /********************************************************
                    **	Função:
                    **		Exibição de uma página completa
                    **  Descrição:
                    **		Exibe uma página na saída padrão
                    **	Parâmetros:
                    **		'pg_atual'  - armazena a página a ser exibida
                    **      'cont'      - armazena o contador da identação
                    **	Valor retornado:
                    **		Não possui retorno especificado
                    ********************************************************/
                        void pag_exibe (Pagina *pg_at, int cont);

                    /********************************************************
                    **	Função:
                    **		Impressão de uma página completa
                    **  Descrição:
                    **		Imprime uma página num arquivo de texto .txt
                    **	Parâmetros:
                    **      'arq'       - armazena o arquivo lógico
                    **		'pg_atual'  - armazena a página a ser exibida
                    **      'cont'      - armazena o contador da identação
                    **	Valor retornado:
                    **		Não possui retorno especificado
                    ********************************************************/
                        void pag_escreve (FILE *, Pagina *, int);


                        void pag_escreve_busca (FILE *, Pagina *);

                    /********************************************************
                    **	Função:
                    **		Copia de informaçãoes
                    **  Descrição:
                    **		Copia de todos os parâmetros importantes de uma
                    **      chave
                    **	Parâmetros:
                    **      'destino'   - armazena a chave que receberá
                    **                  os dados
                    **		'fonte'     - armazena a chave que fornecerá
                    **                  os dados
                    **	Valor retornado:
                    **		Não possui retorno especificado
                    ********************************************************/
                        void info_copia (Info *destino, Info *fonte);
        };
#endif // ArvoreB_h
