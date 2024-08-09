#include<bits/stdc++.h>
using namespace std;

/*
algo:
- searching string ko map mai dalo
- maintain another map for curr window elms freq to be stored
- check if they match and continue
*/

int search(string pat, string txt) {
    // store freq
	    vector<int> hashpat(26, 0);
	    for(char c : pat)
	        hashpat[c-'a']++;
	    
	    int k = pat.size();
        int i=0, j=0, ans=0;
        vector<int> hashtxt(26, 0);

        while(j < txt.size()){
            // maintain size
            if(j-i+1 < k){
                hashtxt[txt[j]-'a']++;  // increment count
                j++;
            }else if(j-i+1 == k){  // size hit
                hashtxt[txt[j]-'a']++;  // increment count
                if(hashpat == hashtxt){ // check if curr window freq matches pattern freq
                    ans++;
                }
                
                // before sliding window, fix next window
                hashtxt[txt[i]-'a']--;
                i++, j++;                
            }
        }
        return ans;

	}