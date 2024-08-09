#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) 
            return "";
      sort(strs.begin(), strs.end());
      int last = strs.size()-1;
      string ans="";
      for(int i=0;i<strs[0].size();i++){
          if(strs[0][i] == strs[last][i]){
              ans += strs[0][i];
          }else{
              break;
          }
      }
      return ans;
    }

    int main(){


        return 0;
    }