#include<iostream>
#include<vector>
using namespace std;

// lower bound of elm x is the smallest index where (arr[index] >= x)

int lowerBound(vector<int> arr, int n, int x) {
	int s = 0, e = n-1, ans=n;
	while(s<=e){
		int m = s+(e-s)/2;
        if (arr[m] >= x) {
            e = m-1;
			ans = m;
		}else 
            s = m + 1;
        }
	return ans;
}

// upperbound of x is the smallest index where (arr[index] > x)

int upperBound(vector<int> &arr, int x, int n){
	int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}


int main(){

    return 0;
}