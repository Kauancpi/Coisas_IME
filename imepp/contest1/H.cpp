#include <iostream>

using namespace std;

int check(int arr[],int tamanho){
    float sum=0;
    int sum_temp=0;
    for(int i=0;i<tamanho;i++){
        sum+=arr[i];
    }
    float media=sum/tamanho;
    for(int i=0;i<tamanho;i++){
        for(int j=0;j<=i;j++){
            sum_temp += arr[tamanho-j-1];
        }
        if((float(sum_temp)/float((i+1))) > media){
            cout << "NO" << "\n";
            return(0);
        }
        sum_temp=0;
    }
    cout << "YES" << "\n";
    return(0);
}

int main(){
    int numero_de_operacoes;
    int tamanho;
    cin >> numero_de_operacoes;

    for(int i=0;i<numero_de_operacoes;i++){
        cin >> tamanho;
        int arr[tamanho];
        for(int j=0;j<tamanho;j++){
            cin >> arr[j];
        }
        check(arr,tamanho);
        

    }
}