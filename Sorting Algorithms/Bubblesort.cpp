#include <iostream>
using namespace std;

// For B(bubble) I(insertion) S(selection)
//Time complexity = O(n^2)

// for M(Merge) H(Heapsort) Q(Quicksort) - Time Complexity of O(nlog(n)) 

// Bubble Sort: O(n^2) in the worst and average cases, O(n) in the best case (if the list is already sorted).
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

// repeatedly swap the adjacent elements in the array to get the max elm at its right posn 

void bubblesort(int A[], int n){      // Gives k largest elements in every pass eg: largest elm at end in first successful comparision
    for(int i=0;i<n-1;i++){           // Gives 2nd largest elem at n-1 index in second pass .....      
        int flag = 0;                   
        for(int j=0;j<n-i-1;j++){
            if(A[j] > A[j+1]){
                swap(A[j], A[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)
            return;
    }
}

int main(){
    int A[] = {3,7,9,10,6,5,12,4,11,2}, n = 10;
    bubblesort(A, n);
    for(int i=0;i<n;i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}