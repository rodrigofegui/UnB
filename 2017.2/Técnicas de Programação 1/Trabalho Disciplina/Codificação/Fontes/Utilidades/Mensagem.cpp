#include "../../Bibliotecas/Utilidades/Mensagem.hpp"

/*  Mensagens de início */
const string Mensagem::INI_APP              ("Iniciada a aplicação.");
const string Mensagem::INI_APP_TST          ("Iniciada a aplicação de teste.");
const string Mensagem::INI_AUT              ("Iniciada a função de Autenticar.");
const string Mensagem::INI_USR              ("Iniciada a função de Usuário.");
const string Mensagem::INI_EST              ("Iniciada a função da Estante.");
const string Mensagem::INI_EST_CON_LVR      ("Iniciada o comando de consultar livro.");
const string Mensagem::INI_EST_CON_USR      ("Iniciada o comando de consultar usuário.");
const string Mensagem::INI_EST_CON_TRC      ("Iniciada o comando de consultar troca.");
const string Mensagem::INI_EST_CRS          ("Iniciada o comando de criar resenha.");
const string Mensagem::INI_EST_INC_LVR      ("Iniciada o comando de inserir livro.");
const string Mensagem::INI_EST_RMV_LVR      ("Iniciada o comando de remover livro.");
const string Mensagem::INI_EST_STR          ("Iniciada o comando de sinalizar troca.");
const string Mensagem::INI_TST              ("Tentativa: " + FMT_INI_GLB);

/*  Mensagens de identificação */
const string Mensagem::LBL_APE              ("Apelido: ");
const string Mensagem::LBL_ATR              ("Autor: ");
const string Mensagem::LBL_DAT              ("Data: ");
const string Mensagem::LBL_GEN              ("Gênero Lit.: ");
const string Mensagem::LBL_NOM              ("Nome: ");
const string Mensagem::LBL_TEL              ("Telefone: ");
const string Mensagem::LBL_TIT              ("Título: ");


/*  Mensagens de leitura */
const string Mensagem::LEITURA              ("Leitura dos dados.");
const string Mensagem::LER_ESC              ("Digite a sua escolha: ");
const string Mensagem::LER_APE              ("Digite o apelido: ");
const string Mensagem::LER_ATR              ("Digite o autor: ");
const string Mensagem::LER_DAT              ("Digite o data: ");
const string Mensagem::LER_DSP              ("Digite a disponibilidade (S/N): ");
const string Mensagem::LER_NOM              ("Digite o nome: ");
const string Mensagem::LER_GEN              ("Digite o gênero: ");
const string Mensagem::LER_SEN              ("Digite a senha: ");
const string Mensagem::LER_TEL              ("Digite o telefone: ");
const string Mensagem::LER_TXT              ("Digite o texto: ");
const string Mensagem::LER_TIT              ("Digite o título: ");
const string Mensagem::LER_TIT_LVR          ("Digite o título do livro: ");
const string Mensagem::LER_TIT_RES          ("Digite o título da resenha: ");

/*  Mensagens de aquisição */
const string Mensagem::AQS_APE              ("Apelido adquirido com êxito.");
const string Mensagem::AQS_ATR              ("Autor adquirido com êxito.");
const string Mensagem::AQS_DAT              ("Data adquirida com êxito.");
const string Mensagem::AQS_DSP              ("Disponibilidade adquirida com êxito.");
const string Mensagem::AQS_NOM              ("Nome adquirido com êxito.");
const string Mensagem::AQS_GEN              ("Gênero adquirido com êxito.");
const string Mensagem::AQS_SEN              ("Senha adquirida com êxito.");
const string Mensagem::AQS_TEL              ("Telefone adquirido com êxito.");
const string Mensagem::AQS_TIT              ("Título adquirido com êxito.");
const string Mensagem::AQS_TXT              ("Texto adquirido com êxito.");


