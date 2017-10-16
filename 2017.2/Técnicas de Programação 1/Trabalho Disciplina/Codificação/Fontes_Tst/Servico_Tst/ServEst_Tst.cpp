#include "../../Bibliotecas_Tst/Servico_Tst/ServEst_Tst.hpp"

const string ServEstTst::LIVRO_COD      ("00001");
const string ServEstTst::LIVRO_DAT      ("12/10/79");
const string ServEstTst::LIVRO_GEN      ("NOVELA");
const string ServEstTst::LIVRO_NOM      ("Douglas Adams");
const string ServEstTst::LIVRO_TIT      ("Guia do Mochileiro");
const string ServEstTst::LIVRO_TIT_RES  ("Muito bom");
const string ServEstTst::LIVRO_TXT_RES  ("Melhor resposta: 42!");

const string ServEstTst::USUAR_NOM      ("Rodrigo F. G.");
const string ServEstTst::USUAR_APE      ("rodfg");
const string ServEstTst::USUAR_TEL      ("(61)-123456789");
const string ServEstTst::USUAR_PSS      ("advc");

const string ServEstTst::DIVISOR        (", ");
const string ServEstTst::INICIO_P       ("(");
const string ServEstTst::TERMINACAO_P   (")");
const string ServEstTst::TERMINACAO_F   ("]");
const bool   ServEstTst::INSERCAO       (TesteUnitario::PASSOU);

const string ServEstTst::LIVRO_EXI      (LIVRO_TIT);
const string ServEstTst::LIVRO_EBD      ("Anjos e Demonios");

const string ServEstTst::USUARIO_EXI    (USUAR_APE);
const string ServEstTst::USUARIO_EBD    ("marta");

const string ServEstTst::MSG_INI_CON    ("Tentativa de consulta: [");
const string ServEstTst::MSG_INI_CRS    ("Tentativa de criar resenha: [(");
const string ServEstTst::MSG_INI_INC    ("Tentativa de inserção: [");
const string ServEstTst::MSG_INI_RMV    ("Tentativa de remoção: [");

const string ServEstTst::MSG_SUC_CON    ("Sucesso na consulta.");
const string ServEstTst::MSG_SUC_CRS    ("Sucesso em criar resenha.");
const string ServEstTst::MSG_SUC_INC    ("Sucesso na inserção.");
const string ServEstTst::MSG_SUC_RMV    ("Sucesso na remoção.");

const string ServEstTst::MSG_FLH_CON_L  ("Falha na consulta: livro inexistente.");
const string ServEstTst::MSG_FLH_CON_U  ("Falha na consulta: usuário inexistente.");
const string ServEstTst::MSG_FLH_CRS    ("Falha em criar resenha.");
const string ServEstTst::MSG_FLH_INC    ("Falha na inserção.");
const string ServEstTst::MSG_FLH_RMV    ("Falha na remoção.");
const string ServEstTst::MSG_EBD        ("Falha ao acessar a Base de Dados.");


Resultado ServEstTst::consultar(const Titulo &id) throw (runtime_error){
    Log::escrever(msgInicio(id));

    if(id.getCampo() == LIVRO_EXI){
        Log::escrever(MSG_SUC_CON);
        return Resultado(criarLivro(), criarResenha());
    }

    if(id.getCampo() == LIVRO_EBD){
        Log::escrever(MSG_EBD);
        throw runtime_error (MSG_EBD);
    }

    Log::escrever(MSG_FLH_CON_L);
    return Resultado (Resultado::FLH_CON);
}

Resultado ServEstTst::consultar (const Apelido &id) throw (runtime_error){
    Log::escrever(msgInicio(id));

    if(id.getCampo() == USUARIO_EXI){
        Log::escrever(MSG_SUC_CON);
        return Resultado (criarUsuario());
    }

    if(id.getCampo() == USUARIO_EBD){
        Log::escrever(MSG_EBD);
        throw runtime_error (MSG_EBD);
    }

    Log::escrever(MSG_FLH_CON_U);
    return Resultado (Resultado::FLH_CON);
}

