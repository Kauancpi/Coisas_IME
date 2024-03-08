#include <iostream>
#include <string>

using namespace std;

int main(){
    string numero;
    int lenght;
    int k=0;

    cin >> numero;

    size_t found = numero.find("0");
    if (found != string::npos){
        numero.erase(found,1);
    }
    else{
        numero.erase(numero.begin());
    }
        
     cout << numero;


}