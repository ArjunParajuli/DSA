// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// used the sliding window approach

 bool checkInclusion(string s1, string s2) {
        vector<int> h1(26, 0);
        vector<int> h2(26, 0);
        int r=0, l=0;
        if(s1.size()>s2.size())
            return false;
            // insert in both hashmaps
            // r points to the rightmost index of the window
            // l points to the leftmost index of the window
        while(r<s1.size()){
            h1[s1[r]-'a'] += 1; 
            h2[s2[r]-'a'] += 1;
            r+=1;
        }
        // r went a step ahead, so put it back to its rightmost index for the window
        r -= 1;
        while(r < s2.size()){
            if(h1 == h2)
                return true;
            
            // increment r before extending the window further ahead
                r+=1;
                // add char from right
                if(r != s2.size())
                    h2[s2[r]-'a'] += 1; 
                // remove char from left, so that window is maintained
                h2[s2[l]-'a'] -= 1;
                // increment left to extend window one step ahead
                l+=1;
        }
        return false;

    }

    int main(){
        cout << checkInclusion("ab", "eidba000");

        return 0;
    }