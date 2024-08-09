#include<iostream>
#include<stack>
using namespace std;

bool findRedundantBrackets(string &str)
{
    stack<char> s;
   for(int i=0;i<str.size();i++){
       char ch = str[i];
       if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            s.push(ch);
       else if(ch == ')'){
           int opCount = 0;
            // count ooperators between the brackets
           while(!s.empty() && s.top() != '('){
               char temp = s.top();
               if(temp == '+' || temp == '-' || temp == '*' || temp == '/')
                    opCount++;
                s.pop();
           }
           // pop the closing bracket ')'
           s.pop();
           // agar bracket k bich hai operator nahi hai then opCount=0 i.e redundant bracket
           if(opCount == 0)
                return true;        
       } 
   }
   // yaha tak pohoche matlab har brackets k andar operator tha so not redundant
    return false;
}


int main(){
    string str = "(a+c*b)+(c))";
    if(findRedundantBrackets(str)) 
        cout << "Redundant";
        else 
        cout << "Not Redundant";

    return 0;
}