#include "../../Bibliotecas/Utilidades/TesteUnitario.hpp"

void TesteUnitario::validar(){
    validarTrue();  validarFalse();

    validarEQ();    validarNE();

    validarLT();    validarLE();

    validarGT();    validarGE();
}

void TesteUnitario::validarTrue(){
    int cont = 1;

    cout << cont++ << endl;
    expect_True(false);
    cout << cont++ << endl;
    expect_True(true);
}

void TesteUnitario::validarFalse(){
    int cont = 1;

    cout << cont++ << endl;
    expect_False(false);
    cout << cont++ << endl;
    expect_False(true);
}

void TesteUnitario::validarEQ(){
    int cont = 1;

    cout << cont++ << endl;
    expect_EQ ('a', 'b');
    cout << cont++ << endl;
    expect_EQ ('e', 'e');

    cout << cont++ << endl;
    expect_EQ (2, 3);
    cout << cont++ << endl;
    expect_EQ (3, 42);
    cout << cont++ << endl;
    expect_EQ (2, 2);

    cout << cont++ << endl;
    expect_EQ (2.5, 2.4);
    cout << cont++ << endl;
    expect_EQ (2.51, 2.5);
    cout << cont++ << endl;
    expect_EQ (2.5, 2.5);

    cout << cont++ << endl;
    expect_EQ ("abdc", "adc");
    cout << cont++ << endl;
    expect_EQ ("teste", "Teste");
    cout << cont++ << endl;
    expect_EQ ("teste", "teste");
    cout << cont++ << endl;
    expect_CEQ ("teste", "TEstE");
    cout << cont++ << endl;
    expect_CEQ ("teste", "TEst");
}

void TesteUnitario::validarNE(){
    int cont = 1;

    cout << cont++ << endl;
    expect_NE ('a', 'b');
    cout << cont++ << endl;
    expect_NE ('e', 'e');

    cout << cont++ << endl;
    expect_NE (2, 3);
    cout << cont++ << endl;
    expect_NE (3, 42);
    cout << cont++ << endl;
    expect_NE (2, 2);

    cout << cont++ << endl;
    expect_NE (2.5, 2.4);
    cout << cont++ << endl;
    expect_NE (2.51, 2.5);
    cout << cont++ << endl;
    expect_NE (2.5, 2.5);

    cout << cont++ << endl;
    expect_NE ("abdc", "adc");
    cout << cont++ << endl;
    expect_NE ("teste", "Teste");
    cout << cont++ << endl;
    expect_NE ("teste", "teste");
    cout << cont++ << endl;
    expect_CNE ("teste", "TEstE");
    cout << cont++ << endl;
    expect_CNE ("teste", "TEst");
}

void TesteUnitario::validarLT(){
    int cont = 1;

    cout << cont++ << endl;
    expect_LT ('A', 'a');
    cout << cont++ << endl;
    expect_LT ('e', 'e');

    cout << cont++ << endl;
    expect_LT (2, 1);
    cout << cont++ << endl;
    expect_LT (3, 42);

    cout << cont++ << endl;
    expect_LT (3.1415, 3.1416);
    cout << cont++ << endl;
    expect_LT (3.14, 3.14);
    cout << cont++ << endl;
    expect_LT (3.15, 3.14);
}

void TesteUnitario::validarLE(){
    int cont = 1;

    cout << cont++ << endl;
    expect_LE ('a', 'b');
    cout << cont++ << endl;
    expect_LE ('e', 'E');

    cout << cont++ << endl;
    expect_LE (2, 1);
    cout << cont++ << endl;
    expect_LE (42, 3);
    cout << cont++ << endl;
    expect_LE (42, 42);

    cout << cont++ << endl;
    expect_LE (3.1415, 3.1456);
    cout << cont++ << endl;
    expect_LE (3.14, 3.14);
    cout << cont++ << endl;
    expect_LE (3.15, 3.14);
}

void TesteUnitario::validarGT(){
    int cont = 1;

    cout << cont++ << endl;
    expect_GT ('a', 'B');
    cout << cont++ << endl;
    expect_GT ('E', 'e');
    cout << cont++ << endl;
    expect_GT ('e', 'e');

    cout << cont++ << endl;
    expect_GT (4, 2);
    cout << cont++ << endl;
    expect_GT (4, 42);
    cout << cont++ << endl;
    expect_GT (42, 42);

    cout << cont++ << endl;
    expect_GT (3.14, 3.15);
    cout << cont++ << endl;
    expect_GT (3.1415, 3.1415);
    cout << cont++ << endl;
    expect_GT (3.14, 3.14);
}

