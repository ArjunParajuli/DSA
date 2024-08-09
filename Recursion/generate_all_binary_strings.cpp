#include<iostream>
#include<vector>
using namespace std;

void printArr(int arr[], int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void generateBinary(int i, int n, int arr[]){
    // base case 
    if(i == n){
        printArr(arr, n);
        return;
    }

    // ek baar ith pos mei 0 rakhkar recursion ko dedo
    arr[i]=0;
    generateBinary(i+1, n, arr);

    // ek baar ith pos mei 1 rakhkar recursion ko dedo
    arr[i]=1;
    generateBinary(i+1, n, arr);
}

int main(){
    int n = 2;
    int arr[n];
    generateBinary(0, n, arr);

    return 0;
}