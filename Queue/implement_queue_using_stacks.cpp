#include<bits/stdc++.h>
using namespace std;

// use FIFO behavious using stack


/*

method 1: (push operation in O(n) time but pop and peek in O(1) time)
push algo:-
- push all elms from s1 to s2
- add elm to s1
- push all elms from s2 to s1

pop algo:
- 


method 2: (push operation in O(1) time but pop and peek in O(n) time)
push algo:
- just push into stack 1.

pop algo:
- if s2 stack not empty, just pop from s2 stack.
- if s2 stack empty, push all elms from s1 into s2 then pop the top elm of s2. 

peek algo:(same as pop)
- if s2 stack not empty, just return top elm s2 stack.
- if s2 stack empty, push all elms from s1 into s2 then return top elm of s2.  

*/

    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int elm = -1;
        if(!s2.empty()){
            elm = s2.top();
            s2.pop();
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            elm = s2.top();
            s2.pop();
        }
        return elm;
    }
    
    int peek() {
        int front = -1;
        if(!s2.empty()){
            front = s2.top();
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            front = s2.top();
        }
        return front;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }