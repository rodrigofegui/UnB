#ifndef DOMINIO_BASE_TST_H
    #define DOMINIO_BASE_TST_H

    /**
     *  @file   DominioBase_Tst.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../../Bibliotecas/Dominio/DominioBase.hpp"
    #include "../TesteClasse.hpp"

    /**
     *  @class  DominioBaseTst
     *  Responsável por implementar o protocolo de teste
     *  para os domínios base desenvolvidos, além de agrupar
     *  as condições e os processos comuns a todos os domínios
     */
    class DominioBaseTst : public TesteClasse{
        private:
            /*  Etapas de teste */
            void finalizar() override;

        protected:
            /**
             *  Domínio a ser testado em vários cenários */
            DominioBase *corpoTeste;

            /**
             *  Validar o domínio sob testo quando é submetido
             *  um argumento válido
             *  @param campo Campo a priori válido para o domínio
             */
            void validarCampoOk (const string &campo);

            /**
             *  Validar o domínio sob testo quando é submetido
             *  um argumento inválido
             *  @param campo Campo a priori inválido para o domínio
             */
            void validarCampoNOk (const string &campo);
    };
#endif // DOMINIO_BASE_TST_H
