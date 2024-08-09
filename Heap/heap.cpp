#include <iostream>
using namespace std;

/*
Heap:- Heap is a complete binary tree that satisfies the heap property: for min heap, parent node always less than child nodes. for max heap, parent node always greater than child nodes.

- Complete binary tree: A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. 

- Perfect Binary Tree: A binary tree of height h having the maximum number of nodes is a perfect binary tree. For a given height h, the maximum number of nodes is 2^(h+1)-1. There are no gaps.

# Implementation of Heap:
-> We use array with 1 based indexing for implementing heap, visualize using tree but implement using array.
    - first store all elms level by level in array. 
    - for parent to child, formula: for ith node, left child is at (2*i) and its right child is at (2*i+1) index
    - for child to parent, ith node's parent is at i/2 index
*/


/*
# Heapify: Heapify is the process of reshaping a binary tree into a heap data structure. i.e putting the inserted elm in its correct posn.

V.V.V.IMP: time to convert array into heap is O(n) (creation of heap takes O(n) time)

Benefits of heap: find max elm and min elm in O(1) time ( in array it takes o(n) time)

Time for insertion: O(logn)
Time for Deletion: O(logn)
creation of heap: O(n)  

Q) why heapifying an array takes O(n) time and not O(nlogn) time?
-> bcoz heapify starts from last non-leaf nodes and heapifying each index doesn't always take logn time so we cannot say exactly O(nlogn). 
At each index, it checks from itself to the downmost root node(for its subtree only and not above it). so we can't say it is checking O(logn) for each node.
*/

/*

Note: Heap data structure in stl is implemented in priority_queue<type> pq;
- pq.pop() will delete the top elm

- creating minheap: priority_queue<int, vector<int>, greater<int>> pq; (type of data, type of container you want to use, comparetor function)
smallest elm will stay at top in min heap
*/

class Heap{
    public:
    int * arr;
    int size;
    int capacity;

    Heap(int capacity){
        arr = new int[capacity];
        size = 0;
        this->capacity = capacity;
    }


/*
Insertion algorithm: time: O(logn) (heapify takes logn i.e height of tree)
- insert at last posn
- put it at its correct posn
*/

    // taking max heap here
    void insert(int val){
        if(size == capacity)
            cout << "Heap Overflow!" << endl;

        // insert at last posn in array
        size++;
        int index = size;
        arr[index] = val;

        // take it to its correct posn/heapify
        while(index > 1){ // since we're using 1 based indexing
        // if curr node elm is greater than its parent
            if(arr[index] > arr[index/2]){
                int parentIndex = index/2;
                swap(arr[index], arr[parentIndex]);
                index = parentIndex; // check further
            }else{ // elm in correct posn
                break;
            }
        }
    }


/*
algorithm for deleting:
- replace root node with the elm at last bcoz the last node doesn't have any child so no problem will be created further
- put the new root node in its correct posn(heapify)
*/

void deleteElm(){
    if(size == 0)
        cout << "Heap underflow!" << endl;

    // replace
    arr[1] = arr[size]; // 1 based indexing
    size--; 

    int index = 1;
    // put root in its correct posn
    while(index < size){ // no need for <= bcoz last index ko heapify karneki need nahi hai
        int leftChildIdx = 2*index;  // for 0 indexing, lc=2*i+1, rc=2*i+2
        int rightChildIdx = 2*index+1; 

        // swap root with the largest child 
        int largestChildIdx = index;
        if(leftChildIdx <= size && arr[leftChildIdx] > arr[largestChildIdx]){  // for 0 based, use < size
                largestChildIdx = leftChildIdx;
        }

        if(rightChildIdx <= size && arr[rightChildIdx] > arr[largestChildIdx]){
                largestChildIdx = rightChildIdx; 
        }
       
       if(largestChildIdx == index){
            break; // elm is in its right posn
       }else{ // Swap with its largest child
            swap(arr[largestChildIdx], arr[index]);
            index = largestChildIdx;
       }

    }
}
};

void print(int arr[], int size){
    // 1 based indexing followed here
    for(int i=1;i<=size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    }


// VVVIMP (heapify the given index i.e put the elm at given index in its correct posn). Each heapify operation takes O(log n) time
void heapify(int *arr, int n, int index){
    int leftChildIdx = 2*index;
    int rightChildIdx = 2*index+1;
    
    int largestChildIdx = index;

    // find and swap curr elm with its largest child and do the same further using recursion
    if(leftChildIdx <= n && arr[leftChildIdx] > arr[largestChildIdx])
        largestChildIdx = leftChildIdx;
    
    if(rightChildIdx <= n && arr[rightChildIdx] > arr[largestChildIdx])
        largestChildIdx = rightChildIdx;

    // if elm is not at correct posn
    if(largestChildIdx != index){
        swap(arr[largestChildIdx], arr[index]);
        index = largestChildIdx;

    // recursive call for further checking
        heapify(arr, n, index); 
    }
}

// convert array to heap  (for 0 based indexing, loop will be from (n/2)-1 to 0)
    void buildHeap(int arr[], int n){
        // indices n/2 + 1 through n are leaf nodes
        for(int i=n/2;i>0; i--){ // upto 1 index only bcoz we're using 1 based indexing
            heapify(arr, n, i);
        }
    }

    void heapSort(int arr[], int n){
    // since we're using 1 based indexing
    while(n != 1){  // when n = 1, it means array has only one elm so it is already at its correct posn 
        swap(arr[1], arr[n]);  // swap first and last elms
        n--;        // decrement array size
        heapify(arr, n , 1); // heapify the first elm
    }
}



int main(){
    Heap h(20);
    // h.insert(10);
    // h.insert(20);
    // h.insert(5);
    // h.insert(11);
    // h.insert(6);
    // h.print();
    // h.deleteElm();
    // h.print();

    int arr[] = {-1, 5, 10, 15, 20, 25, 12}; // 1 based indexing array
    buildHeap(arr, 6);
    heapSort(arr, 6); 
    print(arr, 6); 

    return 0;
}

