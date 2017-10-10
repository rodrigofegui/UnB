#include "../../Bibliotecas/Utilidades/TesteUnitario.hpp"

void TesteUnitario::validar(){
    validarTrue();  validarFalse();

    validarEQ();    validarNE();

    validarLT();    validarLE();

    validarGT();    validarGE();
}

void TesteUnitario::validarTrue(){
    int cont = 1;
    cout << endl << endl << "\t\tValidação Teste True!" << endl;

    msgTeste (cont++);
    capturarFalha(expect_True, false);

    msgTeste (cont++);
    capturarFalha(expect_True, true);
}

void TesteUnitario::validarFalse(){
    int cont = 1;
    cout << endl << endl << "\t\tValidação Teste False!" << endl;

    msgTeste (cont++);
    capturarFalha(expect_False, false);

    msgTeste (cont++);
    capturarFalha(expect_False, true);
}

void TesteUnitario::validarEQ(){
    int cont = 1;
    cout << endl << endl << "\t\tValidação Teste EQ!" << endl;

    msgTeste (cont++);
    capturarFalha(expect_EQ, 'a', 'b');
    msgTeste (cont++);
    capturarFalha(expect_EQ, 'e', 'e');

    msgTeste (cont++);
    capturarFalha(expect_EQ, 2, 3);
    msgTeste (cont++);
    capturarFalha(expect_EQ, 3, 42);
    msgTeste (cont++);
    capturarFalha(expect_EQ, 2, 2);

    msgTeste (cont++);
    capturarFalha(expect_EQ, 2.5, 2.4);
    msgTeste (cont++);
    capturarFalha(expect_EQ, 2.51, 2.5);
    msgTeste (cont++);
    capturarFalha(expect_EQ, 2.5, 2.5);

    msgTeste (cont++);
    capturarFalha(expect_EQ, "abdc", "adc");
    msgTeste (cont++);
    capturarFalha(expect_EQ, "teste", "Teste");
    msgTeste (cont++);
    capturarFalha(expect_EQ, "teste", "teste");
    msgTeste (cont++);
    capturarFalha(expect_CEQ, "teste", "TEstE");
    msgTeste (cont++);
    capturarFalha(expect_CEQ, "teste", "TEst");
}

void TesteUnitario::validarNE(){
    int cont = 1;
    cout << endl << endl << "\t\tValidação Teste NE!" << endl;

    msgTeste (cont++);
    capturarFalha(expect_NE, 'a', 'b');
    msgTeste (cont++);
    capturarFalha(expect_NE, 'e', 'e');

    msgTeste (cont++);
    capturarFalha(expect_NE, 2, 3);
    msgTeste (cont++);
    capturarFalha(expect_NE, 3, 42);
    msgTeste (cont++);
    capturarFalha(expect_NE, 2, 2);

    msgTeste (cont++);
    capturarFalha(expect_NE, 2.5, 2.4);
    msgTeste (cont++);
    capturarFalha(expect_NE, 2.51, 2.5);
    msgTeste (cont++);
    capturarFalha(expect_NE, 2.5, 2.5);

    msgTeste (cont++);
    capturarFalha(expect_NE, "abdc", "adc");
    msgTeste (cont++);
    capturarFalha(expect_NE, "teste", "Teste");
    msgTeste (cont++);
    capturarFalha(expect_NE, "teste", "teste");
    msgTeste (cont++);
    capturarFalha(expect_CNE, "teste", "TEstE");
    msgTeste (cont++);
    capturarFalha(expect_CNE, "teste", "TEst");
}

void TesteUnitario::validarLT(){
    int cont = 1;
    cout << endl << endl << "\t\tValidação Teste LT!" << endl;

    msgTeste (cont++);
    capturarFalha(expect_LT, 'A', 'a');
    msgTeste (cont++);
    capturarFalha(expect_LT, 'e', 'e');

    msgTeste (cont++);
    capturarFalha(expect_LT, 2, 1);
    msgTeste (cont++);
    capturarFalha(expect_LT, 3, 42);

    msgTeste (cont++);
    capturarFalha(expect_LT, 3.1415, 3.1416);
    msgTeste (cont++);
    capturarFalha(expect_LT, 3.14, 3.14);
    msgTeste (cont++);
    capturarFalha(expect_LT, 3.15, 3.14);
}

void TesteUnitario::validarLE(){
    int cont = 1;
    cout << endl << endl << "\t\tValidação Teste LE!" << endl;

    msgTeste (cont++);
    capturarFalha(expect_LE, 'a', 'b');
    msgTeste (cont++);
    capturarFalha(expect_LE, 'e', 'E');

    msgTeste (cont++);
    capturarFalha(expect_LE, 2, 1);
    msgTeste (cont++);
    capturarFalha(expect_LE, 42, 3);
    msgTeste (cont++);
    capturarFalha(expect_LE, 42, 42);

    msgTeste (cont++);
    capturarFalha(expect_LE, 3.1415, 3.1456);
    msgTeste (cont++);
    capturarFalha(expect_LE, 3.14, 3.14);
    msgTeste (cont++);
    capturarFalha(expect_LE, 3.15, 3.14);
}

