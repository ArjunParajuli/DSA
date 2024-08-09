#include<iostream>
#include<vector>
using namespace std;

// almost same as rob helper 1 
// here we changed the search range i.e. get ans1 with first elm included and ans2 with last elm included
 
 int solve(int s, int e, vector<int>& nums){
        if(s > e){
            return 0;
        }

 // solve 1 case (ek baar current elm ko lelo and ek baar maat lo)
        int option1 = nums[s] + solve(s+2, e, nums);
        int option2 = 0 + solve(s+1, e, nums);

        return max(option1, option2);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }

        // take first elm so cannot take last elm
        int ans1 =  solve(0, n-2, nums);
        // not take first elm so taking last elm
        int ans2 = solve(1, n-1, nums);

        return max(ans1, ans2);
    }

    int main(){
    vector<int> v = {1,2,3,1};
    cout << rob(v);

    return 0;
}

// optimized
int robSpaceOptimized(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0]; // for case like [1]
        // base case analysis: for last index maxm ans willbe value at last index
        int prev = nums[n-1]; 
        int next=0, curr=0;
        for(int i=n-2;i>=0;i--){
            // temp stores val of dp[i+2]
            int temp = 0;
            // to avoid index out of bound
            if(i+2 < n)
                temp = next;
            int include = nums[i] + temp;
            int exclude = 0+prev;

            curr = max(include, exclude);

            // update variables
            next = prev;
            prev = curr;
        }
        return curr;
    }


    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }

        vector<int> temp1, temp2;
        for(int i=0;i<n;i++){
            if(i != 0)
                temp1.push_back(nums[i]);
            if(i != n-1)
                temp2.push_back(nums[i]);
        }


        // take first elm so cannot take last elm
        int ans1 =  robSpaceOptimized(temp1);
        // not take first elm so taking last elm
        int ans2 = robSpaceOptimized(temp2);

        return max(ans1, ans2);
    }