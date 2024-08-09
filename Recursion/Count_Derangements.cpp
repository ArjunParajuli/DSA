#include<iostream>
using namespace std;

/*
Q)A Derangement is a permutation of n elements, such that no element appears in its original position.
algo:
i) ek baar first elm and koi ek elm ko swap kardo then baki elms k liye f(n-2) ways hogi
ii) and ek baar sirf first elm ko koi ek elm ki jagah fix kardo then remaining n-1 elm k liye f(n-1) ways hongi 
- multiply by n-1 bcoz har ek elm k liye n-1 choices hai

Easy explanation:
- 1st case: ham ek elm k liye solve karenge i.e. (n-1) ways when that elm is swapped with some particular elm and f(n-2) call for remn n-2 elms [baki recursion karega]
- 2nd case: when an elm can go in any of the (n-1) spaces, so (n-1) ways for that elm and f(n-1) call for remn (n-1) elms

Time Complexity: O(2^n)
Auxiliary Space: O(h) where h= log n is the maximum height of the tree
*/
int countDerangements(int n) {
    if(n==1) return 0;
    if(n==2) return 1;

    // ya toh first case ya toh second case
    int ans = (n-1)*countDerangements(n-2) + (n-1)*countDerangements(n-1) ;
    return ans;
}

int main(){
    cout << countDerangements(4);

    return 0;
}