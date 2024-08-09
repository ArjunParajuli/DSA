#include<iostream>
#include<deque>
#include<vector>
using namespace std;

void solve(vector<int>&nums,int k){
    deque<int>dq;
    vector<int>ans;
    
    // First window, 
    for(int i=0;i<k;i++){
        // agar curr num dq k last num se bada hai toh dq se pop karo before inserting the big num so that dq will store elms in decreasing order(maxm to min at end)
        while(!dq.empty() && nums[i] >= nums[dq.back()]){
            dq.pop_back();
        }
        // insert index
        dq.push_back(i);
    }
    // Store the answer for first window
    ans.push_back(nums[dq.front()]);

    // Process remaining windows
    for(int i = k;i<nums.size();i++){
        // out of window wale elm ko remove karo
        if(!dq.empty() && i-dq.front()+1 > k){
            dq.pop_front(); // front element to be removed incase of out of window
        }

        // same step as above to maintain decreasing order
        while(!dq.empty() && nums[i] >= nums[dq.back()]){
            dq.pop_back();
        }
        // Insert the index 
        dq.push_back(i); 
        // Store answer of current window
        ans.push_back(nums[dq.front()]);
    }
    // Print the answer
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
    vector<int>nums{1,3,-1,-3,5,3,6,7};
    int k = 3;
    solve(nums,k);
    return 0;
}