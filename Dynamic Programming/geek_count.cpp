#include<bits/stdc++.h>
using namespace std;

/*

algo:
- i will iterate in original string i.e. s
- j will iterate in "geek" i.e. t
- once include curr char if s[i]==t[i] then recursive call for (i+1, j+1)
- once exclude so, recursive call for (i+1, j)
- if j reaches end of t string, then one answer is found 

*/

// Memiozation
const int mod = 1e9 + 7;

int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp) {
    // base cases
    if (j == t.size()) return 1; // if we've matched the entire subsequence "geek"
    if (i == s.size()) return 0; // if we've reached the end of string s without matching "geek"

    // if this subproblem has already been solved, return the stored result
    if (dp[i][j] != -1) return dp[i][j];

    // recursive case
    int inc = 0;
    if (s[i] == t[j]) {
        inc = solve(s, t, i + 1, j + 1, dp); // include s[i] in the subsequence
    }
    int exc = solve(s, t, i + 1, j, dp); // exclude s[i] from the subsequence

    // store the result in dp array and return it
    return dp[i][j] = (inc + exc) % mod;
}

int geekCount(string s) {
    string t = "geek";
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(t.size(), -1));
    return solve(s, t, 0, 0, dp);
}

// Tabulation
int geekCount(string s) {
    string t = "geek";
    int n = s.size();
    vector<vector<int>> dp(n+1, vector<int>(t.size()+1, 0));
    for(int i=0;i<=n;i++){
        dp[i][t.size()] = 1;
    }
    
    for(int i=n-1;i>=0;i--){
        for(int j=t.size()-1;j>=0;j--){
            int inc = 0;
        if (s[i] == t[j]) 
            inc = dp[i + 1][j + 1]; // include s[i] in the subsequence
        
        int exc = dp[i + 1][j]; // exclude s[i] from the subsequence

        dp[i][j] = (inc + exc) % mod;
        }
    }
    
    return dp[0][0];
}