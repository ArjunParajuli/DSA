#include<bits/stdc++.h>
using namespace std;

/*
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.
Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]

- hypothetically doubling the array
- in first traversal, we dont push in ans, we just put the elms in stack that are greatest
- in 2nd traversal, we push in the ans arr


time: O(4n) worst
space: O(2n)
*/

vector<int> nextGreaterElements(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n, -1);
        stack<int> st;

         for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top() <= a[i]){
                st.pop();
            }
            st.push(a[i]);
         }
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top() <= a[i]){
                st.pop();
            }

            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            st.push(a[i]);
        }
        return ans;
    }