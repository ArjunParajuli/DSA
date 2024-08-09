#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// yt-pepcoding 

// max consecutive ones with only k flips allowed

// very similar to max consecutive ones ii

/*
 sliding window:
 - start j = -1, and current window is from j+1 to i-1 
 - whenever coount exceeds k, we move j to next 0 elm and continue 

*/
 int longestOnes(vector<int>& nums, int k) {
       int count0=0, currlen=0, maxlen=0, j=0;
       for(int i=0;i<nums.size();i++){
           if(nums[i] == 0){
               count0++;
           }
           while(count0 > k){
               if(nums[j]==0){
                   count0--;
               }
               j++;
           }
           currlen = (i)-(j)+1;
           maxlen = max(maxlen, currlen);
       }
       return maxlen;
    }

int main() {
    vector<int> arr = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1};
    cout << longestOnes(arr, 3);

    return 0;
}