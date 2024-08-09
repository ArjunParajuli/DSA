#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

/*
- start from end and maintain maximum element upto current index
- if current element equal to maximum elm then that is one of the ans
*/
vector<int> leaders(vector<int> a, int n){
        vector<int> ans;
        int maxm = INT_MIN;
        for(int i=n-1;i>=0;i--){
            maxm = max(maxm, a[i]);
            if(maxm == a[i])
                ans.push_back(a[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

int main(){
    vector<int> ans={16, 17,4,3,5,2};
    ans = leaders(ans, ans.size());
    for(int itr:ans)
        cout << itr << " ";

    return 0; 

}