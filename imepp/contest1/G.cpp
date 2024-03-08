#include <iostream>

using namespace std;

int maior_tamanho(int arr[],int tamanho){
    int numero_temp;
    int counter = 1;
    int counter_temp=0;
    for(int i=0;i<tamanho;i++){
        numero_temp=arr[i];
        for(int j=i;j<tamanho;j++){
            if(arr[j+1]!=numero_temp){
                counter++;
            }
            else{
                if(counter>counter_temp){
                    counter_temp=counter;
                }
                break;
            }
        }
        counter=0;
    }
    return(counter_temp);

}


int main(){
    int tamanho;
    cin >> tamanho;

    int arr[tamanho];
    int max;

    for(int i=0;i<tamanho;i++){
        cin >> arr[i];
    }

    max=maior_tamanho(arr,tamanho);

    cout << max;


}