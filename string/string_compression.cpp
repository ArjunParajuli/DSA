#include<bits/stdc++.h>
using namespace std;

 int compress(vector<char>& chars) {
        int prev = 0, curr = 1;
        int i=0, len=1;
        while(curr<chars.size()){
            if(chars[curr] == chars[prev]){
                curr++;
                len++;
            }else{
                chars[i++]=chars[prev];
                if(len > 1){
                    int start = i;
                 while(len){
                    chars[i++] = (len%10)+'0';
                    len /= 10;
                }
                    reverse(chars.begin()+start, chars.begin()+i);
                }
                len=1;
                prev = curr;
                curr++;
            }
        }
        if(curr>=chars.size()){
            chars[i++] = chars[prev];
            if(len > 1){
                    int start = i;
                 while(len){
                    chars[i++] = (len%10)+'0';
                    len /= 10;
                }
                    reverse(chars.begin()+start, chars.begin()+i);
                }
        }

        return i;
    }

int main(){
    vector<char> chars = {'a', 'a', 'b', 'b'};
    cout << compress(chars);

    return 0;
}