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

struct ItemSentenca{
    float Valor;
    ItemSentenca *Prox;
};

struct Pilha{ //Header/Cabe?alho
    ItemSentenca *Topo;
    int Total;
};

void Ini_Pilha(Pilha *P){
    P->Topo = NULL;
    P->Total = 0;
}

int Pilha_Vazia(Pilha *P){

    return (P->Topo == NULL);
}

ItemSentenca *Criar_Item(float Valor){
    ItemSentenca *ItemSent;

    ItemSent = new ItemSentenca;
    if (ItemSent != NULL){
        ItemSent->Valor = Valor;
        ItemSent->Prox = NULL;
    }

    return ItemSent;
}

int Empilhar(Pilha *P, float Valor){
    int Ret=1; //C�digo de Erro
    ItemSentenca *ItemSent;

    ItemSent = Criar_Item(Valor);
    if (ItemSent == NULL)
        Ret = -1; //N�o conseguiu aloicar espa?o na mem?ria
    else{
        ItemSent->Prox = P->Topo;
        P->Topo = ItemSent;

        P->Total++;
    }

    return Ret;
}

ItemSentenca* Desempilhar(Pilha *P){
    ItemSentenca* Ret;

    if (Pilha_Vazia(P)){
        Ret = NULL; //Lista vazia
    }
    else{
        Ret = P->Topo;
        P->Topo = P->Topo->Prox;
        P->Total--;
    }

    return Ret;
}

void Imprime_Lista(ItemSentenca* Item){

    if (Item != NULL){
        cout << Item->Valor << ", ";

        Imprime_Lista(Item->Prox);
    }
}

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

No* InsereNoArv(Arvore* Arv, int ValorNum, string ValorTexto, No* NoIni, string TipoLig, int Debug){
    No *Item;

    if (Arv->Raiz == NULL){//�rvore Vazia
        //Aloca espa�o, grava os dados e retorna o ponteiro pro elemento
        NoIni = CriaNo(ValorNum, ValorTexto);
        Arv->Raiz = NoIni;
        Arv->TotalElem++;
    }
    else{
        if ((NoIni != NULL) && (TipoLig != "")){// Se passou o pai, insere diretamente
            //Aloca espa�o, grava os dados e retorna o ponteiro pro elemento
            Item = CriaNo(ValorNum, ValorTexto);
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
                if (Debug){
                    cout << endl << "No INI: " << NoIni->ValorTexto << endl;
                    if (NoIni->Esq != NULL){
                        cout << endl << "No INI->Esq: " << NoIni->Esq->ValorTexto << endl;
                    }
                    else{
                        cout << endl << "No INI->Esq: NULL" << endl;
                    }
                    if (NoIni->Dir != NULL){
                        cout << endl << "No INI->Dir: " << NoIni->Dir->ValorTexto << endl;
                    }
                    else{
                        cout << endl << "No INI->Dir: NULL" << endl;
                    }
                    system("pause");
                }

                if (ValorTexto < NoIni->ValorTexto){
                    if (Debug) cout << endl << "Entrando � esquerda de " << NoIni->ValorTexto << endl;

                    NoIni->Esq = InsereNoArv(Arv, ValorNum, ValorTexto, NoIni->Esq, "", Debug);

                    if (Debug) cout << endl << "Valor de No INI->Esq: " << NoIni->Esq->ValorTexto << endl;
                }
                else{
                    if (ValorTexto > NoIni->ValorTexto){
                        if (Debug) cout << endl << "Entrando � direita de " << NoIni->ValorTexto << endl;

                        NoIni->Dir = InsereNoArv(Arv, ValorNum, ValorTexto, NoIni->Dir, "", Debug);

                        if (Debug) cout << endl << "Valor de No INI->Dir: " << NoIni->Dir->ValorTexto << endl;
                    }
                    else{ //O item j� existe
                        //Item = NULL;

                        cout << endl << "Item " << NoIni->ValorTexto <<" j� existe!!!" << endl;
                    }
                }
            }
            else{
                //Aloca espa�o, grava os dados e retorna o ponteiro pro elemento
                NoIni = CriaNo(ValorNum, ValorTexto);
                Arv->TotalElem++;
                if (Debug){
                    cout << endl << "Criando Novo No INI: " << NoIni->ValorTexto << endl;
                    system("pause");
                }

            }
        }
    }

    return NoIni;
}

