#include <iostream>
#include<vector>
using namespace std;
 
  int searchInsert(vector<int>& nums, int target) {
       int start = 0, end = nums.size()-1;
       int ans=-1;
       while(start <= end){
           int mid = start + (end-start)/2;
           if(nums[mid] >= target){
               ans = mid;
               end = mid-1; 
           }else if(nums[mid] < target){
               ans = mid+1;
               start = mid+1;
           }
       }
       return ans;
    } 

    int main(){
        vector<int> v={1,2,5,7};
        cout << searchInsert(v, 5);

        return 0;
    }