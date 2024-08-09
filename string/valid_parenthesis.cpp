#include <bits/stdc++.h>
using namespace std;

 bool isValid(string s) {
        stack<char> st;
        // push all opening braces in stack
        for(int i=0;i<s.size();i++){
            if( ( s[i]=='(' ) || ( s[i]=='{' ) || ( s[i]=='[' ) )
                st.push(s[i]);
            else{
                // still valid so pop and continue
                char top = st.top();
                if( ( s[i]==')' && top=='(' ) || ( s[i]==']' && top=='[' ) || ( s[i]=='}' && top=='{' ) ){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        if(!st.empty())
            return false;

        return true;
    }

int main(){

    cout << isValid("()[]{}");

    return 0;
}