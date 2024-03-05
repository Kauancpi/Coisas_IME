#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main(){
    int tamanho;
    cin >> tamanho;

    int array[tamanho];

    for (int i=0;i<tamanho;i++){
        cin >> array[i];
    }

    insertionSort(array,tamanho);
    
    for(int i=0;i<tamanho-1;i++){
        if(i%2==0){
            array[tamanho - 1 - i/2]=0;
        }
        else if(i%2==1){
            array[(i-1)/2]=0;
        }
    }
    insertionSort(array,tamanho);
    
    std::cout << array[tamanho-1];
}