#ifndef APRES_CTRL_USU_HPP
    #define APRES_CTRL_USU_HPP

    /**
     *  @file   AUsu.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../TUI.hpp"
    #include "../../Interfaces/InterFunc.hpp"
    #include "../../Interfaces/InterSUsu.hpp"

    /**
     *  @class  AUsu
     *  Controladora da funcionalidade de Usuário
     *  de usuário à estante virtual.
     */
    class AUsu : public TUI, public InterFunc{
        private:
            Apelido     apelido;
            Usuario     *usuario = nullptr;
            InterSUsu   *servico = nullptr;

            /*  Métodos herdados */
            Resultado direcionar (const Resultado &);
            Resultado leitura ();
            Resultado tratarErro ();
            Resultado tratarErro (const Resultado &);
			void finalizar ();
    };
#endif // APRES_CTRL_USU_HPP
