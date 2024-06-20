#include <iostream>
#include <string>
#include <vector>

using namespace std;


class FuncionarioBase{
    int id;
    string name;
    double salary;
    string tipo;

    protected:
    FuncionarioBase(int id_, string nome, double salario, string typee):id(id_),name(nome),salary(salario),tipo(typee){}

    public:
    int get_id(){
        return(id);
    }

    string get_name(){
        return(name);
    }

    double get_salary(){
        return(salary);
    }
    
    string get_tipo(){
        return(tipo);
    }
    
    void exibirDetalhes(){
        cout << "ID: " << id << endl;
        cout << "Nome: " << name << endl;
        cout << "Salario: " << salary << endl;
        cout << "Tipo: "<< tipo << endl;
    }

};

class Funcionario:public FuncionarioBase{
    public:
    Funcionario(int id_, string nome, double salario, string typee):FuncionarioBase(id_, nome,salario,typee){}

};


class Gerente:public FuncionarioBase{
    vector<FuncionarioBase> equipe;
    public:
    Gerente(int id_, string nome, double salario):FuncionarioBase(id_, nome,salario,"gerente"){}

    bool adicionarFuncionario(FuncionarioBase &trabalhador){
        if(equipe.size()<10 && trabalhador.get_tipo()!="gerente"){
            for(int i=0;i<equipe.size();i++){
                if(equipe[i].get_id()==trabalhador.get_id()){
                    cout << "Este funcionario ja esta na equipe" << endl;
                    return(false);
                }
            }
            
            equipe.push_back(trabalhador);
            cout << "Funcionario colocado com sucesso" << endl;
            return(true);
        }
        else{
            cout << "Funcionario nao pode ser adicionado na equipe" << endl;
            return(false);
        }
    }

    void mostrarTime(){
        cout << "Gerente: " << endl;
        exibirDetalhes();

        for(int i=0;i<equipe.size();i++){
            cout << "Funcionario " << i+1 << ": " << endl;
            equipe[i].exibirDetalhes();
        }

    }

    double salario_total(){
        double x=0;
        x+=get_salary();

        for(int i=0;i<equipe.size();i++){
            x+=equipe[i].get_salary();
        }

        cout << "Salario total: " << x << endl;
        return(x);

    }


};

int main(){
    Funcionario F1(1,"Kauan",100,"vendedor"),F2(2,"Thurler",200,"developer"),F3(3,"Romariz",150,"gerente");
    Gerente G1(0,"Bob",1000);

    G1.adicionarFuncionario(F1);
    G1.adicionarFuncionario(F2);
    G1.adicionarFuncionario(F3);
    G1.adicionarFuncionario(F2);

    G1.mostrarTime();
    G1.salario_total();

}
