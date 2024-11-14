#include<bits/stdc++.h>
using namespace std;

string infixToPostfix(string s) {
        unordered_map<char, int> pr;
        pr['-']=1;
        pr['+']=1;
        pr['*']=2;
        pr['/']=2;
        pr['^']=3;
        pr['(']=-1;
        string ans="";
        stack<char> st;
        for(int i=0;i<s.size();i++){
            // If the scanned character is an operand, add it to output.
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
                ans += s[i];
                 // If the scanned character is an ‘(‘, push it to the stack.
            }else if(s[i]=='(') st.push(s[i]);
            else if(st.empty()) st.push(s[i]);
              // If the scanned character is an ‘)’, pop and output from the stack until an ‘(‘ is encountered.
            else if(s[i]==')') {
                while(!st.empty() && st.top() != '('){
                       char top = st.top();
                        st.pop();
                        ans += top;  
                    }
                    st.pop();
                }else{
                        while(!st.empty() && pr[s[i]] <= pr[st.top()]){
                            char top = st.top();
                            st.pop();
                            ans += top;
                        }
                        st.push(s[i]);
                }
        }
         while(!st.empty()){
                ans += st.top();
                st.pop();
            }
        return ans;
    }


/*   Reverse String
   * Replace ( with ) and vice versa
   * Get Postfix
   * Reverse Postfix  *  */
string infixToPrefix(string infix) {
  int l = infix.size();

  // Reverse infix
  reverse(infix.begin(), infix.end());

  // Replace ( with ) and vice versa
  for (int i = 0; i < l; i++) {
    if (infix[i] == '(') {
      infix[i] = ')';
      i++;
    } else if (infix[i] == ')') {
      infix[i] = '(';
      i++;
    }
  }

  string prefix = infixToPostfix(infix);

  // Reverse postfix
  reverse(prefix.begin(), prefix.end());

  return prefix;
}

// postfix to infix
/*
insert operands in stack
whenever operator found pop from stack and put the operator in betn them and again push it in stack

time: O(n) + O(n) [for string concatenation]

*/
string postToInfix(string s) {
        stack<string> st;
        for(int i=0;i<s.size();i++){
            if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9'){
                string ch = "";
                ch += s[i];
                st.push(ch);
            }else{
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                st.push("("+op2+s[i]+op1+")");
            }
        }
        return st.top();
    }

// same as post to infix, here just traverse from last index
// time: O(n) + O(n) [for string concatenation] for worst case
    string preToInfix(string s) {
        stack<string> st;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9'){
                string ch = "";
                st.push(ch+s[i]);
            }else{
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                string t = "("+op1+s[i]+op2+")";
                st.push(t);
            }
        }
        return st.top();
    }

// postfix to prefix
    string postToPre(string s) {
        stack<string> st;
        for(int i=0;i<s.size();i++){
            if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9'){
                string ch = "";
                st.push(ch+s[i]);
            }else{
                string operand1 = st.top();
                st.pop();
                string operand2 = st.top();
                st.pop();
                st.push(s[i]+operand2+operand1);
            }
        }
        return st.top();
    }

// prefix to postfix
string preToPost(string s) {
         stack<string> st;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9'){
                string ch = "";
                st.push(ch+s[i]);
            }else{
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                string t = op1+op2+s[i];
                st.push(t);
            }
        }
        return st.top();
    }



int main(){
    string s = ("(p+q)*(c-d)");
    cout << "Infix expression: " << s << endl;
    cout << "Prefix Expression: " << infixToPostfix(s) << endl;

    return 0;
}