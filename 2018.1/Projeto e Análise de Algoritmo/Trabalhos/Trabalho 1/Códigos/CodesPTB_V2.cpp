/*****************************************************************
**  Projeto e Analise de Algoritmos - Turma A - 117536
**  Professor:
**				- Jan Correia
**  Responsável:
**				- Rodrigo Ferreira Guimarães - 140170740
**  Finalidades:
**              - Computar as mudanças de posição realizadas num
**				Insertion Sort não otimizado
*****************************************************************/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

#define QNT_MIN	1
#define PULOS_MIN 0
#define TST_MAX	5
#define ELM_MAX 100000
#define TAM_MAX 1000000
#define EXIBIR	1
#define POS_MIN 1


using namespace std;

unsigned long long int cntTrocaInsertionSort (vector<int> *);
vector<int> lerLinha (int);
void exibir (vector<int> *);

int main (){
	int qntTestes;

	cin >> qntTestes;

	do{
		int qntElementos;
		vector<int> entrada;

		cin >> qntElementos;
		entrada = lerLinha(qntElementos);

        //*
        cout << endl << "Ent: ";
        exibir(&entrada);

        //*/
        cout << cntTrocaInsertionSort(&entrada) << endl;

		qntTestes--;
	}while(qntTestes);

	return 0;
}

unsigned long long int cntTrocaInsertionSort (vector<int> *origem){
    vector<int> pulos(origem->size(), PULOS_MIN);
    int menor, maior, posMenor = 0;
    unsigned long long int contTroca = 0, maxCont = 0;

    menor = maior = *origem->begin();

    for (int posAtual = 1; posAtual < origem->size(); posAtual++){
        int valorAtual = origem->at(posAtual);

        /*
        cout << endl << "Valor Atual => " << valorAtual << endl;
        cout << "Menor => " << menor << endl;
        cout << "Maior => " << maior << endl;
        cout << "Pos. Atual => " << posAtual << endl;
        cout << "Pos. Menor => " << posMenor << endl;
        cout << "Cont. Troca => " << contTroca << endl;
        //*/

        if(valorAtual < menor){
            //cout << endl << "Valor < menor" << endl;
            menor = valorAtual;
            posMenor = posAtual;
            pulos[posAtual] = posAtual;

        }else if(valorAtual == menor){
            //cout << endl << "Valor = menor" << endl;

            if((posAtual - posMenor) == 1){
                //cout << endl << "Delta_Menor = 1" << endl;
                pulos[posAtual] = pulos[posMenor] - 1;
                posMenor = posAtual;

                if(pulos[posAtual] < PULOS_MIN) pulos[posAtual] = PULOS_MIN;

            }else pulos[posAtual] = (posAtual - 1) - posMenor + pulos[posMenor];

        }else if(valorAtual >= maior){
            //cout << endl << "Valor >= maior" << endl;
            maior = valorAtual;

        }else{
            //cout << endl << "Valor no Bolo" << endl;
            // Negativo, Igual e Positivo
            int valDelta[2] = {-ELM_MAX, ELM_MAX}, posDelta[3] = {0, -1, 0};
            bool delta_N, delta_I, delta_P;

            delta_N = delta_I = delta_P = false;

            for(int posBusca = 0; posBusca < posAtual; posBusca++){
                int delta = origem->at(posBusca) - valorAtual;

                if((delta < 0) && (delta > valDelta[0])){
                    delta_N = true;
                    valDelta[0] = delta;
                    posDelta[0] = posBusca;

                }else if((delta == 0) && posDelta[1] == -1){
                    delta_I = true;
                    posDelta[1] = posBusca;
                }else if((delta > 0) && (delta < valDelta[1])){
                    delta_P = true;
                    valDelta[1] = delta;
                    posDelta[2] = posBusca;
                }
            }

            if(delta_I){
                /*
                cout << endl << "posAtual = " << posAtual << endl;
                cout << "posIgual = " << posDelta[1] << endl;
                //*/

                if(abs(posAtual - posDelta[1]) == 1)
                    pulos[posAtual] = pulos[posDelta[1]];
                else{
                    pulos[posAtual] = (posAtual - 1) - pulos[posDelta[1]] - maxCont;

                    if (!pulos[posDelta[1]]) pulos[posAtual]--;

                    /*
                    cout << "Pulos[Igual] = " << pulos[posDelta[1]] << endl;
                    cout << "Pulos[Atual] = " << pulos[posAtual] << endl;
                    cout << "MaxCont = " << maxCont << endl;
                    //*/

                    if((posAtual == origem->size() - 1) && (valorAtual != maior) && pulos[posAtual] == pulos[posDelta[1]]){
                        //cout << "SOMOU +1 no IGUAL!" << endl;
                        pulos[posAtual]++;
                    }
                }

            }else if(delta_N && ((abs(posAtual - posDelta[0]) == 1) || posDelta[2] == 0)){
                pulos[posAtual] = pulos[posDelta[0]];

            }else if(delta_P){
                pulos[posAtual] = (posAtual - posDelta[2]) + pulos[posDelta[2]];

                if(pulos[posMenor] == posAtual - 1)
                    pulos[posAtual]--;

                if((pulos[posAtual] == posAtual) && (posAtual != posMenor))
                    pulos[posAtual]--;

                //*
                cout << endl <<"DELTA_P" << endl;
                cout << "posAtual = " << posAtual << endl;
                cout << "posMeMa = " << posDelta[2] << endl;
                cout << "puloMeMa = " << pulos[posDelta[2]] << endl;
                cout << "Delta ind = " << (posAtual - posDelta[2]) << endl;
                cout << "puloAtual = " << pulos[posAtual] << endl << endl;
                //*/
            }
        }

        if(pulos[posAtual] > maxCont) maxCont = pulos[posAtual];
        contTroca += pulos[posAtual];
    }

    //*
    cout << "Pul: ";
    exibir(&pulos);
    //*/

	return contTroca;
}

vector<int> lerLinha(int qnt){
	vector<int> leitura;
	int ler;

	while(qnt--){
		cin >> ler;
		leitura.push_back(ler);
	}

	return leitura;
}

void exibir (vector<int> *vetor){
    for (int pos = 0; pos < vetor->size();){
        cout << vetor->at(pos);

        if (pos++ != vetor->size()) cout << " ";
    }

    cout << endl;
}
