#include<iostream>
#include<vector>
using namespace std;

/*
source: love babbar dp class 2
algo: explore all possibile ways

*/

// 1. using recursion
// time O(n^amount) bcoz each level of the recursion tree, we perform a loop over all n coins. 
// harr ek amount pe sarey coins use karke dekhna hai 
    int solveRecursive(vector<int>& coins, int amount){
        // base case [target amt reached]
        if(amount == 0)
            return 0;
        
        int minm = INT_MAX; // to track the minimum number of coins needed.
        // explore all possibile ans for each coin 
        for(int i=0;i<coins.size();i++){
            // for each decremented amount, loop thr all coins and use them if possible 
            // (using for loop bcoz eg: [1,2,5], amt=11 ke liye pehle 11 ke liye amount (11-1), (11-2), (11-5) hokar call jayega uske baad 10 k liye vi 3 call jayega & so on  )
            if(amount-coins[i] >= 0){  // for cases: coins=[3], amt=2 don't enter
                int recAns = solveRecursive(coins, amount-coins[i]);
                // valid ans
                if(recAns != INT_MAX){  
                    int ans = 1 + recAns; // 1 represents the current coin being used
                    minm = min(minm, ans); //  minimum of its current value and the new calculated value
                }
            }
        }
        return minm;
    }

    int coinChange(vector<int>& coins, int amount) {
       int ans = solveRecursive(coins, amount);
       if(ans == INT_MAX) // for cases: coins=[3], amt=2
          return -1; 
       else
          return ans;
    }


    // 2. using memoization [ '*' matlab yaha change kiya hai recursive solution ko ] topdown approach i.e. amount se 0 tak jarahe ho
int solveMemo(vector<int>& coins, int amount, vector<int>& dp){
        // base case [target amt reached]
        if(amount == 0)
            return 0;

        // *
        if(dp[amount] != -1)
            return dp[amount];
        
        int minm = INT_MAX; // to track the minimum number of coins needed.
        // explore all possibile ans for each coin
        for(int i=0;i<coins.size();i++){
            if(amount-coins[i] >= 0){  // for cases: coins=[2], amt=3
                int recAns = solveMemo(coins, amount-coins[i], dp);
                // valid ans
                if(recAns != INT_MAX){  
                    int ans = 1 + recAns; // 1 represents the current coin being used
                    minm = min(minm, ans); //  minimum of its current value and the new calculated value
                }
            }
        }
        // *
        dp[amount] = minm;
        return dp[amount];
    }

    int coinChangeMemoization(vector<int>& coins, int amount) {
       // *
       int n = amount+1; // bcoz we need index upto amount
       vector<int> dp(n, -1);
       int ans = solveMemo(coins, amount, dp);
       if(ans == INT_MAX)
          return -1; 
       else
          return ans;
    }


// 3. Tabulation bottom up time: O(amount*nums.size()) and space O(n)
// base case analyze & replace amount with val inside loop & recursive logic with dp array
int coinChangeTabulation(vector<int>& coins, int amount) {
        int n = amount+1; 
        vector<int> dp(n, -1);
        dp[0] = 0; // base case analysis
         
         // replace amount with val inside loop & recursive logic with dp array 
        for(int val=1;val<=amount;val++){ // start from 1 bcoz 0th index covered in base case
            int minm = INT_MAX; 
            for(int i=0;i<coins.size();i++){
                if(val-coins[i] >= 0){  
                    int recAns = dp[val-coins[i]];
                    if(recAns != INT_MAX){  
                        int ans = 1 + recAns; 
                        minm = min(minm, ans); 
                    }
                }
            }
            dp[val] = minm;
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }

// can't be space optimized bcoz dp[val] depends on dp[val-coins[i]] and coins[i] can be any elm hence no optimization possible
