#include<bits/stdc++.h>
using namespace std;

/*
optimal: two pointer approach 
- first store minm elm from start to curr index in left_min arr
- store maxm elm from end to curr index in right_max arr
- now apply two pointer for arr[i] <= arr[j], maxm = max(maxm, j-i)
*/

// time:O(n)

 int maxIndexDiff(int arr[], int n) 
    { 
        vector<int> left_min(n, 0);
        vector<int> right_max(n, 0);
        
        // create and store reqd arrays
        int minm = INT_MAX;
        for(int i=0;i<n;i++){
            minm = min(minm, arr[i]);
            left_min[i] = minm;
        }
        
        int maxm = INT_MIN;
        for(int i=n-1;i>=0;i--){
            maxm = max(maxm, arr[i]);
            right_max[i] = maxm;
        }
        
        // two pointer
        int i=0, j=0;  // i iterates over left_min and j iterates over right_max
        int ans = 0;
        while(i<n && j<n){
            if(left_min[i] <= right_max[j]){
                ans = max(ans, j-i); // store maxm betn curr j-i and maxm
                j++;                 // try to find maxm ans so increment j further
            }else{
                i++;    // arr[i] > arr[j] elm found so check for next ith elm now
            }
        }
        return ans;
    }


int main(){

    return 0;
}