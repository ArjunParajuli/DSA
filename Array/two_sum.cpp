 #include <iostream>
 #include <vector>
using namespace std;


// using hashmap ( time O(n) )
/*
algo :
- start from first elm, check for all elm if (target-nums[i]) is present in the nums array or not
- if found return else push that elm with its index in hashmap
*/ 

 vector<int> twoSum(vector<int>& nums, int target) {
      map<int, int> mp;
      for(int i=0;i<nums.size();i++){
          // elm found
          int required = target-nums[i];
          if(mp.find(required) != mp.end()){
              return {i, mp[required]};
          }else{ // not found then push elm with its index into map 
                mp[nums[i]] = i;
          }
      }
      return {-1, -1};
    }

// 

void main(){

}
 
