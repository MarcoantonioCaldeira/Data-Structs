#include<iostream>
#include <locale.h> 
#include <stdlib.h> 

using namespace std;

int* Retorna_Num(int Num){
	int *num;
	
	if(Num <= 0){
		
		Num == NULL;
		
	}else{
	 
		num = (int *) malloc(Num * sizeof(int));			
	}
	
	return num;
}


int main(){
	
	int *vet = Retorna_Num(10);
	
	cout << *vet;
	cout << endl << vet;
	
	
	if(vet != NULL){
		
		cout << endl << "Alocado corretamente!!!";
		
	}else{
		
		cout << "Não foi alocado corretamente";
	}
}
