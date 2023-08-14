#include <iostream>

using namespace std;

struct No{
    int ValorNum;
    int Bal; //Fator de balanceamento
    No* Esq;
    No* Dir;
};

//header ou cabe?alho ou cabe?a
struct Arvore{
    No* Raiz; //Onde a arvore começa
    int TotalElem;
};

//Pilha para armazenar os ancestrais de um n?
struct ItemPilha{
    No* NoArv;
    struct ItemPilha* Prox;
};

struct Pilha{
    struct ItemPilha* Topo;
    int Tamanho;
};

void IniPilha(Pilha* P){
    P->Topo = NULL;
    P->Tamanho = 0;
}

void Empilha(Pilha* P, No* NoArv){
    ItemPilha* Item;

    Item = (ItemPilha *) malloc(sizeof(ItemPilha));
    Item->NoArv = NoArv;
    Item->Prox = P->Topo;

    P->Topo = Item;
    P->Tamanho++;
}

ItemPilha* Desempilha(Pilha* P){
    ItemPilha* Item;

    if (P->Topo != NULL){
        Item = P->Topo;
        P->Topo = Item->Prox;
        P->Tamanho--;
    }
    else{
        Item = NULL;
    }

    return Item;
}

void ImprimePilha(Pilha *P, ItemPilha *Item){

    if (Item != NULL){
        cout<<Item->NoArv->ValorNum<<", ";
        ImprimePilha(P, Item->Prox);
    }
}

void LimpaPilha(Pilha *P){
    ItemPilha *Item;
    if (P->Tamanho > 0){
        Item = Desempilha(P);
        free(Item);
        LimpaPilha(P);
    }
}

void Ini_Arvore(Arvore* Arv){
    Arv->Raiz = NULL;
    Arv->TotalElem = 0;
}

void ImprimeArvore(No* NoArv, string Tipo) {
    string TextoEsq = "NULL", TextoDir = "NULL";

    if (NoArv != NULL){
        if (NoArv->Esq != NULL){
            TextoEsq = 	to_string(NoArv->Esq->ValorNum);
        }

        if (NoArv->Dir != NULL){
            TextoDir = 	to_string(NoArv->Dir->ValorNum);
        }

        //imprime o item na tela
        if (Tipo == "PRE") {
            /*cout << NoArv->ValorNum << ", ";*/
            cout << "Pai:" << NoArv->ValorNum << endl;
            cout <<"Filho Esq: " << TextoEsq  << endl;
            cout <<"Filho Dir: " << TextoDir  << endl << endl;
        }

        ImprimeArvore(NoArv->Esq, Tipo);

        if (Tipo == "CEN") {
            /*cout << NoArv->ValorNum << ", ";*/
            cout << "Pai:" << NoArv->ValorNum << endl;
            cout <<"Filho Esq: " << TextoEsq  << endl;
            cout <<"Filho Dir: " << TextoDir  << endl << endl;
        }

        ImprimeArvore(NoArv->Dir, Tipo);

        if (Tipo == "POS") {
            /*cout << NoArv->ValorNum << ", ";*/
            cout << "Pai:" << NoArv->ValorNum << endl;
            cout <<"Filho Esq: " << TextoEsq  << endl;
            cout <<"Filho Dir: " << TextoDir  << endl << endl;
        }
    }
}
/*No* CriaNo(int ValorNum){
	No* Ret;

	Ret = new No;

	Ret->ValorNum = ValorNum;
	Ret->Bal = 0;
	Ret->Esq = NULL;
	Ret->Dir = NULL;

	return Ret;
}*/

No* CriaNo(int ValorNum){
    No* Ret;

    Ret = new No;
    if (Ret != NULL){
        Ret->ValorNum = ValorNum;
        Ret->Esq = NULL;
        Ret->Dir = NULL;
    }

    return Ret;
}

//Encontrar item na ?rvore ordenada
No* EncontrarNo(No* NoArv, int ValorNum){
    No* Ret;


    if (NoArv == NULL){
        Ret = NULL;
    }
    else{
        if (ValorNum == NoArv->ValorNum){
            Ret = NoArv;
        }
        else{
            //procura ? esquerda (menor) ou direita (maior)
            if	(ValorNum < NoArv->ValorNum){
                Ret = EncontrarNo(NoArv->Esq, ValorNum);
            }
            else{
                Ret = EncontrarNo(NoArv->Dir, ValorNum);
            }
        }
    }

    return Ret;
}


