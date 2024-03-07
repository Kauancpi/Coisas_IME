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

    size_t isFound1 = nome_problema.find(amigo1);
    size_t isFound2 = nome_problema.find(amigo2);
    size_t isFound3 = nome_problema.find(amigo3);
    size_t isFound4 = nome_problema.find(amigo4);
    size_t isFound5 = nome_problema.find(amigo5);
    if (isFound1 != string ::npos)
    {
        k++;
    }
    char arr1[]="Danil";
    isFound1=nome_problema.find(arr1, isFound1+1);
    if (isFound1 != string::npos)
    {
        k++;
    }

    if (isFound2!=string::npos)
    {
        k++;
    }
    char arr2[]="Olya";
    isFound2=nome_problema.find(arr2, isFound2+1);
    if (isFound2 != string::npos)
    {
        k++;
    }

    if (isFound3!=string::npos)
    {
        k++;
    }
    char arr3[]="Slava";
    isFound3=nome_problema.find(arr3, isFound3+1);
    if (isFound3 != string::npos)
    {
        k++;
    }

    if (isFound4!=string::npos)
    {
        k++;
    }
    char arr4[]="Ann";
    isFound4=nome_problema.find(arr4, isFound4+1);
    if (isFound4!=string::npos)
    {
        k++;
    }

    if (isFound5!=string::npos)
    {
        k++;
    }
    char arr5[]="Nikita";
    isFound5=nome_problema.find(arr5, isFound5+1);
    if (isFound5!=string::npos)
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