#include<iostream> 
#include<vector>
using namespace std;

// yt-striver 

/*
Q) Given a list arr of N integers, return sums of all subsets in it.
algo:
for each index, we once call recursion after adding it to the sum and once call recursion without adding it to sum
basically, for each index, we pick once and not pick it once.

time: O(2^n)
space: O(2^n)
if we sort ans, it becomes O(2^n log 2^n)
*/

 void solve(int i, int sum, vector<int> &ans, vector<int> &arr){
        if(i == arr.size()){
            ans.push_back(sum);
            return;
        }
        // pick the elm
        solve(i+1, sum+arr[i], ans, arr);
        // don't pick the elm
        solve(i+1, sum, ans, arr);
    }

    vector<int> subsetSums(vector<int> arr)
    {
     vector<int> ans;
     int sum = 0;
     solve(0, sum, ans, arr);
     return ans;
    }

int main(){
    vector<int> arr = {1, 2, 3};
    vector<int> ans = subsetSums(arr);
    for(int itr:ans)
        cout << itr << " ";

    return 0;
}