#include<iostream>
#include<vector>
using namespace std;

/*
algo: very same as subset sum, here find total sum of elms and if even then call the subsetsum function with sum as half the totalSum of array. 

*/

// 1. Recursion
bool solve(vector<int> &arr, int sum, int i, int currsum){
         if(i >= arr.size()) // we're out of index 
            return false;  
         if(currsum == sum) // sum found
            return true;
         if(currsum > sum)  // sum exceeded
            return false;

        
        // if curr index elm is greater than sum then ignore this index
        if(arr[i] > sum){
            return solve(arr, sum, i+1, currsum);
        }
        
        // once include current elm and once don't include current elm
        bool include = solve(arr, sum, i+1, currsum+arr[i]);
        bool exclude = solve(arr, sum, i+1, currsum);
        return include || exclude;
        
    }

    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        int i=0, currsum=0;
        return solve(arr, sum, i, currsum);
    }

    bool canPartition(vector<int>& nums) {
        // find total sum
        int totalSum=0, n=nums.size();
        for(int num : nums){
            totalSum += num;
        }
        // if totalsum is even then we call subsetSum function with totalsum/2
        if(totalSum % 2 == 0)
            return isSubsetSum(nums, totalSum/2);

        return false;
    }



// 2. Memoization
bool solveMemo(vector<int> &arr, int i, int sum, vector<vector<int>> &dp){
        if(sum == 0)
            return true;
        if(i >= arr.size()) // we're out of index and sum is still not 0 so false
            return false;  
     
     if(dp[i][sum] != -1)
        return dp[i][sum];
        
        // if curr index elm is greater than sum then ignore this index
        if(arr[i] > sum){
            return solveMemo(arr, i+1, sum, dp);
        }
        
        // once include current elm and once don't include current elm
        bool include = solveMemo(arr, i+1, sum-arr[i], dp);
        bool exclude = solveMemo(arr, i+1, sum, dp);
        return dp[i][sum] = include || exclude;
        
    }

    bool isSubsetSumMemoization(vector<int>arr, int sum){
        int n=arr.size();
        // bcoz we're going from n to 0
        vector<vector<int>> dp(n + 1, vector<int>(sum+1, -1));
        return solveMemo(arr, 0, sum, dp);
    }

    bool canPartitionMemoization(vector<int>& nums) {
        // find total sum
        int totalSum=0, n=nums.size();
        for(int num : nums){
            totalSum += num;
        }
        // if totalsum is even then we call subsetSum function with totalsum/2
        if(totalSum % 2 == 0)
            return isSubsetSumMemoization(nums, totalSum/2);

        return false;
    }


// 3. Tabulation: analyse base case & replace recursive logic with dp array
bool isSubsetSumTabulation(vector<int>arr, int sum){
        int n=arr.size();
        if(n == 1) return false;
        // i deontes row & sum denotes col
        vector<vector<int>> dp(n + 1, vector<int>(sum+1, 0)); // for base case

        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }
        
        // opp direction from top down
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=sum;j++){ // j is going from 0 to sum i.e. doing work of sum here
            // once include current elm and once don't include current elm
            
            // Check if the current element can be included 
            bool include = (j - arr[i] >= 0) ? dp[i+1][j-arr[i]] : false;
            bool exclude = dp[i+1][j];
            dp[i][j] = include || exclude;
            }
        }
        return dp[0][sum];
    }
