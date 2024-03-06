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

int achar_minimo_maior(node*head,int x){
    node* current=head;
    int k=1000000000;
    while(current!=NULL){
        if(current->data >= x && current->data < k){
            k=current->data;
        }
        current = current->next;
    }
    if(k==1000000000){
        return(-1);
    }
    else{
        return(k);
    }
}

int main(){
    
    int modulo;
    node* head=NULL;
    int numero_de_operacoes;
    int numero;
    int numero_temp=0;
    string operacao;
    bool existe;
    string operacao_temp="+";

    cin >> numero_de_operacoes;

    for(int i=0;i<numero_de_operacoes;i++){

        std::cin >> operacao >> numero;
        
        if(operacao=="+" && operacao_temp!="?"){
            existe = search(head,numero);
            if(existe==true){
                operacao_temp = operacao;
                continue;

            }
            if(existe==false){
                push(&head,numero);
            }

        }
        else if(operacao=="?"){
            numero_temp=achar_minimo_maior(head,numero);
            cout << numero_temp << "\n";

        }
        else if(operacao=="+" && operacao_temp == "?"){
                
            modulo = (numero+numero_temp)%1000000000;
            if(modulo<0){
                modulo=1000000000+modulo;
            }
            existe = search(head,modulo);
            if(existe==true){
                operacao_temp = operacao;
                continue;

            }
            if(existe==false){
                push(&head,modulo);
                } 

        }
        operacao_temp = operacao;
        
    }
}