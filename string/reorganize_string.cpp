#include<bits/stdc++.h>
using namespace std;

/*
algo:
- first store all chars with their frequency
- now place the highest occuring char on 0th, 2nd, 4th index and so on
- finally place all the other remaining characters in the remaining place 
*/

 string reorganizeString(string s) {
      int  hash[26] = {0};
      // store frequency of each char
      for(int i=0;i<s.size();i++){
          hash[s[i]-'a']++;
      }
      int max_occr = INT_MIN;
      char max_occr_elm;
      // find max frequency
      for(int i=0;i<26;i++){
          if(hash[i] > max_occr){
              max_occr = hash[i];
              max_occr_elm = i+'a'; 
          }
      }
      int index=0;
      int len = hash[max_occr_elm-'a'];
      // place max occr elm in alternate indexes
      while(index<s.size() && len > 0){
          s[index] = max_occr_elm;
          len--;
          index += 2;
      }
      // if max occr char still remains, then no ans possible
      if(len != 0){
          return "";
      }
      // reset max occr elm frequency from hashmap
      hash[max_occr_elm-'a']=0;
      // place rest of the elms
      for(int i=0;i<26;i++){
          while(hash[i] > 0){
              // index reposition
              index = (index >= s.size()) ? 1 : index;
              s[index] = i+'a';  // insert char
              hash[i]--;
              index += 2;
          }
      }
      return s;
    }

int main(){
    cout << reorganizeString("aaabb");

    return 0;
}