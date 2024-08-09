

#include <iostream>
#include<cmath>
using namespace std;

int decimalToBinary(int n){
    int ans = 0;
    int i=0;
    while(n > 0){
        int rem = n % 2;
        ans = ans + rem * pow(10, i++);
        n /= 2;
    }
    return ans;
}

int decimalToBinaryUsingLogicalOptr(int n){
    int ans = 0;
    int i=0;
    while(n > 0){
        // & of each bit (1010 & 0001)
        int lastBit = n & 1;
        ans = ans + lastBit * pow(10, i++);
        n = n >> 1; // right shifting once means dividing by 2 & left shifting means multiply by 2
    }
    return ans;
}


int main()
{
    cout << decimalToBinaryUsingLogicalOptr(10);
    

    return 0;
}
