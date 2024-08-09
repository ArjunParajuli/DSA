
#include<bits/stdc++.h>
using namespace std;

/*
striver YT

# for each index, amount of water trapped = min(leftmax, rightmax)-arr[i]

brute force: for each elm, find leftmax and rightmax and find amount trapped, so O(n^2) time

better:
- create two arrays, prefixmax: stores maxm elm from left upto it and suffixmax: stores maxm elm from right upto it

optimal: two-pointer
- use left and right pointer & we always check to find the part that is minm between them bcoz we increment amount with min(leftmax, rightmax)-a[i]
- update amount if current checking elm is less than their respective max elm else just update the max elm.

*/

int trapUsingArr(vector<int>& height) {
        int n = height.size();
        vector<int> prefix(n), suffix(n);
        int lmax = INT_MIN;
        for(int i=0;i<n;i++){
            lmax = max(lmax, height[i]);
            prefix[i] = lmax;
        }
        int rmax = INT_MIN;
        for(int i=n-1;i>=0;i--){
            rmax = max(rmax, height[i]);
            suffix[i] = rmax;
        }
        int amount = 0;
        // bcoz minm betn left & right height tak water store hosakta hai
        for(int i=0;i<n;i++){
            amount += min(prefix[i], suffix[i]) - height[i];
        }
        return amount;
    }


int trapOptimized(vector<int>& height) {
        int n = height.size();
        int amount = 0, left=0, right=n-1, leftmax=0, rightmax=0;
        while(left <= right){
            // we want the minm side since we use min(leftmax, rightmax)
            // left part small so increment amount using leftmax
            if(height[left] < height[right]){
                // means water can be trapped here
                if(height[left] < leftmax){
                    amount += leftmax-height[left];
                }else{ // water cant be trapped since curr elm > leftmax so update leftmax
                    leftmax = height[left];
                }
                left++;
            }else{ // right part small so increment amount using rightmax
                // means water can be trapped here
                if(height[right] < rightmax){
                    amount += rightmax-height[right];
                }else{ // water cant be trapped since curr elm > rightmax so update rightmax
                    rightmax = height[right];
                }
                right--;
            }
        }
        return amount;
    }

int main(){


    return 0;
}