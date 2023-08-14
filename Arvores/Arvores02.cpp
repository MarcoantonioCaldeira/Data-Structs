#include <iostream>

using namespace std;

struct No{
	int ValorNum;
	string ValorTexto;
	No* Esq;
	No* Dir;
};

//header ou cabe�alho ou cabe�a
struct Arvore{
	No* Raiz;
	int TotalElem;
};

void Ini_Arvore(Arvore* Arv){
	Arv->Raiz = NULL;
	Arv->TotalElem = 0;
}

No* CriaNo(int ValorNum, string ValorTexto){
	No* Ret;

	Ret = new No;
	if (Ret != NULL){
		Ret->ValorNum = ValorNum;
		Ret->ValorTexto = ValorTexto;
		Ret->Esq = NULL;
		Ret->Dir = NULL;
	}

	return Ret;
}

No* InsereNoArv(Arvore* Arv, int ValorNum, string ValorTexto, No* NoPai, string TipoLig){
	No *Item;

	//Aloca espa�o, grava os dados e retorna o ponteiro pro elemento
	Item = CriaNo(ValorNum, ValorTexto);
	if (NoPai != NULL){// Se passou o pai, insere diretamente
		if (TipoLig == "E"){
			NoPai->Esq = Item;
		}
		else{
			NoPai->Dir = Item;
		}
	}
	else{
		if (Arv->Raiz == NULL){//�rvore Vazia
			Arv->Raiz = Item;
		}
	}

	Arv->TotalElem++;

	return Item;
}


void ImprimeArvore(No* NoArv) {

	if (NoArv != NULL){
		ImprimeArvore(NoArv->Esq);
		ImprimeArvore(NoArv->Dir);
		cout << /*endl << "Item: " <<*/ NoArv->ValorTexto << ", "; //<< ", Num: " << NoArv->ValorNum;
	}
}

Arvore Arv;
No *Item, *ItemE1, *ItemD1;
int main (){
	setlocale (LC_ALL,"Portuguese");

	Ini_Arvore(&Arv);
	Item = InsereNoArv(&Arv, 0, "1", NULL, ""); //Raiz
	ItemE1 = InsereNoArv(&Arv, 0, "2", Item, "E"); //N� esquerdo
	ItemD1 = InsereNoArv(&Arv, 0, "3", Item, "D"); //N� direito

	Item = InsereNoArv(&Arv, 0, "4", ItemE1, "E");
	ItemE1 = InsereNoArv(&Arv, 0, "7", Item, "E");
	InsereNoArv(&Arv, 0, "A", ItemE1, "E"); //Folhas
	InsereNoArv(&Arv, 0, "B", ItemE1, "D"); //Folhas

	InsereNoArv(&Arv, 0, "5", ItemD1, "E");
	Item = InsereNoArv(&Arv, 0, "6", ItemD1, "D");
	ItemE1 = InsereNoArv(&Arv, 0, "8", Item, "E");
	InsereNoArv(&Arv, 0, "9", Item, "D");
	InsereNoArv(&Arv, 0, "C", ItemE1, "E");

	ImprimeArvore(Arv.Raiz);

	return 0;
}