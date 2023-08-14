#include<iostream>
#include<stdlib.h>

using namespace std;

struct Numero{
	int Num;
	Numero *Prox;
};

struct Lista{
	int Tam;
	Numero *Inicio;
};


void Ini_Lista(Lista *N){
	N -> Inicio == NULL;
	N -> Tam = 0;
}


int Lista_Vazia(Lista *N){
	
	return (N->Inicio == NULL);	
	
}

Numero* Posicao(Lista *N, int Num){
	Numero *Pos = NULL, *Elem;
	
	Elem = N->Inicio;
	
	while(Pos == NULL && Elem != NULL) {
		if (Elem->Num == Num){
			Pos = Elem;
		}
		
		Elem = Elem->Prox;
	}
	return Pos;
}

Numero* PosicaoAnt(Lista *N, int Num){
	Numero *Pos = NULL, *Prox;
	
	Prox = N->Inicio;
	
	while(Prox != NULL && Prox->Num < Num){
		Pos = Prox;
		Prox = Prox->Prox;
	}
	
	return Pos;
}


Numero* Criar_Item(int Num){
	Numero *Item;
	
	Item = new Numero;
	
	if(Item != NULL){
		Item->Num = Num;
		Item->Prox = NULL;
	}
	
	return Item;
}



int Inserir_Numero(Lista *N, int Num){
	int Ret=1; 
	Numero *Item, *Pos;
	
	
	Item = Criar_Item(Num);
	
	if (Item == NULL){
		Ret = -1;
	}
	else{
		
		Pos = Posicao(N, Num);
		if (Pos != NULL){
			Ret = -2;
		}
		else{
						
			Pos = PosicaoAnt(N, Num);
			if(Pos == NULL){
				Item->Prox = N->Inicio;
				N->Inicio = Item;
			}
			else{
				Item->Prox = Pos->Prox;
				Pos->Prox = Item;
			}				
			N->Tam++;
		}	
	}
	return Ret;	
}


int Remover_Numero(Lista *N, int Num){
	int Ret=1;
	Numero *Pos, *PosAnt;
	
	if(Lista_Vazia(N)){
		
		Ret = -1;
		
	}else{
		
		Pos = Posicao(N, Num);
		if (Pos != NULL){
			PosAnt = PosicaoAnt(N,Num);	
			if(PosAnt == NULL){
				N->Inicio = Pos->Prox;
			}
			else{
				PosAnt->Prox = Pos->Prox;
			}			
			N->Tam--;
			free(Pos);
		}
		else{ //Time n?o existe!!
			Ret = -2;	
		}	
	}
	
	return Ret;
}



void Imprime_Lista_Numero(Numero* Item){
		
	if (Item != NULL){		
	
		cout << endl << "Numero: " << Item->Num;
		Imprime_Lista_Numero(Item->Prox);
	}
}


//Numero* copiar_lista(Numero *N, Numero *N2){
//	Numero* resultado = NULL;
//	
//	while(N != NULL){
//		
//		Numero* atual = N2;
//		
//		while(atual != NULL){
//			
//			if (N->Num == atual->Num) {
//				
//                Inserir_Numero(resultado, atual->Num);
//            } 
//        	atual = atual->Prox;
//		}	
//		N = N->Prox;
//	}
//	return resultado;
//}

//
void Dividir_Lista(Numero *Item, int N, Lista *N_G, Lista *N_P){
	Numero *curr = Item;


	while(curr != NULL){
		if(curr->Num > N){
			
			Inserir_Numero(N_G, curr->Num);
			
		}else{
			if(curr->Num < N){
				
				Inserir_Numero(N_P, curr->Num);		
			}
		} 	
		curr = curr->Prox;	
    }
    
    cout << "Numeros maiores que: "<< N << endl;
    
    
    	curr = N_G->Inicio;
    	
    	while(curr != NULL){
			cout << curr->Num << "" << endl;
			curr = curr->Prox;
		}

    cout << "Numeros menores que: " << N << endl;
    
        curr = N_P->Inicio;
    	
    	while(curr != NULL){
			cout << curr->Num << ""<< endl;
			curr = curr->Prox;
		}
}



Lista N;
Lista N2;
Lista N_G, N_P;
int escolha, escolha_operacao, num, Num_lista = 4;
string decisao, decisao_r, operacao_lista, operacao_lista_2, decisao_divisao;

