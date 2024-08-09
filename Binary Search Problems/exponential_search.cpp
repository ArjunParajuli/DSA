#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// improves binary search by some extent
// also known as doubling search, galloping search, stranik search
int binarySearch(vector<int> &arr, int start, int end, int x){
    while(start <= end){
        int mid = start +(end-start)/2;
        if(arr[mid] == x)
            return mid;
        else if(arr[mid] > x)
            end = mid-1;
        else    
            start = mid+1; 
    }
    return -1;
}

int exponentialSearch(vector<int> &arr, int x){
    if(arr[0] == x) return 0;
    int n = arr.size();
    int i = 1;
    while(i<n && arr[i]<=x){
        i = i*2;
    }
    return binarySearch(arr, i/2, min(i, n-1), x);   //min(i, n-1) so that if i goes out of index(eg i=16 in this case) then we do binary search for upto the last index  
}

int main(){
    vector<int> arr = {3,4,5,6,11,13,14,15,56,70};
    cout << exponentialSearch(arr, 11);

    return 0;
}