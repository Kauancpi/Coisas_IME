#include <iostream>
#include <vector>

using namespace std;

class pedaco{
    public:
    vector <int> confeito;

    pedaco(int n_confeitos){
        confeito.resize(n_confeitos);
        for(int i=0;i<n_confeitos;i++){
            n_confeitos=0;
        }
    }

    void coloca_confeito(int i){
        confeito[i]=1;
    }

};

int numero_maximo_cortes(vector<pedaco*> &biscoito,int N,int M){
    int k=0;
    for(int i=0;i<N;i++){
        
    }

}

int main(){

    int N,M;
    int inicial,final;

    cin >> N >> M;

    vector<pedaco*> biscoito;
    biscoito.resize(N);
    for(int i=0;i<N;i++){
        biscoito[i]=new pedaco(M);
    }

    for(int i=0;i<M;i++){
        cin >> inicial >> final;

        for(int j=inicial;j<final;j++){
            biscoito[j]->coloca_confeito(i);
        }

    }




}