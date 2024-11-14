#include <iostream>
using namespace std;

// For B(bubble) I(insertion) S(selection)
//Time complexity = O(n^2)

// for M(Merge) H(Heapsort) Q(Quicksort) - Time Complexity of O(nlog(n)) 

// Insertion Sort: O(n^2) in the worst and average cases, O(n) in the best case.

    // i start from 1 bcoz first elm is taken as sorted arr divide the array in 2 parts, 
    // left part always sorted and right side array unsorted       
    // compare and insert right side arrays element in left sides sorted position 

void insertionsort(int A[], int n){  // Mainly compatible for linked lists than arrays
    for(int i=1;i<n;i++){
        int j = i-1;
        int temp = A[i];
        while(j >= 0 && A[j] > temp){       // 3,7,9,10,6,5,12,4,11,2
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = temp; // after shifting of elms is done, insert the temp elm in its right position
    }                            
}

int main(){
    int A[] = {3,7,9,10,6,5,12,4,11,2}, n = 10;
    insertionsort(A, n);
    for(int i=0;i<n;i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}