/*  Mensagens de redirecionamento */
const string Mensagem::RED_AUT              ("A redirecionar para Autenticar.");
const string Mensagem::RED_USU              ("A redirecionar para Usuário.");
const string Mensagem::RED_EST              ("A redirecionar para Estante.");
const string Mensagem::RED_EST_CON_LVR      ("A redirecionar para Consultar Livro.");
const string Mensagem::RED_EST_CON_USR      ("A redirecionar para Consultar Usuário.");
const string Mensagem::RED_EST_CON_TRC      ("A redirecionar para Consultar Troca.");
const string Mensagem::RED_EST_CRS          ("A redirecionar para Criar Resenha.");
const string Mensagem::RED_EST_INC_LVR      ("A redirecionar para Inserir Livro.");
const string Mensagem::RED_EST_RMV_LVR      ("A redirecionar para Remover Livro.");
const string Mensagem::RED_EST_STR          ("A redirecionar para Sinalizar Troca.");

/*  Mensagens de criação */
const string Mensagem::CRI_LVR              ("Livro criado com êxito.");
const string Mensagem::CRI_LGN              ("Login criado com êxito.");
const string Mensagem::CRI_USR              ("Usuário criado com êxito.");
const string Mensagem::CRI_RES              ("Resenha criado com êxito.");

/*  Mensagens de sucesso */
const string Mensagem::SUC_AUT              ("Autenticação operou com sucesso: ");
const string Mensagem::SUC_USR              ("Usuário operou com sucesso: ");
const string Mensagem::SUC_EST_CON_LVR      ("Livro encontrado: ");
const string Mensagem::SUC_EST_CON_LVR_RES  ("Resenha(s) associada(s):");
const string Mensagem::SUC_EST_CON_USR      ("Usuário encontrado: ");
const string Mensagem::SUC_EST_CON_TRC      ("Usuário(s) encontrado(s): ");

/*  Mensagens de erro */
const string Mensagem::ERR_DUB              ("Erro: Entrada inválida ou Base de Dados.");
const string Mensagem::ERR_ABD              ("Erro: Acesso Base de Dados.");
const string Mensagem::ERR_USU_EXI          ("Erro: Usuário existente.");

/*  Mensagens de falha */
const string Mensagem::FLH                  ("Falha na operação.");
const string Mensagem::FLH_ESC              ("Falha: Valor fornecido não pertence as opções permitidas.");
const string Mensagem::FLH_LIM              ("Falha: Limite de tentativas foi alcançado.");
const string Mensagem::FLH_LVR              ("Falha: Livro não encontrado.");
const string Mensagem::FLH_USR              ("Falha: Usuário não encontrado.");
const string Mensagem::FLH_LGN              ("Falha: Login não encontrado.");

/*  Mensagens de finalização */
const string Mensagem::FIM                  ("\nA execução finalizou!");
const string Mensagem::FIM_APP              ("Finalizada a aplicação.");
const string Mensagem::FIM_AUT              ("Finalizada a função de Autenticar.");
const string Mensagem::FIM_USR              ("Finalizada a função de Usuário.");
const string Mensagem::FIM_EST              ("Finalizada a função da Estante.");
const string Mensagem::FIM_EST_CON_LVR      ("Finalizado o comando de consultar livro.");
const string Mensagem::FIM_EST_CON_USR      ("Finalizado o comando de consultar usuário.");
const string Mensagem::FIM_EST_CON_TRC      ("Finalizado o comando de consultar troca.");
const string Mensagem::FIM_EST_CRS          ("Finalizado o comando de criar resenha.");
const string Mensagem::FIM_EST_INC_LVR      ("Finalizado o comando de inserir livro.");
const string Mensagem::FIM_EST_RMV_LVR      ("Finalizado o comando de remover livro.");
const string Mensagem::FIM_EST_STR          ("Finalizado o comando de sinalizar troca.");

/*  Mensagens de Formatação */
const string Mensagem::FMT_DVS              ("', '");
const string Mensagem::FMT_INI_GLB          ("['");
const string Mensagem::FMT_INI_PAR          ("('");
const string Mensagem::FMT_TRM_GLB          ("'].");
const string Mensagem::FMT_TRM_PAR          ("')");

const string Mensagem::SAUDACAO_FIM         ("Volte sempre!");