No* BuscaPai(No* NoArv, int ValorNum, Pilha *P){
    No* Ret;

    if (NoArv != NULL){
        if (ValorNum == NoArv->ValorNum){
            Ret = NULL;
        }
        else{
            Empilha(P, NoArv);
            if ((NoArv->Esq == NULL && ValorNum < NoArv->ValorNum) ||
                (NoArv->Dir == NULL && ValorNum > NoArv->ValorNum)){
                // Encontrou posi??o
                Ret = NoArv;
            }
            else{
                //procura ? esquerda (menor) ou direita (maior)
                if	(ValorNum < NoArv->ValorNum){
                    Ret = BuscaPai(NoArv->Esq, ValorNum, P);
                }
                else{
                    Ret = BuscaPai(NoArv->Dir, ValorNum, P);
                }
            }
        }
    }

    return Ret;
}

void Rot_dir(Arvore* Arv, No* Pai, Pilha* P){
    No *U, *Avo;

    cout << endl << "Rota��o � direita!!" << endl;
    cout << endl << "Pai: " << Pai->ValorNum << endl;

    U = Pai->Esq;
    Pai->Esq = U->Dir;
    U->Dir = Pai;
    Pai->Bal = 0;
    if (Pai == Arv->Raiz){ //Atualiza ra�z da �rvore
        cout << endl << "Atualiza��o da ra�z para " << U->ValorNum <<endl;
        Arv->Raiz = U;
        Arv->Raiz->Bal = 0;
    }
    else{ //Atualiza av� para apontar para o novo pai
        Avo = P->Topo->NoArv; //Instancia o av�
        cout << endl << "Atualiza��o apontamento do pai de " << U->ValorNum << " para " << Avo->ValorNum << endl;
        if (Avo->ValorNum > U->ValorNum){
            Avo->Esq = U;
        }
        else{
            Avo->Dir = U;
        }
        Avo->Bal = 0;
        //cout << endl << "Avo->Esq: " << Avo->Esq->ValorNum<< endl;
    }
}

void Rot_esq_dir(Arvore* Arv, No* Pai, Pilha* P){
    No *U, *V, *Avo;

    cout << endl << "Rota??o ? esquerda-direita!!" << endl;
    U = Pai->Esq;
    V = U->Dir;
    U->Dir = V->Esq;
    V->Esq = U;
    Pai->Esq = V->Dir;
    V->Dir = Pai;
    if (V->Bal == -1){
        Pai->Bal = 1;
    }
    else{
        Pai->Bal = 0;
    }

    if (V->Bal == 1){
        U->Bal = -1;
    }
    else{
        U->Bal = 0;
    }

    if (Pai == Arv->Raiz){ //Atualiza ra?z da ?rvore
        cout << endl << "Atualiza??o da ra?z para " << V->ValorNum <<endl;
        Arv->Raiz = V;
        Arv->Raiz->Bal = 0;
    }
    else{ //Atualiza av? para apontar para o novo pai
        Avo = P->Topo->NoArv; //Instancia o av?
        cout << endl << "Atualiza??o apontamento do pai de " << V->ValorNum << " para " << Avo->ValorNum << endl;
        if (Avo->ValorNum > V->ValorNum){
            Avo->Esq = V;
        }
        else{
            Avo->Dir = V;
        }
        Avo->Bal = 0;
    }
}

void Rot_dir_zero(Arvore* Arv, No* Pai, Pilha* P){
    No *U, *Avo;

    U = Pai->Esq;
    if (U->Bal == 0){
        cout << endl << "Rota??o ? direita-zero!!" << endl;

        Pai->Esq = U->Dir;
        U->Dir = Pai;
        Pai->Bal = -1;
        U->Bal = 1;

        if (Pai == Arv->Raiz){ //Atualiza ra?z da ?rvore
            cout << endl << "Atualiza��o da ra�z para " << U->ValorNum <<endl;
            Arv->Raiz = U;
        }
        else{ //Atualiza av? para apontar para o novo pai
            Avo = P->Topo->NoArv; //Instancia o av?
            cout << endl << "Atualiza??o apontamento do pai de " << U->ValorNum << " para " << Avo->ValorNum << endl;
            if (Avo->ValorNum > U->ValorNum){
                Avo->Esq = U;
            }
            else{
                Avo->Dir = U;
            }
        }
    }
}

