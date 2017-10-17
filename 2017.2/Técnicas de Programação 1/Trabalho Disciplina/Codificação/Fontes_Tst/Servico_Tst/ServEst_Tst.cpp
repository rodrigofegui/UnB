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

const string ServEstTst::DIVISOR        (Mensagem::FMT_DVS);
const string ServEstTst::INICIO_P       (Mensagem::FMT_INI_PAR);
const string ServEstTst::TERMINACAO_P   (Mensagem::FMT_TRM_PAR);
const string ServEstTst::TERMINACAO_F   (Mensagem::FMT_TRM_GLB);

const string ServEstTst::LIVRO_EXI      (LIVRO_TIT);
const string ServEstTst::LIVRO_EBD      ("Anjos e Demonios");

const string ServEstTst::USUARIO_EXI    (USUAR_APE);
const string ServEstTst::USUARIO_EBD    ("marta");

const string ServEstTst::MSG_INI		(Mensagem::INI_TST);


Resultado ServEstTst::consultar(const Titulo &id) throw (runtime_error){
    Log::escrever(msgInicio(id, true));

    if(id.getCampo() == LIVRO_EXI){
        Log::escrever(Resultado::SUCESSO);
		cout << Resultado::SUCESSO << endl;
        return Resultado(criarLivro(), criarResenha());
    }

    if(id.getCampo() == LIVRO_EBD){
        Log::escrever(Mensagem::ERR_ABD);
        throw runtime_error (Mensagem::ERR_ABD);
    }

    Log::escrever(Mensagem::FLH_LVR);
	cout << Mensagem::FLH_LVR << endl;
    return Resultado (Resultado::FLH_CON);
}

Resultado ServEstTst::consultar (const Apelido &id) throw (runtime_error){
    Log::escrever(msgInicio(id, true));

    if(id.getCampo() == USUARIO_EXI){
        Log::escrever(Resultado::SUCESSO);
		cout << Resultado::SUCESSO << endl;
        return Resultado (criarUsuario());
    }

    if(id.getCampo() == USUARIO_EBD){
        Log::escrever(Mensagem::ERR_ABD);
        throw runtime_error (Mensagem::ERR_ABD);
    }

    Log::escrever(Mensagem::FLH_USR);
	cout << Mensagem::FLH_USR << endl;
    return Resultado (Resultado::FLH_CON);
}

Resultado ServEstTst::criarResenha (const Titulo &livro, const Resenha &resenha) throw (runtime_error){
    Log::escrever(msgInicio(livro, resenha));

    if(livro.getCampo() == LIVRO_EXI){
        Log::escrever(Resultado::SUCESSO);
        cout << Resultado::SUCESSO << endl;
        return Resultado(Resultado::SUCESSO);
    }

    if(livro.getCampo() == LIVRO_EBD){
        Log::escrever(Mensagem::ERR_ABD);
        throw runtime_error (Mensagem::ERR_ABD);
    }

    Log::escrever(Mensagem::FLH);
    cout << Mensagem::FLH << endl;
    return Resultado (Resultado::FLH_CRI);
}

Resultado ServEstTst::incluir (const Livro &livro) throw (runtime_error){
    Log::escrever(msgInicio(livro));

    if(livro.getTitulo().getCampo() == LIVRO_EXI){
        Log::escrever(Mensagem::FLH);
        cout << Mensagem::FLH << endl;
        return Resultado (Resultado::FLH_INC);
    }

    if(livro.getTitulo().getCampo() == LIVRO_EBD){
        Log::escrever(Mensagem::ERR_ABD);
        throw runtime_error (Mensagem::ERR_ABD);
    }

    Log::escrever(Resultado::SUCESSO);
    cout << Resultado::SUCESSO << endl;
    return Resultado(Resultado::SUCESSO);
}

Resultado ServEstTst::procurar(const Titulo &id) throw (runtime_error){
    Log::escrever(msgInicio(id));

    if(id.getCampo() == LIVRO_EXI){
        Log::escrever(Resultado::SUCESSO);
		cout << Resultado::SUCESSO << endl;
        return Resultado(criarUsuario());
    }

    if(id.getCampo() == LIVRO_EBD){
        Log::escrever(Mensagem::ERR_ABD);
        throw runtime_error (Mensagem::ERR_ABD);
    }

    Log::escrever(Mensagem::FLH);
	cout << Mensagem::FLH << endl;
    return Resultado (Resultado::FLH_PRO);
}

Resultado ServEstTst::remover (const Titulo &livro) throw (runtime_error){
    Log::escrever(msgInicio(livro, false));

    if(livro.getCampo() == LIVRO_EXI){
        Log::escrever(Resultado::SUCESSO);
        cout << Resultado::SUCESSO << endl;
        return Resultado(Resultado::SUCESSO);
    }

    if(livro.getCampo() == LIVRO_EBD){
        Log::escrever(Mensagem::ERR_ABD);
        throw runtime_error (Mensagem::ERR_ABD);
    }

    Log::escrever(Mensagem::FLH);
    cout << Mensagem::FLH << endl;
    return Resultado (Resultado::FLH_RMV);
}

Resultado ServEstTst::sinTroca (const Apelido &idUsuario, const Titulo &idLivro, const bool &disp) throw (runtime_error){
    Log::escrever(msgInicio(idLivro, disp));

    if (consultar(idUsuario).getCampo() == Resultado::SUCESSO
        && consultar(idLivro).getCampo() == Resultado::SUCESSO){
        Log::escrever(Resultado::SUCESSO);
        cout << Resultado::SUCESSO << endl;

        if (!disp)
            return Resultado (Resultado::SUCESSO);

        return Resultado(criarUsuario());
    }

    Log::escrever(Mensagem::FLH);
    cout << Mensagem::FLH << endl;
    return Resultado (Resultado::FLH_STC);
}

string ServEstTst::msgInicio (const DominioBase &tentativa, bool ctrl){
    string msgIni;
    if (ctrl) msgIni = MSG_INI;
    else      msgIni = MSG_INI;

    return msgIni + tentativa.getCampo() + TERMINACAO_F;
}

string ServEstTst::msgInicio (const Titulo &tentativa, bool ctrl){
    return MSG_INI + tentativa.getCampo() + DIVISOR + bool2str(ctrl) + TERMINACAO_F;
}

string ServEstTst::msgInicio (const Titulo &tentativa){
    return MSG_INI + tentativa.getCampo() + TERMINACAO_F;
}

string ServEstTst::msgInicio (const Titulo &livro, const Resenha &resenha){
    return MSG_INI + livro.getCampo() + TERMINACAO_P
                        + DIVISOR + INICIO_P + resenha.getTitulo().getCampo()
                            + DIVISOR + resenha.getTexto().getCampo() + TERMINACAO_F;
}

string ServEstTst::msgInicio (const Livro &livro){
    return MSG_INI + livro.getCodigo().getCampo()
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

	Log::escrever (Mensagem::CRI_LVR);

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

	Log::escrever (Mensagem::CRI_RES);

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

	Log::escrever (Mensagem::CRI_USR);

    return novo;
}
