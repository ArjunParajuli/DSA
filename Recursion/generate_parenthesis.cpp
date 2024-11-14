#include<iostream>
#include<vector>
using namespace std;

// watch yt- aditya verma and neetcode for explanation

/*
algo:
- maintain count of open and close parenthesis
- add open parenthesis only if open < n
- we're allowed to add closing parenthesis only if count of open > count of close (to form valid parenthesis)
- at each call, we can make two calls, add open or add close if valid conditions are met.
*/

    void generateParenthesis(vector<string> &ans,  string temp, int open, int close, int n){
        if(open == n && close == n){
            ans.push_back(temp);
            return;
        }
        if(open != n){
            //string temp1 = temp;
            temp.push_back('(');
            generateParenthesis(ans, temp, open+1, close, n);
            temp.pop_back();
        }
        if(open > close){
            //string temp2 = temp;
            temp.push_back(')');
            generateParenthesis(ans, temp, open, close+1, n);
            temp.pop_back();
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
        int open=0, close=0;
        vector<string> ans;
        string temp = "";
        generateParenthesis(ans, temp, open, close, n);
        return ans;
    }

int main(){
    vector<string> ans;
    ans = generateParenthesis(3);
    for(auto itr:ans){
        cout << itr << endl;
    }

    return 0;
}