void Rot_esq(Arvore* Arv, No* Pai, Pilha* P){
    No *U, *Avo;

    cout << endl << "Rota??o ? esquerda!!" << endl;
    U = Pai->Dir;
    Pai->Dir = U->Esq;
    U->Esq = Pai;
    Pai->Bal = 0;

    if (Pai == Arv->Raiz){ //Atualiza ra?z da ?rvore
        cout << endl << "Atualiza??o da ra?z para " << U->ValorNum <<endl;
        Arv->Raiz = U;
        Arv->Raiz->Bal = 0;
    }
    else{ //Atualiza av? para apontar para o novo pai
        Avo = P->Topo->NoArv; //Instancia o av?
        cout << endl << "Atualiza??o apontamento do pai de " << U->ValorNum << " para " << Avo->ValorNum << endl;
        if (Avo->ValorNum > U->ValorNum){
            Avo->Esq = U;
        }
        else{
            Avo->Dir = U;
        }
        Avo->Bal = 0;
    }
}

void Rot_dir_esq(Arvore* Arv, No* Pai, Pilha* P){
    No *U, *V, *Avo;

    cout << endl << "Rota??o ? direita-esquerda!!" << endl;
    U = Pai->Dir;
    V = U->Esq;
    U->Esq = V->Dir;
    V->Dir = U;
    Pai->Dir = V->Esq;
    V->Esq = Pai;
    if (V->Bal == 1){
        Pai->Bal = -1;
    }
    else{
        Pai->Bal = 0;
    }

    if (V->Bal == -1){
        U->Bal = 1;
    }
    else{
        U->Bal = 0;
    }

    if (Pai == Arv->Raiz){ //Atualiza ra?z da ?rvore
        cout << endl << "Atualiza??o da ra?z para " << V->ValorNum <<endl;
        Arv->Raiz = V;
        Arv->Raiz->Bal = 0;
    }
    else{ //Atualiza av? para apontar para o novo pai
        Avo = P->Topo->NoArv; //Instancia o av?
        cout << endl << "Atualiza??o apontamento do pai de " << V->ValorNum << " para " << Avo->ValorNum << endl;
        if (Avo->ValorNum > V->ValorNum){
            Avo->Esq = V;
        }
        else{
            Avo->Dir = V;
        }
        Avo->Bal = 0;
    }
}

void Rot_esq_zero(Arvore* Arv, No* Pai, Pilha* P){
    No *U, *Avo;

    U = Pai->Dir;
    if (U->Bal == 0){
        cout << endl << "Rota??o ? esquerda-zero!!" << endl;

        Pai->Dir = U->Esq;
        U->Esq = Pai;
        Pai->Bal = 1;
        U->Bal = -1;

        if (Pai == Arv->Raiz){ //Atualiza ra?z da ?rvore
            cout << endl << "Atualiza??o da ra?z para " << U->ValorNum <<endl;
            Arv->Raiz = U;
        }
        else{ //Atualiza av? para apontar para o novo pai
            Avo = P->Topo->NoArv; //Instancia o av?
            cout << endl << "Atualiza??o apontamento do pai de " << U->ValorNum << " para " << Avo->ValorNum << endl;
            if (Avo->ValorNum > U->ValorNum){
                Avo->Esq = U;
            }
            else{
                Avo->Dir = U;
            }
        }
    }
}

