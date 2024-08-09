#include <bits/stdc++.h>
using namespace std;

// method 1
//  vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         // all anagram strings become same when sorted
// // use map to store key value pairs & here, key=sortedString and value=vector having all anagrm strings   
//     map<string, vector<string>> mp;
//     for(auto itr : strs){   
//             string currStr = itr;  // store each string in curr 
//             sort(currStr.begin(), currStr.end());  // sort it and store it as a key
//             mp[currStr].push_back(itr); // map sorted String with the original string
//         }
//     vector<vector<string>> ans;
//     for(auto itr : mp){
//         ans.push_back(itr.second);
//     }
//     return ans;
//     }

// better method just insted of key=string, we use key=hashArray.

 vector<int> hash(const string& str) {
    vector<int> hashVec(256, 0); // Initialize with 256 elements, all set to 0
    for (char c : str) {
        hashVec[c]++;
    }
    return hashVec;
}

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // all anagram strings become same when sorted
        // use map to store key value pairs & here, key=hashArr and value=vector having all anagrm strings   
    map<vector<int>, vector<string>> mp;
    for (auto itr : strs) {
        mp[hash(itr)].push_back(itr);
    }
    vector<vector<string>> ans;
    for(auto itr : mp){
        ans.push_back(itr.second);
    }
    return ans;
    }

    

int main(){

    return 0;
}