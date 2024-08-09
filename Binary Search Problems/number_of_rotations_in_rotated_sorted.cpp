#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ans is the index of the minm elm in the array
// same as finding the minimum elm in rotated and sorted array.
	int findKRotation(int arr[], int n) {
	    int s=0, e=n-1;
	    int minm = INT_MAX;
        int minInd=-1;
	    while(s<=e){
	        int mid = s+(e-s)/2;
	        if(arr[s] <= arr[mid]){
	            if(arr[s] < minm){
	                minm = arr[s];
	                minInd = s;
	            }   
	            s = mid + 1;
	        }else{
	            if(arr[mid] < minm){
	                minm = arr[mid];
	                minInd = mid;
	            }
	            e = mid;
	        }
	    }
	    return minInd;
	}

int main(){
    int arr[] = {3,4,5,1,2};
    cout << findKRotation(arr, 5);

    return 0;
}