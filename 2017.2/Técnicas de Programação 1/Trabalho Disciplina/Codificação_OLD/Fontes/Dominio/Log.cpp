#include "../../Bibliotecas/Dominio/Log.hpp"

const string Log::DIR_PADRAO ("../../Log/");

Log::Log(fstream arqLog){
    setArqLog(arqLog);
}

fstream Log::getArqlog() const{
    return arqLog;
}

void Log::setArqLog (const fstream &arqLog){
    arqLog = arqLog;
}

string Log::getData(){
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    ostringstream os;
    os << put_time(&tm, "%d/%m/%Y");

    return os.str();
}

string Log::getHora(){
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    ostringstream os;
    os << put_time(&tm, "%H:%M:%S");

    return os.str();
}

void Log::escreverMsg (const string &msg){
    arqLog << getHora() + "\t" + msg;
}

fstream Log::criarArq(){
    try{
        string dir = DIR_PADRAO + getData() + ".txt";
        fstream novo (dir.c_str());

        return novo;
    }catch (...){
        cout << "Falha arquivo!" << endl;
    }
}

void Log::deletar(){
    if(arqLog.is_open()) arqLog.close();

    delete this;
}
