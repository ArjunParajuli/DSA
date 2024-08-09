int removeDuplicates(vector<int>& nums) {
        int i=0;
      for(int j=1;j<nums.size();j++){
          // when unique elm is found
          if(nums[i] != nums[j]){
              nums[i+1] = nums[j];
              i++;
          }
      }
      return i+1;
    }