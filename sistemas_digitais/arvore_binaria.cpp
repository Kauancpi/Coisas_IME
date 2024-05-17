#include <iostream>
#include <new>

using namespace std;

struct no{
    int chave;
    no *esquerda;
    no *direita;
};

void criar_no(no **node,int xdd){
    *node = new no();
    if(!node){
        cout << "error" << endl;
    }
    (*node)->chave=xdd;
    (*node)->direita=(*node)->esquerda=NULL;
}

int adicionar_elemento(no **raiz,int xdd){
    
    if(*raiz==NULL){
        criar_no(raiz,xdd);
        return(0);
    }
    else if(xdd < (*raiz)->chave){
        adicionar_elemento(&(*raiz)->esquerda,xdd);
        return(0);
    }
    else if(xdd > (*raiz)->chave){
        adicionar_elemento(&(*raiz)->direita,xdd);
        return(0);
    }
    else if(xdd==(*raiz)->chave){
        cout << "Nao da pra inserir";
        return(0);
    }
    
}

int imprimir_arvore(no *raiz){
    if(raiz==NULL){
        return(0);
    }
    cout << raiz->chave << endl;
    imprimir_arvore(raiz->esquerda);
    imprimir_arvore(raiz->direita);
    return(0);

}

struct no *busca(no *raiz,int xdd,no **pai){
    while(raiz->chave!=xdd){
        if(xdd<raiz->chave && raiz->esquerda!=NULL){
            raiz=raiz->esquerda;
        }
        else if(xdd>raiz->chave && raiz->direita!=NULL){
            raiz=raiz->direita;
        }
        else{
            break;
        }
    }
    if(xdd==raiz->chave){
        return(raiz);
    }
    return(NULL);
}

int main(){
    no *raiz=NULL;
    no *cum;

    adicionar_elemento(&raiz,40);
    adicionar_elemento(&raiz,20);
    adicionar_elemento(&raiz,10);
    adicionar_elemento(&raiz,30);
    adicionar_elemento(&raiz,80);
    adicionar_elemento(&raiz,60);
    adicionar_elemento(&raiz,50);
    adicionar_elemento(&raiz,70);

    imprimir_arvore(raiz);
    cum=busca(raiz,10,NULL);

    cout << endl;

    imprimir_arvore(cum);






}