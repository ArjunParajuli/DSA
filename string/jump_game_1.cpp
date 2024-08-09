#include <iostream>
#include <vector>
using namespace std;

// YT- Nikhil Lohia

// check if end position can be reached or not
 bool canJump(vector<int>& nums) {
        int finalPos = nums.size()-1;
        // start from second last
        int start = nums.size()-2;
        for(int i=start;i>=0;i--){
            // if finalPos can be reached from current index
            // then update finalPos to current index
            if(nums[i]+i >= finalPos){
                finalPos = i;
            }
        }
        // if finalPos reaches first index that means end position can be reached
        if(finalPos == 0)
            return true;
        else
            return false;

    }

int main(){
    vector<int> arr = {2,3,1,1,4};
    cout << canJump(arr);

    return 0;
}