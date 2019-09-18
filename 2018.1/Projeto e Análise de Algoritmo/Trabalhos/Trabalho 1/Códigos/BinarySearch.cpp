/*****************************************************************
**  Projeto e Analise de Algoritmos - Turma A - 117536
**  Professor:
**				- Jan Correia
**  Responsável:
**				- Rodrigo Ferreira Guimarães - 140170740
**  Finalidades:
**              - Pesquisa de valores num dado vetor ordenado,
**              retornando sua posição ou -1 caso não exista.
*****************************************************************/
#include <iostream>
#include <stdio.h>
#include <list>
#include <map>

#define MIN_ABS (-1000000000)
using namespace std;

list<long int> lerLinha ();
map<long int, long int> lerEntrada ();
long int buscar (long int *, map<long int, long int> *);
long int buscaBinaria (long int *, long int, long int, map<long int, long int> *);
void exibir (list<long int> *);
void exibir (map<long int, long int> *);

int main(){
    list<long int> ctrl = lerLinha();
    map<long int, long int> entradas = lerEntrada();
    map<long int, long int>::iterator itMap;

    for(long int fluxo = ctrl.back(); fluxo > 0; fluxo--){
        long int ler;
        cin >> ler;

        cout << buscar(&ler, &entradas) << endl;
    }

    return 0;
}

list<long int> lerLinha(){
	list<long int> leitura;
	long int ler;

	do{
		cin >> ler;
		leitura.push_back(ler);
	}while(cin.get() != '\n');

	return leitura;
}

map<long int, long int> lerEntrada (){
    map<long int, long int> leitura;
    long int ler, maior = MIN_ABS,cont = 0;

    do{
        cin >> ler;

        if(ler > maior){
            maior = ler;
            leitura[ler] = cont;
        }

        cont++;
    }while(cin.get() != '\n');

    return leitura;
}

long int buscar (long int *chave, map<long int, long int> *dicio){
    return buscaBinaria (chave, 0, dicio->size(), dicio);
}

long int buscaBinaria (long int *chave, long int ini, long int fim, map<long int, long int> *dicio){
    if (ini > fim)  return -1;

    int meio = (ini + fim) / 2;
    map<long int, long int>::iterator itMeio = dicio->begin();

    advance(itMeio, meio);

    if(itMeio == dicio->end()) return -1;

    if(itMeio->first == *chave){
        itMeio--;
        if (meio == 0 || itMeio->first != *chave)
            return itMeio->second;
        return buscaBinaria(chave, ini, meio - 1, dicio);
    }
    if(itMeio->first < *chave) return buscaBinaria(chave, meio + 1, fim, dicio);
    else return buscaBinaria(chave, ini, meio - 1, dicio);
}

void exibir (list<long int> *lista){
    for (list<long int>::iterator it = lista->begin(); it != lista->end();){
        cout << *it;

        if (++it != lista->end()) cout << " ";
    }

    cout << endl;
}

void exibir (map<long int, long int> *dicio){
    cout << endl << "Dicio:" << endl;
    cout << "[";

    for (map<long int, long int>::iterator it = dicio->begin(); it != dicio->end();){
        cout << "{" << it->first << ", " << it-> second << "}";

        if (++it != dicio->end()) cout << ", ";
    }

    cout << "]" << endl << endl;
}