void BalancearAVL(Arvore* Arv, Pilha* P, char Lado, string Op){
    ItemPilha *Pai;
    No *U;
    int Bal;

    if (P->Tamanho > 0){ //H? ancestrais para analisar na pilha
        //verifica qual lado do pai est? havendo a inser??o
        if (Lado == 'E' && Op== "INS" || Lado == 'D' && Op == "REM" ){
            Bal = -1;
        }
        else{
            Bal = 1;
        }
        Pai = Desempilha(P);
        Pai->NoArv->Bal += Bal; //atualiza o fator de balanceamento

        cout << endl << "Atualizando fator para pai " << Pai->NoArv->ValorNum << " Bal = " << Pai->NoArv->Bal << endl;
        //system("pause");
        //Verifica se houve desbalanceamento
        switch(Pai->NoArv->Bal){
            case 0:
            case -1:
            case 1:
                if (P->Tamanho > 0 &&
                    (Pai->NoArv->Bal != 0 && Op == "INS" ||
                     Pai->NoArv->Bal == 0 && Op == "REM")){
                    //verifica se est? ? direita ou esquerda do av? para propagar o balanceamento
                    if (P->Topo->NoArv->ValorNum < Pai->NoArv->ValorNum){
                        Lado = 'D';
                    }
                    else{
                        Lado = 'E';
                    }

                    BalancearAVL(Arv, P, Lado, Op);
                }
                break;
            case -2:
                U = Pai->NoArv->Esq;
                if (U->Bal == -1){
                    Rot_dir(Arv, Pai->NoArv, P);
                }
                else{
                    if (U->Bal == 0 && Op == "REM"){
                        Rot_dir_zero(Arv, Pai->NoArv, P);
                    }
                    else{
                        Rot_esq_dir(Arv, Pai->NoArv, P);
                    }
                }

                //Pai->NoArv->Bal = 0; //Atualizado nas fun??es de rota??o, pois mda o pai ap?s a rota??o
                break;
            case 2:
                U = Pai->NoArv->Dir;
                if (U->Bal == 1){
                    Rot_esq(Arv, Pai->NoArv, P);
                }
                else{
                    if (U->Bal == 0 && Op == "REM"){
                        Rot_esq_zero(Arv, Pai->NoArv, P);
                    }
                    else{
                        Rot_dir_esq(Arv, Pai->NoArv, P);
                    }
                }

                //Pai->NoArv->Bal = 0; //Atualizado nas fun??es de rota??o, pois mda o pai ap?s a rota??o
                break;
        }
    }
}

/*
No* InsereNoArv(Arvore* Arv, int ValorNum, No* NoPai, string TipoLig){
	No *Item, *Aux;
	int Erro = 0;
	char Lado;
	Pilha P;

	//Aloca espa?o, grava os dados e retorna o ponteiro pro elemento
	Item = CriaNo(ValorNum);
	if (Arv->Raiz == NULL){//?rvore Vazia
		Arv->Raiz = Item;
	}
	else{
		if (NoPai != NULL){// Se passou o pai, insere diretamente
			if (TipoLig == "E"){
				NoPai->Esq = Item;
			}
			else{
				NoPai->Dir = Item;
			}
		}
		else{	//N?o passa o pai, vai procurar qual pai deve ser usado para inser??o
			IniPilha(&P);
			Aux = BuscaPai(Arv->Raiz, ValorNum, &P); //Busca o pai e carrega a pilha de ancestrais
			if (Aux != NULL){
				if (ValorNum < Aux->ValorNum){
					Aux->Esq = Item;
					Lado = 'E';
				}
				else{
					Aux->Dir = Item;
					Lado = 'D';
				}

				BalancearAVL(Arv, &P, Lado, "INS");
			}
			else{
				cout << endl << "Item " << ValorNum << " j? existe!!";
				Erro = 1;
			}

			LimpaPilha(&P);
		}
	}

	if (Erro == 0){
		Arv->TotalElem++;
	}

	return Item;
}*/


