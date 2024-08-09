#include<bits/stdc++.h>
using namespace std;

/*
sliding window doesnt work for -ve elms bcoz
for [-1, -1, 1]. k=0 For this case, sum wont exceed k and we will never decrement sum using i. so count remains 0.

see prepcoding video for logic
algo:
- store current sum and the frequency of this currentsum
- check currsum-k exists in map or not
- if exists then update ans 
*/

 int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int currsum=0, count=0;
    // store currsum and its frequency in hashmap
    for(int i=0;i<nums.size();i++){
        currsum += nums[i];
        int toFind = currsum-k;
        auto itr = mp.find(toFind);
        if(itr!=mp.end())
            count += itr->second;
        mp[currsum]++;
    }  
    return count;
    }

int main(){

    return 0;
}