#include<bits/stdc++.h>
using namespace std;

/* 
Striver YT
find missing and repeating elm 


*/

// better approach with space
 vector<int> findTwoElement(vector<int> arr, int n) {
       int countArr[n] = {0};
       int missing, repeating;
       for(int i=0;i<n;i++){
           countArr[arr[i]-1]++;
       }
       for(int i=0;i<n;i++){
           if(countArr[i] == 0)
                missing = i+1;
            if(countArr[i] == 2)
                repeating = i+1;
       }
       return {repeating, missing};
        
    }

    /*
    optimal
    algo:
     use sum of arr - sum to n this gives x-y i.e. x is repeating and y is missing number
     use sum of sqrs of arr - sum of sqrs to n this gives x^2-y^2
     we got two eqn, so we can solve and find individual values of x and y. 

    */
   vector<int> findTwoElement(vector<int> arr) {
        long long n = arr.size();
        long long sumToN = (n*(n+1))/2;
        long long sumToNSqr = (n*(n+1)*(2*n+1))/6;
        long long sumArr = 0;
        long long sumSqrArr = 0;
        for(int i=0;i<n;i++){
            sumArr += arr[i];
            sumSqrArr += (long long)arr[i] * (long long)arr[i];
        }
        
        long long val1 = sumArr-sumToN; // x-y
        long long val2 = sumSqrArr-sumToNSqr; // x^2-y^2
        val2 = val2/val1; // now we get x+y
        
        long long x = (val1+val2)/2; // x-y+(x+y)/2 = x
        long long y = x-val1; // x-(x-y)=y
        
        return {int(x), (int)y};
    }