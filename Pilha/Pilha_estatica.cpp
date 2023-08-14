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
	int Topo;
};

void Ini_Lista(Liga *L){
	L->Topo = -1;
}

int Lista_Cheia(Liga *L){
		
	return ((L->Topo + 1) == Tam);	
}

int Lista_Vazia(Liga *L){
	
	return (L->Topo == -1);		
}


int Empilhar(Liga *L, int Codigo, string Nome, int Ano_f){
	int Ret=1; //C?digo de Erro
	
	if (Lista_Cheia(L)){
		Ret = -1; //Lista cheia
	}
	else{ 
		L->Lista[L->Topo + 1].Codigo = Codigo;
		L->Lista[L->Topo + 1].Nome = Nome;
		L->Lista[L->Topo + 1].Ano_f = Ano_f;
		L->Topo++;
	}
	return Ret;
}

int Desempilhar(Liga *L){
	int Ret=1, Pos;
	
	if (Lista_Vazia(L)){
		Ret = -1; //Lista vazia
	}
	else{
		Ret = L->Topo;
		L->Topo --;
	}
	
	return Ret;
}

//void Imprime_Lista(Liga *L){
//	int Cont;
//	
//	for(Cont=L->Topo;Cont>-1;Cont--){
//		cout << endl << "Time[" <<Cont<<"]";
//		cout << endl << "C?digo: " << L->Lista[Cont].Codigo;
//		cout << endl << "Nome: " << L->Lista[Cont].Nome;
//		cout << endl << "Ano funda??o: " << L->Lista[Cont].Ano_f << endl;
//	}	
//}

void Imprime_Lista_Rec(int Pos){
	
	if (Pos >= 0){
		cout << endl << "Time[" <<Pos<<"]";
		cout << endl << "Codigo: " << L->Lista[Pos].Codigo;
		cout << endl << "Nome: " << L->Lista[Pos].Nome;
		cout << endl << "Ano funda??o: " << L->Lista[Pos].Ano_f << endl;		
		
		Imprime_Lista_Rec(Pos-1);
	}
	
}

void MostraMsgErro(int CodErro, string TipoOp){
	
	if (TipoOp == "INS"){
		switch(CodErro){
			case -1:
				cout << endl<< "ERRO INSER??O ["<<CodErro<<"]: Lista cheia!!!" << endl;
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
		}		
	}
}

Liga T;
int CodErro;
int main(){	
	setlocale(LC_ALL,"Portuguese");
	
	//MostraMsgErro(Remover_Time(&T,50), "REM");
	Ini_Lista(&T);
	Empilhar(&T,50, "Palmeiras", 1914);
	Empilhar(&T,40, "Santos", 1909);
	Empilhar(&T,10, "Corinthians", 1910);		
	Imprime_Lista_Rec(&T, T.Topo);
//	MostraMsgErro(Inserir_Time(&T,50, "Bragantino", 1970), "INS");		
//	//Imprime_Lista(&T);	
//	system("pause");
//	Remover_Time(&T,50); 
//	Imprime_Lista_Rec(&T, 0);
//	system("pause");
//	CodErro = Remover_Time(&T,50);
//	MostraMsgErro(CodErro, "REM"); 
		
	return 0;
} 
