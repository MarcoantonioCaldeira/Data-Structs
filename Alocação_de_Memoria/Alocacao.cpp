#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;


int main(){
	
	char *v_nome;
	v_nome = (char *) malloc(sizeof(char));
	
	gets(v_nome);
	
	cout << v_nome;
	return 0;
}
