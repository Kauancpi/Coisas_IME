#include <iostream>
#include <set>
using namespace std;

int main(){
    int numero_operacoes;
    cin >> numero_operacoes;

    std::set<int> set1;

    int numero;
    int numero_temp;
    string operacao;
    string operacao_temp="+";
    int modulo;
    
    for(int i=0;i<numero_operacoes;i++){
        
        std::cin >> operacao >> numero;
        
        if(operacao=="+" && operacao_temp!="?"){
            set1.insert(numero);
            
        }
        else if(operacao=="?"){
            auto it = set1.lower_bound(numero);
            if(it==set1.end()){
                numero_temp=-1;
            }
            else{
                numero_temp=*it;
            }
            cout << numero_temp << "\n";

        }
        else if(operacao == "+" && operacao_temp == "?"){
            
            modulo = (numero+numero_temp)%1000000000;
            
            if(modulo<0){
                modulo=1000000000+modulo;
            } 
            set1.insert(modulo);
            

        }
        operacao_temp = operacao;
    }
    
}
