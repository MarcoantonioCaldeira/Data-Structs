#include<iostream>



using namespace std;


void Num_Crescente(int *aponta_num1, int *aponta_num2, int *aponta_num3){
	int dec;
	
	
	if(*aponta_num2 > *aponta_num1){

		dec = *aponta_num1;

		*aponta_num1 = *aponta_num2;

		*aponta_num2 = dec;

	}
	

	if(*aponta_num3 > *aponta_num1){

		dec = *aponta_num1;

		*aponta_num1 = *aponta_num3;

		*aponta_num3 = dec;

	}

	
	if(*aponta_num3 > *aponta_num2)	{

		dec = *aponta_num2;

		*aponta_num2 = *aponta_num3;

		*aponta_num3 = dec;

	}


	cout << *aponta_num1 << " Posicao: " << &aponta_num1

	<< endl << *aponta_num2 << " Posicao: " << &aponta_num2

	<< endl << *aponta_num3 << " Posicao: " << &aponta_num3;
	
	cout << endl<< *aponta_num1 << " > " << *aponta_num2 << " > " << *aponta_num3;
}


int main(){	

	setlocale(LC_ALL,"Portuguese");

	int num1 = 8, num2 = 10, num3 = 20;	
	
	Num_Crescente(&num1, &num2, &num3);
	
	return 0;


}
