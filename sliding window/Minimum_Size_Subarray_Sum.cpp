#include<iostream>
#include<vector>
using namespace std;


/* variable size sliding window problem
algo:
- increase window size until condition met (condition is currsum must be >= target)
- once condition met, store curr length of window and try to minimize window 
*/

int minSubArrayLen(int target, vector<int>& nums) {
        int i=0, j=0, currsum=0, minlen = INT_MAX;
        while(j < nums.size()){
            currsum += nums[j];
            // increase window til condition met
            if(currsum < target){
                j++;
            }
            // condition met, 
            else if(currsum >= target){
                minlen = min(minlen, j-i+1);  // store
                // minimize ans (increment i till currsum becomes very close to target(i.e. <= target), )
                while(currsum > target){
                    // to counter cases like [1,2,3,4,5] & target=11
                    if(currsum-nums[i] >= target){ // if decrementing with ith elm makes currsum < target then don't decrement
                        currsum -= nums[i];
                        i++;
                    }else
                        break;
                }
                minlen = min(minlen, j-i+1);
                j++;
            }
        }
        return minlen==INT_MAX ? 0 : minlen;
    }

// my soln
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0, j=0;
        int sum = 0;
        int len = INT_MAX;
        while(j < nums.size()){
            sum += nums[j];

            if(sum < target){
                j++;
            }else if(sum == target){
                len = min(len, j-i+1);
                j++;
            }else{
                while(i <= j && sum > target){
                    len = min(len, j-i+1);
                    sum -= nums[i];
                    i++;
                }
                if(sum == target)
                    len = min(len, j-i+1);
                j++; 
            }
        }
        return len==INT_MAX ? 0 : len;
    }