#include<iostream>
#include<vector>
using namespace std;

 vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // two pointer approach
        // start low=0, high=n-1
        // and shrink towards k elements nearest to x
        int low=0, high=arr.size()-1;
        while(high-low >= k){  // bcoz the ans subarray length should be equal to k
            if(x-arr[low] > arr[high]-x)
                low++;          // betn low and high elms, jiska difference high hai
                                // usko move towards elm close to x
            else
                high--;
        }
        return vector<int>(arr.begin()+low, arr.begin()+high+1);
    }


int main(){
    vector<int> arr = {1,2,3,4,5};
    vector<int> ans;
    ans= findClosestElements(arr, 2, 5);
    for(int it : ans)
        cout << it << " ";

    return 0;
}

