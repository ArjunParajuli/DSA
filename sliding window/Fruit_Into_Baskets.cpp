#include<iostream>
#include<unordered_map>
using namespace std;

/* this ques can have diffn story scenarios also
algo: same as longest substr with k unique chars, here we use 2 as k bcoz 2 baskets are given in ques
*/

int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int i=0, j=0, maxlen=0;
        while(j < fruits.size()){
            mp[fruits[j]]++;
            if(mp.size() < 2){
                maxlen = max(maxlen, j-i+1);
                j++;
            }else if(mp.size() == 2){
                maxlen = max(maxlen, j-i+1);
                j++;
            }else if(mp.size() > 2){
                while(mp.size() > 2){
                    mp[fruits[i]]--;
                    if(mp[fruits[i]] == 0)
                        mp.erase(fruits[i]);
                    i++;
                }
                maxlen = max(maxlen, j-i+1);
                j++;
            }
        }
        return maxlen;
    }