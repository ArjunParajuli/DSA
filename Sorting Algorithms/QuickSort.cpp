//YT-code help
#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*

algo:
- In each partition algo, find correct posn of pivot elm and place all elms smaller than pivot to left of pivot and all elms greater than pivot to its right.  
- call rec for left part of pivot elm
- same for right part

*/

/*
Why is the worst-case time complexity of Quick Sort O(n^2)? How can this be mitigated?

Answer: The worst-case occurs when the pivot chosen repeatedly divides the array into a highly unbalanced partition, such as when the pivot is the smallest or largest element. This results in n recursive calls, each operating on an array of size decreasing by one, leading to O(n^2) complexity. This can be mitigated by:
Using Randomized Quick Sort: Randomly selecting the pivot element.
Using the "Median-of-Three" method: Picking the pivot as the median of the first, middle, and last elements.
*/

/*

TC: Best, Avg case is O(NlogN), Worst case is O(N^2)
SC: O(N) recursive stack space


Advantages of Quick Sort:
It is a divide-and-conquer algorithm that makes it easier to solve problems.
It is efficient on large data sets.
It has a low overhead, as it only requires a small amount of memory to function.

Disadvantages of Quick Sort:
It has a worst-case time complexity of O(N^2), which occurs when the pivot is chosen poorly.
It is not a good choice for small data sets.
It is not a stable sort, meaning that if two elements have the same key, their relative order will not be preserved in the sorted output in case of quick sort, 
because here we are swapping elements according to the pivot’s position (without considering their original positions).

Why Quick Sort preferred for Arrays and Merge Sort for Linked Lists?
->    Quick Sort is generally preferred for arrays because it require random access to elements which is easily possible in arrays and can be easily implemented in-place, which means 
it doesn’t require any extra memory space beyond the original array.
    Merge Sort is generally preferred for linked lists because it doesn’t require random access to elements, which is not efficient for linked lists since we need to traverse the list linearly.
In Merge Sort, we divide the linked list into two halves recursively until we have individual elements. Then, we merge the individual elements by comparing and linking them in a sorted order. 

Also, Merge Sort is a stable sort, which means it maintains the relative order of equal elements in the sorted list. This is important for linked lists,
 where the original order of equal elements may be significant.
*/


int partition(vector<int> &arr, int s, int e){
    int pivot = arr[s];
    
    // count num of elms less than pivot
    int cnt=0;
    for(int i=s+1;i<=e;i++){ // first elm taken as pivot so start from s+1
        if(arr[i] <= pivot) cnt++;
    }

    // place pivot in its correct posn
    int pivotIndex = s+cnt;
    swap(arr[s], arr[pivotIndex]);


    // place all elms small than pivot in its left and greater in its right part
    int i = s, j = e;
    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= pivot) i++;
        while(arr[j] > pivot) j--; 

        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSortFunc(vector<int> &arr, int s, int e){
// base case (single or no elm in arr)
    if (s >= e) {
        return;
    }

    int pivotIdx = partition(arr, s, e);
    quickSortFunc(arr, s, pivotIdx - 1); // rec on left part
    quickSortFunc(arr, pivotIdx + 1, e); // rec on right part
}

int main(){
    vector<int> A = {7,3,9,10,6,5,12,4,11,2};
    int n = 10;
    quickSortFunc(A, 0, n-1);
    for(int i=0;i<n;i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}