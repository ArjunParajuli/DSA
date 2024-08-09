#include<iostream>
#include<vector>
using namespace std;

/*
codehelp DP assignment

brute force: find all subsequences of s and match each of them with t

better:
recursion algo: 
- check if(curr char of both strings match), if yes call recusion for (i+1, j+1)
- call recursion for (i+1, j) i.e. exclude curr elm of s but not of t bcoz we're matching/searching for characters of t so we cannot skip t's characters

*/


// 1. Recursion
int solve(string &s, string &t, int i, int j){
        // base case
        if(j == t.size()){ // i kahi vi ho lekin j end index mai gaya means matching subsequence mila
            return 1;
        }else if(i == s.size() && j < t.size()){
            return 0;
        }

        int ans = 0;
        if(s[i] == t[j]){
            ans += solve(s, t, i+1, j+1); 
        }

        ans += solve(s, t, i+1, j);

        return ans;
    }

    int numDistinct(string s, string t) {
        int i=0, j=0;
        return solve(s, t, i, j);
    }



// 2. Memoization
int solveMemo(string &s, string &t, int i, int j, vector<vector<int>> &dp){
        // base case
        if(j == t.size()){
            return 1;
        }else if(i == s.size() && j < t.size()){
            return 0;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if(s[i] == t[j]){
            ans += solveMemo(s, t, i+1, j+1, dp); 
        }

        ans += solveMemo(s, t, i+1, j, dp);

        return dp[i][j] = ans;
    }

    int numDistinctMemoization(string s, string t) {
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, -1)); // size+1 taken bcoz i & j going upto index s.size() & t.size()
        int i=0, j=0;
        return solveMemo(s, t, i, j, dp);
    } 



// 3. Tabulation

  int numDistinctTabulation(string s, string t) {
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));

        // base case analysis

        // fill last col cells with 1
        for(int i=0;i<=s.size();i++)
            dp[i][t.size()] = 1;


        // opp to topdown
        for(int i=s.size()-1;i>=0;i--){ // start from -1 bcoz last index covered in base case
            for(int j=t.size()-1;j>=0;j--){
                long long ans = 0;
                if(s[i] == t[j]){
                    ans += dp[i+1][j+1]; 
                }

                ans += dp[i+1][j];

                dp[i][j] = ans;
            }
        }

        return dp[0][0]; // bcoz we're building ans from bottom to top
    }


// 4. space optimized possible bcoz dp[i][j] depends on dp[i+1][j+1] & dp[i+1][j]
// so depends on curr row and next row
    int numDistinctSpaceOptimized(string s, string t) {
        // t.size() bcoz next & curr go from last & secondlast rows
        vector<int> next(t.size()+1, 0);
        vector<int> curr(t.size()+1, 0);

        // base case analysis (last col cells have 1)
        curr[t.size()] = 1;
        next[t.size()] = 1;

        for(int i=s.size()-1;i>=0;i--){
            for(int j=t.size()-1;j>=0;j--){
                long long ans = 0;
                if(s[i] == t[j]){
                    ans += next[j+1]; // next row
                }

                ans += next[j];

                curr[j] = ans;
            }
            next = curr;
        }

        return curr[0]; // bcoz we're building ans from bottom to top
    }