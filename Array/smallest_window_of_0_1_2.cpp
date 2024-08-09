#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// algo:
// 1 - update indexValue of each 0 1 2 accn to current index
// 2 - if all indexvalues found, calculate length of current window
// 3 - return min window length

int smallestWindow(string s){
    int zeroInd=-1, oneInd=-1, twoInd=-1;
    int minLen = INT_MAX;
    for(int i=0;i<s.size();i++){
        char ch = s[i];
        // update index value
        if( ch == '0' ){
               zeroInd = i;
           }else if( ch == '1' ){
               oneInd = i;
           }else if( ch == '2' ){
               twoInd = i;
           }

        // find length
       if(zeroInd!=-1 && oneInd!=-1 && twoInd!=-1){
               int minm = min(zeroInd, min(oneInd, twoInd));
                int maxm = max(zeroInd, max(oneInd, twoInd));
                minLen = min(minLen, maxm-minm+1);
           }  
       }
       if(zeroInd==-1 || oneInd==-1 || twoInd==-1)
        return -1;
       return minLen;
    }


int main(){
    cout << "Length of smallest window is " << smallestWindow("01212");

    return 0;
}