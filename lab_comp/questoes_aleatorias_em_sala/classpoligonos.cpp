#include <iostream>
#include <cmath>

using namespace std;

class poligono_regular{
    int numero_lados;
    float tamanho_lados;
    public:
    poligono_regular(int numero, float tamanho):numero_lados(numero),tamanho_lados(tamanho){
        if(numero>=3){
            numero_lados=numero;
        }
        else{
            cout << "nao eh um numero de lados valido, o default eh 3 lados\n";
            numero_lados=3;
        }
        if(tamanho>0){
            tamanho_lados=tamanho;
        }
        else{
            cout << "nao eh um tamanho de lados valido,o default eh 1 cm\n";
            tamanho_lados=1;
        }

    }

    int soma_angulos(){
        int soma;
        soma=180*(numero_lados-2);
        return(soma);
    }

    float perimetro(){
        float perimetro;
        perimetro=numero_lados*tamanho_lados;
        return(perimetro);
    }

    float get_Lado(){
        return(tamanho_lados);
    }


};

class triangulo:public poligono_regular{
    public:
    triangulo(float lado):poligono_regular(3,lado){}

    float Area(){
        float area;
        float lado;

        lado=get_Lado();
        area=(lado*lado)*sqrt(3)/4;
        return(area);
    }

};

class quadrado:public poligono_regular{
    public:
    quadrado(float lado):poligono_regular(4,lado){}

    float Area(){
        float area;
        float lado;

        lado=get_Lado();
        area=lado*lado;
        return(area);
    }
};

int main(){
    poligono_regular cum(-1,-1);


}