#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

/*
    go to each node and convert it accordingly
*/
 
 int sum(Node * node){
        if(node == NULL) return 0;
        // leaf node 
        if(node->left == NULL && node->right == NULL){
            int currVal = node->data; // store leaf node's value
            node->data = 0; // update leaf node to 0
            return currVal; // return leaf node's value to its parent
        }
        
        // for non-leaf node
        int leftSum = sum(node->left);  // get left child sum
        int rightSum = sum(node->right); // get right child sum
        int currVal = node->data;        // store current node's value
        node->data = leftSum+rightSum;   // update current node's value
        
        return currVal+node->data;  // return node's current value + (left and right child's sum)
    }
    
    void toSumTree(Node *node)
    {
        if(node == NULL) return;
        sum(node); // this func modifies the tree
    }