#include <iostream>

using namespace std;



class no{
    public:
    no(){
        valor = -1;
        esquerda=NULL;
        direita=NULL;
    };
    int valor;
    no *esquerda;
    no *direita;
};

int adicionar_valor(int k, no **raiz_arvore){
    if((*raiz_arvore)->valor==-1){
        (*raiz_arvore)->valor=k;
        return(0);

    }
    else{
        if(k<(*raiz_arvore)->valor){
            no esquerda;
            (*raiz_arvore)->esquerda=&esquerda;
            adicionar_valor(k,&(*raiz_arvore)->esquerda);

        }
        if(k>(*raiz_arvore)->valor){
            no direita;
            (*raiz_arvore)->direita=&direita;
            adicionar_valor(k,&(*raiz_arvore)->direita);
        }
        if(k==(*raiz_arvore)->valor){
            return(0);
        }

    }

    return(0);

}

int imprimir_arvore(no *raiz_arvore){
    cout << raiz_arvore->valor;
    if(raiz_arvore->esquerda!=NULL){
        imprimir_arvore(raiz_arvore->esquerda);

    }
    if(raiz_arvore->direita!=NULL){
        imprimir_arvore(raiz_arvore->direita);
    }
    return(0);
}

int main(){
    no raiz;

    no*raiz_arvore=&raiz;
    
    adicionar_valor(3,&raiz_arvore);
    adicionar_valor(2,&raiz_arvore);
    adicionar_valor(1,&raiz_arvore);
    adicionar_valor(4,&raiz_arvore);
    adicionar_valor(5,&raiz_arvore);

    imprimir_arvore(raiz_arvore);

}