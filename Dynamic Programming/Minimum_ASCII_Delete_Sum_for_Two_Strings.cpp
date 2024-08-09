#include<iostream>
#include<vector>
using namespace std;


/*
codehelp DP assignment

brute force: create all subsequences of both strings and for all matching subsequences, find ans & do same for all matching subsequences & return minm ans

Better:

Recursion Algo:
- check each char of both strings.
- If chars match continue with next chars of both strings, 
- else two case arises: once remove char from first string & once remove char from second string, then we take minm of then 

*/


// 1. Recursion

int solve(string &s1, string &s2, int i, int j) {
        int cost = 0;
        // base case (koi ek string khatam hogya then we have to remove all chars of other string)
        if(i == s1.size() || j == s2.size()){
            // cost of removing all chars of remaining string

            for(int idx=i;idx<s1.size();idx++) cost += s1[idx];  
            for(int idx=j;idx<s2.size();idx++) cost += s2[idx];

            return cost;
        }

        if(s1[i] == s2[j]){
            cost = solve(s1, s2, i+1, j+1);
        }else{
            int removeFromS1 = s1[i] + solve(s1, s2, i+1, j); // cost is curr char & solve ahead
            int removeFromS2 = s2[j] + solve(s1, s2, i, j+1);

            cost = min(removeFromS1, removeFromS2);
        }

        return cost;
    }

    int minimumDeleteSum(string s1, string s2) {
        return solve(s1, s2, 0, 0);
    }



// 2. Memoization

 int solveMemo(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
        int cost = 0;
        // base case (koi ek string khatam hogya then we have to remove all chars of other string)
        if(i == s1.size() || j == s2.size()){
            // cost of removing all chars of remaining string

            for(int idx=i;idx<s1.size();idx++) cost += s1[idx];  
            for(int idx=j;idx<s2.size();idx++) cost += s2[idx];

            return cost;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s1[i] == s2[j]){
            cost = solveMemo(s1, s2, i+1, j+1, dp);
        }else{
            int removeFromS1 = s1[i] + solveMemo(s1, s2, i+1, j, dp); // cost is curr char & solve ahead
            int removeFromS2 = s2[j] + solveMemo(s1, s2, i, j+1, dp);

            cost = min(removeFromS1, removeFromS2);
        }

        return dp[i][j] = cost;
    }

    int minimumDeleteSumMemoization(string s1, string s2) {
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        return solveMemo(s1, s2, 0, 0, dp);
    }



// 3. Tabulation
int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));

        // base case analysis
        // last col & row mai ek string empty hai so dusre ko vi empty karneki cost rakhna hai 

        // fill last col
        for(int i=s1.size()-1;i>=0;i--){ // s2.size()-1 se start karna hai bcoz dp[3][3] mai dono empty hai so 0 rahega
            dp[i][s2.size()] = s1[i] + dp[i+1][s2.size()]; 
        }

        // fill last row
        for(int i=s2.size()-1;i>=0;i--){ 
            dp[s1.size()][i] = s2[i] + dp[s1.size()][i+1]; 
        }

        for(int i=s1.size()-1;i>=0;i--){
            for(int j=s2.size()-1;j>=0;j--){
                int cost = 0;
                if(s1[i] == s2[j]){
                    cost = dp[i+1][j+1];
                }else{
                    int removeFromS1 = s1[i] + dp[i+1][j]; 
                    int removeFromS2 = s2[j] + dp[i][j+1];

                    cost = min(removeFromS1, removeFromS2);
                }
            dp[i][j] = cost;
            }
        }

        return dp[0][0];
    }