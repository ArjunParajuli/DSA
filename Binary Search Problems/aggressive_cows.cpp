#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossibleSoln(int n, int k, vector<int> &stalls, int mid){
        // can we place k cows with atleast mid distance between them
        
        int cow = 1;
        int pos = stalls[0]; // place first cow in first index
        for(int i=1;i<n;i++){
            if(stalls[i] - pos >= mid){ // place first cow
                cow++;
                pos = stalls[i]; // one more cow has been placed
            }
            if(cow == k) // all cows placed
                return true;
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        int start = 0;
        int ans = -1;
        int end = stalls[n-1]-stalls[0];
        while(start <= end){
            int mid = start + (end-start)/2;
            if(isPossibleSoln(n, k, stalls, mid)){
                ans = mid;  // if possoble soln found, try to maximize the soln
                start = mid+1; // so check in right posn
            }else{
                end = mid-1; // else check in left posn
            }
        }
        return ans;
    }

    int main(){
        vector<int> stalls = {1, 2, 4, 8, 9};
        cout << solve(5, 3, stalls);

        return 0;
    }