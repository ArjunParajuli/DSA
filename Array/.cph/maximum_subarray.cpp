#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

/*
- start adding currsum with each elm of array
- maintain maxsum for each iteration
- if at any iteration, currsum<0, then currsum=0 to reset the currsum
*/

//  int maxSubArray(vector<int>& nums) {
//         int currsum=0, maxsum=INT_MIN;
//         for(int i=0; i<nums.size();i++){
//            currsum += nums[i];
//            maxsum = max(currsum, maxsum);
//            if(currsum < 0)
//                 currsum = 0;
//         }
//         return maxsum;
//     }

// if asked to print the subarray
     vector<int> maxSubArray(vector<int>& nums) {
    int currsum = 0, maxsum = INT_MIN;
    int ansStart = 0, ansEnd = -1, start = 0; // Initialize ansStart to 0
    for (int i = 0; i < nums.size(); i++) {
        if (currsum == 0)
            start = i;
        currsum += nums[i];
        if (currsum > maxsum) {
            maxsum = currsum;
            // update maximum sum subarray start and end indexes
            ansStart = start;
            ansEnd = i;
        }
        if (currsum < 0)
            currsum = 0;
    }
    vector<int> ans(nums.begin() + ansStart, nums.begin() + ansEnd + 1); // second arg is len
    return ans;
}
     /*
     DnC approach
     time: O(nlogn), space O(logn)
     */
     int maxSubArrayHelper(vector<int>& nums, int s, int e){
        // base case
        if(s == e) return nums[s];  // array divided to single elm 

        int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN; 
        int mid = s+((e-s)>>1);

        int maxLeftSum = maxSubArrayHelper(nums, s, mid);
        int maxRightSum = maxSubArrayHelper(nums, mid+1, e);

        // find max cross Border Sum
        int leftBorderSum=0, rightBorderSum=0;
        for(int i=mid;i>=s;i--){
            leftBorderSum += nums[i];
            maxLeftBorderSum = max(maxLeftBorderSum, leftBorderSum);
        }
        for(int i=mid+1;i<=e;i++){
            rightBorderSum += nums[i];
            maxRightBorderSum = max(maxRightBorderSum, rightBorderSum);
        }
        int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;

    // return max of left sum, right sum and crossborder sum
        return max(crossBorderSum, max(maxLeftSum, maxRightSum));
    }

    int maxSubArrayDnC(vector<int>& nums) {
        return maxSubArrayHelper(nums, 0, nums.size()-1);
    }


int main(){
    vector<int> v = {5,6,-7,-9,7,8};
    vector<int> ans;
    ans = maxSubArray(v);
    for(auto itr:ans)
        cout << itr << " "; 

    return 0;
}