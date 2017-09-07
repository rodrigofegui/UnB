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
    return noLimite(src.size(), lim);
}

bool Manipulacao::noLimite(int alvo, int lim){
    if (alvo <= lim)
        return TesteUnitario::PASSOU;

    return TesteUnitario::FALHOU;
}

bool Manipulacao::intervaloF(int alvo, int minimo, int maximo){
    if ((alvo >= minimo) && (alvo <= maximo))
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

bool Manipulacao::ePar (int alvo){
    if (alvo%2)
        return TesteUnitario::PASSOU;

    return TesteUnitario::FALHOU;
}

bool Manipulacao::localizar(vector<int> grupo, int alvo){
    for (int pos = 0; pos < grupo.size(); pos++)
        if (grupo.at(pos) == alvo)
            return TesteUnitario::PASSOU;

    return TesteUnitario::FALHOU;
}

bool Manipulacao::localizar(vector<string> grupo, string alvo){
    for (int pos = 0; pos < grupo.size(); pos++)
        if (grupo.at(pos) == alvo)
            return TesteUnitario::PASSOU;

    return TesteUnitario::FALHOU;
}

bool Manipulacao::eBissexto (int ano){
    if ((!(ano%4) && (ano%100))
        || !(ano%400))
        return TesteUnitario::PASSOU;

    return TesteUnitario::FALHOU;
}

bool Manipulacao::haRepeticao(string src){
    src = maiuscula(src);

    for (int pos = 0; pos < src.size(); pos++)
        if(src.find(src.at(pos), pos + 1) != -1)
            return TesteUnitario::PASSOU;

    return TesteUnitario::FALHOU;
}