void TesteUnitario::validarGT(){
    int cont = 1;
    cout << endl << endl << "\t\tValidação Teste GT!" << endl;

    msgTeste (cont++);
    capturarFalha(expect_GT, 'a', 'B');
    msgTeste (cont++);
    capturarFalha(expect_GT, 'E', 'e');
    msgTeste (cont++);
    capturarFalha(expect_GT, 'e', 'e');

    msgTeste (cont++);
    capturarFalha(expect_GT, 4, 2);
    msgTeste (cont++);
    capturarFalha(expect_GT, 4, 42);
    msgTeste (cont++);
    capturarFalha(expect_GT, 42, 42);

    msgTeste (cont++);
    capturarFalha(expect_GT, 3.14, 3.15);
    msgTeste (cont++);
    capturarFalha(expect_GT, 3.1415, 3.1415);
    msgTeste (cont++);
    capturarFalha(expect_GT, 3.14, 3.14);
}

void TesteUnitario::validarGE(){
    int cont = 1;
    cout << endl << endl << "\t\tValidação Teste GE!" << endl;

    msgTeste (cont++);
    capturarFalha(expect_GE, 'a', 'b');
    msgTeste (cont++);
    capturarFalha(expect_GE, 'E', 'e');
    msgTeste (cont++);
    capturarFalha(expect_GE, 'e', 'e');

    msgTeste (cont++);
    capturarFalha(expect_GE, 4, 2);
    msgTeste (cont++);
    capturarFalha(expect_GE, 2, 4);
    msgTeste (cont++);
    capturarFalha(expect_GE, 42, 42);

    msgTeste (cont++);
    capturarFalha(expect_GE, 3.15, 3.14);
    msgTeste (cont++);
    capturarFalha(expect_GE, 3.1415, 3.1416);
    msgTeste (cont++);
    capturarFalha(expect_GE, 3.14, 3.14);
}



void TesteUnitario::capturarFalha(bool (* func) (bool condF), bool cond){
    try{
        func(cond);
        msgSucesso();
    }catch(invalid_argument e){
        msgCatch(e.what());
    }catch(length_error e){
        msgCatch(e.what());
    }
}

void TesteUnitario::capturarFalha(bool (* func) (char c1, char c2), char val1, char val2){
    try{
        func (val1, val2);
        msgSucesso();
    }catch(invalid_argument e){
        msgCatch(e.what());
    }catch(length_error e){
        msgCatch(e.what());
    }
}

void TesteUnitario::capturarFalha(bool (* func) (int i1, int i2), int val1, int val2){
    try{
        func (val1, val2);
        msgSucesso();
    }catch(invalid_argument e){
        msgCatch(e.what());
    }catch(length_error e){
        msgCatch(e.what());
    }
}

void TesteUnitario::capturarFalha(bool (* func) (double d1, double c2), double val1, double val2){
    try{
        func (val1, val2);
        msgSucesso();
    }catch(invalid_argument e){
        msgCatch(e.what());
    }catch(length_error e){
        msgCatch(e.what());
    }
}

void TesteUnitario::capturarFalha(bool (* func) (string s1), string val1){
    try{
        func (val1);
        msgSucesso();
    }catch(invalid_argument e){
        msgCatch(e.what());
    }catch(length_error e){
        msgCatch(e.what());
    }
}

void TesteUnitario::capturarFalha(bool (* func) (string s1, string s2), string val1, string val2){
    try{
        func (val1, val2);
        msgSucesso();
    }catch(invalid_argument e){
        msgCatch(e.what());
    }catch(length_error e){
        msgCatch(e.what());
    }
}



bool TesteUnitario::expect(void *pt, bool cond) throw (invalid_argument){
    if(cond){
        if (!pt) return PASSOU;
        else throw invalid_argument (tratarFalha(FALHA_NULL));

    }else{
        if (pt) return PASSOU;
        else throw invalid_argument (tratarFalha(FALHA_NNULL));
    }
}

bool TesteUnitario::expect_Null(void *pt) throw (invalid_argument){
    return expect(pt, true);
}

bool TesteUnitario::expect_NotNull(void *pt) throw (invalid_argument){
    return expect(pt, false);
}



bool TesteUnitario::expect (bool avaliar, bool cond) throw (invalid_argument){
    if(avaliar){
        if (cond) return PASSOU;
        else throw invalid_argument (tratarFalha(FALHA_TRUE));
    }else{
        if (!cond) return PASSOU;
        else throw invalid_argument (tratarFalha(FALHA_FALSE));
    }
}

