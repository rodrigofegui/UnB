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
            /*  Mensagens padrão */
            const static string MSG_INI;
            const static string MSG_SUC;
            const static string MSG_EBD;
            const static string MSG_L_INE;

			/*	Mensagem para o inicio da autenticação */
            static string msgInicio (const Login &);

        public:
            /** Gatilho de Apelido Inexitente */
            const static string LOGIN_INE;
            /** Gatilho de Falha comunicação com a Base de Dados */
            const static string LOGIN_EBD;

            Resultado autenticar (const Login &) throw (runtime_error);
    };
#endif // SERV_CTRL_AUT_TST_HPP
