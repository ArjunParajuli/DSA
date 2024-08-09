#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > stockBuySell(vector<int> A, int n){
        vector<vector<int>> ans;
        for(int i=0;i<n-1;i++){
            if(A[i] < A[i+1])
                ans.push_back({i, i+1});
        }
        return ans;
    }

    int main(){
        vector<vector<int>> a = {
            {1,2,3},
            {1,2,3}
        }



        return 0;
    }