#include <iostream>
#include <stdlib.h>

using namespace std;

struct Item{
    int Num;
    int Prox;
};

struct Cab{
    Item Lista[10];
    int Inicio;
};

Cab L;

int main(){

	L.Inicio = -1;

	//Insere 50
	L.Lista[0].Num= 50;
	L.Lista[0].Prox= L.Inicio;
	L.Inicio = 0;

	//Insere 40
	L.Lista[1].Num = 40;
	L.Lista[1].Prox = L.Inicio;
	L.Inicio = 1;

    L.Lista[2].Num= 30;
    L.Lista[2].Prox = L.Inicio;
    L.Inicio = 2;

    L.Lista[3].Num= 10;
    L.Lista[3].Prox= L.Inicio;
    L.Inicio = 3;

    L.Lista[4].Num= 100;
    L.Lista[4].Prox= L.Lista[0].Prox; //Posicao 4 vai receber posicao 0
    L.Lista[0].Prox = 4; //Posicao 0 vai ser igual ao valor de posica 4

    L.Lista[5].Num= 60;
    L.Lista[5].Prox= L.Lista[0].Prox; //Posicao 5 vai receber posica 0
    L.Lista[0].Prox=5; //Posicao 0 vai ser igual ao valor de posica 5
	
	return 0;
}

