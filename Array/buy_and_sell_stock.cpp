#include<bits/stdc++.h>
using namespace std;

// The cost of stock on each day is given in an array A[] of size N. Find all the segments of days on which you buy and 
// sell the stock so that in between those days for which profit can be generated.

// Input:
// N = 7
// A[] = {100,180,260,310,40,535,695}
// Output:
// 1
// Explanation:
// One possible solution is (0 3) (4 6)
// We can buy stock on day 0,
// and sell it on 3rd day, which will 
// give us maximum profit. Now, we buy 
// stock on day 4 and sell it on day 6.

 vector<vector<int> > stockBuySell(vector<int> A, int n){
        vector<vector<int>> ans;
        int buy=0, sell=0, i=0;
        // run upto second last to avoid index out of bound
        while(i<n-1){
            if(A[i] < A[i+1]){
                sell++;
                i++;
            }else{ // if next elm is equal or smaller than current elm, we got the right sell time
                if(buy < sell){
                    ans.push_back({buy, sell});
                }
                buy=sell=i+1; 
                i++;
            }
            
        }
        // we looped upto second last elm so check for last elm also
        if(buy < sell){
            ans.push_back({buy, sell});
        }
        return ans;
    }

int main(){
    vector<int> arr = {100,180,260,310,40,535,695};
    vector<vector<int>> ans = stockBuySell(arr, 7);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}