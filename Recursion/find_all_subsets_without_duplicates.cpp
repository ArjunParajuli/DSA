#include<iostream> 
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

// brute force
/*
same as find_all_subsets problem, we're just using a set here
O(log n) time increased for inserting in set
*/

/*

 void solve(int i, set<vector<int>> &ans, vector<int> &arr, vector<int> temp){
        if(i == arr.size()){
            ans.insert(temp);
            return;
        }
        // pick the elm
        temp.push_back(arr[i]);
        solve(i+1, ans, arr, temp);
        // don't pick the elm
        temp.pop_back();
        while(i + 1 < arr.size() && arr[i] == arr[i+1])
            i++;
        solve(i+1, ans, arr, temp);
    }

    vector<vector<int>> subsetsWithoutDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> temp;
        // sort the original array to keep duplicates together and check using while loop
         sort(nums.begin(), nums.end());
        solve(0, ans, nums, temp);
        vector<vector<int>> ansVec;
        for(auto itr : ans){     
            ansVec.push_back(itr);
        }
        return ansVec;
    }
*/

// ooptimal yt- striver

void solve(int i, vector<vector<int>> &ans, vector<int> &arr, vector<int> &temp){
        // add current subset to ans
        ans.push_back(temp);
       for(int j=i;j<arr.size();j++){
           // skip consecutive duplicates
           if(j > i && arr[j]==arr[j-1])
                continue; 
            temp.push_back(arr[j]);
            solve(j+1, ans, arr, temp);
            temp.pop_back();
       }
    }

    vector<vector<int>> subsetsWithoutDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end()); // to keep duplicates together
        solve(0, ans, nums, temp);
        return ans;
    }


int main(){
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans = subsetsWithoutDup(arr);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}