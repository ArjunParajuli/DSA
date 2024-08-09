#include<iostream>
#include<stack>
using namespace std;

 void reverse(stack<string> &st, string &ans){
        if(st.empty())
            return;
        
        string str = st.top();
        st.pop();
        reverse(st, ans);
        ans += str;
    }
 
 // insert into stack only the valid path and pop out if any /.. if found in string
    string simplifyPath(string path) {
        stack<string> st;
        int i=0;
        int start, end; 
        while(i < path.size()){
            start = i;
            end = i+1;
            // move end till we get '/'
            while(end < path.size() && path[end] != '/')
                end++;
            // string to push into stack 
            string toPush = path.substr(start, end-start);
            i = end;
            if(toPush == "/" || toPush == "/.")
                continue;
            else if(toPush == "/.."){
                if(!st.empty())
                    st.pop();
            }else{
                st.push(toPush);
            }
        }
        if(st.empty())
            return "/";
        string ans = "";
        reverse(st, ans);
        return ans;
    }

int main(){
    
    cout << simplifyPath("/home//foo/");

    return 0;
}