Resultado ServEstTst::criarResenha (const Livro &livro, const Resenha &resenha) throw (runtime_error){
    Log::escrever(msgInicio(livro, resenha));

    if(livro.getTitulo().getCampo() == LIVRO_EXI){
        Log::escrever(MSG_SUC_CRS);
        return Resultado(Resultado::SUCESSO);
    }

    if(livro.getTitulo().getCampo() == LIVRO_EBD){
        Log::escrever(MSG_EBD);
        throw runtime_error (MSG_EBD);
    }

    Log::escrever(MSG_FLH_CRS);
    return Resultado (Resultado::FLH_CRI);
}

Resultado ServEstTst::incluir (const Livro &livro) throw (runtime_error){
    Log::escrever(msgInicio(livro, INSERCAO));

    if(livro.getTitulo().getCampo() == LIVRO_EXI){
        Log::escrever(MSG_SUC_INC);
        return Resultado(Resultado::SUCESSO);
    }

    if(livro.getTitulo().getCampo() == LIVRO_EBD){
        Log::escrever(MSG_EBD);
        throw runtime_error (MSG_EBD);
    }

    Log::escrever(MSG_FLH_INC);
    return Resultado (Resultado::FLH_INC);
}

Resultado ServEstTst::remover (const Livro &livro) throw (runtime_error){
    Log::escrever(msgInicio(livro, !INSERCAO));

    if(livro.getTitulo().getCampo() == LIVRO_EXI){
        Log::escrever(MSG_SUC_RMV);
        return Resultado(Resultado::SUCESSO);
    }

    if(livro.getTitulo().getCampo() == LIVRO_EBD){
        Log::escrever(MSG_EBD);
        throw runtime_error (MSG_EBD);
    }

    Log::escrever(MSG_FLH_RMV);
    return Resultado (Resultado::FLH_RMV);
}

string ServEstTst::msgInicio (const DominioBase &tentativa){
    return MSG_INI_CON + tentativa.getCampo() + TERMINACAO_F;
}

string ServEstTst::msgInicio (const Livro &livro, const Resenha &resenha){
    return MSG_INI_CRS + livro.getCodigo().getCampo()
                            + DIVISOR + livro.getDataPublicacao().getCampo()
                            + DIVISOR + livro.getGenero().getCampo()
                            + DIVISOR + livro.getAutor().getCampo()
                            + DIVISOR + livro.getTitulo().getCampo() + TERMINACAO_P
                        + DIVISOR + INICIO_P + resenha.getTitulo().getCampo()
                            + DIVISOR + resenha.getTexto().getCampo() + TERMINACAO_F;
}

string ServEstTst::msgInicio (const Livro &livro, bool cond){
    string msgIni;

    if (cond == INSERCAO)   msgIni = MSG_INI_INC;
    else                    msgIni = MSG_INI_RMV;

    return msgIni + livro.getCodigo().getCampo()
                    + DIVISOR + livro.getDataPublicacao().getCampo()
                    + DIVISOR + livro.getGenero().getCampo()
                    + DIVISOR + livro.getAutor().getCampo()
                    + DIVISOR + livro.getTitulo().getCampo() + TERMINACAO_F;
}

Livro * ServEstTst::criarLivro(){
    Codigo codigo (LIVRO_COD);
    Data data;
    GeneroLiterario gen;
    Nome autor;
    Titulo tit;

    data.setCampo(LIVRO_DAT);
    gen.setCampo(LIVRO_GEN);
    autor.setCampo(LIVRO_NOM);
    tit.setCampo(LIVRO_TIT);

    Livro *novo = new Livro ();
    novo->setAutor(autor);
    novo->setCodigo(codigo);
    novo->setDataPublicacao(data);
    novo->setGenero(gen);
    novo->setTitulo(tit);

    return novo;
}

Resenha * ServEstTst::criarResenha(){
    Texto txt;
    Titulo tit;

    tit.setCampo(LIVRO_TIT_RES);
    txt.setCampo(LIVRO_TXT_RES);

    Resenha *nova = new Resenha ();
    nova->setTexto(txt);
    nova->setTitulo(tit);

    return nova;
}

Usuario* ServEstTst::criarUsuario(){
    Apelido apelido;
    Nome nome;
    Senha sen;
    Telefone tel;

    apelido.setCampo(USUAR_APE);
    nome.setCampo(USUAR_NOM);
    sen.setCampo(USUAR_PSS);
    tel.setCampo(USUAR_TEL);

    Usuario *novo = new Usuario();
    novo->setApelido(apelido);
    novo->setNome(nome);
    novo->setSenha(sen);
    novo->setTelefone(tel);

    return novo;
}
