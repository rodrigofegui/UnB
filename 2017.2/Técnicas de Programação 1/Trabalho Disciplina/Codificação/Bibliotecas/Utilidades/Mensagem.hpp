#ifndef MENSAGEM_HPP
    #define MENSAGEM_HPP

    /**
     *  @file   Mensagem.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include <string>
    using namespace std;

    /**
     *  @class  Mensagem
     *  Responsável por implementar as mensagens
     *  padrão a ser utilizadas
     */
    class Mensagem{
        public:
            /*  Mensagens de aquisição */
            /** Sinalização de sucesso na aquisição de
             *  um apelido */
            const static string AQS_APE;
            /** Sinalização de sucesso na aquisição de
             *  um autor */
            const static string AQS_ATR;
            /** Sinalização de sucesso na aquisição de
             *  uma data */
            const static string AQS_DAT;
            /** Sinalização de sucesso na aquisição de
             *  uma disponibilidade */
            const static string AQS_DSP;
            /** Sinalização de sucesso na aquisição de
             *  um nome */
            const static string AQS_NOM;
            /** Sinalização de sucesso na aquisição de
             *  um gênero */
            const static string AQS_GEN;
            /** Sinalização de sucesso na aquisição de
             *  uma senha */
            const static string AQS_SEN;
            /** Sinalização de sucesso na aquisição de
             *  um telefone */
            const static string AQS_TEL;
            /** Sinalização de sucesso na aquisição de
             *  um título */
            const static string AQS_TIT;
            /** Sinalização de sucesso na aquisição de
             *  um texto */
            const static string AQS_TXT;

            /*  Mensagens de criação */
            /** Sinalização no sucesso na criação de
             *  um Livro */
            const static string CRI_LVR;
            /** Sinalização no sucesso na criação de
             *  um Login */
            const static string CRI_LGN;
            /** Sinalização no sucesso na criação de
             *  um Usuário */
            const static string CRI_USR;
            /** Sinalização no sucesso na criação de
             *  uma Resenha */
            const static string CRI_RES;

            /*  Mensagens de início */
            /** Sinalização do início da atividade da Aplicação */
            const static string INI_APP;
            /** Sinalização do início da atividade da Aplicação
             *  de teste */
            const static string INI_APP_TST;
            /** Sinalização do início da função de Autenticar */
            const static string INI_AUT;
            /** Sinalização do início da função de Usuário */
            const static string INI_USR;
            /** Sinalização do início da função de Estante */
            const static string INI_EST;
            /** Sinalização do início do comando de consulta
             *  de livro da função de Estante */
            const static string INI_EST_CON_LVR;
            /** Sinalização do início do comando de consulta
             *  de usuário da função de Estante */
            const static string INI_EST_CON_USR;
            /** Sinalização do início do comando de consulta
             *  de troca da função de Estante */
            const static string INI_EST_CON_TRC;
            /** Sinalização do início do comando de criar
             *  resenha da função de Estante */
            const static string INI_EST_CRS;
            /** Sinalização do início do comando de inserção
             *  de livro da função de Estante */
            const static string INI_EST_INC_LVR;
            /** Sinalização do início do comando de remoção
             *  de livro da função de Estante */
            const static string INI_EST_RMV_LVR;
            /** Sinalização do início do comando de sinalizar
             *  troca de livro da função de Estante */
            const static string INI_EST_STR;
            /** Sinalização de teste */
            const static string INI_TST;

            /*  Mensagem de identificação */
            /** Sinalização de identificação de um Apelido */
            const static string LBL_APE;
            /** Sinalização de identificação de um Autor */
            const static string LBL_ATR;
            /** Sinalização de identificação de uma Data */
            const static string LBL_DAT;
            /** Sinalização de identificação de um Gênero */
            const static string LBL_GEN;
            /** Sinalização de identificação de um Nome */
            const static string LBL_NOM;
            /** Sinalização de identificação de um Telefone */
            const static string LBL_TEL;
            /** Sinalização de identificação de um Título */
            const static string LBL_TIT;

            /*  Mensagens de leitura */
            /** Sinalização do início da leitura dos dados
             *  a serem fornecidos pelo usuário */
            const static string LEITURA;
            /** Leitura da escolha feita pelo usuário */
            const static string LER_ESC;
            /** Leitura do apelido fornecido pelo usuário */
            const static string LER_APE;
            /** Leitura do autor fornecido pelo usuário */
            const static string LER_ATR;
            /** Leitura da data fornecida pelo usuário */
            const static string LER_DAT;
            /** Leitura da disponibilidade fornecida pelo usuário */
            const static string LER_DSP;
            /** Leitura do nome fornecido pelo usuário */
            const static string LER_NOM;
            /** Leitura do gênero fornecido pelo usuário */
            const static string LER_GEN;
            /** Leitura da senha fornecida pelo usuário */
            const static string LER_SEN;
            /** Leitura do telefone fornecido pelo usuário */
            const static string LER_TEL;
            /** Leitura do título fornecido pelo usuário */
            const static string LER_TIT;
            /** Leitura do título do livro fornecido pelo usuário */
            const static string LER_TIT_LVR;
            /** Leitura do título da resenha fornecido pelo usuário */
            const static string LER_TIT_RES;
            /** Leitura do texto fornecido pelo usuário */
            const static string LER_TXT;

            /*  Mensagens de redirecionamento */
            /** Sinalização de redirecionamento para Autenticar */
            const static string RED_AUT;
            /** Sinalização de redirecionamento para Usuário */
            const static string RED_USU;
            /** Sinalização de redirecionamento para Estante */
            const static string RED_EST;
            /** Sinalização de redirecionamento para Consultar
             *  Livro */
            const static string RED_EST_CON_LVR;
            /** Sinalização de redirecionamento para Consultar
             *  Usuário */
            const static string RED_EST_CON_USR;
            /** Sinalização de redirecionamento para Consultar
             *  Troca */
            const static string RED_EST_CON_TRC;
            /** Sinalização de redirecionamento para Criar
             *  Resenha */
            const static string RED_EST_CRS;
            /** Sinalização de redirecionamento para Inserir
             *  Livro */
            const static string RED_EST_INC_LVR;
            /** Sinalização de redirecionamento para Remover
             *  Livro */
            const static string RED_EST_RMV_LVR;
            /** Sinalização de redirecionamento para Sinalizar
             *  Disponibilidade ou não de Troca */
            const static string RED_EST_STR;

            /*  Mensagens de sucesso */
            /** Sinalização de sucesso na função Autenticar */
            const static string SUC_AUT;
            /** Sinalização de sucesso na função Usuário */
            const static string SUC_USR;
            /** Sinalização de sucesso no comando de consultar
             *  livro na função Estante */
            const static string SUC_EST_CON_LVR;
            /** Sinalização de sucesso no comando de consultar
             *  livro na função Estante e tendo resenha */
            const static string SUC_EST_CON_LVR_RES;
            /** Sinalização de sucesso no comando de consultar
             *  usuario na função Estante */
            const static string SUC_EST_CON_USR;
            /** Sinalização de sucesso no comando de consultar
             *  troca na função Estante */
            const static string SUC_EST_CON_TRC;

            /*  Mensagens de erro */
            /** Sinalização de erro dúbio */
            const static string ERR_DUB;
            /** Sinalização de erro acesso à Base de Dados */
            const static string ERR_ABD;
            /** Sinalização de erro por usuário já existente */
            const static string ERR_USU_EXI;

            /*  Mensagens de falha */
            /** Sinalização de falha na operação */
            const static string FLH;
            /** Sinalização de falha por escolha inválida */
            const static string FLH_ESC;
            /** Sinalização de falha por limite de tentativas */
            const static string FLH_LIM;
            /** Sinalização de falha por livro inexistente */
            const static string FLH_LVR;
            /** Sinalização de falha por usuário inexistente */
            const static string FLH_USR;
            /** Sinalização de falha por login inexistente */
            const static string FLH_LGN;

            /*  Mensagens de finalização */
            /** Sinalização do final da execução do programa */
            const static string FIM;
            /** Sinalização do final da execução da Aplicação */
            const static string FIM_APP;
            /** Sinalização do final da execução da função
             *  Autenticar */
            const static string FIM_AUT;
            /** Sinalização do final da execução da função
             *  Usuário */
            const static string FIM_USR;
            /** Sinalização do final da execução da função
             *  Estante */
            const static string FIM_EST;
            /** Sinalização do final da execução do comando de
             *  consultar livro da função Estante */
            const static string FIM_EST_CON_LVR;
            /** Sinalização do final da execução do comando de
             *  consultar usuário da função Estante */
            const static string FIM_EST_CON_USR;
            /** Sinalização do final da execução do comando de
             *  consultar troca da função Estante */
            const static string FIM_EST_CON_TRC;
            /** Sinalização do final da execução do comando de
             *  criar resenha da função Estante */
            const static string FIM_EST_CRS;
            /** Sinalização do final da execução do comando de
             *  inserir livro da função Estante */
            const static string FIM_EST_INC_LVR;
            /** Sinalização do final da execução do comando de
             *  remover livro da função Estante */
            const static string FIM_EST_RMV_LVR;
            /** Sinalização do final da execução do comando de
             *  sinalizar troca de livro da função Estante */
            const static string FIM_EST_STR;

            /*  Mensagens de Formatação */
            /** Formatação de um divisor padrão */
            const static string FMT_DVS;
            /** Formatação de uma terminação global */
            const static string FMT_INI_GLB;
            /** Formatação de uma terminação parcial */
            const static string FMT_INI_PAR;
            /** Formatação de uma terminação global */
            const static string FMT_TRM_GLB;
            /** Formatação de uma terminação parcial */
            const static string FMT_TRM_PAR;

            /** Saudação para finalização de conversa */
            const static string SAUDACAO_FIM;
    };
#endif // MENSAGEM_HPP
