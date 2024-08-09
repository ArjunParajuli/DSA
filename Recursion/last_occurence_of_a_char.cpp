#include<iostream>
#include<string>
using namespace std;

int lastOccur(string s, char c, int i, int ans){
    
    if( i >= s.size() )
        return ans;
    
    if(s[i] == c)
        ans = i;

    return lastOccur(s, c, i+1, ans);
}

int main(){
    cout << lastOccur("abcddefda", 'd', 0, -1);

    return 0;
}