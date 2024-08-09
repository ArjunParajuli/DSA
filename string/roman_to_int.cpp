#include<bits/stdc++.h>
using namespace std;

 int romanToInt(string s) {
// in Roman numerals, when a smaller value appears before a larger value, it represents subtraction, while when a smaller value appears after or equal to a larger value, it represents addition.
        int ans = 0;
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
         
        for(int i=0;i<s.size();i++){
           if(m[s[i]] < m[s[i+1]]){
               ans -= m[s[i]];
           }else{
               ans+= m[s[i]];
           }
        }
        return ans;
    }

int main(){
    
    cout<<romanToInt("MCMXCIV");

    return 0;
}