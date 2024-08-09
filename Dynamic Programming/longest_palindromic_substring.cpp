#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// 1. Recursion,  time:O(n^3) space: O(n), recursion stack may go up to n levels deep.
 bool isPalin(string &s, int i, int j){
        if(i > j){
            return true;
        }
        
        if(s[i] == s[j])
            return isPalin(s, i+1, j-1);
        else
            return false;
        
    }

    string longestPalindrome(string s) {
        string ans = "";
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(isPalin(s, i, j)){
                    string curr = s.substr(i, j-i+1);
                    if(curr.size() > ans.size())
                        ans = curr;
                }
            }
        }
        return ans; 
    }


// 2. Memoization time:O(n^2) space: O(n^2)
bool isPalinMemo(string &s, int i, int j, vector<vector<int>> &dp){
        if(i > j){
            return true;
        }

        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == s[j])
            return dp[i][j] = isPalinMemo(s, i+1, j-1, dp);
        else
            return dp[i][j] = false;
        
    }

    string longestPalindromeMemoization(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        string ans = "";
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalinMemo(s, i, j, dp)){
                    string curr = s.substr(i, j-i+1);
                    if(curr.size() > ans.size())
                        ans = curr;
                }
            }
        }
        return ans; 
    }


// better approach - expand from every index and find max, time:O(n^2) space:O(n)
string expand(string &s, int st, int e){
        while(st>=0 && e<s.size() && s[st] == s[e]){
            st--;
            e++;
        }
        return s.substr(st+1, e-st-1); 
   }

    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 1) return s;
        string ans = "";

        for(int i=0;i<n-1;i++){
            // check for odd len & even len 
            string odd_expand = expand(s, i, i); 
            string even_expand = expand(s, i, i+1); 

            if(ans.size() < odd_expand.size())
                ans = odd_expand;

            if(ans.size() < even_expand.size())
                ans = even_expand;
        }

        return ans;
    }


int main(){

    return 0;
}