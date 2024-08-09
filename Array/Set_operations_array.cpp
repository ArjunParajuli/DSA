#include <iostream>
using namespace std;

void display(int A[], int n){
    for(int i=0;i<n;i++)
        cout << A[i] << " ";
    cout << endl;
}

//merging two sorted arrays

void mergeArrays(int A[], int B[], int lengthA, int lengthB){
    int C[lengthA+lengthB];
    int i,j,k;
    i=j=k=0;
    while(i < lengthA && j < lengthB){
        if(A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }
    while(i < lengthA){C[k++] = A[i++];}
    while(j < lengthB){C[k++] = B[j++];}
    display(C, k);
}

void unionArray(int A[], int B[], int lengthA, int lengthB){
    int C[lengthA+lengthB];
    int i,j,k;
    i=j=k=0;
    while(i < lengthA && j < lengthB){
        if(A[i] == B[j]){
            C[k++] = A[i++];
            j++;
        }else if(A[i] < B[j])
            C[k++] = A[i++];
        else 
            C[k++] = B[j++];
    }
    while(i < lengthA){C[k++] = A[i++];}
    while(j < lengthB){C[k++] = B[j++];}
    display(C, k);
}

void intersectionArray(int A[], int B[], int lengthA, int lengthB){
    int C[lengthA+lengthB];
    int i,j,k;
    i=j=k=0;
   while(i < lengthA && j < lengthB){
        if(A[i] == B[j]){
            C[k++] = A[i++];
            j++;
        }else if(A[i] < B[j])
            i++;
        else 
            j++;
    }
    display(C, k);
}

// (A-B) operation

void differenceArray(int A[], int B[], int lengthA, int lengthB){
    int C[lengthA+lengthB]; 
    int i,j,k;
    i=j=k=0;
   while(i < lengthA && j < lengthB){
        if(A[i] == B[j]){
           i++,j++;
        }else if(A[i] < B[j])
           C[k++]=A[i++];
        else 
            j++;
    }
    while(i < lengthA){C[k++]=A[i++];}
    display(C, k);
}


int main(){
    int A[] = {1,2,4,6};
    int B[] = {1,2,5,6,9,11};

    mergeArrays(A, B, 4, 6);
    unionArray(A, B, 4, 6);
    intersectionArray(A, B, 4, 6);
    differenceArray(A, B, 4, 6);

    return 0;
}