#include<iostream>
#include<stack>
using namespace std;

int countRev (string s)
{
    // insert all parenthesis except when valid parenthesis(eg: {}) occur, remove them from stack
    if(s.size()%2 != 0) return -1;
    stack<char> st;
    for(int i=0;i<s.size();i++){
        char ch = s[i];
        if(ch == '{')
            st.push(ch);
        else{
            if(!st.empty() && st.top()=='{')
                st.pop();
            else
                st.push(ch);
        }
    }
    // after removing all valid parenthesis, we are left with all invalid parenthesis( {{ or }{ or }} )
    int cnt = 0;
    while(!st.empty()){
        char ch1 = st.top();
        st.pop(); 
        char ch2 = st.top();
        st.pop();
        // if ( '{{' or '}}' ) found in stack increment one
        if(ch1 == ch2){
            cnt++;
        }else{ // ( '}{' ) found so increment two
            cnt += 2;
        }
    }
    return cnt;
}

int main(){

    cout << countRev("}{{}}{{{");
 
    return 0;
}