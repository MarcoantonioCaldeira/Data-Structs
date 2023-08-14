#include<iostream>

using namespace std;


//int Mostra_Nome(string nome, int cont){
//    int re;
//
//    if(cont >= 0){
//
//        cout << endl << nome;
//        re = Mostra_Nome(nome, cont - 1);
//    }
//
//    return re;
//
//}


int Fatorial_Num(int num){
    int re;

    if(num == 1){

        return 1;

    }else{
        re = num * Fatorial_Num(num-1);
    }

    return re;

}


int main(){
    string nome;
    int cont;


//    cout << "Digite o seu nome: ";
//    cin >> nome;
//
//    cout << "Qual a quantidade de vezes?: ";
//    cin >> cont;
//
//    cout << Mostra_Nome(nome, cont);

      cout << Fatorial_Num(5);
}
