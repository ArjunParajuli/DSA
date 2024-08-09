#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
        int i=0, j=k-1, sum=0;
        int ans=0;
        // first find sum of first k elms
        for(int itr=0;itr<=j;itr++){
            sum += nums[itr];
        }
        ans = sum;
        // j++ done here so that for size four array and k also four, it wont enter the loop 
        j++;
        while(j < nums.size()){
            // decrement the ith elm and increment the jth elm
            sum = sum - nums[i++];
            sum = sum + nums[j++];
            // keep track of maxm sum subarray using ans 
            ans = max(sum, ans);
        }
        double finalAns = (ans/(double)k);
        return finalAns; 
    }

    int main(){
         vector<int> A = {1, 12, -5, -6, 50, 3} ;
        cout << findMaxAverage(A, 4);

        return 0;
    }