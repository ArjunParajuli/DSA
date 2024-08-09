#include<iostream>
#include<vector>
using namespace std;

/*
Time Complexity: O(N * log(sum(weights[]) – max(weights[]) + 1))
search space : start with max elm in array, end at sum of all elm in array
algo:
- take mid as least weight and check if this mid gives currDays <= days, if yes it might be ans, so store and check for left half as mid
- else check for right half as mid

*/

 int findMax(vector<int>& weights){
        int maxm = INT_MIN;
        for(int itr : weights){
            maxm = max(maxm, itr);
        }
        return maxm;
    }

    int findSum(vector<int>& weights){
        int sum = 0;
        for(int itr : weights){
            sum += itr;
        }
        return sum;
    }

    int checkCurrentDays(vector<int>& weights, int currweight){
        int currDays = 0, currsum = 0, i=0;
        while(i<weights.size()){
            if(currsum+weights[i] <= currweight){
                currsum += weights[i];
            }else{
                currDays++;
                currsum = weights[i];
            }
            i++;
        }
        currDays++;
        return currDays;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int start = findMax(weights);
        int end = findSum(weights);
        int ans = -1;
        while(start <= end){
            int mid = start + (end-start)/2;
            // returns number of days for current mid as weight
            int currDays = checkCurrentDays(weights, mid);
            // if number of days match then it mid be ans
            if(currDays <= days){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }


int main(){
    vector<int> arr = {3,2,2,4,1,4};
    cout << shipWithinDays(arr, 3);

    return 0;
}