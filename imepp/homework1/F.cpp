#include <iostream>
#include <string>

using namespace std;


int main(){
    int k=0;
    string nome_problema;
    string amigo1="Danil";
    string amigo2="Olya";
    string amigo3="Slava";
    string amigo4="Ann";
    string amigo5="Nikita";

    cin >> nome_problema;

    bool isFound1 = nome_problema.find(amigo1) != string::npos;
    bool isFound2 = nome_problema.find(amigo2) != string::npos;
    bool isFound3 = nome_problema.find(amigo3) != string::npos;
    bool isFound4 = nome_problema.find(amigo4) != string::npos;
    bool isFound5 = nome_problema.find(amigo5) != string::npos;

    if (isFound1)
    {
        k++;
    }
    if (isFound2)
    {
        k++;
    }
    if (isFound3)
    {
        k++;
    }
    if (isFound4)
    {
        k++;
    }
    if (isFound5)
    {
        k++;
    }

    if(k==1){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

}