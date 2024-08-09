#include<bits/stdc++.h>
using namespace std;


/*
NOTE: kth smallest/largest then always think about heap

algo:
- maintain a maxheap, start inserting all possible pairs in maxheap.
- whenever maxheap size becomes greater than k we pop one elm so that heap size remains k 
- after doing so for all possible pairs, we're left with k elms in heap and top top elm is our kth smallest elm


*/

// time O(n^2)*O(logk), k is size of heap ( bcoz push and pop operations have a time complexity of O(log n) in heaps)

// comparator for maxheap (between two pairs, keep the one at top whose fractional value is higher)
 class cmp{
        public:
        bool operator()(pair<int, int> &a, pair<int, int> &b){
            return (double)(a.first) / a.second < (double)(b.first) / b.second;
        } 
    };

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<int> ans;

    // insert all & maintain maxheap of size k
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                pq.push({arr[i], arr[j]});
                if(pq.size() > k)
                    pq.pop();
            }
        }
    
    // top elm has kth smallest elm (bcoz we're left with k small elms & top one is the largest among them)
        pair<int, int> top = pq.top();
        
        ans.push_back(top.first);
        ans.push_back(top.second);
        return ans;
    }