No* AchaMenor(No* NoIni){
    No* Ret;

    if (NoIni->Esq == NULL){
        Ret = NoIni;
    }
    else{
        Ret = AchaMenor(NoIni->Esq);
    }

    return Ret;
}

No* AchaMaior(No* NoIni){
    No* Ret;

    if (NoIni->Dir == NULL){
        Ret = NoIni;
    }
    else{
        Ret = AchaMaior(NoIni->Dir);
    }

    return Ret;
}


No* RemoveNoArv(Arvore* Arv, No* NoIni, string ValorTexto){
    No *Ret, *Suc;

    Ret = NoIni;
    if (NoIni != NULL){
        if (ValorTexto < NoIni->ValorTexto){ //menor
            NoIni->Esq = RemoveNoArv(Arv, NoIni->Esq, ValorTexto);
        }
        else{
            if (ValorTexto > NoIni->ValorTexto){ //maior
                NoIni->Dir = RemoveNoArv(Arv, NoIni->Dir, ValorTexto);
            }
            else{ //igual
                if (NoIni->Esq == NULL && NoIni->Dir == NULL){ //sem filhos
                    Ret = NULL;
                    free(NoIni);
                }
                else{
                    if (NoIni->Esq == NULL){ //1 filho � direita
                        Ret = NoIni->Dir;
                        free(NoIni);
                    }
                    else{
                        if (NoIni->Dir == NULL){ //1 filho � esquerda
                            Ret = NoIni->Esq;
                            free(NoIni);
                        }
                        else{ //dois dilhos
                            //Suc = AchaMenor(NoIni->Dir);
                            Suc = AchaMaior(NoIni->Esq);
                            //Copia os dados do menor para NoIni
                            NoIni->ValorTexto = Suc->ValorTexto;
                            NoIni->ValorNum = Suc->ValorNum;
                            //NoIni->Dir = RemoveNoArv(Arv, NoIni->Dir, Suc->ValorTexto);
                            NoIni->Esq = RemoveNoArv(Arv, NoIni->Esq, Suc->ValorTexto);
                        }
                    }
                }
            }
        }
    }
    else{
        cout << endl << "Item " << ValorTexto << " n�o encontrado!!!";
    }

    return Ret;
}


void ImprimeArvore(No* NoArv, string Tipo) {

    if (NoArv != NULL){
        if (Tipo == "PRE"){
            cout << /*endl << "Item: " <<*/ NoArv->ValorTexto << ", "; //<< ", Num: " << NoArv->ValorNum;
        }

        ImprimeArvore(NoArv->Esq, Tipo);

        if (Tipo == "CEN"){
            cout << /*endl << "Item: " <<*/ NoArv->ValorTexto << ", "; //<< ", Num: " << NoArv->ValorNum;
        }

        ImprimeArvore(NoArv->Dir, Tipo);

        if (Tipo == "POS"){
            cout << /*endl << "Item: " <<*/ NoArv->ValorTexto << ", "; //<< ", Num: " << NoArv->ValorNum;
        }
    }
}


int Altura(No* NoArv){
    int Res, AltEsq, AltDir;

    if (NoArv == NULL){
        Res = -1;
    }
    else{
        AltEsq = Altura(NoArv->Esq);
        AltDir = Altura(NoArv->Dir);

        if(AltEsq > AltDir){
            Res = AltEsq + 1;
        }
        else{
            Res = AltDir + 1;
        }
    }

    return Res;
}

int Operador(string Valor){
    int Ret;

    if ((Valor == "*") || (Valor == "/") || (Valor == "+") || (Valor == "-")){
        Ret = 1;
    }
    else{
        Ret = 0; //N�o � operador!!
    }

    return Ret;
}

float Resolve_Expressao(float Num1, float Num2, string Op){
    float Res;

    if (Op == "*"){
        Res = Num1 * Num2;
    }
    else{
        if (Op == "/"){
            Res = Num1 / Num2;
        }
        else{
            if (Op == "+"){
                Res = Num1 + Num2;
            }
            else{
                if (Op == "-"){
                    Res = Num1 - Num2;
                }
                else{// <=
                    Res = Num1 <= Num2;
                }
            }
        }
    }

    return Res;
}

