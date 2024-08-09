#include<iostream> 
#include<vector>
#include<string>
using namespace std;

// striver
// time : O(2^n) bcoz for every index, we have two options
// space : O(2^n)
/*
 for every index elm, we once take it and once don't take it
*/

void allSubSequences(int i, int n, string &str, string temp, vector<string> &ans){
    if(i==n){
        if(temp != "")
            ans.push_back(temp);
        return;
    }
    // take curr elm
    temp.push_back(str[i]);
    allSubSequences(i+1, n, str, temp, ans);
    // don't take curr elm
    temp.pop_back();
    allSubSequences(i+1, n, str, temp, ans);
}

vector<string> subsequences(string str){
	vector<string> ans;
    int i=0, n=str.size();
    string temp="";
    allSubSequences(i, n, str, temp, ans);
    return ans;
}

int main(){
    vector<string> ans;
    ans = subsequences("bbb");
    for(auto itr:ans){
        cout << itr << " ";
    }

    return 0;
}