void TesteUnitario::validarGE(){
    int cont = 1;

    cout << cont++ << endl;
    expect_GE ('a', 'b');
    cout << cont++ << endl;
    expect_GE ('E', 'e');
    cout << cont++ << endl;
    expect_GE ('e', 'e');

    cout << cont++ << endl;
    expect_GE (4, 2);
    cout << cont++ << endl;
    expect_GE (2, 4);
    cout << cont++ << endl;
    expect_GE (42, 42);

    cout << cont++ << endl;
    expect_GE (3.15, 3.14);
    cout << cont++ << endl;
    expect_GE (3.1415, 3.1416);
    cout << cont++ << endl;
    expect_GE (3.14, 3.14);
}



void TesteUnitario::expect (bool avaliar, bool cond){
    cout << "Testando ";

    try{
        if(avaliar){
            cout << "True:" << endl;
            if (cond) msgSucesso();
            else throw 1;
        }else{
            cout << "False:" << endl;
            if (!cond) msgSucesso();
            else throw 2;
        }
    }catch (int falha){
        msgFalha();
    }
}

void TesteUnitario::expect_True (bool cond){
    expect(true, cond);
}

void TesteUnitario::expect_False (bool cond){
    expect(false, cond);
}



void TesteUnitario::expect (char val1, char val2, string cmp){
        cout << "Testando Comparação:" << endl;

    try{
        if (cmp == "EQ"){
            if (val1 == val2) msgSucesso();
            else throw 0; // FALHA_EQ;
        }else if (cmp == "NE"){
            if (val1 != val2) msgSucesso();
            else throw 1; // FALHA_NE;
        }else if (cmp == "LT"){
            if (val1 < val2) msgSucesso();
            else throw 2; // FALHA_LT;
        }else if (cmp == "LE"){
            if (val1 <= val2) msgSucesso();
            else throw 3; // FALHA_LE;
        }else if (cmp == "GT"){
            if (val1 > val2) msgSucesso();
            else throw 4; // FALHA_GT;
        }else if (cmp == "GE"){
            if (val1 >= val2) msgSucesso();
            else throw 5; //FALHA_GE;
        }
    }catch (int falha){
        msgFalha();

        tratarFalha (falha, val1, val2);
    }
}

void TesteUnitario::expect_EQ (char val1, char val2){
    expect(val1, val2, "EQ");
}

void TesteUnitario::expect_NE (char val1, char val2){
    expect(val1, val2, "NE");
}

void TesteUnitario::expect_LT (char val1, char val2){
    expect(val1, val2, "LT");
}

void TesteUnitario::expect_LE (char val1, char val2){
    expect(val1, val2, "LE");
}

void TesteUnitario::expect_GT (char val1, char val2){
    expect(val1, val2, "GT");
}

void TesteUnitario::expect_GE (char val1, char val2){
   expect(val1, val2, "GE");
}



void TesteUnitario::expect (int val1, int val2, string cmp){
    expect((double) val1, (double) val2, cmp);
}

void TesteUnitario::expect_EQ (int val1, int val2){
    expect(val1, val2, "EQ");
}

void TesteUnitario::expect_NE (int val1, int val2){
    expect(val1, val2, "NE");
}

void TesteUnitario::expect_LT (int val1, int val2){
    expect(val1, val2, "LT");
}

void TesteUnitario::expect_LE (int val1, int val2){
    expect(val1, val2, "LE");
}

void TesteUnitario::expect_GT (int val1, int val2){
    expect(val1, val2, "GT");
}

void TesteUnitario::expect_GE (int val1, int val2){
   expect(val1, val2, "GE");
}



void TesteUnitario::expect (double val1, double val2, string cmp){
    cout << "Testando Comparação:" << endl;

    try{
        if (cmp == "EQ"){
            if (val1 == val2) msgSucesso();
            else throw 0; // FALHA_EQ;
        }else if (cmp == "NE"){
            if (val1 != val2) msgSucesso();
            else throw 1; // FALHA_NE;
        }else if (cmp == "LT"){
            if (val1 < val2) msgSucesso();
            else throw 2; // FALHA_LT;
        }else if (cmp == "LE"){
            if (val1 <= val2) msgSucesso();
            else throw 3; // FALHA_LE;
        }else if (cmp == "GT"){
            if (val1 > val2) msgSucesso();
            else throw 4; // FALHA_GT;
        }else if (cmp == "GE"){
            if (val1 >= val2) msgSucesso();
            else throw 5; //FALHA_GE;
        }
    }catch (int falha){
        msgFalha();

        tratarFalha (falha, val1, val2);
    }
}

void TesteUnitario::expect_EQ (double val1, double val2){
    expect(val1, val2, "EQ");
}

void TesteUnitario::expect_NE (double val1, double val2){
    expect(val1, val2, "NE");
}

