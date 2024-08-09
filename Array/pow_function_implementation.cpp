#include<iostream>
using namespace std;

/*
- if x is -ve, we convert it to positive so we take long bcoz int range is -2^31 to 2^31-1 so converting -ve min val to +ve val will result in overflow.
- brute force: multiply x n times which takes O(n) time
- optimal: use binary exponentiation and steps are reduced to logarithmic order(log(exponent val) base 2)
i) sqr the base and half the exponent for all even exponents
ii) if exponent is odd, we save the extra base in result. eg: 2^5 then follow step i) and multiply extra 2 in result 
*/

 double myPow(double x, int n) {
        if(n == 0) 
            return 1.0;
        else if(n == 1) 
            return x; 

        int tempN = abs(n);
        double res = 1;
        while(tempN > 0){
            // power odd 
            if(tempN%2==1)
                res *= x;
            x = x*x;
            tempN = tempN/2;
        }
        if(n < 0)
            return 1/res;
        return res;
    }

int main(){
    cout << myPow(2.0, 10);

    return 0;
}