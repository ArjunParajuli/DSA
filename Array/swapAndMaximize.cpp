#include <bits/stdc++.h>
using namespace std;

// Given an array a[ ] of N elements. Consider array as a circular array i.e. element after a[n-1] is a[0]. The task is to find maximum sum of 
// the absolute difference between consecutive elements with rearrangement of array elements allowed i.e. after any rearrangement of array 
// elements find |a1 – a2| + |a2 – a3| + …… + |an-1 – an| + |an – a1|.

long long int maxSum(int arr[], int n)
{
    long long int sum = 0;
    sort(arr, arr+n);
    for(int i=0;i<n;i++){
        sum += abs(arr[i] - arr[n-1-i]);
    }
    return sum;
}

int main(){
    int arr[]={4,1,8,2};
    cout << maxSum(arr, 4);
}