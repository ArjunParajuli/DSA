#include <iostream>
using namespace std;

/*
algo:  [heap sort using 0 based indexing]
- first build a maxheap with given input array [O(n) time]
- then replace first elm with last elm and decrement arr len
- heapify the first elm
- do these two steps for all elms in array to get sorted array
*/

/*
Heap sort works by first building a max-heap from the input array and then repeatedly removing the largest element (the root of the heap) and placing it at the end
 of the array. After placing the largest element at the end, we heapify the remaining elements to restore the heap property. This process is repeated until
  the array is fully sorted.
*/



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
    void buildHeap(int arr[], int n){
        for(int i=(n/2)-1;i>=0; i--){ // upto 0 index only bcoz we're using 0 based indexing
            heapify(arr, n, i);
        }
    }

    void heapSort(int *arr, int n){
    // convert array to maxheap
        buildHeap(arr, n);

    // since we're using 0 based indexing
    while(n != 0){
        swap(arr[0], arr[n-1]);  // swap first and last elms
        n--;                   // decrement array size
        heapify(arr, n , 0);   // heapify the first elm
    }
}

int main(){
    int arr[] = {5,1,1,2,0,0};
    heapSort(arr, 6);
    for(int itr:arr)
        cout << itr << " ";

    return 0;
}
