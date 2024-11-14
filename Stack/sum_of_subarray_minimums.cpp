#include<bits/stdc++.h>
using namespace std;

/*
striver YT

ans for each elm would be: (currIdx-nextSmallIndex) * (prevSmallOrEqualIndex-currIdx)
bcoz prevSmallIndex se baad waley sarey subarrays k liye minm elm curr elm hoga. 
And nextSmallIndex se pehle waley sarey subarr k liye minm elm curr elm hoga.

NOTE: we're taking prev smaller or equal elm's index to handle edge cases when first and last elm are same i.e. 1 eg, [1,1] 

Dry run on elm 3 of this arr: [1,4,6,7,3,7,8,1]

*/

 long long mod = 1e9+7;
    vector<int> prevSmallOrEqualIdx(vector<int>& arr){
        vector<int> ans;
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();

            if(st.empty()) ans.push_back(-1);
            else ans.push_back(st.top());
            st.push(i);
        }
        return ans;
    }

     vector<int> nextSmallIdx(vector<int>& arr){
        vector<int> ans(arr.size(), arr.size());
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

            if(st.empty()) ans[i] = arr.size();
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> prev = prevSmallOrEqualIdx(arr);
        vector<int> next = nextSmallIdx(arr);

        // for(int i : prev) cout << i;
        // cout << endl;
        // for(int i : next) cout << i;

        long long int ans = 0;
        for(long long int i=0;i<arr.size();i++){
            long long int currSum = ((i-prev[i])*(next[i]-i)*arr[i])%mod;
            ans = (ans + currSum)%mod;
        }

        return ans;
    }

