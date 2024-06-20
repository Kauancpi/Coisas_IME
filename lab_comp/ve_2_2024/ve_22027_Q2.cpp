#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class personagem {
    string nome;
    string classe;
    int saude_inicial;

    public:
    personagem(){
        nome="";
        classe="";
        saude_inicial=0;
    }
    personagem(string nome_,string classe_,int saude):nome(nome_),classe(classe_),saude_inicial(saude){

    }
    personagem(personagem &p2){
        nome=p2.nome;
        classe=p2.classe;
        saude_inicial=p2.saude_inicial;
    }

    void readFromFile (istream &obj){
        char ch;
        string name="";
        string class_="";
        string health="";
        while(obj.get(ch)&& ch!=','){
            name.push_back(ch);
        }
        while(obj.get(ch)&& ch!=','){
            class_.push_back(ch);
        }
        while(obj.get(ch)&& ch!='\n'){
            health.push_back(ch);
        }

        nome=name;
        classe=class_;
        saude_inicial=stoi(health);
    }

    void writeToFile (ostream &obj){
        for(int i=0;i<nome.size();i++){
            obj.put(nome[i]);
        }
        obj.put(',');
        for(int i=0;i<classe.size();i++){
            obj.put(classe[i]);
        }
        obj.put(',');
        string health=to_string(saude_inicial);
        for(int i=0;i<health.size();i++){
            obj.put(health[i]);
        }
        obj.put('\n');
    }

    bool operator==(personagem p2){
        return((nome==p2.nome));
    }



};


int main(){
    
    fstream arquivo;

    arquivo.open("entrada.txt",ios::in);

    personagem p;
    personagem* temp;
    vector<personagem*> vetor;
    int k=0;

    while(!(arquivo.ios::eof())){
        p.readFromFile(arquivo);
        for(int i=0;i<vetor.size();i++){
            if(p==*vetor[i]){
                k++;
            }

        }
        if(k==0){
            temp=new personagem();
            vetor.push_back(temp);
            *vetor[vetor.size()-1]=p;
        }
        k=0;
    }


    arquivo.close();
    arquivo.open("saida.txt",ios::out);

    for(int i=0;i<vetor.size();i++){
        vetor[i]->writeToFile(arquivo);
    }

    arquivo.close();


}

