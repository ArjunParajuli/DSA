#include <bits/stdc++.h>
using namespace std;

/*
codehelp dp assignments ( see the video of dryrun )



*/

// 1. Recursion:- time: O(sqrt(n)^n), space O(n) 
int solve(int n){
        if(n == 0)
            return 0;

        int i=1;
        int ans = INT_MAX; // bcoz we need least
        int end = sqrt(n);  // run i upto end only bcoz eg: n=12 then end=3 so no point of checking for 4 bcoz 4*4= 16 > 12 
        while(i <= end){
            int perfectSqr = i*i;
            int currans = 1 + solve(n-perfectSqr);  // firstly sarey i=1 k liye karega, uske baad incremented i k liye chalega
            ans = min(ans, currans);  // min of currans and previously stored ans
            i++;
        }
         return ans;
    }

    int numSquares(int n){
        return solve(n);
    }


// 2. Memoization
int solve(int n, vector<int> &dp){
        if(n == 0)
            return 0;

        if(dp[n] != -1)
            return dp[n];

        int i=1;
        int ans = INT_MAX; // bcoz we need least
        int end = sqrt(n);  // run i upto end only bcoz eg: n=12 then end=3 so no point of checking for 4 bcoz 4*4= 16 > 12 
        while(i <= end){
            int perfectSqr = i*i;
            int currans = 1 + solve(n-perfectSqr, dp);
            ans = min(ans, currans);
            i++;
        }
         return dp[n] = ans;
    }

    int numSquares(int n){
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }


// 3. Tabulation time: O(n * sqrt(n)) same for memoization
int numSquares(int n){
        vector<int> dp(n+1, -1);

        dp[0] = 0;  // base case analysis
 
        // going opposite of topdown approach
        // replace n with idx for recursive logic bcoz here idx represents current n
        for(int idx=1;idx<=n;idx++){  
            int i=1;
            int ans = INT_MAX; 
            int end = sqrt(n);  
            while(i <= end){
                int perfectSqr = i*i;
                int currans = INT_MAX;
                if(idx-perfectSqr >= 0)  // avoid index out of bound
                    currans = 1 + dp[idx-perfectSqr];
                ans = min(ans, currans);
                i++;
            }
            dp[idx] = ans;
        }
        return dp[n];  // jo topdown mai recursion mai pass kiya hai wahi index return karo
    }