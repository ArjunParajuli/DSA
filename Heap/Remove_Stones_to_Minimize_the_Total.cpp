#include<bits/stdc++.h>
using namespace std;

/*
Note: If you have an empty priority queue to which you want to add n items, one at a time, then the complexity is O(n * log(n)).
Constructing a priority_queue from a range of elements using iterators has a time complexity of O(n) When you initialize a priority_queue like priority_queue<int> pq(piles.begin(), piles.end()); 
Intuition: We have to take the largest number each time and delete half(floor value) from this.
algo:
so use priority queue so that we can easily access max elm and decrease it by half
- create and insert all elms in pq
- now decrease top elm k times

time: O(n log n) (priority queue construction) + O(k log n) (modification loop) + O(n log n) (summing remaining stones) = O((n + k) log n)
*/

 int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(int i=0;i<piles.size();i++){
            pq.push(piles[i]);
        }
        while(k--){
                int top = pq.top();
                pq.pop();
                int toDecrease = top/2;
                int toPush = top-toDecrease;
                pq.push(toPush); 
        }
        int ans = 0;
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }