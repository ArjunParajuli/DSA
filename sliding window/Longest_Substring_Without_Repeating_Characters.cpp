#include<iostream>
#include<unordered_map>
using namespace std;

/* very similar to longest substr with k unique chars
algo:
- condition here will be curr char's count must be only one
- whenever curr char's count becomes > 1 then we decrease window size from begining until condition is satisfied again
*/


int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int i=0,j=0, maxlen = 0;
        while(j < s.size()){
            mp[s[j]]++;
            // curr char's count is 1, so store ans & just increase window size bcoz we want longest substr
            if(mp[s[j]] == 1){
                maxlen = max(maxlen, j-i+1);
                j++;
            }else if(mp[s[j]] > 1){ // curr char's count goes greater than 1, so decrease size until its count becomes 1
                while(mp[s[j]] > 1){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0)
                        mp.erase(mp[s[i]]);
                    i++;
                }
                // update maxlen after condition met
                maxlen = max(maxlen, j-i+1);
                j++;
            }
        }
        return maxlen;
    }

int main(){
    string str = "pwwkew";

    return 0;
}