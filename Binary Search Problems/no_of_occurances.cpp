#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// find total occurance of an elm in O(logn) tine

int firstOccr(vector<int>& nums, int n, int k){
        int s = 0, e = n-1;
        int mid, ans=-1;
        while(s <= e){
            mid = s + (e-s)/2;
            if(nums[mid] == k){
                ans = mid;
                e = mid-1;       // check if elm is in the left also
            }else if(nums[mid] > k)
                e = mid-1;
            else
                s = mid+1;

            mid = s + (e-s)/2; 
        }
        return ans;
    }

    int lastOccr(vector<int>& nums, int n, int k){
        int s = 0, e = n-1;
        int mid, ans=-1;
        while(s <= e){
            mid = s + (e-s)/2;
            if(nums[mid] == k){
                ans = mid;
                s = mid+1;
            }else if(nums[mid] > k)
                e = mid-1;
            else
                s = mid+1;

            mid = s + (e-s)/2; 
        }
        return ans;
    }

   int totalOccr(vector<int>& nums, int target) {
        int n = nums.size();
        int startIndex = firstOccr(nums, n, target);
        int lastIndex = lastOccr(nums, n, target);
        return ((lastIndex - startIndex) + 1);
    }

int main(){
    vector<int> arr = {5,7,7,8,8,10};
    cout << totalOccr(arr, 7);

    return 0;
}