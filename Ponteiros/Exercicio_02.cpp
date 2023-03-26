#include<iostream>

using namespace std;

void Manipular_Vetor(int vet[6]){
	int cont, *p;

	
	for(cont = 0; cont < 6; cont++){
		
		cout << "Digite um numero: ";
		cin >> vet[cont];
		
		p = &vet[cont];
		
	}
	
	for(cont = 0; cont < 5; cont++){
		
		cout << endl << vet[cont] << " posicao: " << p;
	}
	
	
}

int main(){
	
	int vet[6];
	
	Manipular_Vetor(vet);
}
