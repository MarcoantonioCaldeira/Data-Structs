#include<iostream>
#include<stdlib.h>
#include <string.h>
#include<stdio.h>

using namespace std;

char Contar_Caracteres_Frase(char *v_frase){
	int tamanho;
	
	
	v_frase = (char *) malloc(sizeof(char));
	
	cout << "Digite uma frase: ";
	gets(v_frase);
	
	tamanho = strlen(v_frase);
	
	
	cout << "O tamanho da sua frase eh: " << tamanho;
}


int main(){
	
	char *frase;
	
	Contar_Caracteres_Frase(frase);
	
	
}
