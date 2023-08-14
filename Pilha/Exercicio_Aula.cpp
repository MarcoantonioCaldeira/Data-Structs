#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;

//Cria o elemento
struct Elemento{
	string expressao;
	Elemento *Prox;
};
//Cria a lista do tipo Pilha
struct Lista{
	Elemento *Topo;
	int Total;
};

//Inicio a Pilha com 0
void Ini_Lista(Lista *L){
	L->Topo = NULL;
	L->Total = 0;
}

//Para a lista estar vazia o topo deve ser NULL,
//porque o elemento do topo é o ultimo elemento a entrar
int Lista_Vazia(Lista *L){
	
	return (L->Topo == NULL);		
}
//Criando cada elemento que for adicionado
Elemento *Criar_Elemento(string expressao){
	Elemento *Item;

	Item = new Elemento;
	
	if (Item != NULL){
		Item->expressao = expressao;
	}
	
	return Item;
}

//Empilha e Desempilha

int Empilhar(Lista *L, string expressao){
	int Ret=1; //C�digo de Erro	
	Elemento* Item;
	
	Item = Criar_Elemento(expressao);

	if (Item == NULL)
		Ret = -1; //N�o conseguiu aloicar espa�o na mem�ria
	else{ 			
		Item->Prox = L->Topo;
		L->Topo = Item;
				
		L->Total++;
	}
		
	return Ret;
}

Elemento* Desempilhar(Lista *L){
	Elemento* Ret;
	
	if (Lista_Vazia(L)){
		Ret = NULL;
	}
	else{		
		Ret = L->Topo;		
		L->Topo = L->Topo->Prox;
		L->Total--;
	}
	
	return Ret;
}

//Imprime cada elemento
void Imprime_Lista(Lista *L){
	Elemento* Item;
	int Cont=0;
	
	for(Item=L->Topo;Item!=NULL;Item = Item->Prox){

		cout << endl << "Parenteses: " << Item->expressao;
		Cont++;
	}	
}

//Funcao para verificar se os parenteses estão fechados corretamente
bool Verifica_Parenteses(string expressao){
	stack<char> pilha; //cria uma pilha vazia

    //É percorrido caractere por caractere
	for (int i = 0; i < expressao.length(); i++) {

        //Se o caracter for um parêntese ou colchete de abertura, ele é adicionado na pilha
        if (expressao[i] == '(' || expressao[i] == '[') {


            pilha.push(expressao[i]);
            
        }else{
            //Se o caracter for um parêntese ou colchete de fechamento, o topo da pilha é removido
        	if (expressao[i] == ')' || expressao[i] == ']') {
	            if (pilha.empty()) {
	            	
	                return false;
	            }
	
	            char topo = pilha.top();
	            pilha.pop();

	            //Verificação de fechamento
	            if ((topo == '(' && expressao[i] != ')') || (topo == '[' && expressao[i] != ']')) {
	            	
	                return false;
	            }
	        }	
		} 
    }
	
}


Lista L;
string p;

int main(){	
	setlocale(LC_ALL,"Portuguese");

	//Digitar uma
	cout << "Digite um determinado numero de parenteses: ";
	cin >> p;

	
	Ini_Lista(&L);
	Empilhar(&L, p);
	Imprime_Lista(&L);

    //Aplicação da funcao
	if(Verifica_Parenteses(p)){
		
		cout << "Os parenteses est�o corretos"; //(())
		
	}else{
		
		cout << "Os parenteses est�o incorretos"; //(()()
		
	}
		
	return 0;
}         
