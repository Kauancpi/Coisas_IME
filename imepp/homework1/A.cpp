#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        // Move elements of arr[0..i-1],
        // that are greater than key, 
        // to one position ahead of their
        // current position
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
    
    for (int i=0;i<tamanho;i++){
        if (array[i]>array[0]){
            cout << array[i];
            break;
        }
        else{
            if(i==tamanho-1){
                cout << "NO";
            }
            continue;
        }
    }
    
}