#include <iostream>

class jogo{
    int tamanho;
    int **ponteiro;
    int turno;

    
    public:
    jogo(int xdd):tamanho(xdd),turno(1){
        ponteiro=new int*[tamanho];
        for(int i=0;i<tamanho;i++){
            ponteiro[i]=new int[tamanho];
        }
        for(int i=0;i<tamanho;i++){
            for(int j=0;j<tamanho;j++){
                ponteiro[i][j]=-1;
            }
        }
    }
    
    jogo(jogo &jogo2){
        tamanho=jogo2.tamanho;
        ponteiro=new int*[tamanho];
        for(int i=0;i<tamanho;i++){
            ponteiro[i]=new int[tamanho];
        }
        for(int i=0;i<tamanho;i++){
            for(int j=0;j<tamanho;j++){
                ponteiro[i][j]=jogo2.ponteiro[i][j];
            }
        }
    }

    bool jogar(int x,int y){
        if(turno=1){

        }
        if(turno=0){
            
        }
    }

    
    
    
    ~jogo(){
        for(int i=0;i<tamanho;i++){
            delete[] ponteiro[i];
        }
        delete[] ponteiro;
    }
};