#include<iostream> 
#include<vector>
using namespace std;
 
/* yt- striver subsets i
 approach is same as the problem subset_sums
 here, instead of sum, we use temp vector to store subsets 
 algo:
for each elm, we once call recursion after pushing it to temp and once call recursion without pushing it to temp
basically, for each elm, we pick once and not pick it once.

time: O(2^n)
space: O(2^n)
if we sort ans, it becomes O(2^n log 2^n)


*/

 void solve(int i, vector<vector<int>> &ans, vector<int> &arr, vector<int> &temp){
        if(i == arr.size()){
            ans.push_back(temp);
            return;
        }
        // pick the elm
        temp.push_back(arr[i]);
        solve(i+1, ans, arr, temp);
        // don't pick the elm
        temp.pop_back();
        solve(i+1, ans, arr, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, ans, nums, temp);
        return ans;
    }

int main(){
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans = subsets(arr);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}