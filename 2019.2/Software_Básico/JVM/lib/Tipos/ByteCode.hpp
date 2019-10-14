#ifndef TIPOS_BYTE_CODE_HPP
    #define TIPOS_BYTE_CODE_HPP

    #include <string>
    #include <vector>
    #include "Basicos.hpp"

    typedef struct bc {
        std::string mnemonico;
        void (*exibidor) (std::vector<u1>);
        void (*interpretador) (std::vector<u1>);
    } ByteCode;

    extern std::vector<ByteCode> bytecodes;

    void iniciar_bytecodes ();
#endif
