#include<iostream>
#include <stdlib.h>

using namespace std;

struct Item{
    char elemento;
    Item *prox;
};

//Estrutura da Pilha
struct Pilha{
    Item *Topo;
    int Total;
};

void Ini_Pilha(Pilha *P){
    P->Topo = NULL;
    P->Total = 0;
}

int Pilha_Vazia(Pilha *P){
    return (P->Topo == NULL);
}

Item *Criar_Item(char elemento){
    Item *Items;

    Items = new Item;

    if (Items != NULL){
        Items->elemento = elemento;
        Items->prox = NULL;
    }

    return Items;
}


int Empilhar(Pilha *P, char elemento){
    int Ret=1;
    Item* Items;

    Items = Criar_Item(elemento);
    if (Items == NULL)
        Ret = -1;
    else{
        Items->prox = P->Topo;
        P->Topo = Items;
        P->Total++;
    }
    return Ret;
}

Item* Desempilhar(Pilha *P){
    Item *Ret;

    if (Pilha_Vazia(P)) {
        Ret = NULL;
    }else{
        Ret = P->Topo;
        P->Topo = P->Topo->prox;
        P->Total--;
    }
    return Ret;
}


void Emprimir(Pilha *P){
    Item* Items;
    int Cont=0;

    for(Items=P->Topo; Items!=NULL; Items = Items->prox){
        cout << endl << "Lista(Pilha)[" <<Cont<<"]";
        cout << endl << "Nome: " << Items->elemento;
        Cont++;
    }
}


//Estrutura da filha
struct Fila{
    Item *Inicio;
    Item *Fim;
    int Tamanho;
};

void Ini_Fila(Fila *F){
    F->Inicio = NULL;
    F->Fim = NULL;
    F->Tamanho = 0;
}

int Fila_Vazia(Fila *F){
    int Ret;

    if (F->Inicio == NULL ){
        Ret = 1;
    }
    else{
        Ret = 0;
    }

    return Ret;
}

int Tamanho(Fila *F){
    return F->Tamanho;
}

Item* Criar_Item(char elemento){
    Item *Elemento;

    Elemento = (Item *) malloc(sizeof(Item)); //Problema com o campo string

    if (Elemento != NULL) {
        Elemento->elemento = elemento;
        Elemento->prox = NULL;
    }

    return Elemento;
}

void Enfileira(Fila *F, char elemento){
    Item *Elemento;

    Elemento = Criar_Item(elemento);

    if (Elemento != NULL){
        if (Fila_Vazia(F) == 1){
            F->Inicio = Elemento;
        }
        else{
            F->Fim->prox = Elemento;
        }

        F->Fim = Elemento;
        F->Tamanho++;
    }
    else{
        cout << "N�o h� mais espa�o na pilha de alunos!!" << endl;
    }
}


Item* Desenfileira(Fila *F){
    Item *Ret = NULL;

    if (Fila_Vazia(F) == 0){

        Ret = F->Inicio;
        F->Inicio = F->Inicio->prox;

        if(F->Tamanho == 1){
            F->Fim = NULL;
        }

        F->Tamanho--;
    }
    else{
        cout << "Fila vazia!!" << endl;
    }

    return Ret;
}

void Imprime_Fila(Fila *F){
    Item *Cont;

    system("cls");

    cout<<"Elementos";

    for (Cont=F->Inicio; Cont!=NULL; Cont = Cont->prox){
        cout<<"\t"<<Cont->elemento<<"\t";
    }
}


//Pilha 1 e Pilha 2
Pilha P;
Pilha P_2;

//Fila
Fila F;
int escolha, escola_tipo_lista;
char num, ele;

int main(){
    setlocale(LC_ALL,"Portuguese");


    cout << "Escolha a estrutura: Pilha: 1 ou Fila: 2";
    cin >> escola_tipo_lista;

    if(escola_tipo_lista == 1){

        cout << "Escolha: Pilha 1: 1 ou Pilha 2: 2 ";
        cin >> escolha;

        if(escolha == 1){

            Ini_Pilha(&P);

            cout << "Digite um numero : ";
            cin >> num;

            Empilhar(&P, 'num');
            Emprimir(&P);

        }else{

            Ini_Pilha(&P_2);

            cout << "Digite um elemento: ";
            cin >> ele;

            Empilhar(&P_2, 'num');
            Emprimir(&P_2);


        }
    }else{
        if(escola_tipo_lista == 2){

            Ini_Fila(&F);

            cout << "Digite um numero ou um elemento: ";
            cin >> ele;

            Enfileira(&F, ele);

            Desenfileira(&F);

            Imprime_Fila(&F);

        }
    }







}

