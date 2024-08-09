#include <iostream>
#include<queue>
#include<vector>
using namespace std;

/*
BST lecture 3: Love babbar
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

void levelOrderTraversal(Node* root ) {
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		Node* temp = q.front();
		q.pop();

		if(temp == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			cout << temp->data << " ";
			if(temp->left != NULL) {
				q.push(temp->left);
			}
			if(temp->right != NULL) {
				q.push(temp->right);
			}
		}
	}
}

// using LNR approach
Node * convertDLLtoBST(Node * &head, int n){ // head of dll must be passed by ref so that it doesnt go back to its prev place after backtracking from recursive call
    if(n <= 0){
        return NULL;
    }

    // L
    Node * leftSubTree = convertDLLtoBST(head, n/2);

    // N
    Node * root = head;
    root->left = leftSubTree; // link root with its left part
    head = head->right; // update head

    Node * rightSubTree = convertDLLtoBST(head, n-n/2-1);
    root->right = rightSubTree;

    return root;
}

int main(){
    // creating Doubly linked list 
    Node * first = new Node(1);
    Node * second = new Node(2);
    Node * third = new Node(3);

    first->right = second;
    second->left = first;
    second->right = third;
    third->left = second;

    Node* head = first;
	//10<->20<->30

    // creating bst from DLL
    Node * root = convertDLLtoBST(head, 3);
    levelOrderTraversal(root);

    return 0;
}