#include<iostream>
using namespace std;

// find missing elm in a sorted array from 1 to N
int findMissing(int arr[], int n){
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s <= e){
        int diff = arr[mid]-mid;
        // diff=1 then ans is in right side bcoz its a sorted array
         if(diff == 1){
            s = mid+1;
        }else{ // ans is in the left side
            ans = mid;  
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    return ans+1;
}


int main(){
    int arr[] = {1,2,3,4,5,6,7,8};
    cout << findMissing(arr, 9);

    return 0;
}