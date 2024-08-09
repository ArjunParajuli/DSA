#include <iostream>
#include<algorithm>
using namespace std;


    void reverse(int arr[], int start, int end){
        while(start < end){
            swap(arr[start++], arr[end--]);
        }
    }
     void rotateArrAntiClockwise(int arr[], int d, int n){   // rotate anti-clockwise
        d = d % n;
        reverse(arr, 0, n-1);
        reverse(arr, 0, n-d-1);
        reverse(arr, n-d, n-1);
    }

    void rotateArrClockwise(int arr[], int d, int n){   // rotate clockwise
        d = d % n;
        reverse(arr, 0, n-1);
        reverse(arr, 0, d-1);
        reverse(arr, d, n-1);
    }

int main() {
    int arr[] = {2,4,6,8,10,12,14,16,18,20};
    int n=10;
    rotateArrClockwise(arr,3,10);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}