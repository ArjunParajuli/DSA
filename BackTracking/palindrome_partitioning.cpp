#include<iostream>
#include<vector>
#include<string>
using namespace std;
 

// striver 
// dry run for s="aabb"

 bool isPalindrome(string str, int s, int e){
        while(s<=e){
            if(str[s++] != str[e--])
                return false;
        }
        return true;
    }

    void solve(int i, string s, vector<string> &temp, vector<vector<string>> &ans){
        if(i == s.size()){
            ans.push_back(temp);
            return;
        }

        for(int j=i;j<s.size();j++){
            if(isPalindrome(s, i, j)){
                temp.push_back(s.substr(i, j-i+1));
                solve(j+1, s, temp, ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0, s, temp, ans);
        return ans;
    }

    int main(){
        vector<vector<string>> ans = partition("aabb");
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                cout << ans[i][j] << " "; 
            }
            cout << endl;
        }

        return 0;
    }