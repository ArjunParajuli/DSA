#include<bits/stdc++.h>
using namespace std;

string convert(string s, int numRows) {
    if(numRows == 1)
        return s;

    string ans="";
    vector<string> v;
    // i will iterate thr s
    int i=0, row=0, direction=1;
    while(1){
        if(direction){ // direction=1 means go top to bottom
            while(row<numRows && i<s.size()){
                v[row++].push_back(s[i++]);
            }
            // direction = 0;
            row -= 2; // udate row to go botto, to top
        }else{ // direction 0
            while(row>=0 && i<s.size()){
                v[row--].push_back(s[i++]); // -- bcoz going one row upwards
            }
            // direction=1;
            row = 1;  // update row to 1st index bcoz oth index already filled
        }
        if(i>=s.size()){
            break;
        }
        direction = !direction;
    }
    for(int i=0;i<v.size();i++){
        ans += v[i];
    }
   return ans;

    }

int main(){
    cout << convert("PAYPALISHIRING", 4);

    return 0;
}