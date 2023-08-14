#include <iostream>
#include <stdlib.h>

#define Tam 5
using namespace std;

struct Time{
    int Codigo;
    string Nome;
    int Ano_f;
};

struct Liga{ //Header/Cabe�alho
    Time Fila[Tam];
    int Total;
};

void Ini_Lista(Liga *L){
    L->Total = 0;
}

int Fila_Vazia(Liga *L){

    return (L->Total == 0);
}

int Fila_Cheia(Liga *L){

    return (L->Total == Tam);
}


Time *Criar_Time(int Codigo, string Nome, int Ano_f){
    Time *Item;

    Item = new Time;

    if (Item != NULL){
        Item->Codigo = Codigo;
        Item->Nome = Nome;
        Item->Ano_f = Ano_f;
    }

    return Item;
}

int Enfileirar(Liga *L, int Codigo, string Nome, int Ano_f){
    int Ret=1; //C�digo de Erro

    if (Fila_Cheia(L))
        Ret = -1; //Fila cheia
    else{
        L->Fila[L->Total].Codigo = Codigo;
        L->Fila[L->Total].Nome = Nome;
        L->Fila[L->Total].Ano_f = Ano_f;

        L->Total++;
    }

    return Ret;
}

void Desloca_Valores_Esq(Liga *L){ //para remo??o
    int Cont;

    for (Cont=0; Cont < L->Total-1; Cont++){
        L->Fila[Cont] = L->Fila[Cont+1];
    }
}

Time* Desenfileirar(Liga *L){
    Time* Ret;

    if (Fila_Vazia(L)){
        Ret = NULL; //Lista vazia
    }
    else{
        Ret = Criar_Time(L->Fila[0].Codigo, L->Fila[0].Nome, L->Fila[0].Ano_f);
        Desloca_Valores_Esq(L);

        L->Total--;
    }

    return Ret;
}

void Imprime_Lista(Liga *L){
    int Cont;

    for(Cont=0;Cont < L->Total ;Cont++){
        cout << endl << "Time[" <<Cont<<"]";
        cout << endl << "C�digo: " << L->Fila[Cont].Codigo;
        cout << endl << "Nome: " << L->Fila[Cont].Nome;
        cout << endl << "Ano funda��o: " << L->Fila[Cont].Ano_f << endl;
    }
}

void Imprime_Lista_Rec(Liga *L, int Pos){

    if (Pos < L->Total ){
        cout << endl << "C�digo: " << L->Fila[Pos].Codigo;
        cout << endl << "Nome: " << L->Fila[Pos].Nome;
        cout << endl << "Ano funda��o: " << L->Fila[Pos].Ano_f << endl;

        Imprime_Lista_Rec(L, Pos + 1);
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
    Imprime_Lista_Rec(&T, 0);
    system("pause");
    Desenfileirar(&T);
    Imprime_Lista_Rec(&T, 0);
    system("pause");
    Item = Desenfileirar(&T);
    cout << endl << "Valor do c�digo desenfileirado �: " << Item->Codigo;
    Imprime_Lista_Rec(&T, 0);

    return 0;
}