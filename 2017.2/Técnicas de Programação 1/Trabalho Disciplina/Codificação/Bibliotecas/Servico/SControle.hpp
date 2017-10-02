#ifndef SERV_CONTROLE_HPP
    #define SERV_CONTROLE_HPP

    /**
     *  @file   SControle.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../Interfaces/InterCntrl.hpp"

    /**
     *  @class  SControle
     *  Controle da aplicação, na camada de Serviço
     */
    class SControle : public InterCntrl{

        public:
            /**
             *  Construtor padrão
             */
            SControle (){};
    };
#endif // SERV_CONTROLE_HPP
