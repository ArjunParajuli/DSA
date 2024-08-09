#include <bits/stdc++.h>
using namespace std;

vector<string> findWords(vector<string>& words) {
        string r1 = "qwertyuiop";
        string r2 = "asdfghjkl";
        string r3 = "zxcvbnm";

        vector<string> ans;
        for(string word : words){
            vector<int> rowSum(3);
            for(char ch : word){
                ch = tolower(ch);
                if(r1.find(ch) != -1){
                    rowSum[0] = 1;
                }else if(r2.find(ch) != -1){
                    rowSum[1] = 1;
                }else if(r3.find(ch) != -1){
                    rowSum[2] = 1;
                }
            }
            int sum = rowSum[0] + rowSum[1] + rowSum[2];
            if(sum == 1){
                ans.push_back(word);
            }
        }
        return ans;
    }

int main(){
    vector<string> words = {"Hello","Alaska","Dad","Peace"};
    vector<string> ans;
    ans = findWords(words);
    for(auto itr : ans){
        cout << itr << " ";
    }

    return 0;
}