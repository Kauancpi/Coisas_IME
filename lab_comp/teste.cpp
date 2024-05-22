#include <iostream>

using namespace std;

class Lig4
{
private:
    char **matriz;
    int linha, coluna;
    bool vezjogador;
public:
    Lig4(int linha, int coluna){
    vezjogador = false;
    matriz = new char*[linha];
    for (int i = 0; i < linha; i++)
    {
        matriz[i] = new char[coluna];   
    }
    for (int i = 0; i < linha; i++)
    {
    for (int j = 0; j < coluna; j++)
    {
        matriz[i][j]='.';
    }
    
    }
    
    }
    void AlternarVez(){
        vezjogador = !vezjogador;
    }
    void Jogada(int coluna1){
        if (VerificarJogada(coluna1))
        {
            int count = linha-1;
            while (matriz[count][coluna1]!= '.')
            {
                count--;
            }
            if (!vezjogador)
            {
                matriz[count][coluna1] = 'X';
            }
            else
            {
                matriz[count][coluna1] = '0';
            }
        }
    }
    bool VerificarJogada(int coluna1){
        if (coluna1 > coluna || matriz[0][coluna-1] != '.'|| coluna1<0)
        {
            cout << "Jogada Invalida" << endl;
            return false;
        }
        else
        return true;
        
    }
    void Exibir(){
        for (int i = 0; i < linha-1; i++)
        {
            for (int j = 0; j < coluna-1; j++)
            {
                cout << matriz[i][j] << " ";
            }
            cout << endl;            
        }
        cout << endl << endl;
        return;
    }
    void ResultadoFinal(){
        int pontos1=0;
        int pontos2=0;
        int testarcolunas=0;
        for (int i = 0; i < coluna; i++)
        {
            if (VerificarJogada(i))
            {
                testarcolunas++;
            }
        }
        if (testarcolunas==0)
        {
            for (int i = 0; i < linha; i++)
            {
                for (int j = 0; j < coluna; j++)
                {
                    if (j>2)
                    {
                        if (matriz[i][j] == matriz[i][j-1] && matriz[i][j] == matriz[i][j-2] && matriz[i][j-3] ==matriz[i][j] && matriz[i][j] == 'X')
                        {
                            pontos1++;
                        }
                        if (matriz[i][j] == matriz[i][j-1] && matriz[i][j] == matriz[i][j-2] && matriz[i][j-3] ==matriz[i][j] && matriz[i][j] == '0')
                        {
                            pontos2++;
                        } 
                    }
                    if (i>2)
                    {
                        if (matriz[i][j] == matriz[i-1][j] && matriz[i-2][j] == matriz[i][j] && matriz[i-3][j] ==matriz[i][j] && matriz[i][j] == 'X')
                        {
                            pontos1++;
                        }
                        if (matriz[i][j] == matriz[i-1][j] && matriz[i-2][j] == matriz[i][j] && matriz[i-3][j] ==matriz[i][j] && matriz[i][j] == '0')
                        {
                            pontos2++;
                        }
                    }
                    if (i>2 && j>2)
                    {
                        if (matriz[i][j] == matriz[i-1][j-1] && matriz[i][j] == matriz[i-2][j-2] && matriz[i][j] == matriz[i-3][j-3] && matriz[i][j] == 'X')
                        {
                            pontos1++;
                        }
                        if (matriz[i][j] == matriz[i-1][j-1] && matriz[i][j] == matriz[i-2][j-2] && matriz[i][j] == matriz[i-3][j-3] && matriz[i][j] == '0')
                        {
                            pontos2++;
                        }
                    }
                    if (i+3<linha && j+3<coluna )
                    {
                        if (matriz[i][j] == matriz[i+1][j+1] && matriz[i][j] == matriz[i+2][j+2] && matriz[i][j] == matriz[i+3][j+3] && matriz[i][j] == 'X')
                        {
                            pontos1++;
                        }
                        if (matriz[i][j] == matriz[i+1][j+1] && matriz[i][j] == matriz[i+2][j+2] && matriz[i][j] == matriz[i+3][j+3] && matriz[i][j] == '0')
                        {
                            pontos2++;
                        }
                    }
                }
            }
            if (pontos2 > pontos1)
            {
                cout << "Jogador 2 Venceu!" << endl;
            }
            if (pontos2 < pontos1)
            {
                cout << "Jogador 1 Venceu!" << endl;
            }
            if (pontos2 == pontos1)
            {
                cout << "Empatou :(" << endl;
            }
        }
        else
        {
            cout << "Jogo Incompleto" << endl;
        }
    }
    void VamosJogar(){
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            matriz[i][j]= '.';
        }
    }
    
    }
    ~Lig4(){
    for (int i = 0; i < linha; i++)
    {
        delete[]matriz[i];
    }
    delete[]matriz;
    }
};


int main()
{
    Lig4 l(7,6);
    l.Exibir();
    return 0;
}