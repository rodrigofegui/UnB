#ifndef SERV_CTRL_EST_TST_HPP
    #define SERV_CTRL_EST_TST_HPP

    /**
     *  @file   ServEst_Tst.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../../Bibliotecas/Interfaces/InterSEst.hpp"

    /**
     *  @class  ServEstTst
     *  Simulação da camada de serviço para a
     *  funcionalidade da Estante
     */
    class ServEstTst : public InterSEst{
        private:
            /*  Constantes de construção */
            const static string LIVRO_COD;
            const static string LIVRO_DAT;
            const static string LIVRO_GEN;
            const static string LIVRO_NOM;
            const static string LIVRO_TIT;
            const static string LIVRO_TIT_RES;
            const static string LIVRO_TXT_RES;

            const static string USUAR_NOM;
            const static string USUAR_APE;
            const static string USUAR_TEL;
            const static string USUAR_PSS;

            /*  Constantes de trabalho */
            const static string DIVISOR;
            const static string INICIO_P;
            const static string TERMINACAO_P;
            const static string TERMINACAO_F;
            const static bool   INSERCAO;

            /*  Mensagens padrão */
            const static string MSG_INI_CON;
            const static string MSG_INI_CRS;
            const static string MSG_INI_INC;
            const static string MSG_INI_RMV;
			const static string MSG_INI_STC;
			const static string MSG_INI_PRO;

            const static string MSG_SUC_CRS;
            const static string MSG_SUC_CON;
            const static string MSG_SUC_INC;
            const static string MSG_SUC_RMV;
			const static string MSG_SUC_STC;
			const static string MSG_SUC_PRO;

            const static string MSG_FLH_CON_L;
            const static string MSG_FLH_CON_U;
            const static string MSG_FLH_CRS;
            const static string MSG_FLH_INC;
            const static string MSG_FLH_RMV;
			const static string MSG_FLH_STC;
			const static string MSG_FLH_PRO;
            const static string MSG_EBD;

            /*	Mensagem para o início das operações */
            static string msgInicio (const DominioBase &, bool);
            static string msgInicio (const Titulo &, bool);
			static string msgInicio (const Titulo &);
            static string msgInicio (const Titulo &, const Resenha &);
            static string msgInicio (const Livro &);

            /*  Construção dos resultados */
            Livro*   criarLivro();
            Resenha* criarResenha();
            Usuario* criarUsuario();

        public:
            /** Gatilho de Livro Existente */
            const static string LIVRO_EXI;
            /** Gatilho de Falha de comunicação com a
             *  Base de Dados, para livro */
            const static string LIVRO_EBD;
            /** Gatilho de Livro Existente */
            const static string USUARIO_EXI;
            /** Gatilho de Falha de comunicação com a
             *  Base de Dados, para usuários */
            const static string USUARIO_EBD;

            /*  Métodos da interface */
            Resultado consultar (const Titulo &) throw (runtime_error);
            Resultado consultar (const Apelido &) throw (runtime_error);
            Resultado criarResenha (const Titulo &, const Resenha &) throw (runtime_error);
            Resultado incluir (const Livro &) throw (runtime_error);
			Resultado procurar (const Titulo &)  throw (runtime_error);
            Resultado remover (const Titulo &) throw (runtime_error);
            Resultado sinTroca (const Apelido &, const Titulo &, const bool &) throw (runtime_error);
    };
#endif // SERV_CTRL_EST_TST_HPP
