#include<bits/stdc++.h>
using namespace std;

class Node{
        public:
        int data;
        Node * left;
        Node * right;
        
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
    };

/*
brute force: create inorder array and create list for all elms
another: create inorder array of Node* type and after that for each elm, a[i]->left = NULL and a[i]->right = a[i+1]

optimal: 
-Create a dummy node.
-Create a variable called ‘prev’ and make it point to the dummy node.
-Perform in-order traversal and at each step. 
-Set prev -> right = curr
-Set prev -> left = NULL
-Set prev = curr
*/

void inOrd(Node * root, Node * &prev){
    if(root == NULL) return;

    // L
    inOrd(root->left, prev); 
    
    // N
    prev->left = NULL;
    prev->right = root;
    prev = root;
    
    //R
    inOrd(root->right, prev);
}

Node * flattenBST(Node * root){
    Node * dummy = new Node(-1); // to keep track of the head of linked ist formed bcoz prev will keep moving
    Node * prev = dummy;
    inOrd(root, prev);  // after this call prev is at last node
    prev->left = prev->right = NULL; 
    root = dummy->right; // reset root to head of flattened linked list
    return root;
}

void printLL(Node * head){
	Node * temp = head;
	while(temp){
		cout << temp->data << "->";
		temp = temp->right;
	}
}


// Ques: flatten BST in decreasing order (minor change: we perform opposite inorder traversal)
void inDec(Node * root, Node * &prev){
    if(root == NULL) return;

    // L
    inDec(root->right, prev); 
    
    // N
    prev->left = NULL;
    prev->right = root;
    prev = root;
    
    //R
    inDec(root->left, prev);
}

Node * flattenBSTDecreasing(Node * root){
    Node * dummy = new Node(-1); // to keep track of the head of linked ist formed bcoz prev will keep moving
    Node * prev = dummy;
    inDec(root, prev);  // after this call prev is at last node
    prev->left = prev->right = NULL; 
    root = dummy->right; // reset root to head of flattened linked list
    return root;
}

