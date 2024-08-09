#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

 string decodeMessage(string key, string message) {
        // mapArr will contain all alphabets
        char start='a';
        char mapArr[256] = {0};
        string ans;
        for(char ch : key){
            // if index ch in mapArr is empty
            if(ch != ' ' && mapArr[ch] == 0){   // mapArr[a] is same as mapArr[97];
                mapArr[ch] = start; // store 'a'
                start++;    // increment start to becomes 'b' and so on 
            }
        }
        for(char ch : message){
            if(ch == ' '){
                ans.push_back(' ');  // keep space as it is
            }else{
                 char decodedChar = mapArr[ch];
                ans.push_back(decodedChar);
            }
        }
        return ans;
    }

int main(){
    string key = "the quick brown fox jumps over the lazy dog", message = "vkbs bs t suepuv";
    cout << decodeMessage(key, message);

    return 0;
}