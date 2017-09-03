#include "../../Bibliotecas/Utilidades/Manipulacao.hpp"

string Manipulacao::maiuscula (string src){
    for(unsigned int pos = 0; pos < src.size(); pos++)
        src.at(pos) = toupper(src.at(pos));

    return src;
}

string Manipulacao::minuscula (string src){
    for(unsigned int pos = 0; pos < src.size(); pos++)
        src.at(pos) = tolower(src.at(pos));

    return src;
}

bool Manipulacao::tam(string src, int tam){
    if (src.size() == tam)
        return TesteUnitario::PASSOU;

    return TesteUnitario::FALHOU;
}

bool Manipulacao::noLimite (string src, int lim){
    if (src.size() <= lim)
        return TesteUnitario::PASSOU;

    return TesteUnitario::FALHOU;
}

bool Manipulacao::haNum (string src){
    for (int pos = 0; pos < src.length(); pos++)
        if (isdigit(src.at(pos)))
            return TesteUnitario::PASSOU;

    return TesteUnitario::FALHOU;
}

bool Manipulacao::eAlfabetico (string src){
    for (int pos = 0; pos < src.length(); pos++)
        if (!isalpha(src.at(pos)))
            return TesteUnitario::FALHOU;

    return TesteUnitario::PASSOU;
}

bool Manipulacao::eNum (string src){
    for (int pos = 0; pos < src.length(); pos++)
        if (!isdigit(src.at(pos)))
            return TesteUnitario::FALHOU;

    return TesteUnitario::PASSOU;
}
