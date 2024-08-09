#include <bits/stdc++.h>
using namespace std;

// For uniqueElement, just XOR once




// int findDuplicate(vector<int> arr, int n){
//     int ans = 0;
//     for(int i=0;i<n;i++){       // first XOR all elements once
//         ans = ans ^ arr[i];
//     }                           // XOR of same elems gives 0 and XOR of 0 and anyElm gives anyElm

//     for(int i=1;i<n;i++){       // Again XOR but until n-1
//         ans = ans ^ i;
//     }
//     return ans;
// }

// another method
int findDuplicate(vector<int> arr, int n){
    while(arr[0] != arr[arr[0]]){
        swap(arr[0], arr[arr[0]]);
    }
    return arr[0];
}

int main(){
    vector<int> arr = {3,2,4,3,5,1};
    int n = arr.size();
    cout << findDuplicate(arr, n);

    return 0;
}