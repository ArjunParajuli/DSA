 #include <iostream>
#include <string>
#include<vector>
using namespace std;
 
 int peakIndexInMountainArray(vector<int>& arr) {
        int s = 0;
        int e = arr.size()-1;
        int mid = s + (e-s)/2;
        while(s <= e){
            mid = s + (e-s)/2;
            if(arr[mid] < arr[mid+1])
                s = mid+1;
            else if(arr[mid] < arr[mid-1])
                e = mid-1;
            else
                break;
        }
        return mid;
    }

     int main(){
         vector<int> A = {10, 15, 50, 20} ;
        cout << peakIndexInMountainArray(A);

        return 0;
    }