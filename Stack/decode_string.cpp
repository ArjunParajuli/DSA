#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

string decodeString(string s) {
       stack<string> st;
       string ans = "";
       for(auto ch : s){
           if(ch == ']'){
               // take out all elements to be repeated
               string toRepeat="";
               while(!st.empty() && st.top() != "["){
                   toRepeat += st.top();
                   st.pop(); 
               }
               // take out opening bracket
               st.pop();
               // take out number
               string numStr = "";
               // incase multiple digit number
               while(!st.empty() && isdigit(st.top()[0])){
                   numStr += st.top();
                   st.pop();
               }
               reverse(numStr.begin(), numStr.end());
               int num = stoi(numStr);
               // push string to stack
               string strToPush = "";
                while(num){
                    strToPush += toRepeat;
                    num--; 
                }
                st.push(strToPush);
                }else{
           // convert char to string before pushing into stack
           string str = "";
           str += ch;
           st.push(str); 
       }
       }
       // take out answer string from stack
       while(!st.empty()){
           ans += st.top();
           st.pop();
       }
       reverse(ans.begin(), ans.end());
       return ans;
    }

int main(){
    cout << decodeString("3[a2[bc]]");
 
    return 0;
}