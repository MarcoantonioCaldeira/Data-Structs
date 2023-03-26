#include <iostream>
#include <stdlib.h>

#define Tam 10
using namespace std;

struct Time{
	int Codigo;
	string Nome;
	int Ano_f; 
};

struct Liga{ //Header/Cabe?alho
	Time Lista[Tam];
	int Total;
};

void Ini_Lista(Liga *L){
	L->Total = 0;
}

int Lista_Cheia(Liga *L){
		
	return (L->Total == Tam);	
}

int Lista_Vazia(Liga *L){
	
	return (L->Total == 0);		
}

void Desloca_Valores_Dir(Liga *L, int Inicio, int Fim){ //para inser??o em uma posi??o determinada
    int Cont;

    for (Cont=Fim; Cont >= Inicio; Cont--){
        L->Lista[Cont+1] = L->Lista[Cont];
    }    

}

void Desloca_Valores_Esq(Liga *L, int Inicio, int Fim){ //para remo??o
    int Cont;

    for (Cont=Inicio; Cont < Fim; Cont++){
        L->Lista[Cont] = L->Lista[Cont+1];
    }    
}

int Posicao(Liga *L, int Codigo){
	int Pos = -1, Cont = 0;
	
	while(Pos<0 && Cont < L->Total) {
		if (L->Lista[Cont].Codigo == Codigo){
			Pos = Cont;
		}
		
		Cont++;
	}
	
	return Pos;
}

int PosicaoIns(Liga *L, int Codigo){
	int Pos = -1, Cont = 0;
	
	while(Pos<0 && Cont < L->Total) {
		if (L->Lista[Cont].Codigo > Codigo){
			Pos = Cont;
		}
		
		Cont++;
	}
	
	if (Pos < 0){
		Pos = L->Total;
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
			Pos = PosicaoIns(L,Codigo);
			//Insere no fim
			if (Pos < L->Total){
				Desloca_Valores_Dir(L, Pos, L->Total-1);
			}
			
			L->Lista[Pos].Codigo = Codigo;
			L->Lista[Pos].Nome = Nome;
			L->Lista[Pos].Ano_f = Ano_f;
			L->Total++;
		}	
	}
		
	return Ret;
}

int Remover_Time(Liga *L, int Codigo){
	int Ret=1, Pos;
	
	if (Lista_Vazia(L)){
		Ret = -1; //Lista vazia
	}
	else{
		//Procura o time
		Pos = Posicao(L,Codigo);
		if (Pos >=0){
			Desloca_Valores_Esq(L, Pos, L->Total-1);
			L->Total--;
		}
		else{ //Time n?o existe!!
			Ret = -2;	
		}
	}
	
	return Ret;
}

void Imprime_Lista(Liga *L){
	int Cont;
	
	for(Cont=0;Cont<L->Total;Cont++){
		cout << endl << "Time[" <<Cont<<"]";
		cout << endl << "C?digo: " << L->Lista[Cont].Codigo;
		cout << endl << "Nome: " << L->Lista[Cont].Nome;
		cout << endl << "Ano funda??o: " << L->Lista[Cont].Ano_f << endl;
	}	
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

void MostraMsgErro(int CodErro, string TipoOp){
	
	if (TipoOp == "INS"){
		switch(CodErro){
			case -1:
				cout << endl<< "ERRO INSER??O ["<<CodErro<<"]: Lista cheia!!!" << endl;
				system("pause");
				break;	
			case -2:
				cout << endl<< "ERRO INSER??O ["<<CodErro<<"]: Time j? existe!!!" << endl;
				system("pause");
				break;										
		}
	}
	else{ //"REM"
		switch(CodErro){
			case -1:
				cout << endl<< "ERRO REMO??O ["<<CodErro<<"]: Lista vazia!!!" << endl;
				system("pause");
				break;			
			case -2:
				cout << endl<< "ERRO REMO??O ["<<CodErro<<"]: Time n?o existe!!!" << endl;
				system("pause");
				break;						
		}		
	}
}

Liga T;
int CodErro;
int main(){	
	setlocale(LC_ALL,"Portuguese");
	
	//MostraMsgErro(Remover_Time(&T,50), "REM");
	Ini_Lista(&T);
	Inserir_Time(&T,50, "Palmeiras", 1914);
	Inserir_Time(&T,40, "Santos", 1909);
	Inserir_Time(&T,10, "Corinthians", 1910);
	Inserir_Time(&T,30, "S?o Paulo", 1930);
	Inserir_Time(&T,20, "Bragantino", 1970);		
	Imprime_Lista_Rec(&T, 0);
	MostraMsgErro(Inserir_Time(&T,50, "Bragantino", 1970), "INS");		
	//Imprime_Lista(&T);	
	system("pause");
	Remover_Time(&T,50); 
	Imprime_Lista_Rec(&T, 0);
	system("pause");
	CodErro = Remover_Time(&T,50);
	MostraMsgErro(CodErro, "REM"); 
		
	return 0;
}  
