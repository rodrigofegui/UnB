#include "../../Bibliotecas/Dominio/DominioBase.hpp"

void DominioBase::setCampo(const string &campo) throw (invalid_argument, length_error){
    validar (campo);
    this->campo = campo;
}

bool DominioBase::equals(const DominioBase &alvo) const{
    if(this->getCampo() == alvo.getCampo())
        return TesteUnitario::PASSOU;

    return TesteUnitario::FALHOU;
}
