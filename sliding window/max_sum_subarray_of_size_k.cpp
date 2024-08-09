#include<bits/stdc++.h>
using namespace std;

// playlist followed for sliding window: aditya verma yt

/*
sliding window pehechanne ka tarika:
- array or string dia rhega and subarray ya substring nikalna hoga
- window size diya hoga jo subarr or substr k length k barabar hoga

# window can be fixed sized or variable sized:

format for fixed sized window problems:
while(j < n){
    some calculations

    if(curr window size < k){
        j++;
    }else if(curr window size == k)
        find currans
        slide window
}

*/


/*
algo:
basic sliding window technique, first calc sum of curr window and then calculate sum of next window and so on and store the maxm one
*/
long maximumSumSubarray(int k, vector<int> &arr , int n){
        long long int maxm = INT_MIN, currsum=0;
        for(int i=0;i<k;i++){
            currsum += arr[i];
        }
        maxm = max(currsum, maxm);
        long long int low=1, high=k;
        while(high < n){
            currsum = currsum + arr[high] - arr[low-1];
            maxm = max(currsum, maxm);
            low++, high++;
        }
        return maxm;
    }