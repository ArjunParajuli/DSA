#include<bits/stdc++.h>
using namespace std;

/* 
find beauty of each substring using hashmap 
*/

 int findBeauty(vector<int> &mp){
        int maxm = INT_MIN;
        int minm = INT_MAX;
        for(auto itr:mp){
            if(itr >= 1){
                maxm = max(maxm, itr);
                minm = min(minm, itr);
            }
        }
        return maxm-minm;
    }

    int beautySum(string s) {
        int beauty = 0;
        for(int i=0;i<s.size();i++){
            vector<int> mp(26, 0);
            for(int j=i;j<s.size();j++){
                mp[s[j]-'a']++;
                beauty += findBeauty(mp);
            }
        }
        return beauty;
    }