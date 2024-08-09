#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* left;
	Node* right;

	Node(int value) {
		this->data = value;
		this->left = NULL;
		this->right = NULL;
	}
};

/*
brute force: find inorder traversal and store in vector and traverse to get ans
better: do inorder traversal and return first val>terget for successor
optimal: ateach node, compare root->val with target val and eliminate one half, time: O(height of tree) and space: O(1)
*/

void findPredecessor(Node * root, Node * &pre, int &key){
        Node * curr = root;
        while(curr){
            if(curr->data >= key){  // curr node might be ans or key so check further on left subtree bcoz we need elm just small than key
                curr = curr->left;
            }else{                      // curr->data < x->data so store it and check on right subtree bcoz we need elm just small than key
                pre = curr;
                curr = curr->right;
            }
        }
    }

 Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node * curr = root;
        Node * ans = NULL;
        while(curr){
            if(curr->data > x->data){  // curr node might be ans so store it and check further on left subtree
                ans = curr;
                curr = curr->left;
            }else{                      // curr->data <= x->data so check on right subtree
                curr = curr->right;
            }
        }
        return ans;
    }