#include<iostream>
#include<stack>
using namespace std;

// Note: whenever accessing top of stack, make sure to check the stack is empty before accessing stack
// to avoid error

// Expected Time Complexity: O(N*N)
// Expected Auxilliary Space: O(N) recursive.

void insertSorted(stack<int> &st, int elm){
    // base case (also check if stack empty)
    // insert in both cases
    if(st.empty() || st.top() <= elm){
        st.push(elm);
        return;
    }
    
    // solve one case
    int temp = st.top();
    st.pop();
    // recursion
    insertSorted(st, elm);
    // backtracking
    st.push(temp);
}

void sortstack(stack<int> &st){
    // base case
    if(st.empty()) return;

    // solve one case
    int elm = st.top();
    st.pop();
    // recursion
    sortstack(st);
    // backtracking(after emptying the stack, insert elms to its correct position one by one)
    insertSorted(st, elm);
}

void printStack(stack<int> st){
        if(st.empty())
            return;
        
        int temp = st.top();
        st.pop();
        printStack(st);
        st.push(temp);
        cout << st.top() << " ";
    }

int main(){
    stack<int> st;
    st.push(10);
    st.push(30);
    st.push(50);
    st.push(40);
    st.push(20);

    insertSorted(st, 15);
    printStack(st);
    sortstack(st);
    cout << endl;
    printStack(st);
 
    return 0;
}