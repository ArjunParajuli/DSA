#include<iostream>
#include<vector>
using namespace std;

// space O(2^n)
int recFib(int n){
    if(n<=1) return n;
    return recFib(n-2)+recFib(n-1);
}

int fib(int n){
    if(n<=1) return n;
    int a=0, b=1;
    int c=-1;
    for(int i=0;i<n-2;i++){
        c = a+b;
        a = b;
        b = c;
    }
    return c;
}

int main(){
    cout << recFib(4);

    return 0;
}