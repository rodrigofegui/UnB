#ifndef SERVER_HPP
    #define SERVER_HPP

    /**
     *  @file   Server.hpp
     *  @author Rodrigo F. Guimarães
     *  @brief  Responsável por controlar os status dos socketes.
     */
    #include <iostream>
    #include <sys/socket.h> 

	/**
	 * Criação do descritor de arquivo para o socket
	 * @result 
	 */
	int creatSocket () throw ();
	int creatSocket (int dominio) throw ();
	int creatSocket (int dominio, int tipo) throw ();
	int creatSocket (int dominio, int tipo, int protocolo) throw ();

#endif /* SERVER_HPP */