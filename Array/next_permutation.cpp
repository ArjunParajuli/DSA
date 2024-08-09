 #include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Note: refer striver youtube video

/*
brute: generate all possible arrangements(using recursion) in arr and linear search to return the next permutation of the ques arr
better(stl): next_permutation(s.begin(), s.end()); & return s

optimal: 

*/
 
 void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    // temp is the breakpoint index after which we must change the array  
    int temp = -1;
    // next permutation must be greater than current number, so find index of first smaller elm from end except last elm
    for(int i=n-2;i>=0;i--){
        if(nums[i] < nums[i+1]){
            temp = i;
            break;
        }
    }
    // if no such index found then array has the last permutaion number so just return first permutation eg: 321
    if(temp == -1){
        return reverse(nums.begin(), nums.end());
    }
    //swap the temp index elm with first greater elm from end  
    for(int i=n-1;i>temp;i--){
        if(nums[i] > nums[temp]){
            swap(nums[i], nums[temp]);
            break;
        }
    }
    // after swapping, we got a greater number so now make the remaining last parts as small as possible bcoz we want the next permutation eg: [2,3,1]
    reverse(nums.begin()+temp+1, nums.begin()+n);
    }

    int main(){
        vector<int> v={1,2,3};
        nextPermutation(v);
        for(int itr:v)
            cout <<itr;

        return 0;
    }