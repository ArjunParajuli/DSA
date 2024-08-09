#include<bits/stdc++.h>
using namespace std;

/*
algo:
- concatenate given two arrays
- heapify the merged array
*/

// 0 indexed array taken so 
void heapify(vector<int> &arr, int n, int index){
    int leftChildIdx = 2*index+1;
    int rightChildIdx = 2*index+2;
    
    int largestChildIdx = index;

    // find and swap curr elm with its largest child and do the same further using recursion
    if(leftChildIdx < n && arr[leftChildIdx] > arr[largestChildIdx])
        largestChildIdx = leftChildIdx;
    
    if(rightChildIdx < n && arr[rightChildIdx] > arr[largestChildIdx])
        largestChildIdx = rightChildIdx;

    // if elm is not at correct posn
    if(largestChildIdx != index){
        swap(arr[largestChildIdx], arr[index]);
        heapify(arr, n, largestChildIdx);
    }
}
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> arr(a.begin(), a.end());
        arr.insert(arr.end(), b.begin(), b.end());
        int len = arr.size();
        
        for(int i=(len/2)-1;i>=0; i--){ // upto 1 index only bcoz we're using 1 based indexing
            heapify(arr, len, i);
        }
        return arr;
    }