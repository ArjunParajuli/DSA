#include<iostream>
#include<vector>
using namespace std;

/*
source: striver yt
# Note: if ques says find number of ways for something or find the best way[min or max] among all possible ways, then that's when we must apply recursion.

#this problem is just same as fibonacci
*/


int solve(vector<int> &dp, int n){
        if(n == 1 || n == 2) return n;

        if(dp[n] != -1) return dp[n];
        
        dp[n] = solve(dp, n-1)+solve(dp, n-2);
        return dp[n];
    }

    int climbStairsMemo(int n) {
        vector<int> dp(n+1, -1);
        return solve(dp, n);
    }

     int climbStairsTabulation(int n) {
        vector<int> dp(n+1, -1);
        dp[1] = 1;
        if(n == 1) return n;
        dp[2] = 2;
        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }

     int climbStairsSpaceOptimized(int n) {
        int first = 1;
        if(n == 1) return n;
        int sec = 2;
        int curr = n;
        for(int i=3;i<=n;i++){
            curr = first+sec;
            first = sec;
            sec = curr;
        }
        return curr;
    }

