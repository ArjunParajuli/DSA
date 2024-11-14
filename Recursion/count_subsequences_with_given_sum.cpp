#include<iostream> 
#include<vector>
using namespace std;

// striver
// time : O(2^n) bcoz for every index, we have two options
// space : O(n)
/*
 for every idx elm, we once take it and once don't take it
*/


int f(int i, int n, int a[], int k, int sum) {
    if (i == n) {
        // sum matches
        if (k == sum) {
            return 1;
        }
        // sum doesn't match
        return 0;
    }
    // take
    sum += a[i];
    int ans1 = f(i + 1, n, a, k, sum); // count all sums from left call

    // don't take
    sum -= a[i];
    int ans2 = f(i + 1, n, a, k, sum); // count all sums from right call
    return ans1+ans2;
}

int main() {
    int a[] = {1, 2, 3};
    int n = 3;
    int k = 3;
    int sum = 0;
    cout << f(0, n, a, k, sum);

    return 0;
}