No* InsereNoArv(Arvore* Arv, int ValorNum, No* NoIni, Pilha *P, string TipoLig, char Lado){
    No *Item, *Aux,*Ret;

    if (Arv->Raiz == NULL){//�rvore Vazia
        //Aloca espa�o, grava os dados e retorna o ponteiro pro elemento
        NoIni = CriaNo(ValorNum);
        Arv->Raiz = NoIni;
        Arv->TotalElem++;
    }
    else{
        if ((NoIni != NULL) && (TipoLig != "")){// Se passou o pai, insere diretamente
            //Aloca espa�o, grava os dados e retorna o ponteiro pro elemento
            Item = CriaNo(ValorNum);
            if (TipoLig == "E"){
                NoIni->Esq = Item;
            }
            else{
                NoIni->Dir = Item;
            }
            NoIni = Item;
            Arv->TotalElem++;
        }
        else{ //N�o passou o pai, busca o ponto de inser��o
            if (NoIni != NULL){
                if (ValorNum < NoIni->ValorNum){
                    Empilha(P, NoIni);
                    Aux = NoIni->Esq;
                    Ret = InsereNoArv(Arv, ValorNum, NoIni->Esq, P, "", 'E');
                    if (Aux == NULL){ //Chegou no ponto de inser��o filtrando as mudan�as de ponteiros do balanceamento
                        NoIni->Esq = Ret;

                        if (P->Tamanho > 0){
                            //cout << endl<< "Entrando no balanceamento: NoIni: " << NoIni->ValorNum << endl;
                            //cout << endl<< "Entrando no balanceamento: NoIni->Esq: " << NoIni->Esq->ValorNum << endl;
                            BalancearAVL(Arv, P, 'E', "INS");
                            /*if (ValorNum == 1){
                                cout << endl<< "Imprimindo ap�s gravar o 1!!"<< endl;
                                ImprimeArvore(Arv->Raiz, "PRE");
                                system("pause");
                            }*/
                        }
                    }
                }
                else{
                    if (ValorNum > NoIni->ValorNum){
                        Empilha(P, NoIni);
                        Aux = NoIni->Dir;
                        Ret = InsereNoArv(Arv, ValorNum, NoIni->Dir, P, "", 'D');
                        if (Aux == NULL){ //Chegou no ponto de inser��o filtrando as mudan�as de ponteiros do balanceamento
                            NoIni->Dir = Ret;

                            if (P->Tamanho > 0){ //Chegou no ponto de inser��o
                                //cout << endl<< "Entrando no balanceamento: NoIni: " << NoIni->ValorNum << endl;
                                //cout << endl<< "Entrando no balanceamento: NoIni->Dir: " << NoIni->Dir->ValorNum << endl;
                                BalancearAVL(Arv, P, 'D', "INS");
                            }
                        }
                    }
                    else{ //O item j� existe
                        //Item = NULL;

                        cout << endl << "Item " << NoIni->ValorNum <<" j� existe!!!" << endl;
                    }
                }

                /*if (ValorNum == 1 && NoIni != NULL){
                    cout << endl<< "Imprimindo final com o 1!!"<< endl;
                    cout << endl<< "NoIni: " << NoIni->ValorNum<< endl;
                    if (NoIni->Esq != NULL)	{
                        cout << endl<< "NoIni->Esq: " << NoIni->Esq->ValorNum<< endl;
                    }
                    ImprimeArvore(Arv->Raiz, "PRE");
                    system("pause");
                }*/
            }
            else{
                //Aloca espa�o, grava os dados e retorna o ponteiro pro elemento
                NoIni = CriaNo(ValorNum);
                Arv->TotalElem++;
            }
        }
    }

    return NoIni;
}

//Calcular a altura da ?rvore
int Altura(No* NoArv){
    int AltEsq, AltDir, Ret;

    if (NoArv == NULL){
        Ret = -1; //altura da arvore vazia
    }else{
        //verificar a altura da ?rvore da esquerda
        AltEsq = Altura(NoArv->Esq);

        //verificar a altura da ?rvore da direita
        AltDir = Altura(NoArv->Dir);

        //ramo mais alto + ra?z
        if(AltEsq<AltDir){
            Ret =  AltDir + 1;
        }else{
            Ret =  AltEsq + 1;
        }

        /*cout << endl << "N? atual: " << NoArv->ValorNum << " Ret: " << Ret << endl;
        system("pause");*/
    }

    return Ret;
}

No* acha_menor(No* NoArv) {
    No* Ret;

    if(NoArv->Esq == NULL) {
        Ret = NoArv;
    }
    else{
        Ret = acha_menor(NoArv->Esq);
    }

    return Ret;
}

