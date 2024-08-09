#include<iostream>
using namespace std;

/*
algo: we have to convert given str to lexicographically smallest [dictionary mai maxm possible suru mai aana chahiye]
- find distance of each s[i] to 'a' from left and right direction.
- cover distance to 'a' if k is sufficient 
- if k isn't sufficient, then curr char se 'a' ki taraf k times move karo
*/
    string getSmallestString(string s, int k) {
        string ans="";
        int leftDist=0, rightDist=0;
        for(int i=0;i<s.size();i++){
            // find minm distance for each char
            leftDist = s[i] - 'a';
            rightDist = ('z'-s[i])+1;
            int minDist = min(leftDist, rightDist);
            // agar curr char ko 'a' bana sakte hai
            if(k >= minDist){
                k -= minDist;
                ans += 'a';
            }else{  // 'a' nai banasakte so curr char se 'a' ki taraf k times move karo [so that jitna 'a' ke close jaa sakte ho jawo]
                char ch = s[i]-k;
                ans += ch;
                k=0;
            }
        }
        return ans;
    }

    int main(){
        string str = "xaxcd"; // dry run
        int k = 5;
        cout << getSmallestString(str, k);

        return 0;
    }