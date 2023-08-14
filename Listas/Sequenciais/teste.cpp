#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void splitList(Node* head, Node** head1, Node** head2) {
    // Inicializa as duas novas listas vazias
    *head1 = new Node;
    *head2 = new Node;
    Node* current = head;
    Node* current1 = *head1;
    Node* current2 = *head2;
    int count = 0;
    
    // Percorre a lista original e insere cada elemento em uma das duas novas listas
    while (current != NULL) {
        count++;
        if (count % 2 == 1) {
            current1->data = current->data;
            current1->next = new Node;
            current1 = current1->next;
        } else {
            current2->data = current->data;
            current2->next = new Node;
            current2 = current2->next;
        }
        current = current->next;
    }
    
    // Finaliza as novas listas
    current1->next = NULL;
    current2->next = NULL;
    *head1 = (*head1)->next;
    *head2 = (*head2)->next;
}

int main() {
    // Cria uma lista encadeada com alguns elementos
    Node* head = new Node;
    head->data = 1;
    head->next = new Node;
    head->next->data = 2;
    head->next->next = new Node;
    head->next->next->data = 3;
    head->next->next->next = new Node;
    head->next->next->next->data = 4;
    head->next->next->next->next = NULL;
    
    // Divide a lista em duas
    Node* head1;
    Node* head2;
    splitList(head, &head1, &head2);
    
    // Imprime as duas novas listas
    Node* current = head1;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
    current = head2;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
    
    return 0;
}

