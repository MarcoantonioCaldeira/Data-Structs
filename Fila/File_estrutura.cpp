#include <iostream>
#include <stdlib.h>

using namespace std;

struct Time{
    int Codigo;
    string Nome;
    int Ano_f;
    Time *Prox;
};

struct Liga{ //Header/Cabe�alho
    Time *Inicio;
    Time *Fim;
    int Total;
};

void Ini_Lista(Liga *L){
    L->Inicio = NULL;
    L->Fim = NULL;
    L->Total = 0;
}

int Fila_Vazia(Liga *L){

    return (L->Inicio == NULL);
}

Time *Criar_Time(int Codigo, string Nome, int Ano_f){
    Time *Item;

    Item = new Time;
    if (Item != NULL){
        Item->Codigo = Codigo;
        Item->Nome = Nome;
        Item->Ano_f = Ano_f;
        Item->Prox = NULL;
    }

    return Item;
}

int Enfileirar(Liga *L, int Codigo, string Nome, int Ano_f){
    int Ret=1; //C�digo de Erro
    Time* Item;

    Item = Criar_Time(Codigo, Nome, Ano_f);
    if (Item == NULL)
        Ret = -1; //N�o conseguiu aloicar espa�o na mem�ria
    else{
        if(Fila_Vazia(L)){ //Fila t� vazia
            L->Inicio = Item;
        }
        else{
            L->Fim->Prox = Item;
        }

        L->Fim = Item;
        L->Total++;
    }

    return Ret;
}

Time* Desenfileirar(Liga *L){
    Time* Ret;

    if (Fila_Vazia(L)){
        Ret = NULL; //Lista vazia
    }
    else{
        Ret = L->Inicio;

        L->Inicio = L->Inicio->Prox;
        L->Total--;

        if (Fila_Vazia(L)){
            L->Fim = L->Inicio;
        }
    }

    return Ret;
}

void Imprime_Lista(Liga *L){
    Time* Item;
    int Cont=0;

    for(Item=L->Inicio;Item!=NULL;Item = Item->Prox){
        cout << endl << "Time[" <<Cont<<"]";
        cout << endl << "Nome: " << Item->Codigo;
        cout << endl << "Nome: " << Item->Nome;
        cout << endl << "Ano funda��o: " << Item->Ano_f << endl;
        Cont++;
    }
}

void Imprime_Lista_Rec(Time* Item){

    if (Item != NULL){
        cout << endl << "C�digo: " << Item->Codigo;
        cout << endl << "Nome: " << Item->Nome;
        cout << endl << "Ano funda��o: " << Item->Ano_f << endl;

        Imprime_Lista_Rec(Item->Prox);
    }
}

//-> Acesso ao campo da struct via ponteiro *().

void MostraMsgErro(int CodErro, string TipoOp){

    if (TipoOp == "INS"){
        switch(CodErro){
            case -1:
                cout << endl<< "ERRO INSER��O ["<<CodErro<<"]: Pilha cheia!!!" << endl;
                system("pause");
                break;
        }
    }
    else{ //"REM"
        switch(CodErro){
            case -1:
                cout << endl<< "ERRO REMO��O ["<<CodErro<<"]: Pilha vazia!!!" << endl;
                system("pause");
                break;
        }
    }
}
/*
))())(
()(())
0 1 2...
char Sent[7];
Sent[0] =  ')';
Sent[1] =  ')';
Sent[2] =  '(';
Sent[3] =  ')';
Sent[4] =  ')';
Sent[5] =  '(';
Sent[6] = '0';
*/

int Proc_Parenteses(char* V){
    int Ret; //1(OK), -1(Erro)


    return Ret;
}


Liga T;
Time *Item;
int main(){
    setlocale(LC_ALL,"Portuguese");

    //MostraMsgErro(Remover_Time(&T,50), "REM");
    Ini_Lista(&T);
    Enfileirar(&T,50, "Palmeiras", 1914);
    Enfileirar(&T,40, "Santos", 1909);
    Enfileirar(&T,10, "Corinthians", 1910);
    Enfileirar(&T,30, "S�o Paulo", 1930);
    Enfileirar(&T,20, "Bragantino", 1970);
    Imprime_Lista_Rec(T.Inicio);
    system("pause");
    Desenfileirar(&T);
    Imprime_Lista_Rec(T.Inicio);
    system("pause");
    Item = Desenfileirar(&T);
    cout << endl << "Valor do c�digo desenfileirado �: " << Item->Codigo;
    Imprime_Lista_Rec(T.Inicio);

    return 0;
}