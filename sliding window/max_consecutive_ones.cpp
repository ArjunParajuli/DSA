  int longestOnes(vector<int>& nums, int k) {
        int c0=0;
        int i=0, j=0, ans=0;
        while(j < nums.size()){
            if(nums[j] == 0) c0++;
            if(c0 <= k){
                ans = max(ans, j-i+1);
                j++;
            }else if(c0 > k){
                while(c0 > k){
                    if(nums[i] == 0) c0--;
                    i++; 
                }
                j++;
            }
        }
        return ans;
    }