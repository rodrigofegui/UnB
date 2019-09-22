#ifndef BASICOS_TIPOS_H
    #define BASICOS_TIPOS_H
    /**
     *  @file   tipos.h
     *  @author Rodrigo F. Guimarães
     *  @brief Definição dos tipos básicos a serem utilizados
     */

    #include <stdint.h>

    /** Tipo básico para 1 byte sem sinal */
    typedef uint8_t u1;
    /** Tipo básico para 2 bytes sem sinal */
    typedef uint16_t u2;
    /** Tipo básico para 4 bytes sem sinal */
    typedef uint32_t u4;

    /** Dados identificadores de uma classe
     *  JAVA na `constante_pool` */
    typedef struct info_classe {
        u1 tag;
        u2 ind_nome;
    } InfoClasse;

    /** Dados identificadores de um campo
     *  `constante_pool` */
    typedef struct info_ref_campo {
        u2 ind_classe;
        u2 ind_nome_tipo;
    } InfoRefCampo;

    /** Dados identificadores de um nome
     *  e de um tipo na `constante_pool` */
    typedef struct info_nome_tipo {
        u2 ind_nome;
        u2 ind_descritor;
    } InfoNomeTipo;

    /** Dados identificadores de uma string
     *  codificada em UTF-8 na `constante_pool` */
    typedef struct info_utf8 {
        u2 tam;
        u1* bytes;
    } InfoUTF8;

    /** Dados identificadores de um método
     *  na `constante_pool` */
    typedef struct info_mtd {
        u2 ind_classe;
        u2 ind_nome_tipo;
    } InfoMetodo;

    /** Dados identificadores de um método
     *  de interface na `constante_pool` */
    typedef struct info_mtd_itf {
        u2 ind_classe;
        u2 ind_nome_tipo;
    } InfoMetodoInterface;

    /** Dados identificadores de uma referência
     *  para uma string na `constante_pool` */
    typedef struct info_string{
        u2 ind_str;
    } InfoString;

    /** Dados identificadores de um `int`
     *  na `constante_pool` */
    typedef struct info_int {
        u4 bytes;
    } InfoInt;

    /** Dados identificadores de um `float`
     *  na `constante_pool` */
    typedef struct info_float {
        u4 bytes;
    } InfoFloat;

    /** Dados identificadores de um `long`
     *  na `constante_pool` */
    typedef struct info_long {
        u4 bytes_mais;
        u4 bytes_menos;
    } InfoLong;

    /** Dados identificadores de um `double`
     *  na `constante_pool` */
    typedef struct info_double {
        u4 bytes_mais;
        u4 bytes_menos;
    } InfoDouble;

    /** Dados lidos a partir da `constante_pool` */
    typedef struct cp_info {
        u1 tag;
        union dados_cp_info {
            InfoClasse classe;
            InfoRefCampo ref_campo;
            InfoNomeTipo nome_tipo;
            InfoUTF8 utf_8;
            InfoMetodo metodo;
            InfoMetodoInterface metodo_interface;
            InfoString string;
            InfoInt inteiro;
            InfoLong longo;
            InfoDouble duplo;
        } dados;
    } CPInfo;

#endif
