#include<iostream>
using namespace std;

bool isPossibleSolution(int A[], int N, int M, int mid)
    {
        int countStudent = 1;
        int pageSum = 0;
        for(int i = 0; i < N; i++)
        {
            if(pageSum + A[i] <= mid)  // allocating pages to student
            {
                pageSum += A[i];
            }
            else
            {   
                countStudent++;
                if(countStudent > M || A[i] > mid)  
                {   
                    return false;
                }
                pageSum = A[i];  // now allocating to new student, so pageSum=0 se start karo
           }
        }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        int start = 0, sum = 0;
        for(int i = 0; i < N; i++)
            sum += A[i];
        int end = sum;
        int mid = start + (end - start) / 2;
        int ans = -1;
        if(M > N)
            return ans;
        while(start <= end)
        {
            if(isPossibleSolution(A, N, M, mid))
            {
                ans = mid;          // if found then minimize the solution
                end = mid - 1;      // so searching in left part
            }
            else  // search in right part 
                start = mid + 1;
            mid = start + (end - start) / 2;
        }
        return ans;
    }

    int main(){
        int N = 4;
        int A[] = {12,34,67,90};
        int M = 2;

    cout << findPages(A, N, M);

        return 0;
    }