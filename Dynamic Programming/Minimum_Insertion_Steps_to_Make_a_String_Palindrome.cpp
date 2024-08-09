#include<bits/stdc++.h>
using namespace std;

/*
codehelp assignemnt DP

algo:
- we have to find minimum number of insertions to make the string palindrome, so we'll find the longest subsequence which is palindromic &
  return (size of string - size of longest palindromic subsequence) bcoz we have to insert this number of chars to make our string palindromic     

*/

int solve(string &s, int i, int j, vector<vector<int>> &dp){
        if(i > j)
            return 0;
        if(i == j)
            return 1;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if(s[i] == s[j])
            ans += 2 + solve(s, i+1, j-1, dp);
        else{
            int op1 = solve(s, i+1, j, dp);
            int op2 = solve(s, i, j-1, dp);

            ans += max(op1, op2);
        }

        return dp[i][j] = ans;
    }

    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, -1));
        return solve(s, 0, s.size()-1, dp);
    }

    int minInsertions(string s) {
        int n = s.size();
        int lps = longestPalindromeSubseq(s);
        return n-lps;
    }

int main(){

    return 0;
}