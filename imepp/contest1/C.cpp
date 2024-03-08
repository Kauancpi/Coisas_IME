#include <iostream>

using namespace std;

int main(){
    int tamanho;

    cin >> tamanho;

    int arr1[tamanho];
    int arr2[tamanho];

    for(int i=0;i<tamanho;i++){
        cin >> arr1[i];
    }

    for(int i=0;i<tamanho;i++){
        arr2[arr1[i]-1]= i+1;
    }

    for(int i=0;i<tamanho;i++){
        cout << arr2[i] << " ";
    }
}