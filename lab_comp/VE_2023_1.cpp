#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class soldado{
    string nome;
    float saude;
    float poder_de_ataque;

    public:
    soldado(string cum, float cum2, float cum3):nome(cum),saude(cum2),poder_de_ataque(cum3){
        if(cum2<=0 || cum3 < 0){
            std::cout << "Valor inválido de saúde ou ataque, o default será 100 de hp e 10 de ataque";
            saude=100;
            poder_de_ataque=10;
        }
    }
    soldado(){}

    virtual void atacar(shared_ptr<soldado> soldado2);
    void defesa(float ataque);
    float get_attack();
    void show();
    float get_hp();
    bool is_alive();
    string get_name(){
        return(nome);
    }

};


float soldado::get_attack(){
    float k=poder_de_ataque;
    return(k);
}
void soldado::atacar(shared_ptr<soldado> soldado2){
    soldado2->defesa(poder_de_ataque);  
}
void soldado::defesa(float ataque){
    saude=saude-ataque;
}
void soldado::show(){
    std::cout << "Nome: " << nome << endl;
    std::cout << "Pontos de vida: " << saude << endl;
    std::cout << "Pontos de ataque:" << poder_de_ataque << endl;

}
float soldado::get_hp(){
    float x=saude;
    return(x);
}
bool soldado::is_alive(){
    if(saude<=0){
        return(false);
    }
    else{
        return(true);
    }
}

class elfo: public soldado{
    public:
    elfo(string nome,float saude_base,float ataque_base):soldado(nome,saude_base,ataque_base+1){}

};

class anal : public soldado {
public:
    anal(string nome, float saude_base, float ataque_base) : soldado(nome, saude_base, ataque_base + 20) {}
    void atacar(shared_ptr<soldado> soldado2) override;
};

void anal::atacar(shared_ptr<soldado> soldado2) {
    int k = rand() % 10;
    float x = get_attack();
    if (k > 4) {
        soldado2->defesa(x);
    }
}

class humano: public soldado{
    public:
    humano(string nome,float saude_base,float ataque_base):soldado(nome,saude_base,ataque_base){}
    void atacar(shared_ptr<soldado> soldado2)override;

};

void humano::atacar(shared_ptr<soldado> soldado2){
    int k=rand();
    float x=get_attack();

    if(k%10<1){
        soldado2->defesa(x);
        soldado2->defesa(x);
    }
    else{
        soldado2->defesa(x);
    }
}

class sauron: public soldado{
    public:
    sauron(string nome,float saude_base,float ataque_base):soldado(nome,saude_base*10,ataque_base){}

    void atacar(shared_ptr<soldado> soldado2) override;


};

void sauron::atacar(shared_ptr<soldado> soldado2){
    int k=rand();
    float x=get_attack();

    if(k%10<3){
        soldado2->defesa(2*x);
    }
    else{
        soldado2->defesa(x);
    }
}

class orc:public soldado{
    public:
    orc(string nome,float saude_base,float ataque_base):soldado(nome,saude_base,ataque_base){}

    void atacar(shared_ptr<soldado> soldado2) override;

};

void orc::atacar(shared_ptr<soldado> soldado2){
    int k=rand();
    float x=get_attack();

    if(k%10<2){
        soldado2->defesa(1.1*x);
        soldado2->defesa(1.1*x);
    }
    else{
        soldado2->defesa(x);
    }

}

class mago: public soldado{
    private:
    vector<class soldado> exercito_de_zumbis;
    
    public:
    mago(string nome,float saude_base,float ataque_base):soldado(nome,saude_base*2,ataque_base*5){
        soldado z("zumbi",saude_base,ataque_base);
        exercito_de_zumbis.push_back(z);
        exercito_de_zumbis.push_back(z);
        exercito_de_zumbis.push_back(z);
    }

    int get_size();

    void atacar(shared_ptr<soldado> soldado2) override;

    
    ~mago(){
        exercito_de_zumbis.clear();
    }
    
};

int mago::get_size(){
    int k=exercito_de_zumbis.size();
    return(k);
}

void mago::atacar(shared_ptr<soldado> soldado2){
    int x=get_size();
    float y=get_attack();
    soldado2->defesa(y);
    for(int i=0;i<x;i++){
        exercito_de_zumbis[i].atacar(soldado2);
    }
    if(!soldado2->is_alive()){
        exercito_de_zumbis.push_back(*soldado2);
    }

    float f=get_hp();
    float m=get_attack();

    soldado z("zumbi",f/2,m/5);
    exercito_de_zumbis.push_back(z);

}


int main(){
    float ataque_base;
    float saude_base;
    string nome;

    vector<shared_ptr<soldado>> battle_royale;

    std::cout << "Insira a saude_base (acima de 0)\n";
    std::cin >> saude_base; 
    std::cout << "Insira o ataque_base (nao pode ser abaixo de 0)\n";   
    std::cin >> ataque_base;

    for(int i=0;i<27;i++){
        if(i==0){
            std::cout << "Coloque o nome de Sauron\n";
            std::cin >> nome;
            battle_royale.push_back(make_shared<sauron>(nome,saude_base,ataque_base));
        }
        else if(i>0 && i<11){
            std::cout << "Coloque o nome do Orc numero " << i << endl;
            std::cin >> nome;
            battle_royale.push_back(make_shared<orc>(nome,saude_base,ataque_base));
        }
        else if(i>10 && i<16){
            std::cout << "Coloque o nome do elfo numero " << i-10 << endl;
            std::cin >> nome;
            battle_royale.push_back(make_shared<elfo>(nome,saude_base,ataque_base));

        }
        else if(i>15 && i<21){
            std::cout << "Coloque o nome do humano numero " << i-15 << endl;
            std::cin >> nome;
            battle_royale.push_back(make_shared<humano>(nome,saude_base,ataque_base));

        }
        else if(i>20 && i<26){
            std::cout << "Coloque o nome do anao numero " << i-20 << endl;
            std::cin >> nome;
            battle_royale.push_back(make_shared<anal>(nome,saude_base,ataque_base));

        }
        else if(i==26){
            std::cout << "Coloque o nome do mago" << endl;
            std::cin >> nome;
            battle_royale.push_back(make_shared<mago>(nome,saude_base,ataque_base));

        }


    }
    
    for(auto ptr:battle_royale){
        ptr->show();
    }


    while(battle_royale.size()>1){
        int i=0;
        int k=0;
        int z=0;
        int j=0;
        do{
            j=rand();
            k=rand();
            z=battle_royale.size();
            if(z==1){
                break;
            }
            }
        while(k%z==j%z);

        if(z==1){
            break;
        }


        battle_royale[j%z]->atacar(battle_royale[k%z]);

        std::cout << battle_royale[j%z]->get_name() << " atacou " << battle_royale[k%z]->get_name() << endl;
        std::cout << battle_royale[k%z]->get_name() << " ficou com " << battle_royale[k%z]->get_hp() << " de vida" << endl;
        
        if(!(battle_royale[k%z]->is_alive())){
            auto iter=battle_royale.begin()+k%z;
            battle_royale.erase(iter);
        }

    }

    std::cout << battle_royale[0]->get_name() << " ganhou" << endl;

    return(0);



}