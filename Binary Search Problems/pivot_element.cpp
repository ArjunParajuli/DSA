#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// here pivot elm - maximum element in a roatted and sorted array
int pivotElm(vector<int> arr, int n){
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    while(s<=e){
        // single elm case
            if(s == e)
                return s;
                // handle case where mid is at 7 (arr is [4 5 6 7 0 1 2])
             if(arr[mid] > arr[mid+1])
                return mid;
                 // handle case where mid is at 0 (arr is [4 5 6 7 0 1 2])
            else if(arr[mid] < arr[mid-1])
                return mid-1;
                // when mid is on right part of pivot
            else if(arr[mid] < arr[s])
                e = mid-1;
                // when mid is at left part of pivot
            else
                s = mid+1;

                mid = s + (e-s)/2;
}
    return -1; 
}

int main(){
    vector<int> arr = {12,4,6,8,10};
    cout << pivotElm(arr, 5);

    return 0;
}