#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

// - Create an empty stack (say S).
// - Initialize the current node as root.
// - Push the current node to S and set current = current->left until current is NULL
// - If current is NULL and the stack is not empty then:
//      - Pop the top item from the stack.
//      - Print the popped item and set current = popped_item->right 
//      - Go to step 3.
// - If current is NULL and the stack is empty then we are done.

vector<int> inorderUsingStack(Node * root){
    vector<int> ans;
        if(!root) return ans;
        stack<Node *> s;
        Node * curr = root;
        s.push(curr);
        curr = curr->left;
        while(curr || !s.empty()){
        // L
            while(curr){
                s.push(curr);
                curr = curr->left;
            }

        // N
        // (current is null but stack is not empty)
        curr = s.top(); 
        s.pop();
        ans.push_back(curr->data);
        // R
        curr = curr->right;
        }
        return ans;
}