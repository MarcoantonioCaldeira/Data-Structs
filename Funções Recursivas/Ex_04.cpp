#include<iostream>
#include<stdlib.h>
#include<stdlib.h>


using namespace std;


int* Retorna_Num(int tam){
	int cont, *vet;
	
	vet = (int *) malloc(tam * sizeof(int));
	
	for(cont = 0; cont < tam; cont++){
		
		cout << "Digite o elemento do vetor: ";
		cin >> vet[cont];
	}
	
	return vet;
		
}


int* Realizar_Soma(int tam, int *vet_a, int *vet_b){
	
	int cont, *vet_c;
	
	vet_c = (int *) malloc(tam *sizeof(int));
	
	for(cont = 0; cont < tam; cont++){
		
		vet_c[cont] = vet_a[cont] + vet_b[cont];
	}
	
	return vet_c;
	
}

int main(){
	
	int *vet_a, *vet_b, *vet_c, cont, i, tamanho;
	
	cout << "Digite o tamanho desejado: ";
	cin >> tamanho;
	
	vet_a = Retorna_Num(tamanho);
	vet_b = Retorna_Num(tamanho);
	
	vet_c = Realizar_Soma(tamanho, vet_a, vet_b);
	
	
	for(i = 0; i < tamanho; i++){
		
		cout << "Numero: " << vet_c[i];
	}
	
	free(vet_a);
	free(vet_b);
	free(vet_c);
	
	return 0;
}

