#include <iostream>
#include<queue>
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

/*
    Q) convert a given tree which is a complete bt and also a bst into a valid heap:
    -> algo:
    - first store inorder of given tree
    - now perform postorder traversal in input tree and replace the curr node's value with ith index(start from 0) elm of inorder array
*/

// # Main Ques

void inorderT(Node * root, vector<int> &inorder){
    if(!root) return;

    inorderT(root->left, inorder);
    inorder.push_back(root->data);
    inorderT(root->right, inorder);
}

void replaceWithPostOrder(Node * root, vector<int> &inorder, int &index){
    if(!root) return;

    // L
    replaceWithPostOrder(root->left, inorder, index);
    // R
    replaceWithPostOrder(root->right, inorder, index);
    // N
    root->data = inorder[index];
    index++;
}

Node * convertCbtBstToHeap(Node * root){
    if(!root) return NULL;

    // find and store inorder
    vector<int> inorder;
    inorderT(root, inorder);

    // postorder traversal in input tree
    int index = 0;
    replaceWithPostOrder(root, inorder, index);

    return root;
}

int main(){
    // tree for input:
/*
    100
    50 150 
    40 60 110 200
    20 
*/
    Node * root = createTree();
    levelOrderTraversal(root);

    cout << "Tree after converting to heap: " << endl;

    root = convertCbtBstToHeap(root);
    levelOrderTraversal(root);

    return 0;
}