#include <iostream>
#include "../Bibliotecas/Util.hpp"

int main (int argQnt, char* argVlr[]){
	try{
		checkArg(2, argQnt - 1);

	}catch (const std::length_error& e){
		std::cerr << e.what() << std::endl;
	}

	return 0;
}