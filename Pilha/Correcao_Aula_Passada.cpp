#include <iostream>
#include <stdlib.h>



using namespace std;

struct ItemSenti{
    char Item;
    ItemSenti *Prox;
};

struct Pilha{ //Header/Cabecalho
    Time *Topo;
    int Total;
};

void Ini_Pilha(Pilha *P){
    P->Topo = NULL;
    P->Total = 0;
}


int Pilha_Vazia(Pilha *P){

    return (P->Topo == NULL);
}


ItemSenti* Criar_Item(char Item){
      ItemSenti *ItemSenti;

    ItemSenti = (ItemSenti *) malloc(sizeof(ItemSenti));

    if(ItemSenti != NULL){
        ItemSenti->Item = Item;
        ItemSenti->Prox = NULL;
    }

    return ItemSenti;
}

int Empilhar(Pilha *P, char Item){
    int Ret=1; //C?digo de Erro
    ItemSenti *ItemSenti;

    ItemSenti = Criar_Item(Item);

    if(ItemSenti == NULL){
        Ret = -1;
    }
    else{

        ItemSenti->Prox = P->Topo;
        P->Topo = Item;

        P->Total++;
    }

    return Ret;
}

int Desempilhar(Pilha *P){
    ItemSenti* Ret;

    if(Pilha_Vazia(P)){

        Ret == NULL;
    }else{

        Ret = P->Topo;
        P->Topo = P->Topo->Prox;
        P->Total--;
    }

    return Ret;
}

void Imprime_Lista(Pilha *P){
    ItemSenti* Item;
    int Cont = 0;

    for(Item=P->Topo; Item!=NULL; Item = Item->Prox){
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

void Limpa_Pilha(ItemSenti *Item){

    if(Item != NULL){
        Limpa_Pilha(Item->Prox);
        free(Item);
    }

}


int Processar_Parenteses(Fila *){

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


    return 0;
}
