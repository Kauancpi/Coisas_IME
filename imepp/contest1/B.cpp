#include <iostream>

using namespace std;

int achar_posicao(int arr[],int tamanho,int soma){
    for(int i=0;i<tamanho;i++){
        for(int j=i+1;j<tamanho;j++){
            if(arr[i]+arr[j]==soma){
                cout << i+1 << " " << j+1;
                return(0);
            }
        }
    }
    cout << -1;
    return(0);
}

int main(){
    int tamanho, soma;

    cin >> tamanho >> soma;

    int arr[tamanho];

    for(int i=0;i<tamanho;i++){
        cin >> arr[i];
    }

    achar_posicao(arr,tamanho,soma);
    
}