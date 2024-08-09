#include<iostream>
using namespace std;

long long power(long long x, long long n){
        if(n==0)return 1;
        long long temp = power(x, n/2);
        if(n%2==0)
            return (temp*temp)%1000000007;
        else 
            return (temp*temp*x)%1000000007;
    }
    
    int countGoodNumbers(long long n) {
        long long int even = (n+1)/2, odd = n/2;
        int ans = (power(5, even) * power(4, odd))%1000000007;
        return ans;
    }

int main(){
    cout << countGoodNumbers(10);

    return 0;
}