#include<bits/stdc++.h>
using namespace std;

// use LIFO behaviour using queue

/*
method 1: (using two queues)
push:( O(n) time )
- push to q2
- push all from q1 to q2
- push all from q2 to q1

pop: ( O(1) time )
- pop front elm from q1

*/


 queue<int> q1, q2;
    MyStack() {
        
    }
    
    void push(int x) {
        // push q2
        q2.push(x);
        // q1 to q2
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        // q2 to q1
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        int front = -1;
        if(!q1.empty()){
            front = q1.front();
            q1.pop();
        }
        return front;
    }
    
    int top() {
        int front = -1;
        if(!q1.empty()){
            front = q1.front();
        }
        return front;
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }


/*
method 2: ( using 1 queue )
push : O(n) time
- push to queue
- pop and push that popped elm again into queue n-1 times
*/

     queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        // push 
        q.push(x);
        // pop and push that popped elm again into queue n-1 times
        int n = q.size();
        n = n-1;
        while(n--){
            int popped = q.front();
            q.pop();
            q.push(popped);
        }
    }
    
    int pop() {
        int front = -1;
        if(!q.empty()){
            front = q.front();
            q.pop();
        }
        return front;
    }
    
    int top() {
        int front = -1;
        if(!q.empty()){
            front = q.front();
        }
        return front;
    }
    
    bool empty() {
        return q.empty();
    }

    int main(){

        return 0;
    }