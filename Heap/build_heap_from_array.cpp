#include <iostream>
using namespace std;

/*
Q) convert array to heap:
->

brute force: take each elm in array and perform heapify

optimal: all leaf nodes are already in correct posn so just apply heapify on all other elms (leaf nodes in array: (n/2+1)th elm to nth elm) 
- so just apply heapify on (n/2)th elm to 1st elm  
time: O(n)

*/

// VVVIMP (heapify the given index i.e put the elm at given index in its correct pons)
void heapify(int *arr, int n, int index){
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
        index = largestChildIdx;

    // recursive call for further checking
        heapify(arr, n, index); 
    }
}

// convert array to heap
    void buildHeap(int * arr, int n){
        for(int i=n/2-1;i>=0; i--){  // upto 0 index only bcoz we're using 0 based indexing
            heapify(arr, n, i);
        }
    }

int main(){
    int arr[] = {3, 4, 5, 7, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    buildHeap(arr, n);
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";

    return 0;
}
