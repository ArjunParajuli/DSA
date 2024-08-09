#include<vector>
#include<iostream>
using namespace std;

 vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            int index = abs(nums[i])-1;
            if(nums[index] < 0)             // if it is -ve then it was already visited
                res.push_back(abs(nums[i]));
            nums[index] = -nums[index];
        }
        return res;
    }

int main(){
    vector<int> arr = {5,6,5,7,6,8};
    vector<int> ans = findDuplicates(arr);
   for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}

// link to explain video
// https://www.youtube.com/watch?v=ACYunkWQnSI