#include <iostream>

using namespace std;

class lig4{
    char **pointer; 
    int linhas;
    int colunas;
    int vez_jogador;
   
    public:
    lig4(int numero_linhas,int numero_colunas):vez_jogador(1),linhas(numero_linhas),colunas(numero_colunas){
        pointer= new char*[numero_linhas];

        for(int i=0;i<numero_linhas;i++){
            pointer[i]=new char[numero_colunas];
        }
        for(int i=0;i<numero_linhas;i++){
            for(int j=0;j<numero_colunas;j++){
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
        for(int i=0;i<linhas;i++){
            for(int j=0;j<colunas;j++){
                if(pointer[i][j]=='.'){
                    return(false);
                }
            }
        }
        return(true);
    }
    void resultado_final(){
        int pontos1=0;
        int pontos2=0;

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

        cout << "Pontos jogador 1:" << pontos1 << endl;
        cout << "Pontos jogador 2:" << pontos2 << endl;



    }
    
    void jogar_jogo(){
        
        char c='s';
        int k;
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

                do{
                    cout << "Em qual coluna vc gostaria de jogar? (1- " << colunas << ")" << endl;
                    cin >> k;
                } while(!verificar(k));

                jogar(k);
                alternar_vez();
            }
            imprimir();
            resultado_final();
            cout << "Gostaria de jogar novamente? (s/n)" << endl;
            cin >> c; 
        }

    }
    



    ~lig4(){
        for(int i=0;i<linhas;i++){
            delete[] pointer[i];
        }
        delete[] pointer;
    }
};




int main(){
    int linhas;
    int colunas;
    
    cout << "Coloque o numero de linhas: " << endl;
    cin >> linhas;

    cout << "Coloque o numero de colunas: " <<endl;
    cin >> colunas;
    
    lig4 jogo(linhas,colunas);
    jogo.jogar_jogo();
}