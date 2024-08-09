#include<iostream>
#include<vector>
using namespace std;

/*
YT- pepcoding for clear understanding
based on permutation and combination 
two cases can occur:
i. last k two adjacent posts have same color: will be same as previous 'n' ka diffn wala combinations bcoz hamey last mai 2 colors same chahiye so previous 'n'
    waley ka diffn wala combinations mai last wala character hi add kardenge. i.e [ current no. of ways with same last 2 color = prev diffn no.of ways ] 

ii. last k two adjacent posts have different color: isme previous 'n' ka total(same+diffn) combinations mai last color ke alawa baki sarey colors daldo ek ek baar
    kyuki last ke two colors diff karne hai. i.e [ current no. of ways with diffn last 2 color = prev total no.of ways * (k-1) ] 

Hence, same utilizes f(n-2) and diff utilizes f(n-1)
*/

// 1. recursion
long long countWays(int n, int k){
    // base cases
        if(n == 1) return k;
        if(n == 2) return k+(k*(k-1)); // dry run for n=2 pnc
        
        // same means prev ka prev ka total[same = prev ka diffn i.e. uske prev ka total]
        // so f(n-2)*(k-1) and (k-1) bcoz bacha hua space k liye (k-1) tarike honge, dry run for n=3
        // suppose n=3, k=3 then last ke 2 spaces same i.e. f(n-2) and remn 1 space i.e. (k-1)  
        long long same = (k-1)*countWays(n-2, k);
        // previous n ka total * (k-1)
        long long diff = (k-1)*countWays(n-1, k);
        long long ans = same+diff;
        return ans;
    }

// 2. memoization
int mod=1e9+7;
long long solveMemo(int n,int& k,vector<long long>& dp)
    {
        if(n==1)
        return k;
        
        if(n==2)
        return (k * k); // k+k*(k-1) = k*k
        
        if(dp[n]!=-1)
        return dp[n];
        
        long long same=solveMemo(n-2,k,dp)*(k-1);
        long long diff=solveMemo(n-1,k,dp)*(k-1);
        
        return dp[n]=(same+diff);
    }

long long countWays(int n, int k){
        vector<long long> dp(n+1,-1);
        long long ans=solveMemo(n,k,dp);
        
        return ans;
}


// 3. Tabulation
long long countWays(int n, int k){
        vector<long long> dp(n+1,-1);
        dp[1] = k;
        dp[2] = (k * k);  // k+k*(k-1) = k*k
        for(int i=3;i<=n;i++){
            // same depends on (i-2)th and diffn depends on (i-1)th
            dp[i] = (k-1)*dp[i-2] + (k-1)*dp[i-1]; 
        }
        
        return dp[n];
}

// 4. space optimized
long long countWays(int n, int k){
        vector<long long> dp(n+1,-1);
        // first denotes dp[1] & second denotes dp[2]
        long long first = k; 
        long long second = ((long long)k * k); // k+k*(k-1) = k*k

        if(n==1) return first;
        if(n==2) return second;

        long long curr = 0;
        for(int i=3;i<=n;i++){
            // same depends on (i-2)th and diffn depends on (i-1)th
            curr = (k-1)*first + (k-1)*second;
            // update first and second 
            first = second;
            second = curr;
        } 
        return curr%mod;
}

