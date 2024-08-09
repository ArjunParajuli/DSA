#include<iostream>
#include<vector>
using namespace std;

// Note: if memoization code gives TLE it can be solved by passing by reference

// also known as maxm sum of non-adjacent elm
// make tree structure for dry run.

// 1. using recursion [gives TLE]
int robHelper(vector<int>& nums, int i){
        // base case
        if(i >= nums.size())
            return 0;
        
        // solve 1 case (ek baar current elm ko lelo and ek baar maat lo)
        int sum1 = nums[i]+robHelper(nums, i+2);
        int sum2 = 0+robHelper(nums, i+1);

        return max(sum1, sum2);
    }

    int rob(vector<int>& nums) {
        return robHelper(nums, 0);
    }



/* 2. using topdown [rec + memoization] here, index i goes from 0 to n, left to right

1. create dp array
2. if ans already present in dp arr, return it
3. else store ans in dp array and return it

*/

int robHelperMemo(vector<int>& nums, vector<int>& dp, int i){
        // base case
        if(i >= nums.size())
            return 0;
        
        if(dp[i] != -1)
            return dp[i];

        // solve 1 case (ek baar current elm ko lelo and ek baar maat lo)
        int include = nums[i]+robHelperMemo(nums, dp, i+2);
        int exclude = 0+robHelperMemo(nums, dp, i+1);

        dp[i] = max(include, exclude);
        return dp[i];
    }

    int robMemoization(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return robHelperMemo(nums, dp, 0);
    }

    /*
    3. bottomup [tabulation]  here, index i goes from n to 0 [it goes in opposite direction to that of topdown approach] right to left

    1. create dp array [starts from last index & each index stores maxm val upto that index]
    2. analyze base case and fill initial data [can get data accn to base case] 
    3. fill remaining array using recursive logic[replace recursive call with dp array]
    */

    int robUsingTabulation(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1); // harek index mai uske baad se last tak ka maxm value store hota hai
        // base case analysis: for last index maxm ans will be value at last index
        dp[n-1] = nums[n-1]; 
        for(int i=n-2;i>=0;i--){
            // temp stores val of dp[i+2]
            int temp = 0;
            // to avoid index out of bound
            if(i+2 < n)
                temp = dp[i+2];
            int include = nums[i] + temp;
            int exclude = 0+dp[i+1];

            dp[i] = max(include, exclude);
        }
        return dp[0];
    }

// 4. space optimized can be done using variables also. (tabulation method mai replace karo dp[i], dp[i+1], dp[i+2] ko curr, prev and next se)
/*
- dp[i+2]th posn ko next se denote karo
- dp[i+1]th posn ko prev se denote karo
- dp[i]th posn ko curr se denote karo
*/

// tabulation mai dp[i+1] and dp[i+2] mai depend karra hai so we can use variables instead of them
int robSpaceOptimized(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0]; // for case like [1]
        // base case analysis: for last index maxm ans willbe value at last index
        int prev = nums[n-1]; 
        int next=0, curr=0;
        for(int i=n-2;i>=0;i--){
            // temp stores val of dp[i+2]
            int temp = 0;
            // to avoid index out of bound
            if(i+2 < n)
                temp = next;
            int include = nums[i] + temp;
            int exclude = 0+prev;

            curr = max(include, exclude);

            // update variables
            next = prev;
            prev = curr;
        }
        return curr;
    }


int main(){
    vector<int> v = {2,7,9,3,1};
    cout << rob(v);

    return 0;
}

// GFG soln (My soln)

	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n+1, 0);
	    
	    dp[n-1] = arr[n-1];
	    
	    for(int i=n-2;i>=0;i--){
	        int inc = arr[i]+dp[i+2];
            int exc = 0+dp[i+1];
        
            dp[i] = max(inc, exc);
	    }
	    
	    return dp[0];
	}
    
	int findMaxSum(int *arr, int n) {
	    int n2=0;
	    int n1 = arr[n-1];
	    int curr = 0;
	    for(int i=n-2;i>=0;i--){
	        int inc = arr[i]+n2;
            int exc = 0+n1;
        
            curr = max(inc, exc);
            n2 = n1;
            n1=curr;
	    }
	    
	    return n1;
	}