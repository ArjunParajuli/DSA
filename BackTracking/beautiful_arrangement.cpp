#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
brute force: find all permutations and check for each permutation

optimal: initialize nums with 0, and follow the follown steps
*/
 
 void solve(int n, int &cnt, int currnum, vector<int> &nums){
        // currnum exceeds n means this permutation is possible
        if(currnum == n+1){
            cnt++;
            return;
        }

        for(int i=1;i<=n;i++){
            // if curr posn is empty and conditions follow then put currnum in ith posn
            if(nums[i] == 0 && (currnum%i == 0 || i%currnum == 0)){
                nums[i] = currnum; // put currrnum at ith posn
                // after puttn currrnum at ith posn solve(check) for other numbers
                solve(n, cnt, currnum+1, nums);
                // backtrack (reset curr posn)
                nums[i]=0;
            }
        }
    }

    int countArrangement(int n) {
        // tak n+1 size bcoz we don't use the 0th index, we only use index 1 to n
        vector<int> nums(n+1, 0);
        int cnt=0;
        solve(n, cnt, 1, nums);
        return cnt;
    }

    int main(){
        

        return 0;
    }