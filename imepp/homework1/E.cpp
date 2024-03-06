#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

void push(node** head, int data_nova){
    node* novo_node = new node();
    novo_node->data = data_nova;
    novo_node->next = *head;
    *head =novo_node;
}

bool search(node*head,int x){
    if(head==NULL){
        return false;
    }
    if(head->data==x){
        return true;
    }
    return(search(head->next,x));
}

int getCount(node* head)
{
    int count = 0; // Initialize count
    node* current = head; // Initialize current
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int achar_minimo_maior(node*head,int x){
    int count = getCount(head);
    int k=1000000000;
    node* current = head;
    for(int i=0;i<count;i++){
        if(current->data >= x && current->data < k){
            k=current->data;
        }
    }
    if(k=1000000000){
        return(-1);
    }
    else{
        return(k);
    }
}


int main(){
    
    int nao_sei_mais_que_nome_dar;
    node* head=NULL;
    int numero_de_operacoes;
    int numero;
    int numero_temp=0;
    string operacao;
    bool existe;

    cin >> numero_de_operacoes;

    for(int i=0;i<numero_de_operacoes;i++){

        cin >> operacao >> numero;
        string operacao_temp = operacao;
        
        if(operacao=="+" && operacao_temp!="?"){
            existe = search(head,numero);
            if(existe==true){
                break;

            }
            if(existe==false){
                push(&head,numero);
            }

        }
        if(operacao=="?"){
            numero_temp=achar_minimo_maior(head,numero);
            cout << numero_temp << "\n";

        }
        if(operacao=="+" && operacao_temp =="?"){
            nao_sei_mais_que_nome_dar=(numero+numero_temp)%1000000000;
            existe = search(head,nao_sei_mais_que_nome_dar);
            if(existe==true){
                break;

            }
            if(existe==false){
                push(&head,nao_sei_mais_que_nome_dar);
            }

        }
    }
}