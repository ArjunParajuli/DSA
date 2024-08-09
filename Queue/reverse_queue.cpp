#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// Note: better approach is iterative one bcoz using recursion will also increase stack overhead in function call  


// take out elm from queue and insert into stack 
// now from stack push into queue to get the reversed queue
 queue<int> rev(queue<int> &q)
    {
        stack<int> st;
        while(!q.empty()){
            int e = q.front();
            q.pop();
            st.push(e);
        }
        while(!st.empty()){
            int e = st.top();
            st.pop();
            q.push(e);
        }
        return q;
    }

void reverseRecursively(queue<int> &q){
    // base case
    if(q.empty())
        return;
    
    // solve 1 case
    int elm = q.front();
    q.pop();

    // recursion do the remaining job
    reverseRecursively(q);

    // backtrack (while returning from recursion, push the elm into queue)
    q.push(elm);
}

int main(){
    queue<int> q;
    q.push(5);
    q.push(8);
    q.push(6);

    reverseRecursively(q);
    while(!q.empty()){
        cout << q.front();
        q.pop();
    }

    return 0;
}