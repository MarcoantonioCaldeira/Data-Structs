#include<iostream>


using namespace std;


float Calculo_Potencia(float b, float e){ //Entro com a base e o expoente
	
	if(e == 1){ //Verifico se o expoente � igual a 1
		
		return b;
		
	}else{ //Se n�o ele vai fazer base vezes base at� o expoente ser igual a 1 e retornar o valor da base
		
		return b * Calculo_Potencia(b, e - 1);
	}
}


int main(){
	
	cout << Calculo_Potencia(4, 4);
	
}
