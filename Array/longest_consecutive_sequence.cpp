#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

/*

algo:
- store elms in set
- travers arr again & for each elm if it is the starting number of sequence, then find its sequence length
- update the maxlen 

time: O(n)
-> bcoz Even though the while loop can iterate up to n times, it does not do so for each element of nums. It only iterates for elements that are considered as
 the start of a sequence (i.e., elements for which num - 1 does not exist in the HashSet). Since the elements are examined only once and the while loop does not iterate for all elements,
  the overall time complexity remains linear, O(n).

*/

 int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        // store all elms
        for(auto num : nums)
            s.insert(num);
        
        int maxlen = 0;

        // traversal
        for(int i=0;i<nums.size();i++){
                int curr = nums[i];
                int currlen = 1;
            // if curr elm is starting sequence i.e. isse pehle wala elm present nai hai tabhi while loop chalega . so while loop sirf ek baar chalega eg: dry run for [0,3,7,2,5,8,4,6,0,1]
            if(s.find(curr-1) == s.end()){ 
                // curr sequence ka length calculate karo
                while(s.find(curr+1) != s.end()){
                    curr++;
                    currlen++;
                }
                // update maxm length
                maxlen = max(maxlen, currlen);
            }
        }
        return maxlen;
    }