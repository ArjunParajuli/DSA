#include <iostream>
using namespace std;

/*
brute force loop i to n, inner loop i+1 to n, check if a[i]>a[j] then count++. no need to check i<j bcoz its already satisfied
*/

/*
    use merge sort algo
   - divide, sort and then at merging phase, count the inversions.
   - at each mergeing phase, left and right array are sorted so first elm of right arr is smaller than all elms of left arr.
   - so inversion(basically how many swaps possible) can be calculate by formula mid-i+1 (i is first index of left sorted array)
*/

 long long int merge(long long arr[], vector<long long int> &temp, long long int start, long long int mid, long long int end){
        long long int c = 0;
        long long int i=start, j=mid+1, k=start;
        while(i<=mid && j<=end){
            if(arr[i] <= arr[j]){
                temp[k++] = arr[i++];
            }else{
                temp[k++] = arr[j++];
                c += mid-i+1;
            }
        }
        while(i<=mid){
            temp[k++] = arr[i++];
        }
        while(j<=end){
            temp[k++] = arr[j++];
        }
        for (i = start; i <= end; i++) {
            arr[i] = temp[i];
        }
        return c;
    }
    
    long long int mS(long long arr[], vector<long long int> &temp, long long start, long long end){
        if(start >= end)
            return 0;
            
        long long int c = 0;    
        long long int mid = start + (end-start)/2;
        c += mS(arr, temp, start, mid);
        c += mS(arr, temp, mid+1, end);
        c += merge(arr, temp, start, mid, end);
        return c;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        long long int c=0;
        vector<long long int> temp(N, 0);
        c = mS(arr, temp, 0, N-1);
        return c;
    }

int main(){
    int A[] = {3,7,9,10,6,5,12,4,11,2}, n = 10;
    

    return 0;
}