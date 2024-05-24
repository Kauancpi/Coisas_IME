#include <iostream>

using namespace std;

class soma_diferente{
    int numero;
    public:
    soma_diferente(int x):numero(x){}

    void operator! (){
        numero=(-1)*numero;
    }

    int operator+ (soma_diferente &s2){
        return(numero+s2.numero+1);
    }

    void operator= (int x){
        numero=x;
    }

    void operator=(soma_diferente &x){
        numero=x.numero;
    }

    void print_number(){
        cout << numero << endl;
    }

    int operator<<(soma_diferente &help){
        return(numero);

    }

};




int main(){

    soma_diferente c1(2),c2(3);
    string a="aaaaaaa";

    !c1;

    c1.print_number();

    c1=(c1+c2);

    cout << a;


    c1.print_number();

}