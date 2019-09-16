#ifndef Vetor_hpp
    #define Vetor_hpp

    #define VERDADE 1
    #define MENTIRA 0

    typedef int info;
    typedef struct elem{
        info dado;
        int indice;
    }
    tpDado;

    tpDado procura (info *, info);

    tpDado primeiro (info *);

    bool terminou (info *, tpDado);

    info obtervalor (tpDado);

    bool compara (info, info);

    tpDado definirproximo (info *, tpDado);

    tpDado estadonulo ();

#endif // Vetor_hpp
