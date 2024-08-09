#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// same as permutations i but here array contains duplicates also
/*
    - maintain map and push elm in map and before swap check if that elm already existed in map.
    - if yes, then skip this iteration bcoz it'll result in giving same res as before 
*/

void solve(int i, vector<int> &nums, vector<vector<int>> &ans){
        if(i==nums.size()){
            ans.push_back(nums);
            return;
        }
         unordered_map<int, int> mark;
         for(int j=i;j<nums.size();j++){
              if(mark.find(nums[j]) != mark.end()){
                continue;
            }
            mark[nums[j]] = 1;
		    swap(nums[i], nums[j]);
		    solve(i+1, nums, ans);
                // backtrack
            swap(nums[i], nums[j]);
		    }   
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0, nums, ans);
        return ans;
    }

    int main(){
        

        return 0;
    }