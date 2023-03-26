#include<iostream>
#include <stdlib.h>

#define Tam 10

using namespace std;

struct Turma{
	int cod_turma;
	int total_alunos;
};


void Ini_Lista(Turma *T){
	T->Inicio = -1;
	T->Total = 0;
	T->TotEnc = 0;
}


int Lista_Cheia(Turma *T){
	
	return(T->total_alunos == Tam);
}


int Lista_Vazia(Turma *T){
	
	return(T->total_alunos == 0);
}

Busca_Codigo(Turma *T, int Codigo){
	int Pos = -1, Elem;
	
	Elem = T -> Inicio;
	
	
}

int main(){
	
}