int main(){
	
	cout << endl<< "Operacoes com lista " << endl;
	cout << endl << "Escolha um lista(1 ou 2):" << endl;
	cin >> escolha;
	
	
	
	if(escolha == 1){
		
		Ini_Lista(&N);
		do{
				
			cout << "Inseir Numero: " << "1"<< endl;
			cout << "Remover Numero: " << "2"<< endl;
			cout << "Exibir Numero: " << "3"<< endl;
			cout << "Dividir a lista: " << "4"<< endl;
			cin >> escolha_operacao;
	
			switch(escolha_operacao){
				
				case 1:
					do{
						
						cout << "Digite um numero: ";
						cin >> num;
						
						Inserir_Numero(&N, num);
						
						cout << "Deseja colocar outro numero?:[S/N]";
						cin	>> decisao;		
					
					}while(decisao == "S");
				
				case 2:
					
					cout << "Deseja remover algum numero?:[S/N]";
					cin	>> decisao_r;
						
					if(decisao_r == "S"){
						
						cout << "Digite o numero que voce quer remover: ";
						cin >> num;	
						
						Remover_Numero(&N, num);
					};
					
				case 3:
					cout << endl << "Lista" << endl;
					Imprime_Lista_Numero(N.Inicio);	
					
				
				case 4:
					
					cout << endl <<"Digite um numero :";
					cin >> Num_lista;
							
					cout<<endl<<"Lista dividida em duas"<<endl;
					
					//Divide a lista em duas
					Numero *Item = new Numero;
						
					Dividir_Lista(Item, Num_lista, &N_G, &N_P);
						
					//Imprime as duas novas listas
					Numero *atual;
					atual = N.Inicio;
						
						
//					while(atual != NULL){
//						cout << atual->Num << "";
//						atual = atual->Prox;
//					}
//						
//					cout << endl;
//					atual = N2.Inicio;
//						
//					while(atual != NULL){
//						cout << atual->Num << "";
//						atual = atual->Prox;
//					}
				}	
			cout << endl << "Deseja fazer outra operacao?: ";
			cin >> operacao_lista;
		
		}while(operacao_lista == "S");
		
	}else{
		
		if(escolha == 2){	
				
			Ini_Lista(&N2);	
			do{
				
				cout <<"Escolha uma das opcoes: " << endl;
				cout <<"Inseir Numero: " << "1"<< endl;
				cout <<"Remover Numero: " << "2"<< endl;
				cout <<"Exibir a Lista: " << "3"<< endl;
				cout << "Dividir a lista: " << "4"<< endl;
				cin >> escolha_operacao;
			
					switch(escolha_operacao){
						
						case 1:
							
							do{
								cout << "Digite um numero: ";
								cin >> num;
								
								Inserir_Numero(&N2, num);
								
								cout << "Deseja colocar outro numero?:[S/N]";
								cin	>> decisao;
								
							}while(decisao == "S");
							
							
						
						case 2:
							cout << "Deseja remover algum numero?:[S/N]";
							cin	>> decisao_r;
							
							if(decisao_r == "S"){
								cout << "Digite o numero que voce quer remover: ";
								cin >> num;
								
								Remover_Numero(&N2, num);	
								
							}
							
							
						case 3:
							cout << endl << "Lista" << endl;
							Imprime_Lista_Numero(N2.Inicio);
							
						case 4:
					
							cout << endl <<"Digite um numero :";
							cin >> Num_lista;
									
							cout<<endl<<"Lista dividida em duas"<<endl;
							
							//Divide a lista em duas
							Numero *Item = new Numero;
								
							Dividir_Lista(Item, Num_lista, &N, &N2);
								
							//Imprime as duas novas listas
							Numero *atual;
							atual = N.Inicio;
								
								
							while(atual != NULL){
								cout << atual->Num << "";
								atual = atual->Prox;
							}
								
							cout << endl;
							atual = N2.Inicio;
								
							while(atual != NULL){
								cout << atual->Num << "";
								atual = atual->Prox;
							}
				}	
					
				cout << endl << "Deseja fazer outra operacao?: ";
				cin >> operacao_lista_2;	
				
			}while(operacao_lista_2 == "S");	
		}
	}	
}
