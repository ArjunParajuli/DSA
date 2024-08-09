#include<iostream>
#include<unordered_map>
using namespace std;

/*
variable size window format:
while(j<n){
    // do something
    if(consition < k){
        j++;
    }else if(consition == k){
        store curr answer (potential answer)
        j++;
    }else if(consition > k){  this step is extra than fixed size bcoz window size can change
        // do something until condition is not greater than k
        j++;
    }
}

*/


/*
algo:
- here mp.size denotes num of unique characters(condition).
- increment window size till condition met, if condition is met, store curr window size
- if consition > k then we must remove one char from map so that no. uniq char becomes k again 
*/

int longestKSubstr(string s, int k) {
        unordered_map<int, int> mp;
        int i=0, j=0, cnt=-1;
        while(j < s.size()){
            mp[s[j]]++;
            if(mp.size() < k){ // increase window size
                j++;
            }else if(mp.size() == k){ // size found, store ans
                cnt = max(cnt, j-i+1);
                j++;
            }else if(mp.size() > k){  // remove one char from map
                while(mp.size() > k){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return cnt;
    }

    // My approach
    int longestKSubstr(string s, int k) {
        unordered_map<char, int> mp;
        int i=0;
        int maxlen = INT_MIN;
        for(int j=0;j<s.size();j++){
            mp[s[j]]++;
            
            while(mp.size() > k){
                mp[s[i]]--;
                if(mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }
            
            if(mp.size() == k){
                // cout << "Update at " << i << " " << j << endl;
                maxlen = max(maxlen, j-i+1);
                // cout << maxlen;
            }
        }
        return maxlen==INT_MIN ? -1 : maxlen;
    }