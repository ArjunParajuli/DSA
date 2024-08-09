#include<iostream>
#include <vector>
using namespace std;

// The pivot index is the index where
//  the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

int pivotIndex(vector<int>& nums){
        int leftSum = 0;
        int rightSum = 0;
        for(int i=0;i<nums.size();i++){
            rightSum += nums[i];
        }
        for(int i=0;i<nums.size();i++){
             rightSum -= nums[i];
            if(leftSum == rightSum)
                return i;
            leftSum += nums[i];
        }
        return -1;
    }

int main(){
    vector<int> nums = {1,7,3,6,5,6};
    cout << pivotIndex(nums);

    return 0;
}