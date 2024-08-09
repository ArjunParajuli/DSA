#include <iostream>
using namespace std;

// YT - codestorywithMIK

// time O(n^2)
 void flip(string &s){
        int i = s.size()-1;
        while(i >= 0 && s[i] != '0'){
            s[i] = '0';
            i--;
        }

        if(i < 0){
            s = '1'+s;
        }else{
            s[i] = '1'; 
        }
    }

    int numSteps(string s) {
        int op=0;
        while(s.size() > 1){
            int n = s.size();
            if(s[n-1] == '1'){
                flip(s);
            }else{
                s.pop_back();
            }
            op++;
        }
        return op++;
    }


    // time: O(n)
    /*
    even = 1 opr
    odd = 2 opr
    
    */

   int numSteps(string s) {
        int op=0, carry=0;
        int n = s.size();
        for(int i=n-1;i>=1;i--){
            if( ((s[i]-'0')+carry) % 2 == 1 ){
                op += 2;
                carry=1;
            }else{
                op += 1;
            }
        }
        return op+carry;
    }