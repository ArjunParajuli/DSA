#include <iostream>
#include <vector>
using namespace std;

/*
we have to apply merge sort using O(1) space
- our previous merge process was taking extra space
- new merge process:
- find gap i.e. gap=ceil(n/2) or gap=n/2 + n%2
- now i=0, j=i+gap and chech if(a[i]>a[j]) then swap them, again gap=ceil(gap/2) and do the same process until gap=1 and check only once for gap=1

- time: every time we are dividing gap by 2 so logn taken and O(n) time for mergesort func so O(nlogn) is time but space is O(1)
*/

 void mergeInplace(int s, int mid, int e, vector<int>& nums){
        int len = e-s+1;
        int gap = len/2 + len%2;
        while(gap>0){
            int i=s, j=i+gap;
        while(j<=e){
                if(nums[i] > nums[j])  
                    swap(nums[i], nums[j]);
                ++i, ++j;
            }
            gap = gap<=1 ? 0 : (gap/2)+(gap%2);
        }
    }

void mergesort(int s, int e, vector<int>& nums){
        // base case
        if(s>=e){
            return;
        }
        int mid = (s+e)>>1;
        mergesort(s, mid, nums);
        mergesort(mid+1, e, nums);
        mergeInplace(s, mid, e, nums);
    }

int main(){
    int A[] = {3,7,9,10,6,5,12,4,11,2}, n = 10;
    mergesort(A, 0, n-1);
    for(int i=0;i<n;i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}