#include<iostream>
#include<vector>
using namespace std;

/*
codehelp sliding window class
algo:
- whenever, sum gets greater than goal or curr elm is 0 then we must count prefixZero and also decrease window size
- after that update ans

*/

int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i=0, j=0, prefixZero=0, sum=0, count=0;
        while(j < nums.size()){
            sum += nums[j];
            // minimise the window
            while(i<j && (sum > goal || nums[i]==0)){
                // decrease sum
                sum -= nums[i];
                // curr elm is 0 then increase prefixZero   eg: 1,0,0,0,1,0,1 goal=3, dry run for clarity
                if(nums[i] == 0){
                    prefixZero++;
                }else // reset prefixZero to 0
                    prefixZero = 0;
                i++;  // decrease window
            }
            // update ans
            if(sum == goal){
                count += prefixZero+1;
            }

            j++;
        }
        return count;
    }

// hash map(prefixSum)
int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum=0, cnt=0;
        unordered_map<int, int> mp;
        for(int j=0;j<nums.size();j++){
            sum += nums[j];

            if(sum == goal){
                cnt++;
            }
            int reqSumDiff = sum-goal;
                if(mp.find(reqSumDiff) != mp.end()){
                    cnt += mp[reqSumDiff];
                }
            mp[sum]++;
        }
        return cnt;
    }