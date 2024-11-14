#include<iostream>
#include<vector>
using namespace std;

/*

Striver YT

greedy approach: take maxm for each row but wont work for all cases. so we must explore all possible ways. i,e, recursion

recursive approach:
- we need to keep track of current day and last task performed on previous day. i.e.(day, last); initially last=3, no task performed 

*/

// recursion
// TC: O(3^n) states at max and we're running for loop 3 iteration in each state. 
// SC: O(n) recursive stack space
 int solve(vector<vector<int>>& points, int n, int day, int last){
        if(day == n-1){
            int currMax = INT_MIN;
            // last row, so return maxm one
            for(int i=0;i<3;i++){
                if(last != i){
                    currMax = max(currMax, points[day][i]);
                }
            }
            return currMax;
        }
        
        // check all possible points & return maxm one
        int maxm = INT_MIN;
        for(int i=0;i<3;i++){
            if(last != i){
                // find point when we take each ith point
                int curr = points[day][i]+solve(points, n, day+1, i);
                maxm = max(maxm, curr); // return the maxm one
            }
        }
        return maxm;
    }
  
    int maximumPoints(vector<vector<int>>& points, int n) {
        return solve(points, n, 0, 3);
    }

    // memoization time: O(N*4*3) space: O(n*4) size of dp arr
    int solve(vector<vector<int>>& points, int n, int day, int last, vector<vector<int>>&dp){
        if(dp[day][last] != -1) return dp[day][last];
        if(day == n-1){
            int currMax = 0;
            for(int i=0;i<3;i++){
                if(last != i){
                    currMax = max(currMax, points[day][i]);
                }
            }
            return dp[day][last]=currMax;
        }
        
        
        int maxm = 0;
        for(int i=0;i<3;i++){
            if(last != i){
                int curr = points[day][i]+solve(points, n, day+1, i, dp);
                maxm = max(maxm, curr);
            }
        }
        return dp[day][last] = maxm;
    }
    
    // tabulation
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        // Initialize the DP table for the last day (day n-1)
        dp[n-1][0] = max(points[n-1][1], points[n-1][2]);
        dp[n-1][1] = max(points[n-1][0], points[n-1][2]);
        dp[n-1][2] = max(points[n-1][0], points[n-1][1]);
        dp[n-1][3] = max(points[n-1][0], max(points[n-1][1], points[n-1][2]));
        
        for(int day=n-2;day>=0;day--){
            for(int last=0;last<4;last++){
                dp[day][last] = 0;
                // Iterate through the tasks for the current day
                for (int task = 0; task <= 2; task++) {
                    if(last != task){
                        int curr = points[day][task]+dp[day+1][task];
                        dp[day][last] = max(dp[day][last], curr);
                    }
                }
            }
        }
        
        return dp[0][3]; 
    }