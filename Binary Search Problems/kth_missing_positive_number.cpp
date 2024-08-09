#include<iostream>
#include<vector>
using namespace std;

// brute force
//  int findKthPositive(vector<int>& arr, int k) {
//         for(int i=0;i<arr.size();i++){
//             if(arr[i] <= k){
//                 k++;
//             }else
//             break;
//         }
//         return k;
//     }

int findKthPositive(vector<int>& arr, int k) {
       
}

int main(){
    vector<int> arr = {2,3,4,7,11};
    cout << findKthPositive(arr, 5);

    return 0;
}