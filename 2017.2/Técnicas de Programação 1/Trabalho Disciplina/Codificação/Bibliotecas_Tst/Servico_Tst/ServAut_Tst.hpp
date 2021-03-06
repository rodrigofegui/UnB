#ifndef SERV_CTRL_AUT_TST_HPP
    #define SERV_CTRL_AUT_TST_HPP

    /**
     *  @file   ServAut_Tst.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../../Bibliotecas/Interfaces/InterSAut.hpp"

    /**
     *  @class  ServAutTst
     *  Simulação da camada de serviço para a
     *  funcionalidade de Autenticação
     */
    class ServAutTst : public InterSAut{
        private:
            /*  Constantes de trabalho */
            const static string DIVISOR;
            const static string TERMINACAO;

            /*  Mensagens padrão */
            const static string MSG_INI;

			/*	Mensagem para o inicio da autenticação */
            static string msgInicio (const Login &);

        public:
            /** Gatilho de Apelido Exitente */
            const static string LOGIN_EXI;
            /** Gatilho de Apelido Inexitente */
            const static string LOGIN_INE;
            /** Gatilho de Falha comunicação com a Base de Dados */
            const static string LOGIN_EBD;

            Resultado autenticar (const Login &) throw (runtime_error);
    };
#endif // SERV_CTRL_AUT_TST_HPP
