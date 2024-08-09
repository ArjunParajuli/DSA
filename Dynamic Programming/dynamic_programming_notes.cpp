#include<bits/stdc++.h>
using namespace std;

/*

- Dynamic programming is a technique that breaks the problems into sub-problems & saves the result for future purposes so that we dont need to compute the result again.
- It is basically an optimization over recursion.(eg: harek recursive call ka ans store karlo so that firse wo recursive call karte waqt uska ans bina compute karey pata chal jaye)
- agar same problem ko baar baar solve karna padra ho then DP is the soln
- Principle of DP: ek baar jo problem karli usko dobara solve nai karunga bcoz uska ans store kar rakha hai

Q) In which type of problems should we apply DP?
->  problems containing:
- overlapping subproblem [same problem ko baar baar calculate karre ho]
- optimal substructure [jab ek badi problem ka optimal soln depend karra hai on same type of choti problems ka optimal soln]

Types of DP:
- top down approach [recursion + memoization] - recursive approach [slower than bottom up bcoz of function call overhead here]
- bottom up approach [tabulation method] - iterative approach  [faster than top down bcoz of no function call overhead here]


i.Top down [memoization] steps:
1. create dp array
2. if ans already present in dp arr, return it
3. else store ans in dp array and return it

ii.Bottom Up [tabulation] steps:  [can be used if we know some initial data]
1. create dp array
2. analyze base case and fill initial data [can get data accn to base case] 
3. fill remaining array using recursive logic[replace recursive call with dp array]

iii.space optimization:
-> check if dp[i] depends on some pattern then we can make changes accordingly to optimise space by replacing array with some vairables.


Q) How to identify if 1d or 2d or 3d dp should be used?
-> jitne parameters change horahe hai, wohi number ka dp should be used. 


*/


// 1. using recursion  (exponential time of O(2^n))
int fib(int n) {
    if( n==0 ) return 0;
    if( n==1 ) return 1;

    return fib(n-2)+fib(n-1);
}

// 2. using rec+memoization [O(n) time bcoz only n+1 calls made here]
/*
algo:
1. create dp array of size n+1 bcoz f(0) se f(n) tak ka store hoga.
2. if ans already present in dp arr, return it
3. else store ans in dp array and return it
*/

int solve(int n, vector<int> &dp){
    if( n==0 ) return 0;
    if( n==1 ) return 1;

    // 2. if already present
    if(dp[n] != -1){
        return dp[n];
    }

    // 3. else store and return 
    dp[n] = solve(n-2, dp)+solve(n-1, dp);
    return dp[n];
}

int fibUsingMemoization(int n){
    // 1. create dp array
    vector<int> dp(n+1, -1);

    int ans = solve(n, dp);
    return ans;
}


// 3. Using bottom-up approach (tabulation i.e iterative)

int fibUsingTabulation(int n){
    // 1. create arr
    vector<int> dp(n+1, -1);
    // 2. analyze & fill initial spaces
    dp[0] = 0;
    if(n==0) return dp[0];  // for n=0 case  
    dp[1] = 1;
    // 3. fill remaining arr
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}

// 4. space optimized [as we observe, we only need previous two values to solve our problem and we dont need the whole dp array]

int fibUSpaceOptimized(int n){
   int ans=0;
    int prev = 0;
    if(n==0) return 0;  // for n=0 case  
    int curr = 1;
    if(n==1) return 1; // for n=1
    
    for(int i=2;i<=n;i++){
        ans = prev+curr;
        prev = curr;
        curr = ans;
    }
    return ans;
}


int main(){
    cout << fibUsingMemoization(4);

    return 0;
}