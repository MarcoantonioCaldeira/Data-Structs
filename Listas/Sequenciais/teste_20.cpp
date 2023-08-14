#include <iostream>
#include <stdlib.h>

using namespace std;

#define MAX_PROD 50

//Item da lista
struct Produto{
    int Codigo;
    string Nome;
    float Preco;
};

//Lista (Cabe�alho - resumo da lista)
struct Compras{
    Produto Lista[MAX_PROD];
    int Tamanho;
    float Total;
};

void criarLista(Compras *C){ //Cria uma lista vazia
    C->Tamanho = 0;    
    C->Total = 0;
}

int vazia(Compras *C){ //Verifica se a lista est� vazia (1 - Vazia, 0 - Tem mais de 1 elemento)
    int Ret;

    if (C->Tamanho == 0){
        Ret = 1;
    }
    else{
        Ret = 0;
    }    

    return Ret;
}

int cheia(Compras *C){
    int Ret;

    if (C->Tamanho == MAX_PROD){
        Ret = 1;
    }
    else{
        Ret = 0;
    }    

    return Ret;
}

int tamanho(Compras *C){
    return C->Tamanho;
}

Produto * elemento(Compras *C, int Pos){ //Retorna o c�digo
    int Codigo = -1;
    Produto *P;
    
    if (Pos<C->Tamanho){
        P = (Produto *) malloc(sizeof(Produto));
        if (P != NULL){
            //P = C->Lista + Pos;
            P->Codigo =  C->Lista[Pos].Codigo;
            P->Nome = C->Lista[Pos].Nome;
            P->Preco = C->Lista[Pos].Preco;            
        }
    }
    
    return P;
}

int posicao(Compras *C, int Codigo){
    int Pos = -1, Cont = 0;
    
    //Lista n�o pode ser vazia
    //N�o pode passar do �ltimo elemento
    //N�o encontrar o elemento
    if (!vazia(C)){
        while((Cont <= C->Tamanho-1) && (Pos<0)){
            if(C->Lista[Cont].Codigo != Codigo){        
                Cont++;    
            }                
            else{ //Achou!!!
                Pos = Cont;
            }
        }        
    }
        
    return Pos;
}

int posicaoIns(Compras *C, int Codigo){
    int Pos = -1, Cont = 0;
    
    //Busca a posi��o de inser��o, ou seja, primeiro elemento maior
    if (!vazia(C)){
        while((Cont <= C->Tamanho-1) && (Pos<0)){
            if(C->Lista[Cont].Codigo < Codigo){        
                Cont++;    
            }                
            else{ //Achou a posi��o!!!
                Pos = Cont;
            }
        }        
        
        if (Pos == -1){ //N�o encontrou, insere na �ltima posi��o
            Pos = tamanho(C); //C->Tamanho
        }
    }
    else{ //Vazia
        Pos = 0;
    }
        
    return Pos;
}


void Desloca_Valores_Esq(Compras *C, int Inicio, int Fim){ //para remo��o
    int Cont;
    
    for (Cont=Inicio; Cont < Fim; Cont++){
        C->Lista[Cont] = C->Lista[Cont+1];
    }    
}

void Desloca_Valores_Dir(Compras *C, int Inicio, int Fim){ //para remo��o
    int Cont;
    
    for (Cont=Fim; Cont >= Inicio; Cont--){
        C->Lista[Cont+1] = C->Lista[Cont];
    }    
}

int inserir(Compras *C, int Codigo, string Nome, float Preco){    
    int Ret = 1, Pos;

    if (cheia(C) == 0){ //H� espa�o!!
        Pos = posicao(C, Codigo); //Verifica se j� existe
        if (Pos == -1){
            Pos = posicaoIns(C, Codigo);
            Desloca_Valores_Dir(C, Pos, tamanho(C)-1);
            C->Lista[Pos].Codigo = Codigo;
            C->Lista[Pos].Nome = Nome;
            C->Lista[Pos].Preco = Preco;
            
            C->Tamanho++;
            C->Total = C->Total + Preco;            
        }
        else{
            Ret = -2; //Item j� existe!!!
        }    
    }
    else{
        Ret = -1; //Lista Cheia
    }
    
    return Ret;
}

int remover(Compras *C, int Codigo){    
    int Ret = 1, Pos;

    if (vazia(C) == 0){
        Pos = posicao(C, Codigo);
        if (Pos >= 0){
            C->Total = C->Total - C->Lista[Pos].Preco;
            Desloca_Valores_Esq(C, Pos, tamanho(C)-1); //C->Tamanho -1
            C->Tamanho--;            
        }    
        else{
            Ret = -2; //Item n�o existe
        }
    }
    else{ //Vazia
        Ret = -1;
    }
    
    return Ret;
}

void ImprimirRec(Compras *C, int Pos){
    
    if (Pos < C->Tamanho){
        cout << "Item "<< Pos << ": " << endl;
        cout << "     C�digo: "<<C->Lista[Pos].Codigo << endl;
        cout << "     Nome: "<<C->Lista[Pos].Nome << endl;
        cout << "     Pre�o: "<<C->Lista[Pos].Preco << endl;
        cout << endl;
        cout << endl;
        
        ImprimirRec(C, Pos + 1);
    }    
}

void imprimir(Compras *C){
    int Cont;
    
    cout << endl;
    cout << endl;
    cout << "------ IMPRESS�O ------"<< endl;
    /*for(Cont=0;Cont<C->Tamanho;Cont++){
        cout << "Item "<< Cont << ": " << endl;
        cout << "     C�digo: "<<C->Lista[Cont].Codigo << endl;
        cout << "     Nome: "<<C->Lista[Cont].Nome << endl;
        cout << "     Pre�o: "<<C->Lista[Cont].Preco << endl;
        cout << endl;
        cout << endl;
    }*/
    ImprimirRec(C,0);
    cout << "-----------------------" << endl;
    cout << "Total de itens: " << C->Tamanho << endl;
    cout << "Valor a pagar: " << C->Total << endl;
    
}

void MostraErro(char Op, int CodErro){
    switch (Op){
        case 'I':
            switch (CodErro){
                case -1:
                    cout << "Erro de inser��o: Lista cheia!!";
                    break;
                case -2:
                    cout << "Erro de inser��o: Item j� existe!!";        
                    break;
                default: //1
                    cout << "Inser��o OK!!";        
            }
            break;
        case 'R':
            switch (CodErro){
                case -1:
                    cout << "Erro de remo��o: Lista vazia!!";
                    break;
                case -2:
                    cout << "Erro de remo��o: Item n�o encontrado!!";        
                    break;
                default: //1
                    cout << "Remo��o OK!!";        
            }
            break;            
    }
    cout << endl;
}

Compras L;
int Ret;
int main(){    
    setlocale(LC_ALL,"Portuguese");
    
    criarLista(&L);
    
    //MostraErro('R',remover(&L,1));    
    MostraErro('I', inserir(&L,3,"Pasta de Dentes",12.5));
    imprimir(&L);
    system("pause");
    MostraErro('I', inserir(&L,2,"Papel higi�nico",10.3));
    imprimir(&L);
    system("pause");    
    MostraErro('I', inserir(&L,1,"Sabonete",5));    
    //MostraErro('I', inserir(&L,1,"Sabonete",5));
    
    imprimir(&L);
        
    MostraErro('R',remover(&L,3));    
    MostraErro('R',remover(&L,1));    

    imprimir(&L);
        
    
    return 0;
}
