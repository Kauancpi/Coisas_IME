#include <iostream>
#include <string>

using namespace std;

class superpoder{
    string nome;
    int categoria;

    public:
    superpoder(string nome_, int categoria_):nome(nome_),categoria(categoria_){}
    superpoder(){}

    string get_nome(){
        return(nome);
    }
    int get_categoria(){
        return(categoria);
    }


};

class personagem{
    string nome;
    string nome_vida_real;
    superpoder **superpoderes;
    protected:
    personagem(string nome_,string nome_vida_real_):nome(nome_),nome_vida_real(nome_vida_real){
        superpoderes=new superpoder*[4];
        for(int i=0;i<4;i++){
            (superpoderes)[i]=NULL;
        }
    }

    public:
    bool adiciona_superpoder(superpoder &superpoder_a_adicionar){
        for(int i=0;i<4;i++){
            if(superpoderes[i]==NULL){
                superpoderes[i]=&superpoder_a_adicionar;
                return(true);
            }
        }
        return(false);
    }
    string get_nome(){
        return(nome);
    }
    virtual double get_poder_total(){
        double counter=0;
        double temp=0;
        for(int i=0;i<4;i++){
            if(superpoderes[i]!=NULL){
                temp=superpoderes[i]->get_categoria();
                counter+=temp;
            }
        }
        return(counter);
    }

    superpoder** get_pointer(){
        return(superpoderes);
    }

    ~personagem(){
        delete[] superpoderes;
    }

};

class superheroi: public personagem{
    public:
    superheroi(string nome2,string nome3):personagem(nome2,nome3){}

    double get_poder_total() override{
        superpoder** xdd=get_pointer();
        double counter=0;
        double temp=0;
        for(int i=0;i<4;i++){
            if(xdd[i]!=NULL){
                temp=xdd[i]->get_categoria();
                counter+=temp;
            }
        }
        return(1.1*counter);
    }

};

class vilao:public personagem{
    int tempo_prisao;

    public:
    vilao(string nome_,string nome_vida_real_,int tempo_cadeia):personagem(nome_,nome_vida_real_),tempo_prisao(tempo_cadeia){}
    double get_poder_total() override{
        superpoder** xdd=get_pointer();
        double counter=0;
        double temp=0;
        for(int i=0;i<4;i++){
            if(xdd[i]!=NULL){
                temp=xdd[i]->get_categoria();
                counter+=temp;
            }
        }
        return((1+0.01*tempo_prisao)*counter);
    }

};

class confronto{
    public:
    string enfrentar(superheroi &heroi,vilao &villain){
        if(heroi.get_poder_total()>villain.get_poder_total()){
            return(heroi.get_nome());
        }
        if(heroi.get_poder_total()<villain.get_poder_total()){
            return(villain.get_nome());
        }
        else{
            return("empate");
        }
        
    }

};


int main(){

}