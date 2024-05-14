#include <iostream>

using namespace std;

enum modoDeque{
    frente=0,
    retaguarda
};

class deque{
    int tamanho_max;
    int comeco;
    int final;
    int *ponteiro;

    public:
    deque(int tamanho_max_t):tamanho_max(tamanho_max_t),comeco(0),final(0){
        ponteiro=new int[tamanho_max_t]; 
    }
    
    deque(deque &deque2){
        tamanho_max=deque2.tamanho_max;
        comeco=deque2.comeco;
        final=deque2.final;
        ponteiro=new int[tamanho_max];
        for(int i=0;i<tamanho_max;i++){
            ponteiro[i]=deque2.ponteiro[i];
        }

    }
    
    bool inserir(int modo,int valor){
        if(modo==frente){
            if(final-comeco==tamanho_max){
                cout << "estrutura já está cheia" << endl;
                return(false);
            }
            else{
                for(int i=final;i>comeco;i--){
                    ponteiro[i]=ponteiro[i-1];
                }
                ponteiro[0]=valor;
                final+=1;
                cout << "numero inserido corretamente" << endl;
                return(true);
            }

        }
        if(modo==retaguarda){
            if(final-comeco==tamanho_max){
                cout << "estrutura ja esta cheia" << endl;
                return(false);
            }
            else{
                ponteiro[final]=valor;
                final+=1;
                cout << "numero inserido corretamente" << endl;
                return(true);
            }

        }
    }

    bool remover(int modo){
        if(modo==frente){
            if(comeco==final){
                cout << "deque esta vazio";
                return(false);
            }
            else{
                for(int i=comeco;i<final;i++){
                    ponteiro[i]=ponteiro[i+1];
                }
                final-=1;
                cout <<"remocao realizada com sucesso" << endl;
                return(true);
            }

        }
        if(modo==retaguarda){
            final-=1;
            cout << "remocao realizada com sucesso" << endl;
            return(true);
        }
    }
    
    void imprimir(){
        for(int i=comeco;i<final;i++){
            cout << ponteiro[i] << " ";
        }
        cout << endl;
    }
    
    ~deque(){
        delete[] ponteiro;
    }

};

class fila:public deque{
    public:
    fila(int tamanho):deque(tamanho){}

    bool inserir(int modo,int valor){
        if(modo==frente){
            cout << "fila nao insere na frente" <<endl;
            return(false);
        }
        if(modo==retaguarda){
            return(deque::inserir(modo,valor));    
        }
    }
    
    bool remover(int modo){
        bool k;
        if(modo==retaguarda){
            cout << "fila nao remove na retaguarda" << endl;
            return(false);
        }
        if(modo==frente){
            return(deque::remover(modo));        
        }

    }
};

int main(){
    fila fila1(5);

    fila1.inserir(frente,1);
    fila1.inserir(retaguarda,1);
    fila1.imprimir();

    fila1.inserir(retaguarda,2);
    fila1.imprimir();


    fila1.remover(frente);
    fila1.remover(retaguarda);
    fila1.imprimir();

    fila fila2=fila1;
    fila2.inserir(retaguarda,3);
    fila2.imprimir();
    fila1.imprimir();


    

}