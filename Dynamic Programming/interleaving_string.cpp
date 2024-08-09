#include<bits/stdc++.h>
using namespace std;

/*
codhelp DP assignment

brute: create all possible substring of s1 & s2 and concatenate all possible combinations

better algo:
- pick all matching chars from s1 & if nonmatch found, pick matching from s2 & continue doing so till s3 is made

*/


// 1. Recursion
bool solve(string &s1, string &s2, string &s3, int i, int j, int k) {
    // base case: if s3 is made from chars from s1 & s2 then all i, j, k will be at last index
        if(i==s1.size() && j==s2.size() && k==s3.size())
            return true;

        // initialize flag to false in every call bcoz if char from both s1 & s2 don't match s3 then we must return false
        // if char from either s1 or s2 match then at the last recursive call, flag will be: flag = flag(false) || true  
        // & flag gets value true which is returned all the way to the base call 
        bool flag = false;  
        if(i<s1.size() && s1[i] == s3[k])
            flag = flag || solve(s1, s2, s3, i+1, j, k+1);
        if(j<s2.size() && s2[j] == s3[k])
            flag = flag || solve(s1, s2, s3, i, j+1, k+1);

        return flag;  
    }

    bool isInterleave(string s1, string s2, string s3) {
        return solve(s1, s2, s3, 0, 0, 0);
    }



// 2. Memoization(Topdown approach)

    bool solveMemoization(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<vector<int>>> &dp) {
        if(i==s1.size() && j==s2.size() && k==s3.size())
            return true;

        if(dp[i][j][k] != -1)
            return dp[i][j][k];

        bool flag = false;
        if(i<s1.size() && s1[i] == s3[k])
            flag = flag || solveMemoization(s1, s2, s3, i+1, j, k+1, dp);
        if(j<s2.size() && s2[j] == s3[k])
            flag = flag || solveMemoization(s1, s2, s3, i, j+1, k+1, dp);

        return dp[i][j][k] = flag;  
    }

    bool isInterleaveMemoization(string s1, string s2, string s3) {
        vector<vector<vector<int>>> dp(s1.size()+1, vector<vector<int>>(s2.size()+1, vector<int>(s3.size()+1, -1))); // size +1 bcoz we're storing the nth index elm also
        return solveMemoization(s1, s2, s3, 0, 0, 0, dp);
    }



// 3. Tabulation (bottomup)
    bool isInterleaveTabulation(string s1, string s2, string s3) {
        vector<vector<vector<int>>> dp(s1.size()+1, vector<vector<int>>(s2.size()+1, vector<int>(s3.size()+1, 0))); // initialize all as false

        // base condition 
        dp[s1.size()][s2.size()][s3.size()] = true;
        
        // opp to topdown
        for(int i=s1.size();i>=0;i--){
            for(int j=s2.size();j>=0;j--){
                for(int k=s3.size()-1;k>=0;k--){  // k start from s3.size()-1 bcoz base condition covers for dp[s1.size()][s2.size()][s3.size()]
                    bool flag = false;
                    if(i<s1.size() && s1[i] == s3[k])
                        flag = flag || dp[i+1][j][k+1];
                    if(j<s2.size() && s2[j] == s3[k])
                        flag = flag || dp[i][j+1][k+1];

                    dp[i][j][k] = flag;  
                }
            }
        }
        
        return dp[0][0][0];
    }



int main(){

    return 0;
}