#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// By definition of Sieve of Eratosthenes, for every prime number, it has to check the multiples of the prime and mark it as composite.
// refer gfg article for explanation of TC 

// TC: O(N*log(log(N))) 
void sieve (int n){
    vector<int> primes(n + 1, 1); // Initialize all to 1 (assuming all are primes initially)
    primes[0] = primes[1] = 0; // 0 and 1 are not primes

    for (int i = 2; i * i <= n; ++i) {
        if (primes[i] == 1) {
            for (int j = i * i; j <= n; j += i)
                primes[j] = 0; // Mark all multiples of i as non-prime
        }
    }
    
    for(int i=2;i<=n;i++)
        cout << i << ":- " << primes[i] << " " << endl;
} 

int main() {
    sieve(20);

    return 0;
}

// leetcode 3233
vector<int> sieve(int n) {
    vector<int> primes(n + 1, 1); // Initialize all to 1 (assuming all are primes initially)
    primes[0] = primes[1] = 0; // 0 and 1 are not primes

    for (int i = 2; i * i <= n; ++i) {
        if (primes[i] == 1) {
            for (int j = i * i; j <= n; j += i)
                primes[j] = 0; // Mark all multiples of i as non-prime
        }
    }

    // Calculate cumulative sum of primes
    for (int i = 1; i <= n; ++i) {
        primes[i] += primes[i - 1];
    }

    return primes;
}

int nonSpecialCount(int l, int r) {
    int sqrtl = sqrt(l);
    int sqrtr = sqrt(r);

    // Adjust sqrtl for cases where l is not a perfect square
    if ((sqrtl * sqrtl) != l) {
        sqrtl += 1;
    }

    vector<int> primes = sieve(sqrtr);
    int special = primes[sqrtr] - primes[sqrtl - 1];
    return (r - l + 1) - special;
}