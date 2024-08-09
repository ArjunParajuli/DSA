#include <iostream>
#include<vector>
using namespace std;

/*
- either mid is at left part of peak
- or at right part of peak
- accn to that ans is calculated.
*/

int findPeakElement(vector<int>& a) {
        int n = a.size();
        if(n == 1) return 0;
        else if(a[0] > a[1]) return 0;
        else if(a[n-1] > a[n-2]) return n-1;
        // handled edge cases so start from second elm to secondlast elm to avoid segmentation fault
        int s = 1, e = n-2;
        while(s <= e){
            int m = s + (e-s)/2;
            // peak found
            if( (a[m] > a[m-1]) && (a[m] > a[m+1]) )
                return m;
            // peak is at right half(bcoz mid is greater than left elm but smaller than right elm)
            else if( (a[m] > a[m-1]) && (a[m] < a[m+1]) )
                s = m+1;
            // peak is at left half
            else 
                e = m-1;
        }
        return -1;
    }

int main(){
    vector<int> arr = {1,2,1,3,5,6,4};
    cout << findPeakElement(arr);

    return 0;
}