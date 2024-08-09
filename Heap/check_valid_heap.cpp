#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

/*
using recursion, for each node return pair with first val as max val betn itself and its children and second value as true/false denoting max heap or not 
*/

// Q) check if the complete binary tree is a heap or not.
bool isHeap(struct Node* tree) {
        if(tree == NULL) return true;
        
        if(!tree->left && !tree->right) return true;
        
        bool leftAns = isHeap(tree->left);
        bool rightAns = isHeap(tree->right);
        
        // if anyone is false then return false
        if(!leftAns || !rightAns){
            return false;
        }else{
            // if curr node val is greater than both its children's val then return true else false
            if(tree->data > tree->left->data && tree->data > tree->right->data)
                return true;
            else 
                return false;
        }
    }