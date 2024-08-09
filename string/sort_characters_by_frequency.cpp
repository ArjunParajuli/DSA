#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
- Counting Frequency: Iterate through the input string s and count the frequency of each character using a std::map<char, int> charFrequency.
- Convert to Vector: Convert the map to a vector of pairs (std::vector<std::pair<char, int>> charFrequencyVector) for easy sorting.
- Sorting: Sort the vector based on the frequency of characters in descending order using the static compare function.
- Construct Sorted String: Iterate through the sorted vector and construct the sorted string by appending characters based on their frequencies.
*/

 static bool cmp(pair<char, int> a, pair<char, int> b){
        return a.second > b.second;
    }

    string frequencySort(string s) {
        string ans="";
        map<char, int> mp;
        for (char ch : s) {
            mp[ch]++;
        }
        vector<pair<char, int>> hash(mp.begin(), mp.end());
          sort(hash.begin(), hash.end(), cmp);
            for(auto itr : hash){
                ans += string(itr.second, itr.first);
            }
            return ans;
    }

int main(){
    cout << frequencySort("tree");

    return 0;
}