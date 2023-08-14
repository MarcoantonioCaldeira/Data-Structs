#include <iostream>
#include <stdlib.h>



using namespace std;

struct Time{
	int Codigo;
	string Nome;
	int Ano_f; 
	Time *Prox;
};

struct Liga{ //Header/Cabecalho
	Time *Topo;
	int Total;
};

void Ini_Lista(Liga *L){
	L->Topo = NULL;
	L->Total = 0;
}


int Lista_Vazia(Liga *L){
	
	return (L->Topo == NULL);		
}


Time* Criar_Time(int Codigo, string Nome, int Ano_f){
	Time  *Item;
	
	Item = new Time;
	
	if(Item != NULL){
		Item->Codigo = Codigo;
		Item->Nome = Nome;
		Item->Ano_f = Ano_f;
		Item->Prox = NULL;
	}
	
	return Item;
}

int Empilhar(Liga *L, int Codigo, string Nome, int Ano_f){
	int Ret=1; //C?digo de Erro
	Time *Item;
	
	Item = Criar_Time(Codigo, Nome, Ano_f);
	
	if(Item == NULL){
		Ret = -1;	
	}
	else{ 
	
		Item->Prox = L->Topo;
		L->Topo = Item;
		
		L->Total++;
	}
	
	return Ret;
}

int Desempilhar(Liga *L){
	Time* Ret;

	if(Lista_Vazia(L)){
		
		Ret == NULL;
	}else{
		
		Ret = L->Topo;
		L->Topo = L->Topo->Prox;
		L->Total--;
	}
	
	return Ret;
}

void Imprime_Lista(Liga *L){
	Time* Item;
	int Cont = 0;
	
	for(Item=L->Topo; Item!=NULL; Item = Item->Prox){
		cout << endl << "Time[" <<Cont<<"]";
		cout << endl << "C?digo: " << Item->Codigo;
		cout << endl << "Nome: " << Item->Nome;
		cout << endl << "Ano funda??o: " << Item->Ano_f << endl;
		Cont++;
	}	
}

void Imprime_Lista_Rec(Time *Item){
	
	if (Pos >= 0){
		cout << endl << "Time[" <<Pos<<"]";
		cout << endl << "Codigo: " << L->Lista[Pos].Codigo;
		cout << endl << "Nome: " << L->Lista[Pos].Nome;
		cout << endl << "Ano funda??o: " << L->Lista[Pos].Ano_f << endl;		
		
		Imprime_Lista_Rec(Pos-1);
	}
	
}

//void MostraMsgErro(int CodErro, string TipoOp){
//	
//	if (TipoOp == "INS"){
//		switch(CodErro){
//			case -1:
//				cout << endl<< "ERRO INSER??O ["<<CodErro<<"]: Lista cheia!!!" << endl;
//				system("pause");
//				break;									
//		}
//	}
//	else{ //"REM"
//		switch(CodErro){
//			case -1:
//				cout << endl<< "ERRO REMO??O ["<<CodErro<<"]: Lista vazia!!!" << endl;
//				system("pause");
//				break;									
//		}		
//	}
//}

Liga T;
Time *Item;
int main(){	
	setlocale(LC_ALL,"Portuguese");
	
	//MostraMsgErro(Remover_Time(&T,50), "REM");
	Ini_Lista(&T);
	Empilhar(&T,50, "Palmeiras", 1914);
	Empilhar(&T,40, "Santos", 1909);
	Empilhar(&T,10, "Corinthians", 1910);		
	Imprime_Lista_Rec(T.Topo);
	system("pause");
	Desempilhar(&T);
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
