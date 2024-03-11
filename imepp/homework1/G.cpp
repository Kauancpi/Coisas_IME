#include <iostream>

using namespace std;

int first(int arr[], int x, int n)
{
    int low = 0, high = n - 1, res = -1;
    while (low <= high) {
 
        // Normal Binary Search Logic
        int mid = (low + high) / 2;
 
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
 
        // If arr[mid] is same as x, we
        // update res and move to the left
        // half.
        else {
            res = mid;
            high = mid - 1;
        }
    }
    return res;
}

int main(){
    int elements;
    int queries;
    int x;
    int find;
    
    cin >> elements >> queries;
    
    int arr[elements];

    for(int i=0;i<elements;i++){
        
        cin >> arr[i];
    }

    for(int i=0;i<queries;i++){
        
        cin >> x;
        find = first(arr,x,elements);
        cout << find << "\n";

    }

}