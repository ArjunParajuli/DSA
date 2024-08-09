#include <bits/stdc++.h>
using namespace std;

/*
striver YT

algo: we can only take 1 or 2 two jumps
- we start from end and at each step we call recursion for 1 step and for 2 step then return minimum of them 

*/

//1. recursion [start from end position]

int solve(int n, vector<int> &heights, int i) {
    if (i == 0) { // reach 0th index then return 0
        return 0;
    }

    // recursion for taking one step
   int oneStep = solve(n, heights, i - 1) + abs(heights[i] - heights[i - 1]);
   int twoStep = INT_MAX;
   // recursion for taking two steps
   if(i > 1)
      twoStep = solve(n, heights, i - 2) + abs(heights[i] - heights[i - 2]);

    return min(oneStep, twoStep); // we need the minm energy
}

int frogJump(int n, vector<int> &heights) {
    int i = n-1;
    return solve(n, heights, i);
}


// 2. memoization [ as we can see overlapping subproblems i.e. same recursive calls multiple times] top down approach
// time: O(n), space: O(n)

// ith posn stores the min
int solveMemo(int n, vector<int> &heights, int i, vector<int> &dp) {
    if (i == 0) {
        return 0;
    }

    if(dp[i] != -1){
        return dp[i];
    }

   int oneStep = solveMemo(n, heights, i - 1, dp) + abs(heights[i] - heights[i - 1]);
   int twoStep = INT_MAX;
   if(i > 1)
      twoStep = solveMemo(n, heights, i - 2, dp) + abs(heights[i] - heights[i - 2]);

    dp[i] = min(oneStep, twoStep);
    return dp[i];
}

int frogJumpMemoization(int n, vector<int> &heights) {
    vector<int> dp(n+1, -1);
    return solveMemo(n, heights, n-1, dp);
}

// 3. Tabulation [bottom up approach, so we start from 0 to n]
/*
- analyze base case and insert in dp array
- convert recursive reation with dp
*/
int frogJumpTabulation(int n, vector<int> &heights) {
    vector<int> dp(n+1, -1);
    // initial base case
    dp[0] = 0;
    for(int i=1;i<n;i++){
           int oneStep = dp[ i - 1] + abs(heights[i] - heights[i - 1]); // convert recursive reation with dp 
            int twoStep = INT_MAX;
            if(i > 1)
                 twoStep = dp[ i - 2] + abs(heights[i] - heights[i - 2]); // convert recursive reation with dp 
            dp[i] = min(oneStep, twoStep);
    }
    return dp[n-1];
}

// 4. Space Optimization(optimized from tabulation) [ space optimization is always possible if there's index-1 or index-2 ]
// prev2 will work as dp[i-2] & prev will work as dp[i-1] & curr will work as dp[i]
int frogJumpSpaceOptimized(int n, vector<int> &heights) {
    int prev = 0, prev2 = 0, curr = 0;
    for(int i=1;i<n;i++){
          int oneStep = prev + abs(heights[i] - heights[i - 1]);
            int twoStep = INT_MAX;
            if(i > 1)
                 twoStep = prev2 + abs(heights[i] - heights[i - 2]);
           curr = min(oneStep, twoStep);
           // update
           prev2 = prev;
           prev = curr;
    }
    return curr;
}

 int main(){
    vector<int> arr = {7, 4, 4, 2, 6, 6, 3, 4}; // ans = 7
    cout << frogJumpSpaceOptimized(8, arr);

    return 0;
 }

 /*
 My approach:
start from index 0
 */

 // Memoization
 int solve(vector<int>& height, int n, int i, vector<int> &dp){
        if(i>=(n-1)) // last index so return 0 as we cant go any further from here
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int s1 = abs(height[i]-height[i+1])+solve(height, n, i+1, dp);
        int s2 = INT_MAX;
        if(i+2 < n)
            s2 = abs(height[i]-height[i+2])+solve(height, n, i+2, dp);
        
        return dp[i]=min(s1, s2);
    }
  
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n+1, -1);
        return solve(height, n, 0, dp);
    }

    // Tabulation(Bottom up)
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n+1, -1);
        dp[n-1] = 0; // base case analysis i.e. last index se last index pohochneki min cost is 0
        
        for(int i=n-2;i>=0;i--){
            int s1 = abs(height[i]-height[i+1])+dp[i+1];
            int s2 = INT_MAX;
            if(i+2 < n)
                s2 = abs(height[i]-height[i+2])+dp[i+2];
        
            dp[i]=min(s1, s2);
        }
        
        return dp[0];
    }

// optimized
// next2 will work as dp[i-2] & next1 will work as dp[i-1] & curr will work as dp[i]
int minimumEnergy(vector<int>& height, int n) {
        int next1=0, next2=0, curr=0; 
        
        for(int i=n-2;i>=0;i--){
            int s1 = abs(height[i]-height[i+1])+next1;
            int s2 = INT_MAX;
            if(i+2 < n)
                s2 = abs(height[i]-height[i+2])+next2;
        
            curr=min(s1, s2);
            
            next2 = next1;
            next1 = curr;
        }
        
        return curr;
    }
