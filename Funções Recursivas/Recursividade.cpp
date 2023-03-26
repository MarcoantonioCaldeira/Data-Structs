#include<iostream>


using namespace std;

int Imprime_Nome(int contador){ //Criei um parametro contador
	
	if(contador == 0){ //Quando o contador chegar a 0 ele retorna 0
		
		return 0;
		
	}else{ //Mas enquanto ele for maior que 0 ele vai emprimir o meu nome
		cout<<"Marco Antonio" << endl;
		return Imprime_Nome(contador - 1); //Cada vez que chamar a função o contador subtrai 1 até chegar no 0 e a funcao finalizar
		
	}
	
}


int main(){
	
	int cont = 10;
	
	Imprime_Nome(cont); //Chamada da função
	return 0;
}
