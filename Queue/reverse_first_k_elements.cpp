#include<iostream>
#include<queue>
#include<stack>
using namespace std;

/*
algo
- push first k elm from queue to stack 
- now start popping each elm from queue and then push them again into the queue for n-k elms
*/

 queue<int> modifyQueue(queue<int> q, int k) {
        stack<int> st;
        int temp = k;
        while(temp--){
            int elm = q.front();
            q.pop();
            st.push(elm);
        }
        while(!st.empty()){
            int elm = st.top();
            st.pop();
            q.push(elm);
        }
        int n = q.size();
        for(int i=0;i<n-k;i++){
            int elm = q.front();
            q.pop();
            q.push(elm);
        }
        return q;
    }

    int main(){
    queue<int> q;
    q.push(5);
    q.push(8);
    q.push(6);

    q = modifyQueue(q, 2);
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}