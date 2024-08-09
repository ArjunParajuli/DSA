#include <iostream>
using namespace std;

// For B(bubble) I(insertion) S(selection)
//Time complexity = O(n^2)

// for M(Merge) H(Heapsort) Q(Quicksort) - Time Complexity of O(nlog(n)) 

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
// similar to bubblesort but it selects min elm in each pass
// Selection Sort: O(n^2) in all cases.

void selectionsort(int A[], int n){             // selects smallest elem at 1st pos in 1st pass, 2nd smallst elm at 2nd pos in 2nd pass
    int i,j,min;                                  // selects kth smallest elm in kth pass at kth pos
    for(i=0;i<n-1;i++){
            min = i;
        for(j=i+1;j<n;j++){
            if(A[j] < A[min])
                min = j;
        }
        swap(A[i], A[min]);
    }
}

int main(){
    int A[] = {3,7,9,10,6,5,12,4,11,2}, n = 10;         // 2,3,4,5,6,7,9,10,11
    selectionsort(A, n);
    for(int i=0;i<n;i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}