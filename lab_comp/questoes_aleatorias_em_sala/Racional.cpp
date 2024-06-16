#include <iostream>
#include <algorithm>

using namespace std;


class NumeroRacional{
    int numerador;
    int denominador;

    void reduzir_fracao(){
        int gcd;
        gcd=__gcd(numerador,denominador);
        numerador=numerador/gcd;
        denominador=denominador/gcd;
    }

    public:
    NumeroRacional(int num,int den){
        int k;
        if(den==0){
            throw invalid_argument("denominador nao pode ser 0");
        }
        else if(den<0){
            den=(-1)*den;
            num=(-1)*num;
        }
        k=__gcd(num,den);
        num=num/k;
        den=den/k;
        numerador=num;
        denominador=den;
    }


    NumeroRacional operator+(NumeroRacional &n2){
        NumeroRacional k(1,1);
        k.numerador=numerador*n2.denominador+n2.numerador*denominador;
        k.denominador=denominador*n2.denominador;
        k.reduzir_fracao();
        return(k);
    }

    NumeroRacional operator/(NumeroRacional &n2){
        NumeroRacional k(1,1);
        k.numerador=numerador*n2.denominador;
        k.denominador=denominador*n2.numerador;
        k.reduzir_fracao();
        return(k);

    }

    operator float(){
        float k;
        k=(float)numerador/(float)denominador;
        return(k);
    }

    void imprimir(){
        cout << numerador << "/" << denominador << endl;
    }

};

int main(){
    NumeroRacional meio(2,4), terco(1,3);

    meio.imprimir();

    (meio+terco).imprimir();

    (meio/terco).imprimir();

    cout << meio;


}