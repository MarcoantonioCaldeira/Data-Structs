#include<iostream>


using namespace std;

int main(){
	
	string veiculo = "carro";
	string *pv;
	
	
	pv = &veiculo;
	
	
	cout << endl << pv; //Endere�o
	cout << endl << *pv; //Valor da Variavel
	
}
