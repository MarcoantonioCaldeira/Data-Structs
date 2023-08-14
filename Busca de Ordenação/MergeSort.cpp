#include <iostream>
#include <stdlib.h>
#include<string.h>
#include <time.h>

using namespace std;

#define Tam 50

struct Time{
    int Codigo;
    string Nome;
    int Ano_f;
};

struct Liga{ //Header/Cabe�alho
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

void Desloca_Valores_Dir(Liga *L, int Inicio, int Fim){ //para inser��o em uma posi��o determinada
    int Cont;

    for (Cont=Fim; Cont >= Inicio; Cont--){
        L->Lista[Cont+1] = L->Lista[Cont];
    }

}

void Desloca_Valores_Esq(Liga *L, int Inicio, int Fim){ //para remo��o
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
    int Ret=1, Pos; //C�digo de Erro

    if (Lista_Cheia(L)){
        Ret = -1; //Lista cheia
    }
    else{
        //Procura se time j� existe
        Pos = -1;//Posicao(L,Codigo);
        if (Pos >=0){
            Ret = -2;
        }
        else{
            /*Pos = PosicaoIns(L,Codigo);
            //Insere no fim
            if (Pos < L->Total){
                Desloca_Valores_Dir(L, Pos, L->Total-1);
            }*/
            Pos = L->Total;
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
        else{ //Time n�o existe!!
            Ret = -2;
        }
    }

    return Ret;
}

void Imprime_Lista(Liga *L){
    int Cont;

    for(Cont=0;Cont<L->Total;Cont++){
        cout << endl << "Time[" <<Cont<<"]";
        cout << endl << "C�digo: " << L->Lista[Cont].Codigo;
        cout << endl << "Nome: " << L->Lista[Cont].Nome;
        cout << endl << "Ano funda��o: " << L->Lista[Cont].Ano_f << endl;
    }
}



//Carrega o vetor com valores aleat�rios
void CarregaLista(Dados *L, int GeraDados){
    int Cont;

    if (GeraDados){
        for(Cont=0;Cont<Tam;Cont++){
            L[Cont].Valor = rand()%100;
            L[Cont].Ordem = Cont;
        }
    }
    else{
        L[0].Valor = 3; L[1].Valor = 3; L[2].Valor = 1; L[3].Valor = 2; L[4].Valor = 7;
        L[0].Ordem = 0; L[1].Ordem = 1; L[2].Ordem = 2; L[3].Ordem = 3; L[4].Ordem = 4;
        L[5].Valor = 0; L[6].Valor = 5; L[7].Valor = 4; L[8].Valor = 9; L[9].Valor = 6;
        L[5].Ordem = 5; L[6].Ordem = 6; L[7].Ordem = 7; L[8].Ordem = 8; L[9].Ordem = 9;
    }
}

void Swap(Dados *L, int PosA, int PosB){
    Dados Aux;

    Aux = L[PosA];
    L[PosA] = L[PosB];
    L[PosB] = Aux;
}

//void SelectionSort(Dados *L, int Tam){
//    int Cont1, Cont2, Min;
//
//    for(Cont1=0;Cont1<Tam;Cont1++){
//        Min = Cont1;
//
//        //Procura o valor m�nimo na lista n�o ordenada
//        for (Cont2=Cont1+1;Cont2<Tam;Cont2++) {
//            if (L[Min].Valor > L[Cont2].Valor){
//                Min = Cont2;
//            }
//        }
//
//        //Move o valor encontrado pra lista ordenada
//        Swap(L, Cont1, Min);
//
//        /*cout << endl << endl << "Altera��es para Cont1: " << Cont1 << endl;
//        ImprimeLista(L);
//        cout << endl;
//        system("pause");*/
//    }
//}


//void SelectionSortRec(Dados *L, int Inicio, int Fim){
//    int Cont, Min;
//
//    if (Inicio<=Fim){
//        Min = Inicio;
//
//        //Procura o valor m�nimo na lista n�o ordenada
//        for (Cont=Inicio+1;Cont<=Fim;Cont++) {
//            if (L[Min].Valor > L[Cont].Valor){
//                Min = Cont;
//            }
//        }
//
//        //Move o valor encontrado pra lista ordenada
//        Swap(L, Inicio, Min);
//
//        /*cout << endl << endl << "Altera��es para Cont1: " << Cont1 << endl;
//        ImprimeLista(L);
//        cout << endl;
//        system("pause");*/
//
//        SelectionSortRec(L, Inicio+1, Fim);
//    }
//}
//
//void SelectionSortRecBT(Dados *L, int Inicio, int Fim){
//    int Cont, Min;
//
//    if (Inicio<=Fim){
//        Min = (Fim - Inicio);
//
//        SelectionSortRecBT(L, Inicio+1, Fim);
//
//        //Procura o valor m�nimo na lista n�o ordenada
//        for (Cont=(Fim - Inicio)+1;Cont<=Fim;Cont++) {
//            if (L[Min].Valor > L[Cont].Valor){
//                Min = Cont;
//            }
//        }
//
//        //Move o valor encontrado pra lista ordenada
//        Swap(L, (Fim - Inicio), Min);
//
//        /*cout << endl << endl << "Altera��es para Cont1: " << Cont1 << endl;
//        ImprimeLista(L);
//        cout << endl;
//        system("pause");*/
//
//
//    }
//}

void InsertionSort(Dados *L, int Tam){
    int Cont1, Cont2;

    for(Cont1=1;Cont1<Tam;Cont1++){
        Cont2 = Cont1; //Pr�ximo item da lista n�o ordenada

        //Move o pr�ximo item da lista n�o ordenada para
        //a posi��o correta na lista ordenada
        while (Cont2 > 0 && L[Cont2].Valor < L[Cont2-1].Valor ) {
            //Move o valor encontrado pra lista ordenada
            Swap(L, Cont2, Cont2-1);

            Cont2--;
        }

        /*cout << endl << endl << "Altera��es para Cont1: " << Cont1 << endl;
        ImprimeLista(L);
        cout << endl;
        system("pause");*/
    }
}

void BubbleSort(Dados *L , int Tam){
    int Cont1, Cont2, FezSwap;

    Cont1=0;
    do{
        FezSwap = 0;

        //Traz, a partir do fim da lista, cada menor valor
        //at� achar algum valor maior que ele. Se achar,
        //passa a fazer o mesmo com esse novo valor

        for (Cont2=Tam-1;Cont2>Cont1;Cont2--) {
            if (L[Cont2].Valor < L[Cont2-1].Valor){
                //Troca os valores de posi��o
                Swap(L, Cont2, Cont2-1);
                FezSwap = 1;

                /*cout << endl << endl << "Altera��es para Cont1: " << Cont1 << endl;
                ImprimeLista(L);
                cout << endl;
                system("pause");  */
            }
        }

        Cont1++;
    } while (Cont1<Tam && FezSwap==1);
}

void MergeSort(Liga *L, int Inicio, int Fim, int Debug){
    int Meio, Cont, ContA, ContB;
    Time* Aux;

    if (Inicio < Fim){
        Meio = (Inicio + Fim)/2;

        //Quebra em vetores menores (metade)
        if (Debug) {
            cout << "\nMergeSort(" << Inicio << "," << Meio << ")\n";
            system("pause");
        }
        MergeSort(L, Inicio, Meio, Debug); //VetorA
        if (Debug) {
            cout << "\nMergeSort(" << Meio+1 << "," << Fim << ")\n";
            system("pause");
        }
        MergeSort(L, Meio+1, Fim, Debug); //VetorB

        //Junta as partes (merge), pegando sempre o menor elemento de cada parte
        //de forma ordenada
        ContA = Inicio;
        ContB = Meio+1;
        Cont = 0;

        Aux = (Time *) malloc(sizeof(Time) * (Fim - Inicio + 1));
        if (Debug) {
            cout << "\nInicio: " << Inicio << " Meio: " << Meio << " Fim: " << Fim;
            cout << "\nContA:" << ContA;
            cout << "\nContB:" << ContB;
            cout << "\nCont:" << Cont << "\n";
            system("pause");
        }
        while (ContA <= Meio || ContB <= Fim){
            if (ContA > Meio){ //final do VetorA
                Aux[Cont] = L->Lista[ContB];

                if (Debug) {
                    cout << "\nJ� processou vetor esquerdo (A). Copiando vetor direito (B)";
                    cout << "\nContA:" << ContA;
                    cout << "\nContB:" << ContB;
                    cout << "\nCont:" << Cont << "\n";
                    system("pause");
                }
                ContB++;
            }
            else{
                if (ContB > Fim){ //final do VetorB
                    Aux[Cont] = L->Lista[ContA];

                    if (Debug) {
                        cout << "\nJ� processou vetor direito (B). Copiando vetor esquerdo (A)";
                        cout << "\nContA:" << ContA;
                        cout << "\nContB:" << ContB;
                        cout << "\nCont:" << Cont << "\n";
                        system("pause");
                    }
                    ContA++;
                }
                else{
                    if (L->Lista[ContA].Valor < L->Lista[ContB].Valor){ //meio do VetorA
                        Aux[Cont] = L->Lista[ContA];

                        if (Debug) {
                            cout << "\n1� item do vetor esquerdo (A) menor do que 1� item do vetor direito (B). Copiando item do vetor (A) para Aux.";
                            cout << "\nContA:" << ContA;
                            cout << "\nContB:" << ContB;
                            cout << "\nCont:" << Cont << "\n";
                            system("pause");
                        }
                        ContA++;
                    }
                    else{ //meio do VetorB
                        Aux[Cont].Codigo = L->Lista[ContB];
                        if (Debug) {
                            cout << "\n1� item do vetor direito (B) menor ou igual do que 1� item do vetor esquerdo (A). Copiando item do vetor (B) para Aux.";
                            cout << "\nContA:" << ContA;
                            cout << "\nContB:" << ContB;
                            cout << "\nCont:" << Cont << "\n";
                            system("pause");
                        }
                        ContB++;
                    }
                }
            }
            Cont++; //passa para a pr�xima posi��o do vetor com o merge
        }
        //cout << endl << "Valor de Cont: " << Cont;
        //Copia o merge ordenado dos vetores para o vetor original
        for(Cont=Inicio;Cont<=Fim;Cont++){

            L->Lista[Cont].Codigo = Aux[Cont - Inicio].Valor;

            if (Debug) {
                cout << "L["<<Cont<<"].Valor = Aux[" <<Cont - Inicio<<"] (" <<Aux[Cont - Inicio].Valor<<")" << "\n";
                system("pause");
            }
        }

        free(Aux);
    }
}


void MergeSort(Liga *L, int Inicio, int Fim, int Debug){
    int Meio, Cont, ContA, ContB;
    Time *Aux;

    if (Inicio < Fim){
        Meio = (Inicio + Fim)/2;

        //Quebra em vetores menores (metade)
        if (Debug) {
            cout << "\nMergeSort(" << Inicio << "," << Meio << ")\n";
            system("pause");
        }
        MergeSort(L, Inicio, Meio, Debug); //VetorA

        if (Debug) {
            cout << "\nMergeSort(" << Meio+1 << "," << Fim << ")\n";
            system("pause");
        }

        MergeSort(L, Meio+1, Fim, Debug); //VetorB

        //Junta as partes (merge), pegando sempre o menor elemento de cada parte
        //de forma ordenada

        ContA = Inicio;
        ContB = Meio+1;
        Cont = 0;
        Aux = (Time *) malloc(sizeof(Time) * (Fim - Inicio + 1));
        if (Debug) {
            cout << "\nInicio: " << Inicio << " Meio: " << Meio << " Fim: " << Fim;
            cout << "\nContA:" << ContA;
            cout << "\nContB:" << ContB;
            cout << "\nCont:" << Cont << "\n";
            system("pause");
        }

        while (ContA <= Meio || ContB <= Fim){
            if (ContA > Meio){ //final do VetorA

                Aux[Cont].Codigo = L->Lista[ContB].Codigo;
                Aux[Cont].Nome = L->Lista[ContB].Nome;
                Aux[Cont].Ano_f = L->Lista[ContB].Ano_f;

                if (Debug) {
                    cout << "\nJ� processou vetor esquerdo (A). Copiando vetor direito (B)";
                    cout << "\nContA:" << ContA;
                    cout << "\nContB:" << ContB;
                    cout << "\nCont:" << Cont << "\n";
                    system("pause");
                }
                ContB++;
            }
            else{
                if (ContB > Fim){ //final do VetorB
                    Aux[Cont] = L[ContA];

                    if (Debug) {
                        cout << "\nJ� processou vetor direito (B). Copiando vetor esquerdo (A)";
                        cout << "\nContA:" << ContA;
                        cout << "\nContB:" << ContB;
                        cout << "\nCont:" << Cont << "\n";
                        system("pause");
                    }
                    ContA++;
                }
                else{
                    if (L[ContA].Codigo < L[ContB].Codigo){ //meio do VetorA
                        Aux[Cont] = L[ContA];

                        if (Debug) {
                            cout << "\n1� item do vetor esquerdo (A) menor do que 1� item do vetor direito (B). Copiando item do vetor (A) para Aux.";
                            cout << "\nContA:" << ContA;
                            cout << "\nContB:" << ContB;
                            cout << "\nCont:" << Cont << "\n";
                            system("pause");
                        }
                        ContA++;
                    }
                    else{ //meio do VetorB
                        Aux[Cont] = L[ContB];
                        if (Debug) {
                            cout << "\n1� item do vetor direito (B) menor ou igual do que 1� item do vetor esquerdo (A). Copiando item do vetor (B) para Aux.";
                            cout << "\nContA:" << ContA;
                            cout << "\nContB:" << ContB;
                            cout << "\nCont:" << Cont << "\n";
                            system("pause");
                        }
                        ContB++;
                    }
                }
            }
            Cont++; //passa para a pr�xima posi��o do vetor com o merge
        }
        //cout << endl << "Valor de Cont: " << Cont;
        //Copia o merge ordenado dos vetores para o vetor original
        for(Cont=Inicio;Cont<=Fim;Cont++){
            L->Lista[Cont].Valor = Aux[Cont - Inicio].Valor;

            if (Debug) {
                cout << "L["<<Cont<<"].Codigo = Aux[" <<Cont - Inicio<<"] (" <<Aux[Cont - Inicio].Codigo <<")" << "\n";
                system("pause");
            }
        }
        free(Aux);
    }
}

void ImprimeLista(Dados *L){
    int Cont;

    for(Cont=0;Cont<MAX_V1;Cont++){
        cout <<    "[" << L[Cont].Ordem << "] " << L[Cont].Valor << ", ";
    }
}

Dados Lista[MAX_V2];
clock_t T;

int main(){
    setlocale(LC_ALL,"Portuguese");

    //CarregaLista(Lista,0);
    //CarregaLista(Lista,1);


    if (MAX_V2 <= 100){
        cout << endl << endl << "Lista original" << endl << endl;
        ImprimeLista(Lista);
    }

    T = clock();
    //SelectionSort(Lista, MAX_V2);
    //SelectionSortRec(Lista, 0, MAX_V1-1);
    //SelectionSortRecBT(Lista, 0, MAX_V1-1);
    //InsertionSort(Lista, MAX_V2);
    //BubbleSort(Lista, MAX_V2);
    MergeSort(&T, 0, T, T);

    T = clock() - T;//tempo decorrido!!

    if (MAX_V2 <= 100){
        cout << endl << endl << "Lista ordenada" << endl << endl;
        ImprimeLista(Lista);
    }

    cout << endl << endl << "Tempo de Ordena��o: " << ((double) T)/((CLOCKS_PER_SEC/1000)) << " milisegundos.";

    return 0;
}