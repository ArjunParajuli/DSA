#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

void reverseStr(string &str, int start, int end){
    if(start >= end){
        return;
    }

    swap(str[start], str[end]);

    return reverseStr(str, start+1, end-1);

}

int main(){
    string str="abcde";
    int start = 0, end = str.size()-1; 
    reverseStr(str, start, end);
    cout << str;

    return 0;
}