bool TesteUnitario::expect_True (bool cond) throw (invalid_argument){
    return expect(true, cond);
}

bool TesteUnitario::expect_False (bool cond) throw (invalid_argument){
    return expect(false, cond);
}



bool TesteUnitario::expect (char val1, char val2, string cmp) throw (invalid_argument){
    if (cmp == "EQ"){
        if (val1 == val2) return PASSOU;
        else throw invalid_argument (tratarFalha(FALHA_EQ, val1, val2));

    }else if (cmp == "NE"){
        if (val1 != val2) return PASSOU;
        else throw invalid_argument (tratarFalha(FALHA_NE, val1, val2));

    }else if (cmp == "LT"){
        if (val1 < val2) return PASSOU;
        else throw invalid_argument (tratarFalha(FALHA_LT, val1, val2));

    }else if (cmp == "LE"){
        if (val1 <= val2) return PASSOU;
        else throw invalid_argument (tratarFalha(FALHA_LE, val1, val2));

    }else if (cmp == "GT"){
        if (val1 > val2) return PASSOU;
        else throw invalid_argument (tratarFalha(FALHA_GT, val1, val2));

    }else if (cmp == "GE"){
        if (val1 >= val2) return PASSOU;
        else throw invalid_argument (tratarFalha(FALHA_GE, val1, val2));
    }
}

bool TesteUnitario::expect_EQ (char val1, char val2) throw (invalid_argument){
    return expect(val1, val2, "EQ");
}

bool TesteUnitario::expect_NE (char val1, char val2) throw (invalid_argument){
    return expect(val1, val2, "NE");
}

bool TesteUnitario::expect_LT (char val1, char val2) throw (invalid_argument){
    return expect(val1, val2, "LT");
}

bool TesteUnitario::expect_LE (char val1, char val2) throw (invalid_argument){
    return expect(val1, val2, "LE");
}

bool TesteUnitario::expect_GT (char val1, char val2) throw (invalid_argument){
    return expect(val1, val2, "GT");
}

bool TesteUnitario::expect_GE (char val1, char val2) throw (invalid_argument){
   return expect(val1, val2, "GE");
}



bool TesteUnitario::expect (int val1, int val2, string cmp) throw (invalid_argument){
    return expect((double) val1, (double) val2, cmp);
}

bool TesteUnitario::expect_EQ (int val1, int val2) throw (invalid_argument){
    return expect(val1, val2, "EQ");
}

bool TesteUnitario::expect_NE (int val1, int val2) throw (invalid_argument){
    return expect(val1, val2, "NE");
}

bool TesteUnitario::expect_LT (int val1, int val2) throw (invalid_argument){
    return expect(val1, val2, "LT");
}

bool TesteUnitario::expect_LE (int val1, int val2) throw (invalid_argument){
    return expect(val1, val2, "LE");
}

bool TesteUnitario::expect_GT (int val1, int val2) throw (invalid_argument){
    return expect(val1, val2, "GT");
}

bool TesteUnitario::expect_GE (int val1, int val2) throw (invalid_argument){
   return expect(val1, val2, "GE");
}



bool TesteUnitario::expect (double val1, double val2, string cmp) throw (invalid_argument){
    if (cmp == "EQ"){
        if (val1 == val2) return PASSOU;
        else throw invalid_argument (tratarFalha(FALHA_EQ, val1, val2));

    }else if (cmp == "NE"){
        if (val1 != val2) return PASSOU;
        else throw invalid_argument (tratarFalha(FALHA_NE, val1, val2));

    }else if (cmp == "LT"){
        if (val1 < val2) return PASSOU;
        else throw invalid_argument (tratarFalha(FALHA_LT, val1, val2));

    }else if (cmp == "LE"){
        if (val1 <= val2) return PASSOU;
        else throw invalid_argument (tratarFalha(FALHA_LE, val1, val2));

    }else if (cmp == "GT"){
        if (val1 > val2) return PASSOU;
        else throw invalid_argument (tratarFalha(FALHA_GT, val1, val2));

    }else if (cmp == "GE"){
        if (val1 >= val2) return PASSOU;
        else throw invalid_argument (tratarFalha(FALHA_GE, val1, val2));
    }
}

bool TesteUnitario::expect_EQ (double val1, double val2) throw (invalid_argument){
    return expect(val1, val2, "EQ");
}

bool TesteUnitario::expect_NE (double val1, double val2) throw (invalid_argument){
    return expect(val1, val2, "NE");
}

bool TesteUnitario::expect_LT (double val1, double val2) throw (invalid_argument){
    return expect(val1, val2, "LT");
}

bool TesteUnitario::expect_LE (double val1, double val2) throw (invalid_argument){
    return expect(val1, val2, "LE");
}

