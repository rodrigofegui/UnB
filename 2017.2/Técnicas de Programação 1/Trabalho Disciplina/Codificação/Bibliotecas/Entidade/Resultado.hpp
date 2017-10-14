#ifndef RESULTADO_HPP
    #define RESULTADO_HPP

    /**
     *  @file   Resultado.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../Dominio/DominioBase.hpp"
	#include "Login.hpp"

    /**
     *  @class  Resultado
     *  Resultado de operações aceitos na estante digital
     */
    class Resultado : public DominioBase{
        private:
			/*	Entidades/Domínios como resultado */
			Login	*login;

            void validar (const string &campo) throw (invalid_argument) override;

        public:
            /** Sinalização do sucesso */
            const static string SUCESSO;
            /** Sinalização de falha */
            const static string FALHA;
            /** Sinalização de falha por atingir limite */
            const static string FLH_LIM;

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
             *  Atribuição do login do Resultado
             *  @param Login a ser atribuído
             */
			void setLogin (Login *);

			/**
             *  Recuperar o valor atribuído ao login do Resultado
             *  @return Login armazenado na Resenha
             */
			Login * getLogin () const;

            /**
             *  Destrutor padrão
             */
            void deletar() override;
    };

	/*  Definição dos métodos 'Get' */
	inline Login * Resultado::getLogin () const {return this->login;}

	/*  Definição dos métodos 'Set' */
	inline void Resultado::setLogin (Login *login) {this->login = login;}
#endif // RESULTADO_HPP