void TesteUnitario::expect_LT (double val1, double val2){
    expect(val1, val2, "LT");
}

void TesteUnitario::expect_LE (double val1, double val2){
    expect(val1, val2, "LE");
}

void TesteUnitario::expect_GT (double val1, double val2){
    expect(val1, val2, "GT");
}

void TesteUnitario::expect_GE (double val1, double val2){
   expect(val1, val2, "GE");
}



void TesteUnitario::expect (string val1, string val2, string cmp){
    cout << "Testando Comparação:" << endl;

    try{
        if (cmp == "EQ"){
            if (val1 == val2) msgSucesso();
            else throw 0; // FALHA_EQ;
        }else if (cmp == "NE"){
            if (val1 != val2) msgSucesso();
            else throw 1; // FALHA_NE;
        }
    }catch (int falha){
        msgFalha();

        tratarFalha (falha, val1, val2);
    }
}

void TesteUnitario::expect_EQ (string val1, string val2){
    expect (val1, val2, "EQ");
}

void TesteUnitario::expect_NE (string val1, string val2){
    expect (val1, val2, "NE");
}

void TesteUnitario::expect_CEQ (string val1, string val2){
    expect (maiuscula(val1), maiuscula(val2), "EQ");
}

void TesteUnitario::expect_CNE (string val1, string val2){
    expect (maiuscula(val1), maiuscula(val2), "NE");
}



void TesteUnitario::tratarFalha (int falhaCode, char val1, char val2){
    switch(falhaCode){
        case FALHA_EQ:
            cout << "\tDeveria ser '" + string(1, val1) + "', mas veio '" + string(1, val2) + "'!" << endl << endl;
            break;
        case FALHA_NE:
            cout << "\tDeveria ser diferente de '" + string(1, val1) + "', mas veio IGUAL!" << endl << endl;
            break;
        case FALHA_LT:
            cout << "\tDeveria ser maior que '" + string(1, val1) + "', mas veio MENOR ou IGUAL!" << endl << endl;
            break;
        case FALHA_LE:
            cout << "\tDeveria ser maior ou igual a '" + string(1, val1) + "', mas veio MENOR!" << endl << endl;
            break;
        case FALHA_GT:
            cout << "\tDeveria ser menor que '" + string(1, val1) + "', mas veio MAIOR ou IGUAL!" << endl << endl;
            break;
        case FALHA_GE:
            cout << "\tDeveria ser menor ou igual que '" + string(1, val1) + "', mas veio MAIOR!" << endl << endl;
            break;
        default: throw;
    }
}

void TesteUnitario::tratarFalha (int falhaCode, double val1, double val2){
    char buffer[100];
    string strVal1, strVal2;

    sprintf (buffer, "%.2lf", val1);
    strVal1 = buffer;
    sprintf (buffer, "%.2lf", val2);
    strVal2 = buffer;

    switch(falhaCode){
        case FALHA_EQ:
            cout << "\tDeveria ser '" + strVal1 + "', mas veio '" + strVal2 + "'!" << endl << endl;
            break;
        case FALHA_NE:
            cout << "\tDeveria ser diferente de '" + strVal1 + "', mas veio IGUAL!" << endl << endl;
            break;
        case FALHA_LT:
            cout << "\tDeveria ser maior que '" + strVal1 + "', mas veio MENOR ou IGUAL!" << endl << endl;
            break;
        case FALHA_LE:
            cout << "\tDeveria ser maior ou igual a '" + strVal1 + "', mas veio MENOR!" << endl << endl;
            break;
        case FALHA_GT:
            cout << "\tDeveria ser menor que '" + strVal1 + "', mas veio MAIOR ou IGUAL!" << endl << endl;
            break;
        case FALHA_GE:
            cout << "\tDeveria ser menor ou igual que '" + strVal1 + "', mas veio MAIOR!" << endl << endl;
            break;
        default: throw;
    }
}

void TesteUnitario::tratarFalha (int falhaCode, string val1, string val2){
    switch(falhaCode){
        case FALHA_EQ:
            cout << "\tDeveria ser '" + val1 + "', mas veio '" + val2 + "'!" << endl << endl;
            break;
        case FALHA_NE:
            cout << "\tDeveria ser diferente de '" + val1 + "', mas veio IGUAL!" << endl << endl;
            break;
        default: throw;
    }
}



string TesteUnitario::maiuscula (string src){
    for(unsigned int pos = 0; pos < src.size(); pos++)
        src.at(pos) = toupper(src.at(pos));

    return src;
}

string TesteUnitario::minuscula (string src){
    for(unsigned int pos = 0; pos < src.size(); pos++)
        src.at(pos) = tolower(src.at(pos));

    return src;
}
