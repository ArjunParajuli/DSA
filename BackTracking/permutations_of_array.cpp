#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

// same as permutaions of string 
// make recursive tree for understanding
// Time Complexity: O((N! * log N) + (N! * log N!)),  As recursion takes O(N!)  time because we generate every possible permutation and another O(log N)  time is required to insert every permutation in the set. Also, O(N! Log N!)  time is required to sort the array.
// Auxiliary Space: O(N*N!), To store all permutations O(N!) space is required and every permutation is of N size string so total space will be O(N*N!).
 
 void solve(int i, vector<int> &nums, vector<vector<int>> &ans){
        if(i==nums.size()){
            ans.push_back(nums);
            return;
        }
         for(int j=i;j<nums.size();j++){
		        swap(nums[i], nums[j]);
		        solve(i+1, nums, ans);
                // backtrack
                swap(nums[i], nums[j]);
		    }   
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0, nums, ans);
        return ans;
    }

    int main(){
        

        return 0;
    }