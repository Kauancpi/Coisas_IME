#include <iostream>
#include <vector>

using namespace std;




class jogo_forca{
    int numero_de_tentativas;
    int numero_maximo;
    vector<string> lista_palavras;
    string palavra_atual;
    string palavra_em_construcao;
    vector<char> letras_utilizadas;
    public: 
    jogo_forca(std::vector<string> &cum):lista_palavras(cum),numero_maximo(10),palavra_atual(""){}

  
    bool iniciar(){
        srand(time(NULL));
        if(lista_palavras.size()==0){
            cout << "Nao ha mais palavras sobrando" << endl;
            return(false);
        }
        else{
            int k=rand();
            int x=lista_palavras.size();
            numero_de_tentativas=numero_maximo;

            palavra_atual=lista_palavras[k%x];
            palavra_em_construcao="";
            for(int i=0;i<palavra_atual.size();i++){
                palavra_em_construcao.append("_");


            }
            lista_palavras.erase(lista_palavras.begin()+k%x);
            letras_utilizadas.clear();
            return(true);

        }


    }

    void mostrar(){
        cout << "vc tem " << numero_de_tentativas << " sobrando" << endl;
        cout << palavra_em_construcao<< endl;

    }

    bool jogar(char c){
        int j=0;
        if(palavra_atual==""){
            cout<< "inicializacao falhou" << endl;
            return(false);

        }
        for(int i=0;i<letras_utilizadas.size();i++){
            if(c==letras_utilizadas[i]){
                cout << "letra ja adivinhada" << endl;
                return(false);
            }
        }
        letras_utilizadas.push_back(c);
        for(int i=0;i<palavra_atual.size()+1;i++){
            if(palavra_atual[i]==c){
                palavra_em_construcao[i]=c;
                j++;
            }
        }
        if(j==0){
            numero_de_tentativas-=1;
        }
        return(true);
    }

    bool fim_de_jogo(){
        if(palavra_em_construcao==palavra_atual && numero_de_tentativas>=0){
            cout << "vitoria" << endl;
            return(true);

        }
        else if(numero_de_tentativas<=0){
            cout << "derrota" <<endl;
            return(true);
        }
        else{
            return(false);
        }
    }





};


int main(){
    char c='s';
    string palavra;
    vector<string> cum;

    while(c=='s'){
        cout << "Coloque uma palavra pra lista de palavras" << endl;
        cin >> palavra;
        cum.push_back(palavra);
        cout << "Deseja adicionar outra palavra? (s/n)" << endl;
        cin >> c;

    }
    

    jogo_forca jogo1(cum);

    inicio_jogo:
    if(!jogo1.iniciar()){
        cout << "Jogo nao pode ser inicializado" << endl;
        return(0);
    }

    while(!jogo1.fim_de_jogo()){
        cout << "coloque uma letra" << endl;
        cin >> c;
        jogo1.jogar(c);
        jogo1.mostrar();

    }

    cout << "gostaria de jogar novamente?(s/n)" << endl;
    cin >> c;
    if(c=='s'){
        goto inicio_jogo;
    }
}