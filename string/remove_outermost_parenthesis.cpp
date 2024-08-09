#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

// brute force
 string removeOuterParenthesesBruteForse(string s) {
     stack<char> st;
     int n = s.size();
     string ans="";
     int openCount = 0, closeCount = 0;
     for(int i=0;i<n;i++){
         char ch = s[i];
         if(ch == '('){
            openCount++;
            st.push(ch); 
         }else{
             closeCount++;
             st.push(ch);
         }
         // when one part is completely inserted into the stack
        // then we remove its outermost parenthesis and reverse and add it to string
        // do this for eachh part
         if(openCount == closeCount){
             // remove first open bracket
             st.pop();
             string temp = "";
             while(!st.empty()){
                temp.push_back(st.top());
                st.pop();
             }
             // remove last close bracket
             temp.pop_back();
             reverse(temp.begin(), temp.end());
             // append it to string s
             ans += temp;
             openCount = 0;
             closeCount = 0;
         }
     }   
     return ans;
    }

    // optimal
    /*
    - maintain count, if '(' found increment count else decrement count
    - add the char into ans except for outer brackets
    */

      string removeOuterParentheses(string s) {
     int count = 0;
     string ans="";
     for(int i=0;i<s.size();i++){
         char ch = s[i];
         if(ch == '('){
             count++;
         }else{
             count--;
         }
         // if braces are outer opening and closing, don't add them to ans  
         if(count == 1 && ch == '(' || count == 0 && ch == ')'){
             continue;
         }else{
             ans+=ch;
         }
     }
     return ans;
    }

int main(){


    return 0;
}