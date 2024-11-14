#include<bits/stdc++.h>
using namespace std;

void solve(int k, int n, int i, int cnt, vector<int> &t, vector<vector<int>> &ans){
    if(cnt == k){
        if(n == 0) ans.push_back(t);
        return; 
    }

    for(int j=i;j<=9;j++){
        t.push_back(j);
        solve(k, n-j, j+1, cnt+1, t, ans);
        t.pop_back();
    }
}

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> t;
        solve(k, n, 1, 0, t, ans);
        return ans;
    }