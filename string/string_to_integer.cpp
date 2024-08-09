#include <bits/stdc++.h>
using namespace std;

/*
(ans > INT_MAX / 10): This condition checks if multiplying the current result (ans) by 10 would exceed or equal INT_MAX. 
If true, it means that the next digit, when added, would cause an overflow.

(ans == INT_MAX / 10 && s[i] > '7'): This condition checks a specific case where the current result is equal to INT_MAX / 10, and 
the next digit is greater than '7'. In this scenario, adding the next digit would also result in an overflow. (Max val of int = 2147483647)

If either of these conditions is true, the function returns the maximum or minimum integer value (INT_MAX or INT_MIN) based on the sign
 (isNegative). This is a precautionary measure to handle cases where the input string represents an integer that is outside the valid range
  for a 32-bit signed integer. The value '7' is significant because the maximum value for the last digit in a 32-bit signed integer is '7'. 
  If the next digit is greater than '7', it would lead to overflow.
*/

 int myAtoi(string s) {
        int ans=0, isNegative=0;
        int i=0;

        // ignore leading whitespaces
        while(i<s.size() && s[i] == ' '){
            i++;
        }
        // determine sign
        while(i<s.size() && ( s[i]=='-' || s[i]=='+') ){
            // return 0 if sign occurs twice
            if( (s[i] == '-' && s[i+1] == '+') || (s[i] == '+' && s[i+1] == '-') ||
             (s[i] == '-' && s[i+1] == '-') || (s[i] == '+' && s[i+1] == '+') ){
                return 0;
            }else if(s[i] == '-'){
                isNegative = 1;
                i++;
            }else if(s[i] == '+'){
                i++;
            } 
        }
        // now convert to integer if char is digit only 
        while( (i < s.size()) && ( s[i]>=48 && s[i]<=57 ) ){
            // if ans goes out of range return max or min values
            if( (ans > INT_MAX/10) || (ans == INT_MAX/10 && s[i] > '7') ){
                return (isNegative == 1) ? INT_MIN : INT_MAX;
            }
            ans = (ans*10) + (s[i]-'0');
            i++;
        }
        ans = (isNegative == 1) ? ans*(-1) : ans*(1);
        return ans;
    }

    int main(){
        cout << myAtoi("  -56");

        return 0;
    }