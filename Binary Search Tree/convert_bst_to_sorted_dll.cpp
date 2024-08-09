#include<bits/stdc++.h>
using namespace std;

/*
    - using inorder traversal but using RNL instead of LNR bcoz first attach right subtree with root node and attach root node with left subtree
     so that we get the list in sorted order and return head of left subtree
*/

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

// run in bst.cpp file 

// convert bst to sorted DLL
void convertBstToDLL(Node * root, Node * &head){ // head denotes head of DLL
	if(root == NULL)
		return;

	// Right 
	convertBstToDLL(root->right, head);

	// Node (solve one case i.e attach root->right to head and replace head at root)
	root->right = head; // no need to check root!=NULL bcoz already checked at base case
	if(head != NULL){ // avoid seg fault
		head->left = root; 
	}
	head = root;

	// Left
	convertBstToDLL(root->left, head);
}

void printSortedDLL(Node * head){
	Node * temp = head;
	while(temp){
		cout << temp->data << "->";
		temp = temp->right;
	}
}