#include <iostream>
#include <string.h>
using namespace std;

// start i,j from all positions and expands checking further
    int countPalin(string s, int i, int j){
        int ans=0;
        // avoid index out of bounds 
        while(i>=0 && j<s.length() && s[i]==s[j]){
                ans++;
                i--;
                j++;
        }
        return ans;
    }

    int countSubstrings(string s) {
        int ans=0,j;
        for(int i=0;i<s.length();i++){
            // find total no. of odd length palindromes
            // gets all palindromes of odd length
            j=i;
            int oddPalindromes = countPalin(s, i, j);
            // find total no. of even length palindromes
            // gets all palindromes of even length
            j=i+1;
            int evenPalindromes = countPalin(s, i, j);
            ans = ans + oddPalindromes+evenPalindromes;
        }   
        return ans;
    }

int main(){
    string str = "aaa";
    cout << countSubstrings(str);

    return 0;
}