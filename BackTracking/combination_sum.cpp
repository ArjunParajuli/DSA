 #include<iostream> 
#include<vector>
using namespace std;

// time: o(2^N  * K), K IS TIME FOR INSERTING temp array into 2d array ans
 
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
            temp.push_back(candidates[j]);
            //  included curr elm so decrement target by curr elm
            solve(candidates,j,target-candidates[j], ans, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, 0, target, ans, temp);
        return ans;
    }

    int main(){
        vector<int> candidates = {2,3,6,7};
        int target = 7;
        vector<vector<int>> ans;
        ans = combinationSum(candidates, target);
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }

        return 0;
    }