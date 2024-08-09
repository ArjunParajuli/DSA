// YT - Abdul Bari
#include <iostream>
using namespace std;

/* 

 Merge sort is a divide-and-conquer algorithm that recursively divides the array into halves, sorts each half, (divide, sort, merge)
 and then merges the sorted halves. During the merge phase, additional space is required to temporarily store the merged elements.

 In the worst case, merge sort requires additional space proportional to the size of the input array. 
 This is because during the merging process, a temporary array of the same size as the input array is often used. 
 The space needed for this temporary array contributes to the O(n) space complexity.
 The space complexity of merge sort is O(n), where n is the number of elements in the array being sorted.

 algo:
 break array into left and right half
 recursive call for left and right part
 merge left and right array 


Best Case: O(n log n), When the array is already sorted or nearly sorted.
Average Case: O(n log n), When the array is randomly ordered.
Worst Case: O(n log n), When the array is sorted in reverse order.

*/

void merge(int A[], int l, int mid, int h){
    int i,j,k;
    int * B = new int[h+1];     // same as: int B[h+1]; but its not a good practice so. 
    i=l;
    j=mid+1; 
    k=l;  
    while(i <= mid && j <= h){
        if(A[i] < A[j])
            B[k++] = A[i++];     // k and i gets incremented after values assigned
        else    
            B[k++] = A[j++];
    }
    while(i <= mid)
        B[k++] = A[i++];
    while(j <= h)
        B[k++] = A[j++];
    
    for(int i=l;i<=h;i++)
        A[i] = B[i];

    // good practise to release heap memory after use
    delete(B);
}



void mergesort(int A[], int low, int high){
    if(low > high)
        return;

    int mid = (low + high) / 2;
    mergesort(A, low, mid);
    mergesort(A, mid+1, high);
    merge(A, low, mid, high);
}

int main(){
    int A[] = {3,7,9,10,6,5,12,4,11,2}, n = 10;
    mergesort(A, 0, n-1);
    for(int i=0;i<n;i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}