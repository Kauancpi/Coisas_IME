#include <iostream>

using namespace std;

int main(){
    int tamanho;

    cin >> tamanho;

    int arr1[tamanho];
    int arr2[tamanho];

    for(int i=0;i<tamanho;i++){
        cin >> arr1[i];
        arr2[i]=i+1;
        
    }
    for(int i=0;i<tamanho;i++){    
        if(arr1[i]!=0){
            arr2[arr1[i]-1]=0;
        } 
    }

    for(int i=0;i<tamanho;i++){
        if(arr1[i]==0 && arr2[i]!=0){
            for(int j=0;j<tamanho;j++){
                if(arr1[j]==0 && j!=i){
                    arr1[j]=arr2[i];
                    arr2[i]=0;
                }
            }
        }
    }
    
    
    for(int i=0;i<tamanho;i++){
        if(arr1[i]==0){
            for(int j=0;j<tamanho;j++){
                if(arr2[j]!=0){
                    arr1[i]=arr2[j];
                    arr2[j]=0;
                    break;
                }
            }
        }
    }

    for(int i=0;i<tamanho;i++){
        cout << arr1[i] << " ";
    }

}