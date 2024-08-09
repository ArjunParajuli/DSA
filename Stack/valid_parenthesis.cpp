#include<iostream>
#include<stack>
using namespace std;

 bool isValid(string s) {
       if(s.size() == 1)
            return false;

        stack<char> st;
        
        for(int i=0;i<s.size();i++){
            if( ( s[i]=='(' ) || ( s[i]=='{' ) || ( s[i]=='[' ) )
                st.push(s[i]);
            else{
                if(st.empty()) return false;
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

    void printStack(stack<int> st){
        if(st.empty())
            return;
        
        int temp = st.top();
        st.pop();
        printStack(st);
        st.push(temp);
        cout << st.top() << " ";
    }



int main(){

    cout << isValid("}{{}");
 
    return 0;
}