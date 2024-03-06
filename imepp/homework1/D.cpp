#include <iostream>
#include <map>
using namespace std;

int main() {
    map<pair<int, int>, string> myMap;

    // Prompt the user to enter key-value pairs
    int key1, key2;
    string value;
    int maps;
    int testes;
    std::cin >> maps;
    
    for(int i=0;i<maps;i++){
        std::cin >> key1 >> key2 >> value;
        myMap[{key1,key2}]=value;
    }
    std::cin >> testes;
    string xdd[testes];
    for (int j=0;j<testes;j++){
        std::cin >> key1 >> key2;
        xdd[j]=myMap[{key1,key2}];
    }
    for(int i=0;i<testes;i++){
        cout << xdd[i] << "\n";
    }
}