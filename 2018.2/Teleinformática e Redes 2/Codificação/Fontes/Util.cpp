#include "../Bibliotecas/Util.hpp"

void checkArg (int expQnt, int argQnt) throw (const std::length_error&){
	if (argQnt < expQnt)
		throw std::length_error ("Quantidade insuficiente.");
	
	if (argQnt > expQnt)
		throw std::length_error ("Quantidade mais do que o necessário.");
}

/*
4278-1
1360-9
*/