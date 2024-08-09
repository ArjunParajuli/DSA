#include <bits/stdc++.h>
using namespace std;

/*
// striver YT
- very similar to frog jump but here we can take upto k steps jump, so instead taking 1 step and 2 step and getting the min of them, we check 
  minm betn i+1 to i+k index 
  if k=3 then we check minmm betn k-1, k-2, k-3 index
*/


// 1. recursion [apply loop to check minm betn all upto k steps]
int solve(int n, int k, vector<int> &height, int i){
    if(i==0)
        return 0;

    int minCost = INT_MAX;
    for(int idx=1;idx<=k;idx++){
       if(i-idx >= 0){
            int currCost = solve(n, k, height, i-idx) + abs(height[i]-height[i-idx]);
            minCost = min(minCost, currCost);
       }
    }
    return minCost;
}

int minimizeCost(int n, int k, vector<int> &height){
    return solve(n, k, height, n-1);
}

// 2. memoization time: O(n * k) bcoz everytime k jumps are checked, space: O(n)+O(n)
int solveMemo(int n, int k, vector<int> &height, int i, vector<int> &dp){
    if(i==0)
        return 0;

    if(dp[i] != -1)
        return dp[i];

    int minCost = INT_MAX;
    for(int idx=1;idx<=k;idx++){
       if(i-idx >= 0){
            int currCost = solveMemo(n, k, height, i-idx, dp) + abs(height[i]-height[i-idx]);
            minCost = min(minCost, currCost);
       }
    }
    return dp[i] = minCost;
}

int minimizeCostMemoization(int n, int k, vector<int> &height){
    vector<int> dp(n+1, -1);
    return solveMemo(n, k, height, n-1, dp);
}

// 3. tabulation [removes recursive space]
int minimizeCostTabulation(int n, int k, vector<int> &height){
    vector<int> dp(n+1, -1);
    dp[0] = 0;

     for(int i=1;i<n;i++){
         int minCost = INT_MAX;
        for(int idx=1;idx<=k;idx++){
            if (i - idx >= 0) {
              int currCost = dp[i - idx] + abs(height[i] - height[i - idx]);
              minCost = min(minCost, currCost);
            }
        }
        dp[i] = minCost;
     }
     return dp[n-1];
}

// 4. space optimized [we require k-1, k-2, k-3 values when k=3]
// here we reqire o(k) space for list of k elms so space optimization not possible bcoz if worst case(k=n) then space will be same as tabulation. 


/*

My approach
Another approach start from first index

*/

int solve(vector<int>& height, int n, int k, int i){
        if(i >= n-1) return 0;
        
        int minCost = INT_MAX;
        for(int j=i+1;j<=k+i;j++){
            if(j < n){
                int currCost = abs(height[i]-height[j])+solve(height,n,k,j);
                minCost = min(minCost, currCost); 
                }
            }
        return minCost;
    }
  
  // memoization
    int minimizeCost(vector<int>& height, int n, int k) {
        return solve(height, n, k, 0);
    }

       int solve(vector<int>& height, int n, int k, int i, vector<int> &dp){
        if(i >= n-1) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        int minCost = INT_MAX;
        for(int j=i+1;j<=k+i;j++){
            if(j < n){
                int currCost = abs(height[i]-height[j])+solve(height,n,k,j,dp);
                minCost = min(minCost, currCost); 
                }
            }
        return dp[i]=minCost;
    }
  
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> dp(n+1, -1);
        return solve(height, n, k, 0, dp);
    }


    // bottom up
      int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> dp(n+1, 0);
        dp[n-1] = 0;
        
        for(int i=n-2;i>=0;i--){
            int minCost = INT_MAX;
            for(int j=i+1;j<=k+i;j++){
            if(j < n){
                int currCost = abs(height[i]-height[j])+dp[j];
                minCost = min(minCost, currCost); 
                }
            }
            dp[i]=minCost;
        }
        
        return dp[0];
    }