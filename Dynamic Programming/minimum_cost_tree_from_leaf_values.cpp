#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

/*
codehelp dp class 6

same pattern as guess_number_lower_or_higher_II ques 

algo: precomputation used here. i.e we store maxm elm for each range in the array 
- we partition the array at each index. eg: first time left part has only one elm and right part has all other remaining elms, second time left has 2 elms and so on.

*/

// 1.recursion

int solve(vector<int>& arr, map<pair<int, int>, int> &mp, int s, int e){
        if(s > e){ 
            return 0;
        }
        if(s == e){  // single elm then there can't be any nonleaf nodes 
            return 0;
        }

        int ans = INT_MAX;
        // harek i ka partition karna hai
        for(int i=s;i<e;i++){
            // sab partition me sey minm ans nikalo

           // current nonleaf node ka ans + solve for left part + solve for right part
            ans = min(ans, (mp[{s, i}] * mp[{i+1, e}]) + 
                    solve(arr, mp, s, i) + 
                    solve(arr, mp, i+1, e) );       
        }
        return ans;
    }

    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        // precomputation 
        map<pair<int, int>, int> mp;
        for(int i=0;i<n;i++){
            mp[{i, i}] = arr[i]; // when single elm in range, its maxm is that elm itself
            for(int j=i+1;j<n;j++){
                mp[{i, j}] = max(mp[{i, j-1}], arr[j]); // maxm betn prev range's maxm and curr elm 
            }
        }

        int start = 0, end = arr.size()-1;
        return solve(arr, mp, start, end);
    }




// 2. Memoization 
    int solveMemo(vector<int>& arr, map<pair<int, int>, int> &mp, int s, int e, vector<vector<int>> &dp){
        if(s > e){ 
            return 0;
        }
        if(s == e){  // single elm then there can't be any nonleaf nodes 
            return 0;
        }

        if(dp[s][e] != -1)
            return dp[s][e];

        int ans = INT_MAX;
        // harek i ka partition karna hai
        for(int i=s;i<e;i++){
            // sab partition me sey minm ans nikalo

           // current nonleaf node ka ans + solve for left part + solve for right part
            ans = min(ans, (mp[{s, i}] * mp[{i+1, e}]) + 
                    solveMemo(arr, mp, s, i, dp) + 
                    solveMemo(arr, mp, i+1, e, dp) );       
        }
        dp[s][e] = ans;
        return dp[s][e];
    }

    int mctFromLeafValuesMemoization(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        // precomputation 
        map<pair<int, int>, int> mp;
        for(int i=0;i<n;i++){
            mp[{i, i}] = arr[i]; // when single elm in range, its maxm is that elm itself
            for(int j=i+1;j<n;j++){
                mp[{i, j}] = max(mp[{i, j-1}], arr[j]); // maxm betn prev range's maxm and curr elm 
            }
        }

        int start = 0, end = arr.size()-1;
        return solveMemo(arr, mp, start, end, dp);
    }



// 3. Tabulation
    int mctFromLeafValuesTabulation(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n+2, vector<int>(n+1, 0));

        // precomputation 
        map<pair<int, int>, int> mp;
        for(int i=0;i<n;i++){
            mp[{i, i}] = arr[i]; // when single elm in range, its maxm is that elm itself
            for(int j=i+1;j<n;j++){
                mp[{i, j}] = max(mp[{i, j-1}], arr[j]); // maxm betn prev range's maxm and curr elm 
            }
        }

        // opp of topdown approach
        for(int startIdx=n-1;startIdx>=0;startIdx--){
            for(int endIdx=0;endIdx<n;endIdx++){
                if(startIdx >= endIdx){
                        continue;
                    }
                    
                int ans = INT_MAX;
                // harek i ka partition karna hai
                for(int i=startIdx;i<endIdx;i++){
                // (i+1)th row access karre hai so n+2 rows banana padega
                    ans = min(ans, (mp[{startIdx, i}] * mp[{i+1, endIdx}]) + dp[startIdx][i] + dp[i+1][endIdx] );       
                }
                dp[startIdx][endIdx] = ans;
            }
        }
        return dp[0][n-1];
    }


// Note: Space optimization not possible bcoz dp[startIdx][endIdx] depends on dp[startIdx][i] (i.e. same row ka koisi vi column) & dp[i+1][endIdx] (i.e. same column ka koisa vi row)



int main(){


    return 0;
}