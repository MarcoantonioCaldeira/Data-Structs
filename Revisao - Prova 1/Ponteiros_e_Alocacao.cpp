#include<iostream>

using namespace std;


int main(){

//
//    string Carro = "Honda Civic";
//    string *p;
//
//
//    p = &Carro;
//
//    cout << "Endereco de Memoria: " << p;
//    cout << endl <<"Valor da variavel: " << *p;

    //Manipulando elementos de Array

    int *po;
    int vet[10];
    int cont = 0;

//    po=vet; //Endereco de memoria do primeiro elemento do vetor
//    po=&vet[1]; //Mesma coisa

    while(cont <= 10){

        cout << "Digite um valor: ";
        cin >> vet[cont];

        po = &vet[cont];
        cont ++;

       cout << endl << po << "numero: " << *po  << endl;

    }




    return 0;
}