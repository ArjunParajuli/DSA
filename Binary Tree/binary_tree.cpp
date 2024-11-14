#include <iostream>
#include<queue>
using namespace std;

/*
A Binary Tree Data Structure is a hierarchical data structure in which each node has at most two children.

Full Binary tree: Each node has either 0 or 2 children

Complete BT: All levels are completely filled except the last level and the last level has nodes as left as possible.

Perfect BT: ALl leaf nodes are at the same level.

Balanced BT: A binary tree is balanced if the height of the tree is O(Log n) where n is the number of nodes.  For Example, the AVL tree maintains O(Log n) height
		 by making sure that the difference between the heights of the left and right subtrees is at most 1. 
		 Red-Black trees maintain O(Log n) height by making sure that the number of Black nodes on every root-to-leaf path is the same and that 
		 Red nodes cannot have red children(a red node must have black children). All leaves (NIL nodes) are black. These are the null pointers. 
		 The root of the tree is always black.
		 Application:  Red-Black Trees are used in database indexing to maintain a balanced index, ensuring that searches, insertions, and deletions can be performed efficiently.


Degenerate Binary Tree: Every non-leaf node has just one child in a binary tree known as a Degenerate Binary tree. The tree effectively transforms into a linked list as a result, with each node linking to its single child.

NOTE:- If there are n nodes in a binary tree, the maximum height of the binary tree is n-1, and the minimum height is floor (log2(n)+1).
Height of a tree is the number of nodes on the longest path from the root to a leaf, minus one.

Note: Time and space complexity of preorder, inorder, postorder is O(n) and O(h) where h is height of tree.
But the worst space complexity is O(n) incase of skewed trees, where n is number of nodes in tree
so space is also O(n) for all 3 traversals
*/

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

Node * createTree(){
	int data;
	cout << "Enter root node: ";
	cin >> data;

	if(data == -1)
		return NULL;
	
	Node * root = new Node(data);
	cout << "Enter left node of " << data << endl;
	root->left = createTree();
	cout << "Enter right node of " << data << endl;
	root->right = createTree();
	return root;
}

void preOrderTraversal(Node* root) {
	//base case
	if(root == NULL) {
		return;
	}
	// N L R
	//N 
	cout << root->data << " ";
	// L
	preOrderTraversal(root->left);
	// R
	preOrderTraversal(root->right);
}

void inorderTraversal(Node* root) {
	//LNR
	//base case
	if(root == NULL) {
		return;
	}
	//L
	inorderTraversal(root->left);
	// N
	cout << root->data << " ";
	// R
	inorderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
	//LRN
	//base case
	if(root == NULL) {
		return;
	}
	//L
	postOrderTraversal(root->left);
	//R
	postOrderTraversal(root->right);
	//N
	cout << root->data << " ";
}

void levelOrderTraversal(Node* root) {
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		Node* front = q.front();
		q.pop();

	// next level so endl
		if(front == NULL) {
			cout << endl;
			if(!q.empty()) { // push null to mark curr level, except for after completion
				q.push(NULL);
			}
		}
		else {
			//valid node wala case
			cout << front->data << " ";

			if(front->left != NULL) {
				q.push(front->left);
			}
			if(front->right != NULL) {
				q.push(front->right);
			}
		}
	}
}

// int maxDepth(TreeNode* root) {

// // IMP Galti
// if(root==NULL)
// 	return 0;

// queue<TreeNode*> q;
// q.push(root);
// q.push(NULL);
// int count = 1;

// //asli traversal start krete h 

// while(!q.empty()) {
// 	TreeNode* front = q.front();
// 	q.pop();

// 	if(front == NULL) {
// 		cout << endl;
// 		if(!q.empty()) {
// 			count++;
// 			q.push(NULL);
// 		}
// 	}
// 	else {
// 		//valid node wala case
// 		//cout << front->data << " ";

// 		if(front->left != NULL) {
// 			q.push(front->left);
// 		}
// 		if(front->right != NULL) {
// 			q.push(front->right);
// 		}
// 	}
// }
// return count;


// 	// //base case
// 	// if(root == NULL ) {
// 	//     return 0;
// 	// }

// 	// int leftHeight = maxDepth(root->left);
// 	// int rightHeight = maxDepth(root->right);
// 	// int height = max(leftHeight, rightHeight) + 1;
// 	// return height;

// }

// int height(TreeNode* root) {
// 	//base case
// 	if(root == NULL ) {
// 		return 0;
// 	}
// 	int leftHeight = height(root->left);
// 	int rightHeight = height(root->right);
// 	int height = max(leftHeight, rightHeight) + 1;
// 	return height;
// }

// int diameterOfBinaryTree(TreeNode* root) {
	//base case
// 	if(root == NULL) {
// 		return 0;
// 	}   
// 	int option1 = diameterOfBinaryTree(root->left);
// 	int option2 = diameterOfBinaryTree(root->right);
// 	int option3 = height(root->left) + height(root->right);
// 	int diameter = max(option1, max(option2, option3));
// 	return diameter;
// }


int main() {

	  Node* root = createTree();
	  //cout << root->data << endl;
	  cout << "Printing Preorder: ";
	  preOrderTraversal(root);
	  cout << endl;

	  cout << "Printing Inorder: ";
	  inorderTraversal(root);
	  cout << endl;

	  cout << "Printing PostOrder: ";
	  postOrderTraversal(root);
	  cout << endl;

	  cout << "Level Order : ";
	  levelOrderTraversal(root);
	  cout << endl;

  return 0;
}