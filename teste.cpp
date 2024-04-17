#include <iostream>
#include <string>

using namespace std;

class Soldado{
    public:
    string nome;
    int saude=100;
    int ataque=5;

    void atacar(class Soldado soldado2){
        int dano=soldado2.ataque;
        defender(dano);
    }

    void defender(int dano){
        saude-=dano;
    }

};

class Elfo:public Soldado{
    int ataque_elfo=ataque+1;
};

class Humano:public Soldado{

};

class anao:public Soldado{

};

class Sauron:public Soldado{

};