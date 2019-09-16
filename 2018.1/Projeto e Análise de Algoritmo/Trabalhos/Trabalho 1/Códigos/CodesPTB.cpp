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
#define TST_MAX	5
#define ELM_MAX 100000
#define TAM_MAX 1000000
#define EXIBIR	1
#define POS_MIN 1


using namespace std;

vector<int> insertSort (vector<int> *, bool);
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

		insertSort(&entrada, EXIBIR);

		qntTestes--;
	}while(qntTestes);

	return 0;
}

vector<int> insertSort (vector<int> *origem, bool ctrlExibir){
	vector<int> pulos(origem->size(), 0);
	int menor, maior, cont = 0;
    int posMenor = 0, posMaior = 0;

	menor = maior = origem->at(0);

	for(int pos = 1; pos < origem->size(); pos++){
        int valorAtual = origem->at(pos);

        //*
        cout << endl << "Pos = " << pos << endl;
        cout << "valorAtual = " << valorAtual << endl;
        cout << "menor = " << menor << endl;
        cout << "maior = " << maior << endl;
        cout << "cont = " << cont << endl;
        //*/

        if(valorAtual < menor){
            menor = valorAtual;
            posMenor = pulos[pos] = pos;
            cont += pulos[pos];

        }else if(valorAtual == menor){
            pulos[pos] = pulos[posMenor] - 1;
            cont += pulos[pos];

        }else if(valorAtual >= maior){
            maior = valorAtual;

        }else{
            int menorDif = 0, posMenorDif = 0, qntPulos = 0;

            for(int posMedio = 0; posMedio < pos; posMedio++){
                if(abs(origem->at(posMedio) - valorAtual) < menorDif){
                    menorDif = abs(origem->at(posMedio) - valorAtual);
                    posMenorDif = posMedio;
                }

                if(pulos[posMedio]) qntPulos++;
            }

            if(menorDif)
                pulos[pos] = pulos[posMenorDif];
            else
                pulos[pos] = pos - posMenorDif + pulos[posMenorDif] + qntPulos;

            cont += pulos[pos];
        }

        /*
		if(origem->at(pos) < menor){
			//cout << "Sob < menor" << endl;
			menor = origem->at(pos);
			pulos[pos] = pos;
			cont += pos;
		}else if((origem->at(pos) == menor) && (origem->at(pos) != maior)){
			//cout << "Sob = meio" << endl;
			for(int posMenor = 0; posMenor < origem->size(); posMenor++){
				if(origem->at(posMenor) == origem->at(pos)){
					pulos[pos] = pos - posMenor - pulos[posMenor];
					cont += pulos[pos];
					break;
				}
			}
		}else if(origem->at(pos) >= maior){
			//cout << "Sob >= maior" << endl;
			maior = origem->at(pos);
		}else{
			//cout << "Sob meio" << endl;
			for(int posMedio = 0; posMedio < pos; posMedio++){
				if(origem->at(posMedio) > origem->at(pos)){
					pulos[pos] = pos - posMedio + pulos[posMedio];
					cont += pulos[pos];
					break;
				}
			}
		}
        //*/
	}

	if (ctrlExibir){
		cout << endl << "Contador = ";
		cout << cont << endl;
	}

	return *origem;
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
