#include<iostream>
#include<vector>
using namespace std;

/*
Q) difference between iterator and pointer in cpp.
-> - Iterators ensure that you don't accidentally access memory outside the bounds of the container. But using pointer might lead to accessing invalid memory locations.
    - iterators provide a higher level of abstraction and safety compared to pointers.
    - Iterators are primarily used for traversal and manipulation of containers. Pointers are used for a wide range of purposes, including array indexing, dynamic memory allocation, etc.
*/

/*

# VVVIMP bcoz lots of questions on this same pattern
codehelp dp class 5

- same pattern ques are (Longest Increasing Subsequence with diff betn adjacent equals k), (maxm height of stacking cuboid), (russian doll envelopes)
- jab vi insertion, stacking or placement based on some condition ki baat ho, this pattern is used.


algo:
- include exclude pattern, keep track of curr elm and prev elm
- once if(currElm > prevElm) include curr in ans
- once exclude curr elm in ans

*/


// 1. recursion
int solve(vector<int>& nums, int curr, int prev){
        if(curr >= nums.size()){
            return 0;
        }

        int include = 0;
        // if prev is at -1 then it means no elm is taken right now, so we must take curr elm, eg: first elm case
        if(prev == -1 || nums[curr] > nums[prev]){
            // set prev to curr, prev+1 won't work bcoz if prev=-1 & curr is at 3rd elm then we must set prev elm to 3rd elm before moving curr forward 
            include = 1 + solve(nums, curr+1, curr); 
        }
        // exclude so only move curr forward, not prev bcoz prev elm remains the same
        int exclude = 0 + solve(nums, curr+1, prev);

        return max(include, exclude);
    }

    int lengthOfLIS(vector<int>& nums) {
        int prev=-1, curr=0;
        return solve(nums, curr, prev);
    }

// 2. Memoization (#Note: index shifting bcoz prev=-1 then it gives error, so just replace prev with prev+1 in dp array)
 int solveMemo(vector<int>& nums, int curr, int prev, vector<vector<int>> &dp){
        if(curr >= nums.size()){
            return 0;
        }

        if(dp[curr][prev+1] != -1)
            return dp[curr][prev+1];

        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solveMemo(nums, curr+1, curr, dp);
        }
        int exclude = 0 + solveMemo(nums, curr+1, prev,  dp);

        return dp[curr][prev+1] = max(include, exclude);
    }

    int lengthOfLISMemoization(vector<int>& nums) {
        int n = nums.size();
        // both prev & curr go upto last elm so size n+1
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int prev=-1, curr=0;
        return solveMemo(nums, curr, prev, dp);
    }

// 3. Tabulation (both time and space O(n^2))
int lengthOfLISTabulation(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0)); // base case analysis, so initialize all to 0

        // in topdown, curr goes from 0 to n, so here opposite and start from n-1 bcoz nth already covered in base case
        for(int curr=n-1;curr>=0;curr--){
            // in topdown, prev goes from -1 to curr_Index-1, so opp here
            for(int prev=curr-1;prev>=-1;prev--){
                int include = 0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    include = 1 + dp[curr+1][curr+1];  // dp[curr+1][curr] becomes dp[curr+1][curr+1] bcoz it also denotes the prev, hence avoid indexBound
                }
                int exclude = 0 + dp[curr+1][prev+1]; // prev+1 to avoid indexbound
                dp[curr][prev+1] = max(include, exclude);
            }
        }
        return dp[0][0];  // dp[0][-1+1] shifting
    }

// 4. Space Optimization ( d[c][p+1] depends on dp[c+1][c+1] & dp[c+1][p+1] hence depends on current row and next row )
// so we can solve it using two arrays. But each array represents current row and next row here, unlike previous ques where the arrays repr columns. 

// we only have to change the dp array
int lengthOfLISSpaceOptimization(vector<int>& nums) {
        int n = nums.size();
        vector<int> currArr(n+1, 0); // initially secondlast row
        vector<int> nextArr(n+1, 0); // initially last row
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int include = 0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    include = 1 + nextArr[curr+1];  // dp[curr+1][curr+1] becomes nextArr[curr+1] bcoz nextArr repr next row(i.e. curr+1)
                }
                int exclude = 0 + nextArr[prev+1];  // dp[curr+1][prev+1] becomes nextArr[prev+1] 
                currArr[prev+1] = max(include, exclude); // dp[curr][prev+1] becomes currArr[prev+1] bcoz currArr repr current row
            }
            nextArr = currArr;  // shifting upwards
        }
        return currArr[0];
    }


// 5. Most optimized one: using binary search ( time: O(nlogn) )
    // using the lower_bound function which uses binary search internally to return the iterator to a particular elm
    // if the elm is found, lower_bound returns iterator to the first occurance of that elm
    // if elm isn't found, it returns iterator to the elm just greater than our elm

// if number exists, lowerbound gives index of first occr & upper bound gives index of last occr

// we're maintaining a sorted array in ans [maintain increasing order]
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

    int main(){
        vector<int> arr= {2,1,1,5,6,2,3,1};
        cout << lengthOfLISBS(arr);

        return 0;
    }