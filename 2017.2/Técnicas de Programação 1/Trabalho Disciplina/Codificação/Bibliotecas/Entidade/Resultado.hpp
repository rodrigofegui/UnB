#ifndef RESULTADO_HPP
    #define RESULTADO_HPP

    /**
     *  @file   Resultado.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../Dominio/DominioBase.hpp"
	#include "Login.hpp"
	#include "Usuario.hpp"

    /**
     *  @class  Resultado
     *  Resultado de operações aceitos na estante digital
     */
    class Resultado : public DominioBase{
        private:
			/*	Entidades/Domínios como resultado */
			Apelido *apelido = nullptr;
			Login	*login = nullptr;
			Usuario *usuario = nullptr;

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
			/**	Sinalização de falha de cadastramento de usuário */
			const static string FLH_CAD;
			/**	Sinalização de falha na Base de Dados */
			const static string FLH_BD;

            /** Selecionada a opção de autenticar */
            const static string ESC_AUTENTICAR;
            /** Selecionada a opção de cadastrar */
            const static string ESC_CADASTRAR;
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
			Resultado (Usuario *);

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
             *  Destrutor padrão
             */
            void deletar() override;
    };

	/*  Definição dos métodos 'Get' */
	inline Login* Resultado::getLogin () const {return this->login;}
	inline Apelido* Resultado::getApelido () const {return this->apelido;}
	inline Usuario* Resultado::getUsuario () const {return this->usuario;}

	/*  Definição dos métodos 'Set' */
	inline void Resultado::setLogin (Login *login) {this->login = login;}
	inline void Resultado::setApelido (Apelido *apelido) {this->apelido = apelido;}
	inline void Resultado::setUsuario (Usuario *usuario) {this->usuario = usuario;}
#endif // RESULTADO_HPP
