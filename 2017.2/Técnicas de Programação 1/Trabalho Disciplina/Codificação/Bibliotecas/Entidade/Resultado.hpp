#ifndef RESULTADO_HPP
    #define RESULTADO_HPP

    /**
     *  @file   Resultado.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../Dominio/DominioBase.hpp"
	#include "Livro.hpp"
	#include "Login.hpp"
	#include "Resenha.hpp"
	#include "Usuario.hpp"

    /**
     *  @class  Resultado
     *  Resultado de operações aceitos na estante digital
     */
    class Resultado : public DominioBase{
        private:
			/*	Entidades/Domínios como resultado */
			Apelido *apelido = nullptr;
			Livro	*livro = nullptr;
			Login	*login = nullptr;
			Resenha *resenha = nullptr;
			Titulo  *titulo = nullptr;
			Usuario *usuario = nullptr;
			bool	disponibilidade = false;

            void validar (const string &campo) throw (invalid_argument) override{};

        public:
            /** Sinalização do sucesso */
            const static string SUCESSO;
            /** Sinalização de falha */
            const static string FALHA;
            /** Sinalização de falha por atingir limite */
            const static string FLH_LIM;
			/** Sinalização de falha de autenticação de usuário */
            const static string FLH_AUT;
			/**	Sinalização de falha na Base de Dados */
			const static string FLH_BD;
			/**	Sinalização de falha de cadastramento de usuário */
			const static string FLH_CAD;
			/**	Sinalização de falha de consulta */
			const static string FLH_CON;
			/**	Sinalização de falha de criação */
			const static string FLH_CRI;
			/**	Sinalização de falha de inserção */
			const static string FLH_INC;
			/**	Sinalização de falha de inserção */
			const static string FLH_RMV;
			/**	Sinalização de falha de sinalização de troca */
			const static string FLH_STC;
			/**	Sinalização de falha de procra por troca */
			const static string FLH_PRO;

            /** Selecionada a opção de autenticar */
            const static string ESC_AUTENTICAR;
            /** Selecionada a opção de cadastrar */
            const static string ESC_CADASTRAR;
			/** Selecionada a opção de consultar livro */
			const static string ESC_CONS_LIVRO;
			/** Selecionada a opção de consultar usuário */
			const static string ESC_CONS_USR;
			/** Selecionada a opção de consultar troca */
			const static string ESC_CONS_TRC;
			/** Selecionada a opção de criar resenha */
			const static string ESC_CRI_RES;
			/** Selecionada a opção de inserir exemplar de livro */
			const static string ESC_INC_LIVRO;
			/** Selecionada a opção de remover exemplar de livro */
			const static string ESC_RMV_LIVRO;
			/** Selecionada a opção de sinalizar
			 *	disponibilidade de troca de livro */
			const static string ESC_SIN_TROCA;
            /** Selecionada a opção de sair */
            const static string ESC_SAIR;

            /**
             *  Construtor padrão
             */
            Resultado ();

            /**
             *  Construtor de um Resultado, conhecendo-se
             *  o mesmo
             *  @param Resultado a ser conferido
             */
            Resultado (const string &);

			/**
			 *  Construtor de um Resultado, conhecendo-se
			 *  o mesmo
			 *  @param Resultado a ser conferido
			 */
			Resultado (Livro *);

			/**
			 *  Construtor de um Resultado, conhecendo-se
			 *  o mesmo
			 *  @param Resultado a ser conferido
			 */
			Resultado (Livro *, Resenha *);

			/**
			 *  Construtor de um Resultado, conhecendo-se
			 *  o mesmo
			 *  @param Resultado a ser conferido
			 */
			Resultado (Titulo *, Resenha *);

			/**
			 *  Construtor de um Resultado, conhecendo-se
			 *  o mesmo
			 *  @param Resultado a ser conferido
			 */
			Resultado (Titulo *, const bool &);

			/**
			 *  Construtor de um Resultado, conhecendo-se
			 *  o mesmo
			 *  @param Resultado a ser conferido
			 */
			Resultado (Login *);

			/**
			 *  Construtor de um Resultado, conhecendo-se
			 *  o mesmo
			 *  @param Resultado a ser conferido
			 */
			Resultado (Apelido *);

			/**
			 *  Construtor de um Resultado, conhecendo-se
			 *  o mesmo
			 *  @param Resultado a ser conferido
			 */
			Resultado (Titulo *);

			/**
			 *  Construtor de um Resultado, conhecendo-se
			 *  o mesmo
			 *  @param Resultado a ser conferido
			 */
			Resultado (Usuario *);

			/**
			 *  Atribuição do apelido do Resultado
			 *  @param Apelido a ser atribuído
			 */
			void setApelido (Apelido *);

			/**
			 *  Recuperar o valor atribuído ao apelido do Resultado
			 *  @return Login armazenado no Resultado
			 */
			Apelido * getApelido () const;

			/**
			 *  Atribuição da disponibilidade do Resultado
			 *  @param disponibilidade a ser atribuída
			 */
			void setDisponibilidade (const bool &);

			/**
			 *  Recuperar o valor atribuído à disponibilidade do Resultado
			 *  @return disponibilidade armazenada no Resultado
			 */
			bool getDisponibilidade () const;

			/**
             *  Atribuição do livro do Resultado
             *  @param Livro a ser atribuído
             */
			void setLivro (Livro *);

			/**
             *  Recuperar o valor atribuído ao livro do Resultado
             *  @return Livro armazenado no Resultado
             */
			Livro * getLivro () const;

			/**
             *  Atribuição do login do Resultado
             *  @param Login a ser atribuído
             */
			void setLogin (Login *);

			/**
             *  Recuperar o valor atribuído ao login do Resultado
             *  @return Login armazenado no Resultado
             */
			Login * getLogin () const;

			/**
             *  Atribuição da resenha do Resultado
             *  @param Resenha a ser atribuída
             */
			void setResenha (Resenha *);

			/**
             *  Recuperar o valor atribuído à resenha do Resultado
             *  @return Resenha armazenada no Resultado
             */
			Resenha * getResenha () const;

			/**
             *  Atribuição do título do Resultado
             *  @param Título a ser atribuído
             */
			void setTitulo (Titulo *);

			/**
             *  Recuperar o valor atribuído ao título do Resultado
             *  @return Titulo armazenado no Resultado
             */
			Titulo * getTitulo () const;

			/**
			 *  Atribuição do usuario do Resultado
			 *  @param Usuario a ser atribuído
			 */
			void setUsuario (Usuario *);

			/**
			 *  Recuperar o valor atribuído ao usuario do Resultado
			 *  @return Usuario armazenado no Resultado
			 */
			Usuario * getUsuario () const;

			/**
             *  Verificar se dois resultados são iguais
             *  @param alvo Resultado alvo de comparação
             *  @return PASSOU ou FALHOU
             */
			bool equals (const Resultado &);

			/**
			 *	Limpeza do Resultado, tornando-o
			 *	num vazio
			 */
			void clear ();

            /**
             *  Destrutor padrão
             */
            void deletar() override;
    };

	/*  Definição dos métodos 'Get' */
	inline Apelido* Resultado::getApelido () const {return this->apelido;}
	inline bool Resultado::getDisponibilidade () const {return this->disponibilidade;}
	inline Livro* Resultado::getLivro () const {return this->livro;}
	inline Login* Resultado::getLogin () const {return this->login;}
	inline Resenha* Resultado::getResenha () const {return this->resenha;}
	inline Titulo* Resultado::getTitulo () const {return this->titulo;}
	inline Usuario* Resultado::getUsuario () const {return this->usuario;}

	/*  Definição dos métodos 'Set' */
	inline void Resultado::setApelido (Apelido *apelido) {this->apelido = apelido;}
	inline void Resultado::setDisponibilidade (const bool &disponibilidade) {this->disponibilidade = disponibilidade;}
	inline void Resultado::setLivro (Livro *livro) {this->livro = livro;}
	inline void Resultado::setLogin (Login *login) {this->login = login;}
	inline void Resultado::setResenha (Resenha *resenha) {this->resenha = resenha;}
	inline void Resultado::setTitulo (Titulo *titulo) {this->titulo = titulo;}
	inline void Resultado::setUsuario (Usuario *usuario) {this->usuario = usuario;}
#endif // RESULTADO_HPP
