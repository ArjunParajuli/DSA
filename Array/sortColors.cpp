#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void sortColors(vector<int> &nums){
    // inplace solution(without overriding the array elms)
    int low=0, mid=0, high= nums.size()-1;
    // low is for 0s, mid is for 1s, high is for 2s
    while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[low++], nums[mid++]);
        }else if(nums[mid] == 1){
            mid++;
        }else{
            // catch here-> dont increment mid 
            swap(nums[mid], nums[high--]);
        }
    }
}

int main(){
    vector<int> nums = {2,0,2,1,1,0};
    sortColors(nums);
    for(int itr : nums){
        cout << itr << " ";
    }

    return 0;
}