#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define MAX_V1 10
#define MAX_V2 100

struct Dados{
    int Valor;
    int Ordem;
};

//Carrega o vetor com valores aleat�rios
void CarregaLista(Dados *L, int GeraDados){
    int Cont;

    if (GeraDados){
        for(Cont=0;Cont<MAX_V2;Cont++){
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

void SelectionSort(Dados *L, int Tam){
    int Cont1, Cont2, Min;

    for(Cont1=0;Cont1<Tam;Cont1++){
        Min = Cont1;

        //Procura o valor m�nimo na lista n�o ordenada
        for (Cont2=Cont1+1;Cont2<Tam;Cont2++) {
            if (L[Min].Valor > L[Cont2].Valor){
                Min = Cont2;
            }
        }

        //Move o valor encontrado pra lista ordenada
        Swap(L, Cont1, Min);

        /*cout << endl << endl << "Altera��es para Cont1: " << Cont1 << endl;
        ImprimeLista(L);
        cout << endl;
        system("pause");*/
    }
}


void SelectionSortRec(Dados *L, int Inicio, int Fim){
    int Cont, Min;

    if (Inicio<=Fim){
        Min = Inicio;

        //Procura o valor m�nimo na lista n�o ordenada
        for (Cont=Inicio+1;Cont<=Fim;Cont++) {
            if (L[Min].Valor > L[Cont].Valor){
                Min = Cont;
            }
        }

        //Move o valor encontrado pra lista ordenada
        Swap(L, Inicio, Min);

        /*cout << endl << endl << "Altera��es para Cont1: " << Cont1 << endl;
        ImprimeLista(L);
        cout << endl;
        system("pause");*/

        SelectionSortRec(L, Inicio+1, Fim);
    }
}

void SelectionSortRecBT(Dados *L, int Inicio, int Fim){
    int Cont, Min;

    if (Inicio<=Fim){
        Min = (Fim - Inicio);

        SelectionSortRecBT(L, Inicio+1, Fim);

        //Procura o valor m�nimo na lista n�o ordenada
        for (Cont=(Fim - Inicio)+1;Cont<=Fim;Cont++) {
            if (L[Min].Valor > L[Cont].Valor){
                Min = Cont;
            }
        }

        //Move o valor encontrado pra lista ordenada
        Swap(L, (Fim - Inicio), Min);

        /*cout << endl << endl << "Altera��es para Cont1: " << Cont1 << endl;
        ImprimeLista(L);
        cout << endl;
        system("pause");*/


    }
}

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

void MergeSort(Dados* L, int Inicio, int Fim, int Debug){
    int Meio, Cont, ContA, ContB;
    Dados* Aux;

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
        Aux = (Dados *) malloc(sizeof(Dados) * (Fim - Inicio + 1));
        if (Debug) {
            cout << "\nInicio: " << Inicio << " Meio: " << Meio << " Fim: " << Fim;
            cout << "\nContA:" << ContA;
            cout << "\nContB:" << ContB;
            cout << "\nCont:" << Cont << "\n";
            system("pause");
        }
        while (ContA <= Meio || ContB <= Fim){
            if (ContA > Meio){ //final do VetorA
                Aux[Cont] = L[ContB];

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
                    if (L[ContA].Valor < L[ContB].Valor){ //meio do VetorA
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
            L[Cont].Valor = Aux[Cont - Inicio].Valor;
            L[Cont].Ordem = Aux[Cont - Inicio].Ordem;
            if (Debug) {
                cout << "L["<<Cont<<"].Valor = Aux[" <<Cont - Inicio<<"] (" <<Aux[Cont - Inicio].Valor<<")" << "\n";
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

    CarregaLista(Lista,0);
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
    MergeSort(Lista, 0, MAX_V1-1, 1);

    T = clock() - T;//tempo decorrido!!

    if (MAX_V2 <= 100){
        cout << endl << endl << "Lista ordenada" << endl << endl;
        ImprimeLista(Lista);
    }

    cout << endl << endl << "Tempo de Ordena��o: " << ((double) T)/((CLOCKS_PER_SEC/1000)) << " milisegundos.";

    return 0;
}