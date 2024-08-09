#include<bits\stdc++.h>
using namespace std;

// In binary search, the expression mid = start + (end - start) / 2 is used to prevent integer overflow. 
// This is because integers have a limited range that they can represent

int firstOccr(vector<int>& nums, int n, int k){
        int s = 0, e = n-1;
        int mid, ans=-1;
        while(s <= e){
            mid = s + (e-s)/2;
            if(nums[mid] == k){
                ans = mid;
                e = mid-1;
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

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int n = nums.size();
        int f = firstOccr(nums, n, target);
        int l = lastOccr(nums, n, target);
        res.push_back(f);
        res.push_back(l);
        return res;
    }

int main(){
    vector<int> arr = {5,7,7,8,8,10};
    vector<int> show = searchRange(arr, 8);
    for(int elm : show){
        cout << elm << " ";
    }

    return 0;
}