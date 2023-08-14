#include <iostream>
#include <stdlib.h>
#include <time.h>

#define Tam 10
using namespace std;

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

