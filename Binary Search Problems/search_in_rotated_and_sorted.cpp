#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// int pivotElm(vector<int> arr, int n){ // pivot means the minimum element here
//     int s = 0;
//     int e = n-1;
//     int mid = s + (e-s)/2;
//     while (s < e)
//     {
//         if(arr[mid] >= arr[0])   //means pivot(min) elm is to the right of mid eg:4,5,1,2,3
//             s = mid+1;
//         else                // means pivot(min) elm is to the left of mid and can also be mid
//             e = mid;

//        mid = s + (e-s)/2;
//     }
//     return s;
// }

// int binarysearch(vector<int> arr, int s, int e, int k){
//     int mid = s + (e-s)/2;
//     while(s <= e){
//         if(arr[mid] == k)
//             return mid;
        
//         if(arr[mid] < k)
//             s = mid+1;
//         else    
//             e = mid-1;

//         mid = s + (e-s)/2;
//     }
//     return -1;
// }

// int findPosition(vector<int> arr, int n, int k){
//     int pivot = pivotElm(arr, n); // min(pivot) elm index
//     if(k >= arr[pivot] && k <= arr[n-1]) // key is in the second part i.e. 1,2,3
//         return binarysearch(arr, pivot, n-1, k);
//     else    // key is in the first part i.e. 4,5
//         return binarysearch(arr, 0, pivot-1, k);
// }

// striver's soln
/*
algo:
- either the left part or right part is sorted so
- if left part sorted then search on left half else search on right part
*/

// this method works only when this condition is not followed:  arr[low]=arr[mid]=arr[high] 
 int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low <= high){
        int mid = low + (high-low)/2;
        if(nums[mid] == target)
            return mid;
        // left half is sorted
        if(nums[low] <= nums[mid]){
            // search for target
            if(target >= nums[low] && target <= nums[mid]){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }else{ // right half is sorted
             if(target >= nums[mid] && target <= nums[high]){
                 low = mid+1;
             }else{
                 high = mid-1;
             }
        }
        }
        return -1;
    }

//    when this condition is followed: arr[low]=arr[mid]=arr[high]
 int searchWithDuplicates(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low <= high){
        int mid = low + (high-low)/2;
        if(nums[mid] == target)
            return mid;
     // if mid is not the target then low and high won't be target 
        // so low++ and high-- to avoid condition:  arr[low]=arr[mid]=arr[high]
        if(nums[low] == nums[mid] && nums[mid] == nums[high]){
            low++, high--;
            continue; // same case might occur again so skip to next iteration (eg: [11111])
        }

    // rest all same 
    if(nums[low] <= nums[mid]){
        if(target >= nums[low] && target <= nums[mid])
            high = mid-1;
        else
            low = mid+1;
    }else{
        if(target >= nums[mid] && target <= nums[high])
            low = mid+1;
        else
            high = mid-1; 
    }
    }
    return -1;
 }

int main(){
    vector<int> arr = {1,0,1,1,1};
    cout << searchWithDuplicates(arr, 0);

    return 0;
}