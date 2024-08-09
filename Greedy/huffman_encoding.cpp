#include<bits/stdc++.h>
using namespace std;

/*
Q) we have to build the Huffman tree and print all the huffman codes in preorder traversal of the tree.
algo:
- insert all f[i] elms in minheap
- take out top two elms(two smallest elms), add them and insert their addition(sumofNodes) in the minheap again. (make those popped small elms the children of sumofNodes)
- after doing same for all elm in minheap, a tree will be formed
- now preorder traverse the tree, if explored left add "0" to str, explored right then add "1" to str 
*/

class Node{
	    public:
	    int data;
	    Node * left;
	    Node * right;
	    
	    Node(int d){
	        data = d;
	        left = NULL;
	        right = NULL;
	    }
	};
	
	class cmp{
	    public:
	    bool operator()(Node * a, Node * b){
	        return a->data > b->data;
	    }
	};
	
	void traverse(Node * root, vector<string> &ans, string str){
	    if(root == NULL){
	        return;
	    }
	    if(!root->left && !root->right){
	        ans.push_back(str);
	        return;
	    }
	    
	    traverse(root->left, ans, str+"0");
	    traverse(root->right, ans, str+"1");
	}
	
		vector<string> huffmanCodes(string s,vector<int> f,int n)
		{
		    priority_queue<Node*, vector<Node*>, cmp> pq;

            // create min heap with elms from f[i]
		    for(int i=0;i<n;i++){
		        Node * temp = new Node(f[i]);
		        pq.push(temp);
		    }
		    
            // create huffman tree
		    while(pq.size() > 1){
		        Node * top = pq.top(); pq.pop();
		        Node * sectop = pq.top(); pq.pop();
		        
		        Node * sumofNodes = new Node(top->data + sectop->data);
		        
		        sumofNodes->left = top;
		        sumofNodes->right = sectop;
		        
		        pq.push(sumofNodes);
		    }
		    
		    Node * root = pq.top(); // at the end single root elm is left in minheap
		    
		    vector<string> ans;
		    string str = "";
		    traverse(root, ans, str); // traverse and store elms
		    
		    return ans;  // ans array contains huffman codes for corresponding characters in s string
		}