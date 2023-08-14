#include<iostream>

using namespace std;




int Multiplicacao_Sucessiva(int base, int num){
    int Res;

    if(num > 0){
        Res = base + Multiplicacao_Sucessiva(base, num-1);
    }

    return Res;
}


int main(){

   cout << Multiplicacao_Sucessiva(2, 5);
}
