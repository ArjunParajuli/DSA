#include<bits/stdc++.h>
using namespace std;

/*
create tree from end of arr and whenever inserting node at left part, store its inorder successor(root->data) and for rightmost leaf node inSuc is -1

time: avg case O(nlogn) bcoz for each elm in array we insert in bst, worst case O(n^2) if skewed bst is formed
space: O(n)
*/

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
    
    Node * insertBST(Node * root, int &elm, int &inSuc){
        if(root == NULL)
            return new Node(elm);
        
        if(elm < root->data){
            inSuc = root->data;
            root->left = insertBST(root->left, elm, inSuc);
        }else{
            root->right = insertBST(root->right, elm, inSuc);    
        }
        
        return root;
    }
    
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> ans(n, 0);
        Node * root = NULL;
        for(int i=n-1;i>=0;i--){
            int inSuc = -1;
            root = insertBST(root, arr[i], inSuc);
            ans[i] = inSuc;
        }
        return ans;
    }