No* remove(Arvore* Arv, No* NoArv, int ValorNum, Pilha* Pais, char Lado) {
    No *Ret, *Suc;
    if(NoArv == NULL) {
        Ret = NULL;
        cout << "Elemento ausente!!" << endl;
    }
    else {
        Ret = NoArv;
        if(ValorNum < NoArv->ValorNum){
            Empilha(Pais, NoArv);
            NoArv->Esq = remove(Arv, NoArv->Esq, ValorNum, Pais, 'E');
        }
        else{
            if(ValorNum > NoArv->ValorNum){
                Empilha(Pais, NoArv);
                NoArv->Dir = remove(Arv, NoArv->Dir, ValorNum, Pais, 'D');
            }
            else{
                if(NoArv->Esq == NULL && NoArv->Dir == NULL) { /* zero filhos */
                    free(NoArv);
                    Ret = NULL;
                    if (Pais->Tamanho > 0){ //pode necessitar balanceamento
                        BalancearAVL(Arv, Pais, Lado, "REM");
                    }
                    else{
                        Arv->Raiz = Ret; //Atualiza a ra?z, caso n?o haja mais pais na pilha
                    }
                }
                else{
                    if(NoArv->Esq == NULL) { /* 1 filho */
                        Ret = NoArv->Dir;
                        if (Pais->Tamanho > 0){ //pode necessitar balanceamento
                            BalancearAVL(Arv, Pais, Lado, "REM");
                        }
                        else{
                            Arv->Raiz = Ret;  //Atualiza a ra?z, caso n?o haja mais pais na pilha
                        }
                        free(NoArv);
                    }
                    else{
                        if(NoArv->Dir == NULL) { /* 1 filho */
                            Ret = NoArv->Esq;
                            if (Pais->Tamanho > 0){ //pode necessitar balanceamento
                                BalancearAVL(Arv, Pais, Lado, "REM");
                            }
                            else{
                                Arv->Raiz = Ret;  //Atualiza a ra?z, caso n?o haja mais pais na pilha
                            }
                            free(NoArv);
                        }
                        else{ /* 2 filhos */
                            Empilha(Pais, NoArv); //Cadastra o n? na pilha de pais para poder remover/balancear o menor filho ? direita (realmente exclu?do)
                            Suc = acha_menor(NoArv->Dir);
                            //Grava os valores do sucessor por cima do n? a ser eliminado
                            NoArv->ValorNum = Suc->ValorNum;
                            //N?o precisa propagar o balanceamento a partir daqui, mas sim a partir do n? que ? realmente exclu?do (Suc)!!
                            NoArv->Dir = remove(Arv,NoArv->Dir, Suc->ValorNum, Pais, 'D');
                            Ret = NoArv;
                        }
                    }
                }
            }
        }
    }

    return Ret;
}

void InsereOrdemCen(No* NoArv, No* Vetor, int *Pos) {
    if (NoArv != NULL){
        InsereOrdemCen(NoArv->Esq, Vetor, Pos);

        Vetor[*Pos] = *NoArv;
        //cout << "Valor de Pos:" << *Pos << " e item no vetor " << Vetor[*Pos].ValorNum << endl;
        (*Pos)++;

        InsereOrdemCen(NoArv->Dir, Vetor, Pos);
    }
}

No* GeraVetorABP(Arvore* Arv, int MostraTela){
    No* Vetor;
    int Pos = 0, Cont;

    if (Arv->TotalElem > 0){
        Vetor = (No *) malloc(sizeof(No)*(Arv->TotalElem)); //Aloca espa?o no vetor parao total de elementos da ?rvore
        InsereOrdemCen(Arv->Raiz, Vetor, &Pos);

        if (MostraTela==1){
            cout <<endl << endl << "Vetor gerado BPL" << endl << endl;
            for (Cont=0;Cont<Arv->TotalElem;Cont++){
                cout << Vetor[Cont].ValorNum << ", ";
            }
            cout << endl;
        }
    }
    return Vetor;
}

No* GeraArvoreABP(Arvore* Arv, No* Vetor, int Inicio, int Fim){
    int Pos, Meio;
    No* Ret;

    if (Inicio > Fim){
        Ret = NULL; // N?o encontrou!!
    }
    else{
        Meio = (Inicio + Fim)/2;
        Ret = Vetor + Meio; //Aponta para a metade relativa do vetor
        //cout << "Valor do Ret: " << Ret->ValorNum << endl;
        Ret->Esq = GeraArvoreABP(Arv, Vetor, Inicio, Meio-1);
        Ret->Dir = GeraArvoreABP(Arv, Vetor, Meio+1, Fim);
    }

    return Ret;
}

void GravaInsNoArv(Arvore* Arv, int ValorNum, No* NoIni, Pilha *P, string TipoLig) {

    IniPilha(P);
    InsereNoArv(Arv, ValorNum, NoIni, P, TipoLig, '-');
    LimpaPilha(P);
}

