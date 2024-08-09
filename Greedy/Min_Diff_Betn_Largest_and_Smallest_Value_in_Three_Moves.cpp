#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*

After sorting the array, we can get ans is following cases:
- change last 3 elm to min(1st) elm, so ans = a[n-4]-a[0]
- change 1st elm to 2nd elm(a[1]) and last 2 elm also to a[1], so ans=a[n-3]-a[1]
- change first 2 elms to 3rd elm(a[2]) and last elm also to a[3], so ans = a[n-2]-a[2]
- change first 3 elm to last elm, so ans = a[n-1]-a[3]

*/

int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() <= 4) return 0;
        sort(nums.begin(), nums.end());

        int ans = nums[n-1]-nums[0];
        for(int i=0;i<4;i++){
            ans = min(ans, nums[n-4]-nums[0]);
            ans = min(ans, nums[n-3]-nums[1]);
            ans = min(ans, nums[n-2]-nums[2]);
            ans = min(ans, nums[n-1]-nums[3]); 
        }
        return ans;
    }

int main(){
    vector<int> nums={0,0,3,3,3,4,5,6};
    cout << minDifference(nums) << endl;

    return 0;
}