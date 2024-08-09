#include <bits/stdc++.h>
using namespace std;

//moves all zeroes to the end of the array 

void moveZeroes(vector<int>& nums) {
      int nonZero = 0;  // start nonzero index from the first posn
      for(int i=0;i<nums.size();i++){   // now search for nonzero values
          if(nums[i] != 0){             // i++ for all nums[i]=0 and enter if st. only when we get a nonzero val
              swap(nums[i], nums[nonZero]);
              nonZero++;
          }
      }
    }

int main(){
    vector<int> arr = {0,1,0,3,0};
    moveZeroes(arr);
    for(int itr : arr){
        cout << itr << " ";
    } 
    return 0;
}
