#include<iostream>


using namespace std;

int main(){
	
	int *p, cont = 0;
	int array[10];
	
	while(cont<9){
		
		p = &array[cont];
		cout << endl << p << " valor: " << cont;
		
		cont++;	
	}
	
	
}
