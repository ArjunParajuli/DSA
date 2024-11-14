#include <iostream>
#include <queue>
using namespace std;

/*
approach 1: using min heap: 
- build a min heap O(n) time and delete elms k-1 times, after that the first elm is the kth smallest but it takes O(n) space

approach 2: using max heap: time-O(n), space: O(k)
- create max heap of size k with first k elms
- now for all other elms, replace top() elm with smaller elms so that at the end max heap contains k small elms
- after performing second step for all the remn elm in the array, the top elm is the kth smallest elm
    It is working bcoz after making heap, we're inserting only those elms which are smaller than the top elm, Hence the k small elms will remain in heap  
*/

 int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> pq; // max heap
        // push first k elms
        for(int i=0;i<k;i++){
            pq.push(arr[i]);
        }
        // for remn elms, replace max heap top with smaller elms
        for(int i=k;i<=r;i++){
            if(arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }            
        }
        return pq.top();  // constant time for getting top elm
    }


// same algorithm just diff: using min heap and replacing top elm with larger elm than top elm bcoz we need larger elm
// among all elms, we only want k largest elms in our min heap and bcoz its a min heap, we'll have smallest among those k elms at top 
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<k;i++){
            pq.push(nums[i]);
        }
        for(int i=k;i<nums.size();i++){
            if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }

int main(){
    int arr[] = {7,10,4,3,20,15};
    cout << kthSmallest(arr, 0, 5, 3);

    return 0;
}