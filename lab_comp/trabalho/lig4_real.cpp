#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class lig4{
    char **pointer; 
    int linhas;
    int colunas;
    int vez_jogador;
    

   
    public:
    lig4():vez_jogador(1),linhas(6),colunas(7){
        pointer= new char*[6];

        for(int i=0;i<6;i++){
            pointer[i]=new char[7];
        }
        for(int i=0;i<6;i++){
            for(int j=0;j<7;j++){
                pointer[i][j]='.';
            }
        }
    }

    lig4(lig4 &copia){
        linhas=copia.linhas;
        colunas=copia.colunas;
        vez_jogador=copia.vez_jogador;

        pointer=new char*[linhas];
        for(int i=0;i<linhas;i++){
            pointer[i]=new char[colunas];
        }
        for(int i=0;i<linhas;i++){
            for(int j=0;j<colunas;j++){
                pointer[i][j]=copia.pointer[i][j];
            }
        }
    }

    void imprimir(){
        for(int i=0;i<linhas;i++){
            cout << endl;
            for(int j=colunas-1;j>=0;j--){
                cout << pointer[i][j] << ' ';
            }
        }
        cout << endl;
        for(int i=0;i<colunas;i++){
            cout << i+1 << " ";
        }
        cout << endl;

    }
    void alternar_vez(){
        if(vez_jogador==1){
            vez_jogador=2;
        }
        else if(vez_jogador==2){
            vez_jogador=1;
        }
    }
    bool verificar(int coluna){
        if(coluna>colunas || coluna<1){
            return(false);
        }
        for(int i=0;i<linhas;i++){
            if(pointer[i][colunas-coluna]=='.'){
                return(true);
            }
        }
        return(false);

    }

    bool jogar(int coluna){
        if(verificar(coluna)){
            if(vez_jogador==1){
                for(int i=linhas-1;i>=0;i--){
                    if(pointer[i][colunas-coluna]=='.'){
                        pointer[i][colunas-coluna]='X';
                        return(true);
                    }
                }
            }
            else if(vez_jogador==2){
                for(int i=linhas-1;i>=0;i--){
                    if(pointer[i][colunas-coluna]=='.'){
                        pointer[i][colunas-coluna]='O';
                        return(true);
                    }
                }
            }
        }
        return(false);
    }
    bool game_over(){
        pair<int,int> lol;

        lol=resultado_final();
        if(lol.first!=0 || lol.second!=0){
            return(true);
        }
        for(int i=0;i<linhas;i++){
            for(int j=0;j<colunas;j++){
                if(pointer[i][j]=='.'){
                    return(false);
                }
            }
        }
        return(true);
    }
    pair<int,int> resultado_final(){
        int pontos1=0;
        int pontos2=0;
        pair<int,int> xdd;

        for(int i=0;i<linhas;i++){
            for(int j=0;j<colunas;j++){
                if(pointer[i][j]=='X'){
                    if(j+3<colunas){
                        if(pointer[i][j+1]=='X'&&pointer[i][j+2]=='X'&&pointer[i][j+3]=='X'){
                            pontos1++;
                        }
                    }
                    if(i+3<linhas){
                        if(pointer[i+1][j]=='X' && pointer[i+2][j]=='X' && pointer[i+3][j]=='X'){
                            pontos1++;
                        }
                    }
                    if(i+3<linhas && j+3< colunas){
                        if(pointer[i+1][j+1]=='X' && pointer[i+2][j+2]=='X' && pointer[i+3][j+3]=='X'){
                            pontos1++;
                        }
                    }
                    if(i+3<linhas && j-3>=0){
                        if(pointer[i+1][j-1]=='X' && pointer[i+2][j-2]=='X' && pointer[i+3][j-3]=='X'){
                            pontos1++;
                        }
                    }

                }
                else if(pointer[i][j]=='O'){
                    if(j+3<colunas){
                        if(pointer[i][j+1]=='O'&&pointer[i][j+2]=='O'&&pointer[i][j+3]=='O'){
                            pontos2++;
                        }
                    }
                    if(i+3<linhas){
                        if(pointer[i+1][j]=='O' && pointer[i+2][j]=='O' && pointer[i+3][j]=='O'){
                            pontos2++;
                        }
                    }
                    if(i+3<linhas && j+3< colunas){
                        if(pointer[i+1][j+1]=='O' && pointer[i+2][j+2]=='O' && pointer[i+3][j+3]=='O'){
                            pontos2++;
                        }
                    }
                    if(i+3<linhas && j-3>=0){
                        if(pointer[i+1][j-1]=='O' && pointer[i+2][j-2]=='O' && pointer[i+3][j-3]=='O'){
                            pontos2++;
                        }
                    }

                }

            }
        }
        xdd.first=pontos1;
        xdd.second=pontos2;

        return(xdd);
    }
    
    void jogar_jogo(){
        
        char c='s';
        int k;
        int vitorias_1=0;
        int vitorias_2=0;
        while(c=='s'||c=='S'){
            for(int i=0;i<linhas;i++){
                for(int j=0;j<colunas;j++){
                    pointer[i][j]='.';
                }
            }
            vez_jogador=1;
            while(!game_over()){
                cout << "Vez do jogador " << vez_jogador << ":" << endl;
                imprimir();
                if(vez_jogador==1){
                    k=melhor_jogada_cope()+1;
                    while(!verificar(k)){
                        k=rand()%7;
                        k+1;
                    }
                }
                else if(vez_jogador==2){
                do{
                    k=rand()%7+1;
                } while(!verificar(k));}

                jogar(k);
                alternar_vez();
            }
            imprimir();
            pair<int,int> a = resultado_final();
            if(a.first>0){
                cout << "jogador 1 ganhou" << endl;
                vitorias_1++;
            }
            else if(a.second>0){
                cout << "jogador 2 ganhou" << endl;
                vitorias_2++;
            }
            else{
                cout << "empate" << endl;
            }

            if(vitorias_2>0){
                c='f';
            }
            
        }

        cout << "bot ganhou:" << vitorias_1 << endl;

    }

    int melhor_jogada_cope(){
        pair<int,int> omegalul;
        int k=vez_jogador;
        long long int x[7]={0,0,0,0,0,0,0};
        char*** xdd;
        xdd=new char**[7*7*7*7*7];

        for(int i=0;i<7*7*7*7*7;i++){
            xdd[i]=new char*[6];
        }

        for(int i=0;i<7*7*7*7*7;i++){
            for(int j=0;j<6;j++){
                xdd[i][j]=new char[7];
            }
        }

        for(int i=0;i<7*7*7*7*7;i++){
            for(int j=0;j<6;j++){
                for(int k=0;k<7;k++){
                    xdd[i][j][k]=pointer[j][k];
                }
            }
        }

        
        for(int a=0;a<7;a++){
            for(int b=0;b<7;b++){
                for(int c=0;c<7;c++){
                    for(int d=0;d<7;d++){
                        for(int e=0;e<7;e++){
                            k=1;

                            if(!verificar_qualquer(a+1,xdd[a*7*7*7*7+b*7*7*7+c*7*7+d*7+e])){
                                continue;
                            }
                            jogar_qualquer_jogo(a+1,xdd[a*7*7*7*7+b*7*7*7+c*7*7+d*7+e],k);

                            k=2;

                            omegalul=resultado_final_qualquer_jogo(xdd[a*7*7*7*7+b*7*7*7+c*7*7+d*7+e]);
                            if(omegalul.second>0){
                                x[a]-=10;
                            }
                            if(omegalul.first>0){
                                x[a]+=1;
                            }

                            if(!verificar_qualquer(b+1,xdd[a*7*7*7*7+b*7*7*7+c*7*7+d*7+e])){
                                continue;
                            }
                            jogar_qualquer_jogo(b+1,xdd[a*7*7*7*7+b*7*7*7+c*7*7+d*7+e],k);

                            k=1;

                            omegalul=resultado_final_qualquer_jogo(xdd[a*7*7*7*7+b*7*7*7+c*7*7+d*7+e]);
                            if(omegalul.second>0){
                                x[a]-=10;
                            }
                            if(omegalul.first>0){
                                x[a]+=1;
                            }

                            if(!verificar_qualquer(c+1,xdd[a*7*7*7*7+b*7*7*7+c*7*7+d*7+e])){
                                continue;
                            }
                            jogar_qualquer_jogo(c+1,xdd[a*7*7*7*7+b*7*7*7+c*7*7+d*7+e],k);

                            k=2;

                            omegalul=resultado_final_qualquer_jogo(xdd[a*7*7*7*7+b*7*7*7+c*7*7+d*7+e]);
                            if(omegalul.second>0){
                                x[a]-=10;
                            }
                            if(omegalul.first>0){
                                x[a]+=1;
                            }

                            if(!verificar_qualquer(d+1,xdd[a*7*7*7*7+b*7*7*7+c*7*7+d*7+e])){
                                continue;
                            }
                            jogar_qualquer_jogo(d+1,xdd[a*7*7*7*7+b*7*7*7+c*7*7+d*7+e],k);

                            k=1;

                            omegalul=resultado_final_qualquer_jogo(xdd[a*7*7*7*7+b*7*7*7+c*7*7+d*7+e]);
                            if(omegalul.second>0){
                                x[a]-=10;
                            }
                            if(omegalul.first>0){
                                x[a]+=1;
                            }

                            if(!verificar_qualquer(e+1,xdd[a*7*7*7*7+b*7*7*7+c*7*7+d*7+e])){
                                continue;
                            }
                            jogar_qualquer_jogo(e+1,xdd[a*7*7*7*7+b*7*7*7+c*7*7+d*7+e],k);

                            omegalul=resultado_final_qualquer_jogo(xdd[a*7*7*7*7+b*7*7*7+c*7*7+d*7+e]);
                            if(omegalul.second>0){
                                x[a]-=10;
                            }
                            if(omegalul.first>0){
                                x[a]+=1;
                            }

                        }
                    }

                }
            }

        }

        int h=0;
        for(int i=1;i<7;i++){
            if(x[i]>x[h]){
                h=i;
            }
        }

        for(int i=0;i<7*7*7*7*7;i++){
            for(int j=0;j<6;j++){
                delete[] xdd[i][j];
            }
        }

        for(int i=0;i<7*7*7*7*7;i++){
            delete[] xdd[i];
        }

        delete[] xdd;




        return(h);


    }

    bool jogar_qualquer_jogo(int coluna,char **pointer,int vez_jogador){
        if(verificar_qualquer(coluna,pointer)){
            if(vez_jogador==1){
                for(int i=linhas-1;i>=0;i--){
                    if(pointer[i][colunas-coluna]=='.'){
                        pointer[i][colunas-coluna]='X';
                        return(true);
                    }
                }
            }
            else if(vez_jogador==2){
                for(int i=linhas-1;i>=0;i--){
                    if(pointer[i][colunas-coluna]=='.'){
                        pointer[i][colunas-coluna]='O';
                        return(true);
                    }
                }
            }
        }
        return(false);
    }

    pair<int,int> resultado_final_qualquer_jogo(char **pointer){
        int pontos1=0;
        int pontos2=0;
        pair<int,int> xdd;

        for(int i=0;i<linhas;i++){
            for(int j=0;j<colunas;j++){
                if(pointer[i][j]=='X'){
                    if(j+3<colunas){
                        if(pointer[i][j+1]=='X'&&pointer[i][j+2]=='X'&&pointer[i][j+3]=='X'){
                            pontos1++;
                        }
                    }
                    if(i+3<linhas){
                        if(pointer[i+1][j]=='X' && pointer[i+2][j]=='X' && pointer[i+3][j]=='X'){
                            pontos1++;
                        }
                    }
                    if(i+3<linhas && j+3< colunas){
                        if(pointer[i+1][j+1]=='X' && pointer[i+2][j+2]=='X' && pointer[i+3][j+3]=='X'){
                            pontos1++;
                        }
                    }
                    if(i+3<linhas && j-3>=0){
                        if(pointer[i+1][j-1]=='X' && pointer[i+2][j-2]=='X' && pointer[i+3][j-3]=='X'){
                            pontos1++;
                        }
                    }

                }
                else if(pointer[i][j]=='O'){
                    if(j+3<colunas){
                        if(pointer[i][j+1]=='O'&&pointer[i][j+2]=='O'&&pointer[i][j+3]=='O'){
                            pontos2++;
                        }
                    }
                    if(i+3<linhas){
                        if(pointer[i+1][j]=='O' && pointer[i+2][j]=='O' && pointer[i+3][j]=='O'){
                            pontos2++;
                        }
                    }
                    if(i+3<linhas && j+3< colunas){
                        if(pointer[i+1][j+1]=='O' && pointer[i+2][j+2]=='O' && pointer[i+3][j+3]=='O'){
                            pontos2++;
                        }
                    }
                    if(i+3<linhas && j-3>=0){
                        if(pointer[i+1][j-1]=='O' && pointer[i+2][j-2]=='O' && pointer[i+3][j-3]=='O'){
                            pontos2++;
                        }
                    }

                }

            }
        }
        xdd.first=pontos1;
        xdd.second=pontos2;

        return(xdd);
    }

    bool verificar_qualquer(int coluna,char **pointer){
        if(coluna>colunas || coluna<1){
            return(false);
        }
        for(int i=0;i<linhas;i++){
            if(pointer[i][colunas-coluna]=='.'){
                return(true);
            }
        }
        return(false);

    }
    

    ~lig4(){
        for(int i=0;i<linhas;i++){
            delete[] pointer[i];
        }
        delete[] pointer;
    }


};





int main(){
    lig4 jogo;
    jogo.jogar_jogo();
}