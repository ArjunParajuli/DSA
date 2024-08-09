#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& nums) {
        int cnt=0;
        int n = nums.size();
        if(nums[0] < nums[n-1])
            cnt++;
        for(int i=0;i<n-1;i++){             //  [3,4,5,1,2] gives true
            if(nums[i] > nums[i+1])         //  [2,1,3,4] gives false
                cnt++;                      //  [1,2,3] gives true
        }
        if(cnt <= 1)            // if cnt == 2 then ans is false   
            return true;        // cnt == 0 for [1,1,1]
        else
            return false;
    }

    int main(){
    vector<int> arr = {0,1,3,0};
    cout << check(arr); 
    return 0;
}
