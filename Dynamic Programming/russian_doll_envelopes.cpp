#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*

also revise maximum height by stacking cuboids(very similar to this)

algo:
- same as longest_increasing_subsequence just change the condition for include. i.e. replace (nums[curr] > nums[prev]) with function to check if 
    secondlast(prev index) envelope can be put inside the last(curr index) envelope. 

*/

// but this algo gives TLE for some testcases

bool check(vector<int> &curr, vector<int> &prev){
        // curr denotes big cuboid & prev is small 
        if(curr[0] > prev[0] && curr[1] > prev[1]){
            return true;
        } else
            return false;
    }

    int lengthOfLISTabulation(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0)); // base case analysis, so initialize all to 0

        for(int curr=n-1;curr>=0;curr--){  // curr denotes index of last cuboid
            for(int prev=curr-1;prev>=-1;prev--){ // prev denotes index of secondlast cuboid
                int include = 0;
                if(prev == -1 || check(envelopes[curr], envelopes[prev])){ // condition change here
                    include = 1 + dp[curr+1][curr+1];  
                }
                int exclude = 0 + dp[curr+1][prev+1]; 
                dp[curr][prev+1] = max(include, exclude);
            }
        }
        return dp[0][0];  // dp[0][-1+1] shifting
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end()); // sort bcoz we want to get smaller to bigger envelopes
        return lengthOfLISTabulation(envelopes);
    }


// Optimal (using sorting)
/*

algo:
- sort 2d array width wise (accn to 1st elm)
- whenever width is same, we sort those arrays accn to their heights in dereasing order 
eg: [[5,4],[6,4],[6,7],[2,3]] then we must have [[2,3],[5,4],[6,7],[6,4]] so that ans=3. 
But without sorting in decresing order of height in case of width=6, it'd give [[2,3],[5,4],[6,4],[6,7]] & our ans will be 2 only

- then find longest increasing subsequence using the height part of every envelope


*/

static bool cmp(vector<int>& a, vector<int>& b){
    if(a[0] == b[0]) // if width same, sort decreasing order by height
        return a[1] > b[1];
    return a[0] < b[0]; // width, diff, so sort by width
}

int lengthOfLISBS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            // curr elm > last elm of ans, just push it
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
            }else{
                // insert curr elm in sorted position in ans array 
                int lbIndex = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin(); // lower_bound() returns iterator so '-ans.begin()' karnese correct index milta hai(i.e. reqd elm iterator & first elm iterator k bich ka distance)
                ans[lbIndex] = nums[i];
            }
        }
        return ans.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // sort accn to width & by height(decreasing) if width same
        sort(envelopes.begin(), envelopes.end(), cmp);

        // find LIS of heights now to get the ans
        vector<int> heights;
        for(auto env : envelopes)
            heights.push_back(env[1]);

        return lengthOfLISBS(heights);
    }