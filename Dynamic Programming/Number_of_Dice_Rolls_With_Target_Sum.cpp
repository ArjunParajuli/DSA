#include<iostream>
#include<vector>
using namespace std;


/*
NOTE: pattern: ques says number of possible ways then we must use loop inside recursion to explore all possible ways.

codehelp dp class 7
*/

// 1. Recursion
long long int MOD = 1000000007;

    long long solve(int n, int k, int target, int diceUsed, int currsum){
        // base case
        // target found and all dices used
        if(currsum == target && diceUsed == n)
            return 1;

        // all dices must be found & target must also be found to include in ans
        if(currsum != target && diceUsed == n)
            return 0;
        if(currsum == target && diceUsed != n)
            return 0;


        long long ans = 0;
        for(long long face=1;face<=k;face++){
            // used current face of current dice so diceUsed increased by 1 & new currsum is currsum+face  
            if(currsum + face <= target) // don't let currsum exceed target
                ans = ans + solve(n, k, target, diceUsed+1, currsum+face);    
        }
        return (ans%MOD);
    }

    int numRollsToTarget(int n, int k, int target) {
        int diceUsed = 0, currsum = 0;
        return solve(n, k, target, diceUsed, currsum);
    }


// 2. Memoization ( no. of dice repr no. of row & target repr no. of col )
long long solveMemo(int &n, int &k, int &target, int diceUsed, int currsum, vector<vector<long long>> &dp){
        // base case
        // target found and all dices used
        if(currsum == target && diceUsed == n)
            return 1;

        if(currsum != target && diceUsed == n)
            return 0;
        if(currsum == target && diceUsed != n)
            return 0;

        if(dp[diceUsed][currsum] != -1)
            return dp[diceUsed][currsum];

        long long ans = 0;
        for(long long face=1;face<=k;face++){
            // used current face of current dice so diceUsed increased by 1 & new currsum is currsum+face
            if(currsum + face <= target)  
                ans = ans + solveMemo(n, k, target, diceUsed+1, currsum+face, dp);    
        }
        return dp[diceUsed][currsum] = (ans%MOD);
    }

    int numRollsToTarget(int n, int k, int target) {
        int diceUsed = 0, currsum = 0;
        vector<vector<long long>> dp(n+1, vector<long long>(target+1, -1));
        return solveMemo(n, k, target, diceUsed, currsum, dp);
    }


// 3. Tabulation: analyse base case & replace recursive logic with dp array
int numRollsToTarget(int n, int k, int target) {
        int diceUsed = 0, currsum = 0;
        vector<vector<long long>> dp(n+1, vector<long long>(target+1, 0)); // cover base case so 0

        dp[n][target] = 1;  // base case: diceUsed becomes n & currsum becomes target at that position insert 1

        // opposite of topdown 
        for(int i=n-1;i>=0;i--){  // i repr no. of dice
            for(int j=target-1;j>=0;j--){ // j repr target
            // replace recursive logic with dp array i.e.(diceUsed->i, currsum->j)
                long long ans = 0;
                for(long long face=1;face<=k;face++){
                    if(j + face <= target)  
                        ans = ans + dp[i+1][j+face];    
                }
                dp[i][j] = (ans%MOD);
            }
        }

        return dp[0][0];
    }



int main(){


    return  0;
}