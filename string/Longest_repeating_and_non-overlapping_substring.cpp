#include <iostream>
using namespace std;

/*
using two pointer :
- find substring from start and check if it is found, if yes update ans substring
time: close to O(n^3), space: O(n^2)

Node: find() function returns the position of the first occurrence of the substring within the string. 
    If the substring is not found, it returns a special constant value std::string::npos.
*/

string longestSubstring(string s, int n) {
      string max_substr = "-1";
      int maxlen = 0, i=0, j=0;
      while(i<n || j<n){
          string sub_str = s.substr(i, j-i+1); // current substring from ith index
          // substring found 
          if(s.find(sub_str, j+1) != string::npos){ // check from j+1 posn bcoz ques says non-overlapping
              int currlen = j-i+1;
              // curr substr is longer than max substr
              if(currlen > maxlen){
                max_substr = sub_str;
                maxlen = currlen;
              }
              // if not longer then just include one more character and search
              j++;
          }else{ // substring not found, so check from next index 
              i++;
          }
          // i and j are the first and last index of substr so first index can't exceed last index
          if(i > j)
            j=i;
      }
      return max_substr;
    }