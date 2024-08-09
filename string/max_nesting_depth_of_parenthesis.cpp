#include <iostream>
#include <bits/stdc++.h>
using namespace std;

 int maxDepth(string s) {
        int maxans=0, currans=0;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(ch == '('){
                currans++;
                maxans= max(maxans, currans);
            }else if(ch == ')'){
                    currans--;
                }
            }
        return maxans;
    }


int main(){

    return 0;
}