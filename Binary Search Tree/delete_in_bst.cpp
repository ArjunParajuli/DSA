#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
	int data;
	Node * left;
	Node * right;

	Node(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

/*
Four cases:
- target is leaf node
- target has right child, so replace with right child
- target has left child, so replace with left child
- target has both child, replace with inorder predecessor or inorder successor

*/

Node * inorderPredecessor(Node *root){
    if(root == NULL) return NULL;
    
    Node * temp = root;
    while(temp->right){
        temp = temp->right;
    }
    return temp;
}

// Function to delete a node from BST.
Node *deleteNode(Node *root, int x) {
    if(root == NULL)
        return NULL;
        
    // find and delete target
    
    // target found
    if(root->data == x){
        // four cases for deletion
        if(root->left == NULL && root->right == NULL){
            // target is leaf node
            delete root;
            return NULL;
        }else if(root->left == NULL && root->right != NULL){
            // target has right child, so replace with right child
            Node * rightSubTree = root->right;
            delete root;
            return rightSubTree;
        }else if(root->left != NULL && root->right == NULL){
            // target has left child, so replace with left child
            Node * leftSubTree = root->left;
            delete root;
            return leftSubTree;
        }else{  // target has both child
           // Find inorder predecessor in the left subtree
            Node *inp = inorderPredecessor(root->left);
            // Replace root's data with inorder predecessor's data
            root->data = inp->data;
            // Delete the inorder predecessor from the left subtree
            root->left = deleteNode(root->left, inp->data);
        }
        
    }else{ // search for target
        if(x < root->data){
            root->left = deleteNode(root->left, x);
        }else{
            root->right = deleteNode(root->right, x);
        }
    }
    return root;
}