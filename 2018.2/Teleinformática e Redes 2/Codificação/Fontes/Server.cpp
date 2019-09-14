#include "../Bibliotecas/Server.hpp"

int creatSocket () throw (){
	return creatSocket (AF_INET, SOCK_STREAM, 0);
}

int creatSocket (int dominio) throw (){
	return creatSocket (dominio, SOCK_STREAM, 0);
}

int creatSocket (int dominio, int tipo) throw (){
	return creatSocket (dominio, tipo, 0);
}

int creatSocket (int dominio, int tipo, int protocolo) throw (){
	int descritor = socket(dominio, tipo, protocolo);
}