Arvore Arv;
No *Vetor;
Pilha P;
main (){
    setlocale (LC_ALL,"Portuguese");

    Ini_Arvore(&Arv);


    //Teste ABP
    /*GravaInsNoArv(&Arv, 1, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 2, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 3, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 4, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 5, Arv.Raiz, &P, "");*/

    //*********************** AVL - INSER��O
    //Teste AVL - Rota��o ? direita
    GravaInsNoArv(&Arv, 10, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 5, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 15, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 3, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 1, Arv.Raiz, &P, "");

    //Teste AVL - Rota??o ? esquerda-direita
    /*GravaInsNoArv(&Arv, 5, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 2, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 10, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 1, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 3, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 4, Arv.Raiz, &P, "");*/

    //Teste AVL - Rota??o ? esquerda
    /*GravaInsNoArv(&Arv, 10, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 5, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 15, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 18, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 20, Arv.Raiz, &P, "");*/

    //Teste AVL - Rota??o ? direita-esquerda
    /*GravaInsNoArv(&Arv, 5, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 2, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 10, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 12, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 7, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 6, Arv.Raiz, &P, "");*/

    //*********************** AVL - REMO??O
    //Rota??o ? direita (1.1)
    /*GravaInsNoArv(&Arv, 10, Arv.Raiz, &P, "");
 GravaInsNoArv(&Arv, 5, Arv.Raiz, &P, "");
 GravaInsNoArv(&Arv, 15, Arv.Raiz, &P, "");
 GravaInsNoArv(&Arv, 3, Arv.Raiz, &P, ""); */

    //Rota??o ? esquerda-direita (1.2)
    /*GravaInsNoArv(&Arv, 10, Arv.Raiz, &P, "");
 GravaInsNoArv(&Arv, 5, Arv.Raiz, &P, "");
 GravaInsNoArv(&Arv, 15, Arv.Raiz, &P, "");
 GravaInsNoArv(&Arv, 6, Arv.Raiz, &P, "");*/

    //Rota??o ? esquerda (2.1)
    /*GravaInsNoArv(&Arv, 30, Arv.Raiz, &P, "");
 GravaInsNoArv(&Arv, 15, Arv.Raiz, &P, "");
 GravaInsNoArv(&Arv, 40, Arv.Raiz, &P, "");
 GravaInsNoArv(&Arv, 50, Arv.Raiz, &P, "");*/

    //Rota??o ? direita-esquerda (2.2)
    /*GravaInsNoArv(&Arv, 30, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 15, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 40, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 35, Arv.Raiz, &P, ""); 	*/

    //Rota??o ? direita-zero (1.3)
    /*GravaInsNoArv(&Arv, 10, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 5, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 15, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 3, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 6, Arv.Raiz, &P, ""); */

    //Rota??o ? direita-zero (1.3) por exclus?o de folha que tornou o pai um novo folha (mudou a alatura da ?rvore!!)
    /*GravaInsNoArv(&Arv, 10, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 5, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 15, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 3, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 25, Arv.Raiz, &P, ""); */

    //Rota??o ? esquerda-zero (2.3)
    /*GravaInsNoArv(&Arv, 30, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 15, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 40, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 35, Arv.Raiz, &P, "");
    GravaInsNoArv(&Arv, 50, Arv.Raiz, &P, ""); */

    if (Arv.Raiz != NULL){
        cout << endl << "Ordem Pr�-Ordem - �rvore Original ABP/ �rvore Balanceada AVL [Inser��o]" << endl << endl;
        ImprimeArvore(Arv.Raiz, "PRE");
        //cout << endl;
        //system("pause");
        //Teste ABP
        //Vetor = GeraVetorABP(&Arv, 1);
        //Arv.Raiz = GeraArvoreABP(&Arv, Vetor, 0, (Arv.TotalElem-1));

        //Teste AVL	- Remo??o		//retorna o ponteiro pra atualizar a ra?z, caso ela seja o ?nico n?
        /*remove(&Arv, Arv.Raiz, 25, &PilhaPaisRem, 'C');
        cout << endl << endl << "Pr?-Ordem - ?rvore Balanceada AVL [Remo??o]" << endl << endl;
        ImprimeArvore(Arv.Raiz, "PRE");
        cout << endl <<	system("pause");
        remove(&Arv, Arv.Raiz, 15, &PilhaPaisRem, 'C');
        cout << endl << endl << "Pr?-Ordem - ?rvore Balanceada AVL [Remo??o]" << endl << endl;
        ImprimeArvore(Arv.Raiz, "PRE");	*/
    }
}
