#include <iostream>
#include <set>

using namespace std;
void bubbleSort(int arr[], int n) 
{ 
    int i, j; 
    for (i = 0; i < n - 1; i++) 
        for (j = 0; j < n - i - 1; j++) 
            if (arr[j] > arr[j + 1]) 
                swap(arr[j], arr[j + 1]); 
} 

int main(){
    int n,a,b,c;
    int x=0;
    cin >> n >> a >> b >> c;
    int arr[3]={a,b,c};
    bubbleSort(arr,3);

    for(int i=(n/arr[0]);i>=0;i--){
        for(int j=(n/arr[1]);j>=0;j--){
            for(int k=(n/arr[2]);k>=0;k--){
                x=i*arr[0]+j*arr[1]+k*arr[2];
                if(x==n){
                    cout << i+j+k;
                    return(0);
                }
            }
        }
    }

}
