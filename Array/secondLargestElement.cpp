#include <iostream>
#include <limits.h>
using namespace std;

int secondLargestElem(int arr[], int n){
     int secmax = -1;
	    int maxm = -1;
	    for(int i=0;i<n;i++){
	        if(arr[i] > maxm){
	            secmax = maxm;
	            maxm = arr[i];
	        }
	        if(arr[i]>secmax && arr[i]<maxm)
	            secmax = arr[i];
	    }
	    return secmax;
}

int main(){

    int array[] = {2,3,5,7,0,1,7};
    int n = 7;
    cout << secondLargestElem(array, n);

    return 0;
}