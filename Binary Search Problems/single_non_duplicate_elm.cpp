#include<bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return arr[0];
        else if(arr[0] != arr[1]) return arr[0];
        else if(arr[n-1] != arr[n-2]) return arr[n-1];

        int s = 1, e = n-2;
        while(s <= e){
            int mid = s + (e-s)/2;

             //if arr[mid] is the single element:
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) 
            return arr[mid];
        
            // if mid is at odd index and a[mid]==a[mid+1], then we have to go to left side and other case is ....
            // we have to go left eg: {3,3,10,11,11,12,12,13,13} or {1,1,2,2,3,4,4,8,8,9,9}
            if( ((mid%2==1) && (arr[mid] == arr[mid+1])) || ( (mid%2==0) && (arr[mid] == arr[mid-1]) ))
                e = mid-1;
            else    
                s = mid+1;
        } 
        return -1;
    }

int main(){
    vector<int> arr={3,3,10,11,11,12,12,13,13};
    cout << singleNonDuplicate(arr);

    return 0;
}