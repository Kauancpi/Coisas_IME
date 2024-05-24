#include <iostream>

using namespace std;



class contador{
    static int counter;
    public:
    contador(){
        counter ++;
    }

    static void show(){
        cout << counter << endl;
    }

    ~contador(){
        counter --;
    }

};

int contador::counter=0;

int main(){
    contador *x1;
    contador *x2;
    contador *x3;
    contador *x4;

    x1=new contador;
    x2=new contador;
    x3=new contador;
    x4=new contador;


    x1->show();

    delete x1;

    contador::show();

    delete x2;
    delete x3;
    delete x4;

    contador::show(); 

    
}