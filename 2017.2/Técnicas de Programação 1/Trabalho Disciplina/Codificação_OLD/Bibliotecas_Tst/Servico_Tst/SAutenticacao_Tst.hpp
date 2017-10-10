#ifndef SERV_AUTENTICACAO_HPP
    #define SERV_AUTENTICACAO_HPP

    /**
     *  @file   SAutenticacao_Tst.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../../Bibliotecas/Interfaces/InterAut.hpp"
    #include "../../Bibliotecas/Entidade/Login.hpp"

    /**
     *  @class SAutenticacaoTst
     *  Responsável pelo stub da autentificação do usuário,
     *  da camada de serviço.
     */
    class SAutenticacaoTst : public InterAut{
        private:
            /* Constante de teste: Login Aceito */
            const static Login VALIDO;
            /* Constante de teste: Login com falha nos dados */
            const static Login INV_DADOS;
            /* Constante de teste: Login com falha de acesso à Base de Dados */
            const static Login INV_BASE;

        public:
            OpResult autenticar (const Login &login) override;
    };
#endif // SERV_AUTENTICACAO_HPP
