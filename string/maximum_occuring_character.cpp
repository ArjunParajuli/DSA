#include <iostream>
#include <string.h>
using namespace std;

 char getMaxOccuringChar(string str)
    {
        char arr[26] = {0}; // to store the frequency of each character
        // find no. of occurances of each character;
        int max = -1, ans = 0;
        for(int i=0;i<str.length();i++){
            char ch = str[i];
            int index = ch-'a';
            arr[index]++;
            if(max < arr[index]){
                max = arr[index];
                ans = index;
            }else if(max == arr[index]){  // when multiple chars have same freq, update ans with the lexicographically smaller char
                if(index < ans)
                    ans = index;
            }
        }
        return ans+'a';
    }


int main(){
    string str = "outputo";
    cout << getMaxOccuringChar(str);

    return 0;
}