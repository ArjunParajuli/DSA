#include<iostream>
#include<vector>
using namespace std;

/*
striver YT

Q) Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 

algo: (include exclude pattern like in coin change) For the recursive approach, there will be two cases: 
- Consider the ‘last’ element to be a part of the subset. Now the new required sum = required sum – value of ‘last’ element.
- Don’t include the ‘last’ element in the subset. Then the new required sum = old required sum.
In both cases, the index decreases by 1.

*/

// 1. recursion time: O(2^n)
bool solve(vector<int> &arr, int sum, int i) {
    if(sum == 0) return true; // sum found
    if(i == 0){ // reached first index so check if after including first elm, we get our ans or not
        if(arr[i] == sum)
            return true;
        else
            return false;
    }
    
    // once include current elm and once don't include current elm
    bool include = false;
    if(sum >= arr[i]) // before including check 
        include = solve(arr, sum-arr[i], i - 1);
    bool exclude = solve(arr, sum, i - 1);
    return (include || exclude);
}

bool isSubsetSum(vector<int>arr, int sum){
    int n = arr.size();
    int i = n-1;
    return solve(arr, sum, i);
}

// 2. Memoization topdown
bool solveMemo(vector<int> &arr, int sum, int i, vector<vector<int>> &dp) {
    if(sum == 0) return true;
    if(i == 0){
        if(arr[0] == sum)
            return true;
        else
            return false;
    }
    
    if(dp[i][sum] != -1)
        return dp[i][sum];
    
    // once include current elm and once don't include current elm
    bool include = false;
    if(sum >= arr[i])
        include = solveMemo(arr, sum-arr[i], i - 1, dp);
    bool exclude = solveMemo(arr, sum, i - 1, dp);
    return dp[i][sum] = (include || exclude);
}

bool isSubsetSumMemoization(vector<int>arr, int sum){
    int n = arr.size();
    // first check whether the answer(current sum value is already found before or not) is already calculated using the dp array
    vector<vector<int>> dp(n + 1, vector<int>(sum+1, -1));
    int i = n-1;
    return solveMemo(arr, sum, i, dp);
}


// 3. Tabulation: analyse base case & replace recursive logic with dp array
bool isSubsetSumTabulation(vector<int>arr, int sum){
    int n = arr.size();
    
    // i denotes no of rows, sum denotes no of cols
    vector<vector<bool>> dp(n + 1, vector<bool>(sum+1, 0));
    
    // for each row, mark 0th index as true (bcoz sum denotes col so we mark all col in 0th row as true)
    for(int i=0;i<n;i++){
        dp[i][0] = true;  // for all first cols, store 1 bcoz sum denotes col
    }
    
    // second base case: insert true when i=0 & arr[0]=sum (so take memoization base case & replace i with 0 & sum with arr[i] i.e. arr[0])
    dp[0][arr[0]] = true;   
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            bool include = false;
            // imp note: converting topdown to dp arr will give us: include = dp[j-arr[i]][i - 1]; 
           // & exclude = dp[j][i - 1]; but it'll be seg fault bcoz i denotes row & j is for col, so we interchange them, never forget to check it 
           // it's just the order in which we write them in parameters 
            if(j >= arr[i])
                include = dp[i - 1][j-arr[i]];  
            bool exclude = dp[i - 1][j];
            dp[i][j] = (include || exclude);
        }
    }
    return dp[n-1][sum];
}


// 4. space optimization possible, time: same as tabulation i.e. O(n*sum) (Note: whenever dp depends on i-1 or i+1 rows or cols then space optimization is possible)
// as we can see dp[i][j] depends on dp[i-1][j] & dp[i-1][j-arr[i]] i.e curr row depends on upper row. so two arrays can do the job.
// here, curr represents dp[i][] (curr row) & prev represents previous row dp[i-1][].
bool isSubsetSumSpaceOptimized(vector<int>arr, int sum){
    int n = arr.size();
    
    // size sum+1 bcoz in our matrix, sum represents the col & both prev & curr represents rows 
    vector<bool> prev(sum+1, 0); 
    vector<bool> curr(sum+1, 0);

    // first col ko true karo (no loop reqd bcoz we do it for two cells now)
        curr[0] = true;
        prev[0] = true;
    
    // second base case: dp[0][arr[0]] replaced by prev[arr[0]] bcoz dp[0] represents prev row
        prev[arr[0]] = true;   
    
    for(int i=1;i<n;i++){
        for(int j=1;j<=sum;j++){
            bool include = false;
            if(j >= arr[i])
                include = prev[j-arr[i]];   // dp[i-1][] replaced with prev[]
            bool exclude = prev[j];
            curr[j] = (include || exclude); // dp[i][] replaced with curr[]
        }
        // shift row arrays downwards
        prev = curr;
    }
    return prev[sum]; // dp[n-1][] with prev/curr
}
