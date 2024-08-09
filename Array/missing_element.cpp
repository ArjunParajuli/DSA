#include <iostream>
#include <Math.h>
using namespace std;

// for array [1, n] and an elm is occuring twice

int findMissing(int a[], int n){
    for(int i=0;i<n;i++){
        int index = abs(a[i])-1;
            a[index] *= -1;
    }
    for(int i=0;i<n;i++){
        if(a[i] > 0){
            return i;
        }
    }
    return -1;
}

// use for array of range [0, n]

//  int missingNumber(vector<int>& nums) {
//     // Storing XOR of all natural numbers upto n in a variable.
//     // Now taking XOR of elements in another variable.
//     // Take XOR of these two stored variables and return it.
//     // It works because if same_number ^ same_number = 0
//         int XORuptoN = 0, n = nums.size();
//         for(int i=1;i<=n;i++){
//             XORuptoN = XORuptoN ^ i; 
//         }
//         int XORofArrElms = nums[0];
//         for(int i=1;i<n;i++){
//             XORofArrElms = XORofArrElms ^ nums[i];
//         }
//         return (XORuptoN ^ XORofArrElms);
//     }

int main(){
    int nums[] = {1,3,5,3,4};
    cout << findMissing(nums, 5);

    return 0;
}