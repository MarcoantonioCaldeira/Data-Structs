#include<iostream>


using namespace std;

int Fatorial(int num){
	
	if(num == 1){
		
		return 1;
	}else{
		
		return num * Fatorial(num - 1);
	}
	
}

int main(){
	
	cout << Fatorial(5);
}
