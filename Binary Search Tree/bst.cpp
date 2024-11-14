#include <iostream>
#include<queue>
using namespace std;

/* 

The height of a balanced binary tree or BST is approximately log₂(n).
The height of a skewed binary tree or BST is n - 1.

time for inserting: Average case time complexity: O(log n) for a balanced tree
 Worst case compl: O(n) for skewed(unbalanced) tree

 time for search in BST: same as for inserting

 Note: inorder of BST always gives values in sorted order
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

// insert data in its appropriate position
Node* insertIntoBST(Node* root, int data) {
	// first node
	if(root == NULL) {
		root = new Node(data);
		return root;
	}

	//its not the first node
	if(data > root->data) {
		root->right = insertIntoBST( root->right, data);
	}
	else {
		root->left = insertIntoBST( root->left, data);
	}
	return root;
}

// createBST - take val from user and insert into BST
Node * createBST(Node* root) {
	cout << "Enter data:" << endl;
	int data;
	cin >> data;

// cin value and insert into BST
	while(data != -1) {
		root = insertIntoBST(root, data);
		cout << "Enter data:" << endl;
		cin >> data;
	}
	return root;
}

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


void preorder(Node* root) {
	//NLR
	if(root == NULL)
		return ;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(Node* root) {
	//LNR
	if(root == NULL)
		return ;
	
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void postorder(Node* root) {
	//LRN
	if(root == NULL)
		return ;
	
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

Node* minValue(Node* root) {
	if(root == NULL) {
		cout << "NO MIN VALUE" << endl;
		return NULL; 
	}
	Node* temp = root;

	while(temp->left != NULL) {
		temp = temp->left;
	}
	return temp;
}

Node* maxValue(Node* root) {
	if(root == NULL) {
		return NULL;
	}

	//if tree has nodes > 0 count
	Node* temp = root;
	while(temp->right != NULL) {
		temp = temp->right;
	}
	return temp;
}

bool searchInBST(Node* root, int target) {
	//base case
	if(root == NULL) {
		return false;
	}

	//1 case mujhe solve krna h 
	if(root->data == target ) {
		return true;
	}

	//baaaki recursion sambhal lega 
	//left ya right
	bool leftAns = false;
	bool rightAns = false;
	if(target > root->data) {
		rightAns = searchInBST(root->right, target);
	}
	else {
		leftAns = searchInBST(root->left, target);
	}

	return leftAns || rightAns;
}

Node* deleteFromBST(Node* root, int target) {
	///target ko dhundo
	//target ko delete karo

	if(root == NULL) {
		return NULL;
	}

	if(root->data == target) {
		//ab delete karenge
		//4 cases

		
		if(root->left == NULL && root->right == NULL) {
			//1 case -> leaf node
			delete root;
			return NULL;
		}
		else if(root->left != NULL && root->right == NULL) {
			//2 case -> left non null and right null
			Node* childSubtree = root->left;
			delete root;
			return childSubtree;
		}
		else if(root->left == NULL && root->right != NULL) {
			///3 case -> left me NULL and right NON NULL
			Node* childSubtree = root->right;
			delete root;
			return childSubtree;
		}
		//4 case -> left NON NULL && right NON NULL
		else {
			//a -> left subtree ki max value lao
			Node* maxi = maxValue(root->left);
			//replacement
			root->data = maxi->data;

			//delete actual maxi wali node
			root->left = deleteFromBST(root->left, maxi->data);
			return root;
		}
	}
	else if(root->data > target) {
		//left me chalo
		root->left =  deleteFromBST(root->left,  target);
	}
	else {
		//right me jao
		root->right =  deleteFromBST(root->right, target);
	}
	
	return root;
}

// construct bst from inorder
Node * constructBST(vector<int> inorder, int s, int e){
	// base case
	if(s > e){ 
		return NULL;
	}

	// find mid and create its node
	int mid = s+(e-s)/2;
	Node * root = new Node(inorder[mid]);
	// attach left and right part
	root->left = constructBST(inorder, s, mid-1);
	root->right = constructBST(inorder, mid+1, e);

	// return root after attachoing left and right sub trees
	return root; 
}

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

void in(Node * root, Node * &prev){
    if(root == NULL) return;

    // L
    in(root->left, prev); 
    
    // N
    prev->left = NULL;
    prev->right = root;
    prev = root;
    
    //R
    in(root->right, prev);
}

Node * flattenBST(Node * root){
    Node * dummy = new Node(-1); // to keep track of the head of linked ist formed bcoz prev will keep moving
    Node * prev = dummy;
    in(root, prev);  // after this call prev is at last node
    prev->left = prev->right = NULL; 
    root = dummy->right; // reset root to head of flattened linked list
    return root;
}

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

void printLL(Node * head){
	Node * temp = head;
	while(temp){
		cout << temp->data << "->";
		temp = temp->right;
	}
}

int main() {

	Node* root = NULL;
	// root = createBST(root);

	vector<int> inorder = {1,2,3,4,5,6,7};
	root = constructBST(inorder, 0, inorder.size()-1);
	levelOrderTraversal(root);
	// end
	

	// for flatten BST question
	// root = flattenBST(root);
	// printLL(root);
	// end

	root = flattenBSTDecreasing(root);
	printLL(root);

	// Node * head = NULL;
	// convertBstToDLL(root, head);
	// printSortedDLL(head);

	// cout << endl << "Inorder: " ;
	// inorder(root);
	// cout << endl << "Preorder: ";
	// preorder(root);
	// cout << endl << "PostOrder: ";
	// postorder(root);


	// cout << endl;
	// Node* minNode = minValue(root);
	// if(minNode == NULL) {
	// 	cout << "There is no node in tree, so no min value" << endl;
	// }
	// else {
	// 	cout << "Min Value: " << minNode->data << endl;
	// }

	// cout << endl;
	// Node* maxNode = maxValue(root);
	// if(maxNode == NULL) {
	// 	cout << "There is no node in tree, so no max value" << endl;
	// }
	// else {
	// 	cout << "Max Value: " << maxNode->data << endl;
	// }

	// int target ;
	// cout << "Enter the value of target: " << endl;
	// cin >> target;

	// while(target != -1) {
	// 	root = deleteFromBST(root,  target);
	// 	cout << endl << "Printing Level Order Traversal: " << endl;
	// 	levelOrderTraversal(root);

	// 	cout << "Enter the value of target: " << endl;
	// 	cin >> target;
		
	// }

	// int t;
	// cout << "Enter the target: " << endl;
	// cin >> t;

	// while(t != -1) {
	// 	bool ans = searchInBST(root, t);
	// 	if(ans == true) {
	// 		cout << "Found" << endl;
	// 	}
	// 	else {
	// 		cout << "Not Found" << endl;
	// 	}

	// 	cout << "Enter the target: " << endl;
	// 	cin >> t;
		
	// } 



	return 0;
}