/*****************************************************************
**  Projeto e Analise de Algoritmos - Turma A - 117536
**  Professor:
**				- Jan Correia
**  Responsável:
**				- Rodrigo Ferreira Guimarães - 140170740
**  Finalidades:
**              - Ordenar uma sequência de números inteiros
**				dados pelo método de Merge Sort.
*****************************************************************/
#include <iostream>
#include <stdio.h>
#include <list>

#define TAM_MIN 1

using namespace std;

list<int> mergeSort (list<int>);
list<int> merge (list<int>, list<int>);
list<int> lerLinha ();
void exibir (list<int>);

int main (){
	list<int> entradas = lerLinha();

	exibir(mergeSort (entradas));

	return 0;
}

list <int> mergeSort (list <int> original){
    int tam = original.size();

    if (tam <= TAM_MIN) return original;

    list<int> frente, tras;
    list<int>::iterator it;

    for (it = original.begin(); it != original.end(); it++){
        if (frente.size() < (tam/2))    frente.push_back(*it);
        else                            tras.push_back(*it);
    }

    return merge (mergeSort(frente), mergeSort(tras));
}

list<int> merge (list<int> l1, list<int> l2){
    list<int>::iterator itL1 = l1.begin(), itL2 = l2.begin();
    list<int> resultado;

    int existe;
    bool ctrl;

    do{
        existe  = 0;
        ctrl    = true;

        if (itL1 != l1.end()) existe += 1;
        if (itL2 != l2.end()) existe += 2;
        if (existe == 3)
            if (*itL1 <= *itL2) ctrl = false;

        if ((existe == 1) || (existe == 3 && !ctrl)){
            resultado.push_back(*itL1);
            itL1++;
        } else if (ctrl){
            resultado.push_back(*itL2);
            itL2++;
        }
    }while(itL1 != l1.end() || itL2 != l2.end());

    return resultado;
}

list<int> lerLinha(){
	list<int> leitura;
	int ler;

	do{
		cin >> ler;
		leitura.push_back(ler);
	}while(cin.get() != '\n');

	return leitura;
}

void exibir (list<int> lista){
    for (list<int>::iterator it = lista.begin(); it != lista.end();){
        cout << *it;

        if (it++ != lista.end()) cout << " ";
    }

    cout << endl;
}
