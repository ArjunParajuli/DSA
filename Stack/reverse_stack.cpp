#include<iostream>
#include<stack>
using namespace std;

// one basic way is to copy this stack in another stack and that stack will be the reverse of original stack

 void insertAtBottom(stack<int> &st, int elm){
        if(st.empty()){
            st.push(elm);
            return;
        }
        
        int temp = st.top();
        st.pop();
        insertAtBottom(st, elm);
        st.push(temp);
    }

// time complexity - O(n^2) bcoz insertAtBottom takes O(n) time

    void Reverse(stack<int> &st)
    {
        // base case
        if(st.empty())
            return;
        
        // solve one case
        int temp = st.top();
        st.pop();
        // recursive call
        Reverse(st);
        // backtracking
        insertAtBottom(st, temp);
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
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    printStack(st);
    Reverse(st);
    cout << endl;
    printStack(st);
 
    return 0;
}