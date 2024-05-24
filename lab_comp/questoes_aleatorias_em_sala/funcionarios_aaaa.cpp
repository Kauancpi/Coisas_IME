#include <iostream>
#include <string>
#include <vector>

using namespace std;

class empregado{
    const string nome;
    double salario;
    int ramal;
    static int counter;

    public:
    empregado(string name, double money, int phone):nome(name),salario(money),ramal(phone){
        counter++;
        if(counter>50 || counter < 10){
            cout << "erro, tem " << counter << " funcionarios" <<  endl;;
        }
    }

    empregado(const empregado &emp2):nome(emp2.nome){
        counter++;
        salario=emp2.salario;
        ramal=emp2.ramal;
    }

    string get_nome(){
        return(nome);
    }

    double get_salary(){
        return(salario);
    }

    int get_ramal(){
        return(ramal);
    }

    void set_salary(double salary){
        salario=salary;
    }

    void set_ramal(int aaaa){
        ramal=aaaa;
    }


    ~empregado(){
        counter--;
        if(counter>50 || counter < 10){
            cout << "erro tem "  << counter << " funcionarios" << endl;
        }
    }


};


int empregado::counter =0;

int main(){
    vector<empregado*> xdd;

    xdd.resize(100);

    for(int i=0;i<100;i++){
        xdd[i]=new empregado("amogus",100,1);
    }

    for(int i=0;i<100;i++){
        delete xdd[i];
    }
}