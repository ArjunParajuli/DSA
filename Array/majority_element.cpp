 #include <iostream>
 #include <vector>
using namespace std;

// we can use hashing to store count of all elms 
// or sort the array and return arr[n/2] elm bcoz the majority occuring elm occurs more than n/2 times

// optimal approach
/*
Moore’s Voting Algorithm:
- select first elm as possibleAns, check for subsequent elms if same as possibleAns increment count else decrement count
- if count becomes 0 then it won't be our ans bcoz ans must occur more than n/2 times, so count will never be zero for correct ans
*/ 
int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int possibleAns = nums[0];
        int i=1, count = 1;
       while(i<n){
           if(nums[i] == possibleAns){
               count++;
           }else{
               count--;
           }
           if(count == 0){
               if(i<n)
                i++;
               possibleAns = nums[i];
               count = 0;
           }else{
               i++;
           }
       }
       return possibleAns;

    //checking if the stored element is the majority element:(optional part just for checking)
    // int cnt1 = 0;
    // for (int i = 0; i < n; i++) {
    //     if (v[i] == el) cnt1++;
    // }

    // if (cnt1 > (n / 2)) return el;
    // return -1;

    }


int main(){
    vector<int> arr = {2,2,1,1,1,2,2}; 
    cout << majorityElement(arr);

    return 0;
}