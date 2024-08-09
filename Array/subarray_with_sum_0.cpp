#include<bits/stdc++.h>
using namespace std;

/*
idea is to store curr cum in a set and check if it is already present in set or not
*/

  bool subArrayExists(int arr[], int n)
    {
        unordered_set<int> s;  // unordered set takes O(1) time for searching, inertion, deletion on average
        int sum = 0;
        for(int i=0;i<n;i++){
            if(arr[i] == 0) return true; 
            sum += arr[i];
            if(sum == 0 || s.find(sum) != s.end())
                return true;
            s.insert(sum);
        }
        return false;
    }

