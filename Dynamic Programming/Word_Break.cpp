#include<iostream>
#include<vector>
using namespace std;

/*
codehelp assignment DP

algo:
- create word after taking each letter from s & check if it is present in dictionary & if yes then call recursion for doing the same for the remaining string

*/


// 1. Recursion time: O(n^n) bcoz in worst case if eg: s="aaa" & dict mai 'a' hai toh harek char k liye n call jayegi  

    bool check(vector<string>& wordDict, string &word){
        for(string s : wordDict){
            if(s == word) return true;
        }
        return false;
    }

    bool solve(string &s, vector<string>& wordDict, int start){
        // base case
        if(start == s.size()){  // start reached the end index means all words found in dict
            return true;
        }

        bool ans = false;
        string word = "";
        for(int i=start;i<s.size();i++){
            word += s[i];
            if(check(wordDict, word)){
                ans = ans || solve(s, wordDict, i+1);  // continue making word 
            }
        }
        return ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int start = 0;
        return solve(s, wordDict, start);
    }



// Memoization time improved bcoz overlapping subproblems are calculated only once
bool solveMemo(string &s, vector<string>& wordDict, int start, vector<int> &dp){
        // base case
        if(start == s.size()){
            return true;
        }

        if(dp[start] != -1)
            return dp[start];

        bool ans = false;
        string word = "";
        for(int i=start;i<s.size();i++){
            word += s[i];
            // word found in dict so, we call rec for remaining string, but we didnt break the loop so, it'll also continue with the same word and do rec call if found. 
            if(check(wordDict, word)){
                // eg, s="aaaa", wd=["aaa", "aaaa"], when we found word=aaa in dictionary, we make rec call for rem string i.e "a" but then we cant find "a" in the dictionary in next rec call and we return false. 
                // So, we also need to continue searching without breaking the loop then word becomes "aaaa" and we find it in dict and we return true.
                // Basically, "aaa" banneke baad vi rec call karo and also usi word ko continue karke "aaaa" banake vi rec call karo so that we cover all cases.
                ans = ans || solveMemo(s, wordDict, i+1, dp); 
            }
        }
        return dp[start] = ans;
    }

    bool wordBreakMemoization(string s, vector<string>& wordDict) {
        vector<int> dp(s.size()+1, -1);
        int start = 0;
        return solveMemo(s, wordDict, start, dp);
    }



// 3. Tabulation

bool wordBreakTabulation(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, true); // set all to true for covering base case

        // opp of topdown
        for(int start=s.size()-1;start>=0;start--){
            bool ans = false;
            string word = "";
            for(int i=start;i<s.size();i++){
                word += s[i];
                if(check(wordDict, word)){
                    ans = ans || dp[i+1];
                }
            }
            dp[start] = ans;
        }

        return dp[0];
    }
 

 // can't be space optimized bcoz i is running loop from start to end index