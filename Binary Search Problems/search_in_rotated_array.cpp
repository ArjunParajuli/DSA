#include<iostream>
#include<vector>

using namespace std;


// here pivot elm is the highest elm in this roteated and sorted array.
  int pivotIndex(vector<int>& arr){
        int s = 0, e = arr.size()-1;
        int mid = s + (e-s)/2;
        int n = arr.size();

        while(s <= e){
            // single elm case
            if(s == e)
                return s;
                // handle case where mid is at 7 (arr is [4 5 6 7 0 1 2])
             // mid+1<n and mid-1>=0 used so that we dont go out of index(eg: -1)
             if(mid+1 < n && arr[mid] > arr[mid+1])
                return mid;
                 // handle case where mid is at 0 (arr is [4 5 6 7 0 1 2])

                 // for case (1, 3) mid-1 will be -1
            else if(mid-1 >= 0 && arr[mid] < arr[mid-1])
                return mid-1;
                // when mid is on right part of pivot
            else if(arr[mid] < arr[s])
                e = mid-1;
                // when mid is at left part of pivot
            else
                s = mid+1;

                mid = s + (e-s)/2;
        }
        return -1;
    }

    int binarySearch(vector<int>& nums, int s, int e, int target){
        //  int s = 0, e = arr.size()-1; 
        int mid = s + (e-s)/2;
         while(s <= e){
             if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                e = mid-1;
            else 
                s = mid+1;

              mid = s + (e-s)/2;
         }
         return -1;
    }

    int search(vector<int>& nums, int target) {
        int p = pivotIndex(nums);
        // search in first part
        if(target>=nums[0] && target<=nums[p])
            return binarySearch(nums, 0, p, target);
        else  // search in second part
            return binarySearch(nums, p+1, nums.size()-1, target);

        return -1;
    }

 int main(){
        vector<int> nums = {1,3};
        int target = 0;
        cout << search(nums, target);

        return 0;
    }