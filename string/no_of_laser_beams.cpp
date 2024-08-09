#include<bits/stdc++.h>
using namespace std;

// count the Number of Laser Beams in a Bank

// algo:
// store laser count of each row in a vector
//  then multiply to find total lasers
// eg: count- [3, 0, 2, 1]
// then 3*0+3*2+0*2+2*1=8 


int countLasers(string s){
    int cnt=0;
    for(auto ch : s){
        if(ch == 1+'0')
            cnt++;
    }
    return cnt;
}

int numberOfLasers(vector<string> v){
    vector<int> count;
    // pass each string to find laser count
    for(auto str : v){
        count.push_back(countLasers(str));
    }
    int noOfBeams=0;
    for(int i=0;i<count.size();i++){
        int j=i+1;
        while(j<count.size()){
            noOfBeams += count[i]*count[j];
            if(count[j] == 0){
                j++;
            }else{
                break;
            }
        }
    }
    return noOfBeams;
}

int main(){
    // 1 represents laser
    vector<string> bank = {"011001","000000","010100","001000"};
    cout << numberOfLasers(bank);

    return 0;
}