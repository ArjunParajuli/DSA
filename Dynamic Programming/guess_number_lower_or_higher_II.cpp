#include<iostream>
#include<vector>
using namespace std;

/*

codehelp dp class 6  (each class is based on similar pattern questions, so for revision follow each class wise questions)


Pattern: Merge Interval

algo: hamey guarantee karna hai ki ans guess kar payenge but with minimum penalty paid.
- suppose n=5, then we can initially guess 1, 2, 3, 4 or 5
- ab agar 3 guess kiya toh ya toh ans 3 se lower hoga ya toh higher hoga, and same for all other numbers
- so agar initially 3 guess kiya toh iske sarey agle cases nikalo and return the maxm penalty wala case bcoz agar maxm lenge toh guarantee hai ki ans milega.
- now for all other 4 guesses, do the same & find their individual maxm penalty.
- now return the minm of all the guesses(maxm penalties) bcoz sarey cases answer gurantee karte hai & hamey minm wala chahiye.   

*/

// 1. recursion
int solve(int start, int end){
        // base case
        if(start > end){
            // range se bahar, so return 0
            return 0;
        }
        if(start == end){
            //eg: range mai sirf 1 hai toh of course 1 hi select karoge with no penalty
            return 0;
        }

        int ans = INT_MAX; // we need min ans
        // now find answer for all numbers from start to end
        for(int i=start;i<=end;i++){
            // each i ke liye uska maxm possible penalty lo and overall sarey i me se minm return karo
            // +i kyuki we're finding maxm penalty( 'i' is the penalty for each case )
            ans = min(ans, i + max(solve(start, i-1), solve(i+1, end))); // maxm betn left range and right range of the current case
        }
        return ans;
    }

    int getMoneyAmount(int n) {
        int start = 1, end = n;
        return solve(start, end);
    }

// 2. Memoization [ if ans exists return else find ans & store in dp array and return ]
int solveMemo(int start, int end, vector<vector<int>> &dp){
        // base case
        if(start >= end){
            // range se bahar, so return 0
            // or eg: range mai sirf 1 hai toh of course 1 hi select karoge with no penalty
            return 0;
        }

        if(dp[start][end] != -1){
            return dp[start][end];
        }

        int ans = INT_MAX; // we need min ans
        // now find answer for all numbers from start to end
        for(int i=start;i<=end;i++){
            // each i ke liye uska maxm possible penalty lo and overall sarey i me se minm return karo
            // +i kyuki we're finding maxm penalty
            ans = min(ans, i + max(solveMemo(start, i-1, dp), solveMemo(i+1, end, dp))); // maxm betn left range and right range
        }
        dp[start][end] = ans;
        return dp[start][end];
    }

    int getMoneyAmountMemoization(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int start = 1, end = n;
        return solveMemo(start, end, dp);
    }


// 3. Tabulation(bottom up)

int getMoneyAmountTabulation(int n) {
        vector<vector<int>> dp(n+2, vector<int>(n+1, 0)); // base case so insert 0 for all
        
        // top down mai 1 to n jara tha so opp here
        for(int start_idx=n;start_idx>=1;start_idx--){
            // topdown mai n se start hokar 1 ki taraf jara tha so opp here
            for(int end_idx=1;end_idx<=n;end_idx++){
                // invalid range, so skip
                if(start_idx >= end_idx)
                    continue;
                

                // recursive logic to dp arr
                 int ans = INT_MAX; 
                for(int i=start_idx;i<=end_idx;i++){
                    ans = min(ans, i + max(dp[start_idx][i-1], dp[i+1][end_idx])); // kyuki 'i+1' index access karra hai, when i=n, goes out of index so declare vector of size n+2 instead of n+1 
                }
                dp[start_idx][end_idx] = ans;
            }
        }
        return dp[1][n];  // topdown mai jo pass kiyatha wahi return
    }

// Note: Space optimization not possible bcoz dp[start_idx][end_idx] depends on dp[start_idx][i-1] (i.e. same row ka koisi vi column) & dp[i+1][end_idx] (i.e. same column ka koisa vi row)
// Space optimization possible when curr row or curr column depends on next row or next col.



int main(){

    return 0;
}