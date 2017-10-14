#include "../../Bibliotecas/Entidade/Log.hpp"

const string Log::DIR_PADRAO    ("Logs/");
//const string Log::DIR_PADRAO    ("../../../Logs/");

const string Log::FMT_DATA      ("%d-%b-%Y");       // 01-jan-2000
const string Log::FMT_HORA      ("%H:%M:%S");       // 00:00:00

string Log::diretorio   (Log::DIR_PADRAO);
string Log::nome        (Log::nomePadrao());

Log::Log (){
    setDiretorio (Log::DIR_PADRAO);
    setNome (Log::nomePadrao());
}

Log::Log(string diretorio){
    Log ();
    setDiretorio (diretorio);
}

Log::Log(string diretorio,
         string nome){
    setDiretorio (diretorio);
    setNome (nome);
}

void Log::iniciar (){
    ofstream arqLog (getDiretorio() + getNome());

    arqLog << "Arquivo de Log" << endl;
    arqLog << "Registro: Manipulação da Estante Digital" << endl;
    arqLog << "Data: " + getData() << endl;
    arqLog << "Inicio da atividade: " + getHora() << endl << endl;
    arqLog << "Atividades:" << endl;

    arqLog.close ();
}


string Log::nomePadrao (){
    string nome = getData() + ".log";

    return nome;
}

void Log::escrever (string msg){
    ofstream arqLog (getDiretorio() + getNome(), ios::app);

    arqLog << "[" + getHora() + "] " + msg << endl;

    arqLog.close ();
}

string Log::getTempo (const string &frmt){
    auto t = time (nullptr);
    auto tm = *localtime (&t);

    std::ostringstream oss;
    oss << put_time (&tm, frmt.c_str());
    return oss.str();
}

string Log::getData (){
    return getTempo (Log::FMT_DATA);
}

string Log::getHora (){
    return getTempo (Log::FMT_HORA);
}
