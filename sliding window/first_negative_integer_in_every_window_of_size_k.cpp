#include<bits/stdc++.h>
using namespace std;

/*
algo:
- keep -ve elms in queue and for each window insert the front of queue into ans arr
- also after inserting and before sliding the window, update the queue
*/

vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k) {
    vector<long long> ans;
    int i=0,j=0;
    queue<int> q;
    while(j < n){
        // -ve elm found then push into queue
        if(arr[j] < 0)
            q.push(arr[j]);
        
        // if window size is smaller than k, increment it
        if(j-i+1 < k)
            j++;
        else if(j-i+1 == k){ // window size equal to k
        // queue has no -ve elms so push 0
            if(q.empty())
                ans.push_back(0);
            else{ 
                // push first -ve elm of queue
                ans.push_back(q.front());
                // if front elm is the same as ith elm then we must pop bcoz ith elm won't be in next window
                if(q.front() == arr[i]){
                    q.pop();
                }
            }
            i++, j++; // slide window
        }
    }
    return ans;
 }