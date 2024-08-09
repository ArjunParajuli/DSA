#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
algo:
- just reverse the given string and initialize it to s2
- now find lcs of original string and reversed string
*/

  int lcs(string s1, string s2){
        vector<int> curr(s1.size()+1, 0);
        vector<int> next(s1.size()+1, 0);
        
        for(int j=s2.size()-1;j>=0;j--){
            for(int i=s1.size()-1;i>=0;i--){
                if(s1[i] == s2[j]){
                    curr[i] = 1+next[i+1];
                }else{
                    int excs1 = 0+curr[i+1];
                    int excs2 = 0+next[i];

                    curr[i] = max(excs1, excs2);
                }
            }
            next = curr;
        }
        return curr[0];
    }

    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return lcs(s, s2);
    }


// Without usinf LCS
// same algo as LCS
/*

recursive solution algo:
1. if both strings chars match, ans += 2+recursivecall(next index of both str)
2. if chars don't match, two cases arise:
  i. once call recursion by incrementing char of 1st string
  ii. once call recursion by decrementing char of 2nd string
  - now take the maxm ans from these two cases

*/

// Memoization
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

