 #include<iostream> 
#include<vector>
#include<algorithm>
using namespace std;

/*
brute force:
same as combination sum 1 but calling the solve function for next elm(j+1 instead of j) and using vector of set. 
The original array must be sorted first to keep duplicates together.
*/

/*
optimal:
just sort the arr and for avoiding the duplicates, put a condition, everything else is same as combination sum 1
*/

 
void solve(vector<int> &candidates, int i, int target, vector<vector<int>> &ans, vector<int> &temp){
        // base case
        if(target < 0){ // target -ve then take out the curr elm and go back to previous call
            return;
        }
        if(target == 0){    // found one answer
            ans.push_back(temp);
            return;
        }

        for(int j=i;j<candidates.size();j++){
            if(j>i && candidates[j]==candidates[j-1])
                continue;
            temp.push_back(candidates[j]);
            //  included curr elm so decrement target by curr elm
            solve(candidates,j+1,target-candidates[j], ans, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, 0, target, ans, temp);
        return ans;
    }

    int main(){
        vector<int> candidates = {2,3,6,7};
        int target = 7;
        vector<vector<int>> ans;
        ans = combinationSum2(candidates, target);
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }

        return 0;
    }