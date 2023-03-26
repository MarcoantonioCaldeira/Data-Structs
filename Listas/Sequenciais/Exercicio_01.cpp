#include <iostream>
#include <stdlib.h>

#define Tam 10
using namespace std;

struct Time{
	int Codigo;
	string Nome;
	int Ano_f; 
	int Prox;
};

struct Liga{ //Header/Cabe?alho
	Time Lista[Tam];
	int Inicio;
	int TotEnc;
	int Total;
};

void Ini_Lista(Liga *L){
	L->Inicio = -1;
	L->Total = 0;
	L->TotEnc = 0;
}

int Lista_Cheia(Liga *L){
		
	return (L->Total == Tam);	
}

int Lista_Vazia(Liga *L){
	
	return (L->Total == 0);		
}

int Posicao(Liga *L, int Codigo){
	int Pos = -1, Elem;
	
	Elem = L->Inicio;	
	
	while(Pos<0 && Elem != -1) {
		
		if (L->Lista[Elem].Codigo == Codigo){
			Pos = Elem;
		}
		
		Elem = L->Lista[Elem].Prox;
	}
	
	return Pos;
}



int PosicaoAnt(Liga *L, int Codigo){
	int Pos = -1, Prox;
	
	Prox = L->Inicio;
	while(Prox != -1 && L->Lista[Prox].Codigo < Codigo){
		Pos = Prox;
		Prox = L->Lista[Prox].Prox;
	}
	
	return Pos;
}



int Inserir_Time(Liga *L, int Codigo, string Nome, int Ano_f){
	int Ret=1, Pos; //C?digo de Erro
	
	if (Lista_Cheia(L)){
		Ret = -1; //Lista cheia
	}
	else{ 
		//Procura se time j? existe
		Pos = Posicao(L,Codigo);
		if (Pos >=0){
			Ret = -2;
		}
		else{
			L->Lista[L->Total].Codigo = Codigo;
			L->Lista[L->Total].Nome = Nome;
			L->Lista[L->Total].Ano_f = Ano_f;
						
			Pos = PosicaoAnt(L,Codigo);
			
			if(Pos == -1){
				L->Lista[L->Total].Prox = L->Inicio;
				L->Inicio = L->Total;
			}
			else{
				L->Lista[L->Total].Prox = L->Lista[Pos].Prox;
				L->Lista[Pos].Prox = L->Total;
			}
			
			L->TotEnc++;
			L->Total++;
		}	
	}
		
	return Ret;
}

int Remover_Time(Liga *L, int Codigo){
	int Ret=1, Pos, PosAnt;
	
	if (Lista_Vazia(L)){
		Ret = -1; //Lista vazia
	}
	else{
		//Procura o time
		Pos = Posicao(L,Codigo);
		if (Pos >=0){
			PosAnt = PosicaoAnt(L,Codigo);
			if(PosAnt == -1){
				L->Inicio = L->Lista[Pos].Prox;
			}
			else{
				L->Lista[PosAnt].Prox = L->Lista[Pos].Prox;
			}
			
			L->TotEnc--;
		}
		else{ //Time n?o existe!!
			Ret = -2;	
		}
	}
	
	return Ret;
}



void Imprime_Lista_Rec(Liga *L, int Pos){
		
	if (Pos < L->Total){
		cout << endl << "Time[" <<Pos<<"]";
		cout << endl << "C?digo: " << L->Lista[Pos].Codigo;
		cout << endl << "Nome: " << L->Lista[Pos].Nome;
		cout << endl << "Ano funda??o: " << L->Lista[Pos].Ano_f << endl;		
		
		Imprime_Lista_Rec(L, Pos+1);
	}
}


Liga T;
int CodErro;
int main(){	
	setlocale(LC_ALL,"Portuguese");
	
	Ini_Lista(&T);
	Inserir_Time(&T,50, "Palmeiras", 1914);
	Inserir_Time(&T,40, "Santos", 1909);	
	Inserir_Time(&T,10, "Corinthians", 1910);
	Inserir_Time(&T,30, "S?o Paulo", 1930);
	Inserir_Time(&T,20, "Bragantino", 1970);		
	Inserir_Time(&T,100, "Liverpool", 1910);
	Imprime_Lista_Rec(&T, T.Inicio);
	system("pause");	
	 
		
	return 0;
} 
