#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

//Criando o Item
struct ItemSentenca{
    string Valor;
    int Precedencia;
    ItemSentenca *Prox;
};

struct Pilha{
    ItemSentenca *Topo;
    int Total;
};

struct Fila{
    ItemSentenca *Inicio;
    ItemSentenca *Fim;
    int Total;
};

void Ini_Pilha(Pilha *P){
    P->Topo == NULL;
    P->Total = 0;
}

void Ini_Fila(Fila *F){
    F->Inicio = NULL;
    F->Fim = NULL;
    F->Total = 0;
}

int Pilha_Vazia(Pilha *P){

    return (P->Topo == NULL);
}

int Fila_Vazia(Fila *F){

    return (F->Inicio == NULL);
}

ItemSentenca *Criar_Item(string Valor, int Prec){
    ItemSentenca *ItemSent;

    ItemSent = new ItemSentenca;
    if(ItemSent != NULL){
        ItemSent->Valor = Valor;
        ItemSent->Precedencia = Prec;
        ItemSent->Prox = NULL;
    }
}

int Empilhar(Pilha *P, string Valor, int Prec){
    int Ret=1;
    ItemSentenca *ItemSent;

    ItemSent = Criar_Item(Valor, Prec);
    if(ItemSent == NULL){
        Ret = -1;
    }else{
        ItemSent->Prox = P->Topo;
        P->Topo = ItemSent;

        P->Total++;
    }

    return Ret;
}

ItemSentenca *Desempilhar(Pilha *P){
    ItemSentenca *Ret;

    if(Pilha_Vazia(P)){
        Ret = NULL;
    }else{
        Ret = P->Topo;
        P->Topo = P->Topo->Prox;
        P->Total--;
    }

    return Ret;
}

int Enfileirar(Fila *F, string Valor){
    int Ret=1;
    ItemSentenca *ItemSent;

    ItemSent = Criar_Item(Valor, -2);
    if(ItemSent == NULL){
        Ret = -1;
    }else{
        if(Fila_Vazia(F)){
            F->Inicio = ItemSent;
        }
        else{
            F->Fim->Prox = ItemSent;
        }

        F->Fim = ItemSent;
        F->Total++;
    }
    return Ret;
}

ItemSentenca* Desenfileirar(Fila *F){
    ItemSentenca* Ret;

    if(Fila_Vazia(F)){
        Ret = NULL;
    }else{
        Ret = F->Inicio;

        F->Inicio = F->Inicio->Prox;
        F->Total--;

        if(Fila_Vazia(F)){
            F->Fim = F->Inicio;
        }
    }

    return Ret;
}

void Imprime_Lista(ItemSentenca* Item){

    if (Item != NULL){
        cout << Item->Valor << ", ";
        Imprime_Lista(Item->Prox);
    }
}

void Limpa_Lista(ItemSentenca *Item){

    if(Item != NULL){
        Limpa_Lista(Item->Prox);
        free(Item);
    }
}

int Calc_Precedencia(string Valor){
    int Ret = -1;

    if ((Valor == "*") || (Valor == "/") ){
        Ret = 2;
    }
    else{
        if ( (Valor == "+") || (Valor == "-")){
            Ret = 1;
        }
        else{
            if (Valor == "<="){
                Ret = 0;
            }
        }
    }

    return Ret;
}

float Resolve_Expressao(float Num1, float Num2, string Op){
    float Res;

    if(Op == "*"){
        Res = Num1 * Num2;
    }else{

        if (Op == "/"){
            Res = Num1 / Num2;
        }
        else{
            if (Op == "+"){
                Res = Num1 + Num2;
            }
            else{
                if (Op == "-"){
                    Res = Num1 - Num2;
                }
                else{// <=
                    Res = Num1 <= Num2;
                }
            }
        }
    }
    return Res;
}

void Resolve_Pilhas(Pilha *Pilha_Num, Pilha *Pilha_Op){
    string Res, Op;
    float Num1, Num2;
    ItemSentenca* Item;

    //Desempilha os n�meros
    Item = Desempilhar(Pilha_Num);
    Num2 = stof(Item->Valor);
    Item = Desempilhar(Pilha_Num);
    Num1 = stof(Item->Valor);

    //Desempilha o operador
    Item = Desempilhar(Pilha_Op);
    Op = Item->Valor;
    Res = to_string(Resolve_Expressao(Num1, Num2, Op));

    //Atualiza a pilha de n�meros
    Empilhar(Pilha_Num, Res, -1);
}

float Calc_Expressao(Fila *F){
    float Ret = -101010;
    int Prec, FlagRepete;
    string Res;
    Pilha Pilha_Num, Pilha_Op;
    ItemSentenca* Item;

    if (!Fila_Vazia(F)){
        Ini_Pilha(&Pilha_Num);
        Ini_Pilha(&Pilha_Op);

        do{
            Item = Desenfileirar(F);
            if (Item != NULL){
                Prec = Calc_Precedencia(Item->Valor);
                if (Prec == -1){ //N�mero
                    Empilhar(&Pilha_Num, Item->Valor, Prec);
                }
                else{ //Operador
                    //1 - Se a pilha t� vazia, empilha
                    //2 - Se o operador da fila tem preced�ncia maior que
                    //    o operador da pilha, empilha
                    //	  Sen�o fazer a baixa simples da pilha
                    do{
                        if (Pilha_Vazia(&Pilha_Op) == 1 ||
                            Prec > Pilha_Op.Topo->Precedencia){
                            Empilhar(&Pilha_Op, Item->Valor, Prec);
                            FlagRepete = 0;
                        }
                        else{
                            Resolve_Pilhas(&Pilha_Num, &Pilha_Op);
                            FlagRepete = 1;
                        }
                    }while (FlagRepete == 1);
                }
            }
            else{
                //Baixar pilha de operadores fazendo o c�lculo
                Resolve_Pilhas(&Pilha_Num, &Pilha_Op);
            }
        }while(F->Total > 0 || Pilha_Op.Total > 0 );

        Ret = stof(Pilha_Num.Topo->Valor);
    }

    return Ret;
}

Fila F;
int main(){
    setlocale(LC_ALL,"Portuguese");

    Ini_Fila(&F);

    Enfileirar(&F,"14");
    Enfileirar(&F,"<=");
    Enfileirar(&F,"4");
    Enfileirar(&F,"-");
    Enfileirar(&F,"3");
    Enfileirar(&F,"*");
    Enfileirar(&F,"2");
    Enfileirar(&F,"+");
    Enfileirar(&F,"7");

    cout << endl << endl << "--------------------------------------"<< endl;
    cout << "Resultado: " << Calc_Expressao(&F);

    Limpa_Lista(F.Inicio);

    return 0;
}