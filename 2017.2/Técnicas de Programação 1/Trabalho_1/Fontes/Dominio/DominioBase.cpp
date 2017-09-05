#include "../../Bibliotecas/Dominio/DominioBase.hpp"

void DominioBase::setCampo(const string &campo) throw (invalid_argument, length_error){
    validar (campo);
    this->campo = campo;
}
