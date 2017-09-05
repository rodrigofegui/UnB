#include "../../Bibliotecas/Dominio/Nome.hpp"

void Nome::validar (const string &campo) throw (invalid_argument, length_error){
    if(!Manipulacao::noLimite(campo, TAM_MAX))
        throw new length_error (msgErroTam);
}
