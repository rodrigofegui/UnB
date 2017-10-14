#ifndef SERV_CTRL_USU_TST_HPP
    #define SERV_CTRL_USU_TST_HPP

    /**
     *  @file   ServUsu_Tst.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../../Bibliotecas/Interfaces/InterSUsu.hpp"

    /**
     *  @class  ServUsuTst
     *  Simulação da camada de serviço para a
     *  funcionalidade de Usuário
     */
    class ServUsuTst : public InterSUsu{
        private:
            /*  Constantes de trabalho */
            const static string DIVISOR;
            const static string TERMINACAO;

            /*  Mensagens padrão */
            const static string MSG_SUC;
            const static string MSG_INI;
            const static string MSG_CADST_EXT;
            const static string MSG_CADST_EBD;

            /*  Mensagem para o início do cadastramento */
            static string msgInicio (const Usuario &);

        public:
            /** Gatilho para usuário já cadastrado */
            const static string CADST_EXT;
            /** Gatilho para falha de comunicação com a Base de Dados */
            const static string CADST_EBD;

            Resultado cadastrar (const Usuario &) throw (runtime_error);
    };
#endif // SERV_CTRL_USU_TST_HPP
