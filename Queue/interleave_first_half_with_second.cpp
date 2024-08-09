#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// now copy one elm from q1 and q2 into our result queue one by one

// copy queue to arr1, rearrange arr1 to arr2 and copy arr2 to queue
 vector<int> rearrangeQueue(queue<int> &q){
        vector<int> arr1;
        vector<int> arr2;
        int n = q.size(); 
        while(!q.empty()){
            int elm = q.front();
            q.pop();
            arr1.push_back(elm);
        }
        arr2.push_back(arr1[0]);
        int iterations = (n-2)/2;
        int mid = n/2;
        for(int i=1;i<=iterations;i++){
            arr2.push_back(arr1[mid++]);
            arr2.push_back(arr1[i]);
        }
        arr2.push_back(arr1[n-1]);
        // copy to queue
        for (int i = 0; i < arr2.size(); i++) {
        q.push(arr2[i]);
    }
    return arr2;
    }

    // Another approach: copy first half of queue into queue q1 and merge both queues by pushing one elm from each queue into original queue 


     vector<int> rearrangeQueue2(queue<int> &q){
        queue<int> q1;
        int n = q.size();
        // copy first half into q1
        for(int i=0;i<n/2;i++){
            int e = q.front();
            q.pop();
            q1.push(e);
        }
        // now merge both halves into q
        for(int i=0;i<n/2;i++){
            // pop from q1 and push into q
            int e = q1.front();
            q1.pop();
            q.push(e);
            
            // pop and push second half into q
            int t = q.front();
            q.pop();
            q.push(t);
            
        }
        vector<int> arr;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            arr.push_back(t);
        }
        return arr;
    }



int main(){
    queue<int> q;
    q.push(2);
    q.push(4);
    q.push(3);
    q.push(8);
    q.push(6);
    q.push(9);

    vector<int> v;
    v = rearrangeQueue(q);
    for(auto itr:v){
        cout << itr << " ";
    }

    return 0;
}