bool TesteUnitario::expect_GT (double val1, double val2) throw (invalid_argument){
    return expect(val1, val2, "GT");
}

bool TesteUnitario::expect_GE (double val1, double val2) throw (invalid_argument){
   return expect(val1, val2, "GE");
}



bool TesteUnitario::expect (string val1, string val2, string cmp) throw (invalid_argument){
    if (cmp == "EQ"){
        if (val1 == val2) return PASSOU;
        else throw invalid_argument (tratarFalha(FALHA_EQ, val1, val2));

    }else if (cmp == "NE"){
        if (val1 != val2) return PASSOU;
        else throw invalid_argument (tratarFalha(FALHA_NE, val1, val2));
    }
}

bool TesteUnitario::expect_EQ (string val1, string val2) throw (invalid_argument){
    return expect (val1, val2, "EQ");
}

bool TesteUnitario::expect_NE (string val1, string val2) throw (invalid_argument){
    return expect (val1, val2, "NE");
}

bool TesteUnitario::expect_CEQ (string val1, string val2) throw (invalid_argument){
    return expect (Manipulacao::maiuscula(val1), Manipulacao::maiuscula(val2), "EQ");
}

bool TesteUnitario::expect_CNE (string val1, string val2) throw (invalid_argument){
    return expect (Manipulacao::maiuscula(val1), Manipulacao::maiuscula(val2), "NE");
}



void TesteUnitario::msgTeste (int teste){
    char buffer[12];
    sprintf (buffer, "Teste #%02d: ", teste);

    cout << endl << buffer;
}

void TesteUnitario::msgCatch (string mensagem){
    #ifdef ECHO_CATCH
        cout << "\t" + mensagem << endl;
    #endif // ECHO_CATCH
    cout << mensagem << endl;
}



string TesteUnitario::tratarFalha (int falhaCode){
    switch (falhaCode){
        case FALHA_NULL: return "Deveria estar nulo! Alocou indevidamente!";
        case FALHA_NNULL: return "Deveria ter endereço! Não foi alocado";
        case FALHA_TRUE: return "Deveria ser true! Veio FALSE!";
        case FALHA_FALSE: return "Deveria ser false! Veio TRUE!";
        default: return "Erro não catalogado!";
    }
}

string TesteUnitario::tratarFalha (int falhaCode, char val1, char val2){
    switch(falhaCode){
        case FALHA_EQ:
            return "Deveria ser '" + string(1, val1) + "', mas veio '" + string(1, val2) + "'!";
        case FALHA_NE:
            return "Deveria ser diferente de '" + string(1, val1) + "', mas veio IGUAL!";
        case FALHA_LT:
            return "Deveria ser maior que '" + string(1, val1) + "', mas veio MENOR ou IGUAL!";
        case FALHA_LE:
            return "Deveria ser maior ou igual a '" + string(1, val1) + "', mas veio MENOR!";
        case FALHA_GT:
            return "Deveria ser menor que '" + string(1, val1) + "', mas veio MAIOR ou IGUAL!";
        case FALHA_GE:
            return "Deveria ser menor ou igual que '" + string(1, val1) + "', mas veio MAIOR!";
        default: return "Erro não catalogado!";
    }
}

string TesteUnitario::tratarFalha (int falhaCode, double val1, double val2){
    char buffer[100];
    string strVal1, strVal2;

    sprintf (buffer, "%.2lf", val1);
    strVal1 = buffer;
    sprintf (buffer, "%.2lf", val2);
    strVal2 = buffer;

    switch(falhaCode){
        case FALHA_EQ:
            return "Deveria ser '" + strVal1 + "', mas veio '" + strVal2 + "'!";
        case FALHA_NE:
            return "Deveria ser diferente de '" + strVal1 + "', mas veio IGUAL!";
        case FALHA_LT:
            return "Deveria ser maior que '" + strVal1 + "', mas veio MENOR ou IGUAL!";
        case FALHA_LE:
            return "Deveria ser maior ou igual a '" + strVal1 + "', mas veio MENOR!";
        case FALHA_GT:
            return "Deveria ser menor que '" + strVal1 + "', mas veio MAIOR ou IGUAL!";
        case FALHA_GE:
            return "Deveria ser menor ou igual que '" + strVal1 + "', mas veio MAIOR!";
        default: return "Erro não catalogado!";
    }
}

string TesteUnitario::tratarFalha (int falhaCode, string val1, string val2){
    switch(falhaCode){
        case FALHA_EQ:
            return "Deveria ser '" + val1 + "', mas veio '" + val2 + "'!";
        case FALHA_NE:
            return "Deveria ser diferente de '" + val1 + "', mas veio IGUAL!";
        default: return "Erro não catalogado!";
    }
}
