 vector<int> rearrangeArray(vector<int>& nums) {
      vector<int> a(nums.size(), 0);
     int posInd = 0, negInd = 1;
     for(int i=0;i<nums.size();i++){
         if(nums[i] > 0){
             a[posInd] = nums[i];
             posInd += 2;
         }else{
             a[negInd] = nums[i];
             negInd += 2;
         }
     }
     return a;
    }