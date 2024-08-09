#include <iostream>
using namespace std;

 bool isIsomorphic(string s, string t) {
       int hash[256] = {0};  // for mapping
       bool isMapped[256] = {0}; // for checking if the char is already mapped 
       
       // store t's chars s's chars  
       for(int i=0;i<s.size();i++){
           if(hash[s[i]] == 0 && isMapped[t[i]] == 0){      // to tackle cases like s=badc and t=baba
                hash[s[i]] = t[i];  // map 
                isMapped[t[i]] = true;  // mark mapped 
           }
       }
        // check for match
       for(int i=0;i<s.size();i++){
           if(char(hash[s[i]]) != t[i])
                return false;
       }
       return true;
    }

int main(){

    cout << isIsomorphic("egg", "add");

    return 0;
}