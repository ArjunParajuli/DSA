#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void recursiveAdd(string &num1, int i, string &num2, int j, int carry, string &ans){
        if(i<0 && j<0){
            if(carry != 0){
                ans += carry+'0';
            }
            return;
        }
        
        int n1 = ((i >= 0) ? num1[i] : '0') - '0';
        int n2 = ((j >= 0) ? num2[j] : '0') - '0';
        int sum = n1+n2+carry;
        int digit = sum%10;
        carry = sum/10;
        ans += digit+'0';
        recursiveAdd(num1, i-1, num2, j-1, carry, ans);
    }

    string addStrings(string num1, string num2) {
        string ans="";
        recursiveAdd(num1, num1.size()-1, num2, num2.size()-1, 0, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }

int main(){
    string num1 = "11", num2 = "123";
    cout << addStrings(num1, num2);
    
    return 0;
}