float CalcExpArv(No* NoArv, Pilha *P){
    float Res, Num1, Num2;
    ItemSentenca* Item;

    if (NoArv != NULL){
        CalcExpArv(NoArv->Esq, P);
        CalcExpArv(NoArv->Dir, P);

        if (Operador(NoArv->ValorTexto) == 0){
            Empilhar(P, stof(NoArv->ValorTexto));
        }
        else{ //Operador
            Item = Desempilhar(P);
            Num2 = Item->Valor;
            Item = Desempilhar(P);
            Num1 = Item->Valor;

            Res = Resolve_Expressao(Num1, Num2, NoArv->ValorTexto);
            Empilhar(P, Res);
        }

        Res = P->Topo->Valor;
    }
    return Res;
}

Arvore Arv;
Pilha P;
No *Item, *ItemE1, *ItemD1;
main (){
    setlocale (LC_ALL,"Portuguese");

    Ini_Arvore(&Arv);
    Ini_Pilha(&P);

    //�rvore para percursos pr�-ordem, central e p�s-ordem
    /*Item = InsereNoArv(&Arv, 0, "1", NULL, ""); //Raiz
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
    InsereNoArv(&Arv, 0, "C", ItemE1, "E");*/

    //1, 2, 4, 7, A, B, 3, 5, 6, 8, C, 9 - pr�-ordem
    //A, 7, B, 4, 2, 1, 5, 3, C, 8, 6, 9 - ordem central/ in-ordem
    //A, B, 7, 4, 2, 5, C, 8, 9, 6, 3, 1 - p�s-ordem
    //ImprimeArvore(Arv.Raiz, "PRE");
    //cout << endl;
    /*ImprimeArvore(Arv.Raiz, "CEN");
    cout << endl;
    ImprimeArvore(Arv.Raiz, "POS");*/

    //Cadastro da �rvore com a express�o matem�tica
    /*Item = InsereNoArv(&Arv, 0, "*", NULL, ""); //Raiz
    ItemE1 = InsereNoArv(&Arv, 0, "5", Item, "E"); //N� esquerdo
    ItemD1 = InsereNoArv(&Arv, 0, "+", Item, "D"); //N� direito
    Item = InsereNoArv(&Arv, 0, "*", ItemD1, "E"); //N� esquerdo
    InsereNoArv(&Arv, 0, "7", ItemD1, "D"); //N� esquerdo
    ItemE1 = InsereNoArv(&Arv, 0, "+", Item, "E"); //N� esquerdo
    ItemD1 = InsereNoArv(&Arv, 0, "*", Item, "D"); //N� direito
    InsereNoArv(&Arv, 0, "9", ItemE1, "E"); //N� esquerdo
    InsereNoArv(&Arv, 0, "8", ItemE1, "D"); //N� esquerdo
    InsereNoArv(&Arv, 0, "4", ItemD1, "E"); //N� esquerdo
    InsereNoArv(&Arv, 0, "6", ItemD1, "D"); //N� esquerdo*/

    //cout << endl << endl << "Inserindo 6.... " << endl;
    InsereNoArv(&Arv, 0, "6", Arv.Raiz, "", 0);
    //cout << endl << endl << "Inserindo 5.... " << endl;
    InsereNoArv(&Arv, 0, "5", Arv.Raiz, "", 0);
    //cout << endl << endl << "Inserindo 4.... " << endl;
    InsereNoArv(&Arv, 0, "4", Arv.Raiz, "", 0);
    //cout << endl << endl << "Inserindo 8.... " << endl;
    InsereNoArv(&Arv, 0, "8", Arv.Raiz, "", 0);
    InsereNoArv(&Arv, 0, "2", Arv.Raiz, "", 0);
    InsereNoArv(&Arv, 0, "1", Arv.Raiz, "", 0);
    InsereNoArv(&Arv, 0, "3", Arv.Raiz, "", 0);
    InsereNoArv(&Arv, 0, "7", Arv.Raiz, "", 0);
    InsereNoArv(&Arv, 0, "9", Arv.Raiz, "", 0);
    ImprimeArvore(Arv.Raiz, "CEN");
    cout << endl;
    system("pause");
    //RemoveNoArv(&Arv, Arv.Raiz, "8");
    RemoveNoArv(&Arv, Arv.Raiz, "6");
    cout << endl;
    ImprimeArvore(Arv.Raiz, "CEN");
    cout << endl << "Pr� Ordem: " << endl;
    ImprimeArvore(Arv.Raiz, "PRE");


    return 0;
}
