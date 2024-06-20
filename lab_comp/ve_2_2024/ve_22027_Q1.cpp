#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

enum{
    sith=0,
    jedi
};

class sabre_de_luz{
    int tamanho;
    string cor;
    int energia;
    int dono;

    
    public:
    sabre_de_luz(int tamanho_,string cor_,int dono_):tamanho(tamanho_),cor(cor_),dono(dono_){
        if(dono_==0){
            energia=105;
        }
        else if(dono_==1){
            energia=100;
        }

    }

    sabre_de_luz(sabre_de_luz &s){
        tamanho=s.tamanho;
        cor=s.cor;
        energia=s.energia;
        dono=s.dono;
    }

    void imprimir_tudo(){
        cout << tamanho << " " << cor << " " << energia << " ";
        if(dono==0){
            cout << "sith" << endl;
        }
        else{
            cout << "jedi" << endl;
        }
    }

    int get_tamanho(){
        return(tamanho);
    }

    string get_cor(){
        return(cor);
    }

    sabre_de_luz operator+(sabre_de_luz &sabre2){
        int size=tamanho+sabre2.tamanho;
        int energy=energia+sabre2.energia;
        int owner=dono+sabre2.dono;
        if(owner>0){
            owner=1;
        }

        vector<string> cores_total;
        string delim=",";
        string temp;
        string cor_temp=cor;
        string cor2_temp=sabre2.cor;
        size_t pos=0;
        int k=0;

        while ((pos = cor_temp.find(delim)) != std::string::npos) {
            temp = cor_temp.substr(0, pos);
            for(int i=0;i<cores_total.size();i++){
                if(temp==cores_total[i]){
                    k++;
                }
            }
            if(k==0){
                cores_total.push_back(temp);
            }
            k=0;

            
            cor_temp.erase(0, pos + delim.length());
        }
        for(int i=0;i<cores_total.size();i++){
            if(cor_temp==cores_total[i]){
                k++;
            }
        }
        if(k==0){
            cores_total.push_back(cor_temp);
        }


        while ((pos = cor2_temp.find(delim)) != std::string::npos) {
            temp = cor2_temp.substr(0, pos);
            for(int i=0;i<cores_total.size();i++){
                if(temp==cores_total[i]){
                    k++;
                }
            }
            if(k==0){
                cores_total.push_back(temp);
            }
            k=0;

            
            cor2_temp.erase(0, pos + delim.length());
        }
        for(int i=0;i<cores_total.size();i++){
            if(cor2_temp==cores_total[i]){
                k++;
            }
        }
        if(k==0){
            cores_total.push_back(cor2_temp);
        }

        string cor_final="";

        for(int i=0;i<cores_total.size();i++){
            if(i==cores_total.size()-1){
                cor_final+=cores_total[i];
            }
            else{
                cor_final=cor_final+cores_total[i]+",";
            }
            
        }

        sabre_de_luz sabre3(size,cor_final,owner);

        sabre3.energia=energy;

        return(sabre3);
    }

    sabre_de_luz operator*(sabre_de_luz &sabre2){
        int produto1;
        int produto2;

        produto1=tamanho*energia;
        produto2=sabre2.tamanho*sabre2.energia;

        if(produto1>=produto2){
            sabre_de_luz sabre3(*this);
            sabre3.energia-=10;
            if(sabre3.dono==0){
                sabre3.tamanho-=10;
            }
            else if(sabre3.dono==1){
                sabre3.tamanho-=5;
            }
            
            return(sabre3);
        }
        if(produto1<produto2){
            sabre_de_luz sabre3(sabre2);
            sabre3.energia-=10;
            if(sabre3.dono==0){
                sabre3.tamanho-=10;
            }
            else if(sabre3.dono==1){
                sabre3.tamanho-=5;
            }
            
            return(sabre3);
        }
    }

    friend istream& operator >> (istream &is, sabre_de_luz &obj);
    friend ostream& operator << (ostream &os, const sabre_de_luz &obj);
};


istream& operator >> (istream &is, sabre_de_luz &obj){
    cout << "Tamanho?" << endl;
    cin >> obj.tamanho;
    cout << "Cor?" << endl;
    cin >> obj.cor;
    cout << "Dono?(0 para sith e 1 para jedi)" << endl;
    cin >> obj.dono;
    return(is);
}

ostream& operator << (ostream &os, const sabre_de_luz &obj){
    cout << "Tamanho: " << obj.tamanho << endl;
    cout << "Cor: " << obj.cor << endl;
    cout << "Energia: " << obj.energia << endl;

    cout << "Dono: ";
    if(obj.dono==0){
        cout << "sith" << endl;

    }
    else{
        cout << "jedi" << endl;

    }
    return(os);
}



int main(){

    sabre_de_luz sabre1(10,"azul,verde",sith),sabre2(20,"verde,rosa",sith);

    sabre_de_luz sabre3=sabre1+sabre2;

    sabre3.imprimir_tudo();

    cout << sabre3;

    cout << sabre3*sabre1;
    


    
}