#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/*
codehelp DP Assignment

algo: we first find the maxm length mountain array 
reqd ans = (length of arr) - (length of longest mountain array), this gives us the minm number of elms which should be removed to make the mountain array 

algo to find max len of mountain arr:
- for each elm, find longest incr subseq from leftmost elm to itself & find longest decr subseq from rightmost elm to itself. Store them in two arrays LIS & LDS. 
- then we can find max len mountain array using these two arr. i.e. maxm value of LIS[i]-LDS[i]-1

eg: for arr= [2,1,1,5,6,2,3,1]
        LIS= [1,1,1,2,3,2,3,1]
        LDS= [2,1,1,3,3,2,2,1]

        so for i=4, we get max len mountain arr = 3+3-1 = 5
        Hence, min no. of removals = 8-5=3
*/


// LIS func modified, now it returns length of longest incr subseq for each elm upto its curr index
    vector<int> lengthOfLISBS(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS; 
        vector<int> ans;
        ans.push_back(nums[0]);
        LIS.push_back(ans.size()); // LIS for first elm is 1 
        for(int i=1;i<n;i++){
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
                // LIS for this elm will be size of ans arr bcoz its inserted at the end, so all elms left to it in ans array are small than it
                LIS.push_back(ans.size()); 
            }else{
                int lbIndex = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin(); 
                ans[lbIndex] = nums[i]; 
                LIS.push_back(lbIndex+1); // insert LIS for curr elm i.e. lbIndex+1 bcoz all elms left to lbIndex are smaller than curr elm
            }
        }
        // for(int i : LIS)
        //     cout << i << " ";
        // cout << endl;
        return LIS;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> LIS = lengthOfLISBS(nums); // gives LIS arr 
        
        // reverse nums & use LIS func to find LDS arr
        reverse(nums.begin(), nums.end()); 
        vector<int> LDS = lengthOfLISBS(nums);
        reverse(LDS.begin(), LDS.end()); // reverse returned arr to get LDS arr 

        // find len of maxm mountain arr
        int maxMountainArr = INT_MIN;
        for(int i=0;i<LIS.size();i++){
            int currMountainArr;
            // if LIS or LDS for any elm is 1 then we can't form a mountain
            if(LIS[i]==1 || LDS[i]==1)
                currMountainArr = 0;
            else
                currMountainArr = LIS[i]+LDS[i]-1;
            maxMountainArr = max(maxMountainArr, currMountainArr);
        } 
        int minRemoval = nums.size() - maxMountainArr;
        return minRemoval;
    }


