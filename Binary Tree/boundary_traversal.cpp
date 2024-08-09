#include <iostream>
#include<vector>
using namespace std;

/*
boundary: first print leaf node, then left wala part until leaf node, then all leaf nodes and right wala part until root node
*/
struct Node
{
    int data;
    Node* left, * right;
};

    void leftBoundary(Node *root, vector<int> &ans){
        if(root == NULL) return;
        // stop when we reach leaf node
        if(root->left == NULL && root->right == NULL) return;
        
        // push elm 
        ans.push_back(root->data);
        // go right only if no left child
        if(root->left != NULL)
            leftBoundary(root->left, ans);
        else
            leftBoundary(root->right, ans);
    }
    
     void leafBoundary(Node *root, vector<int> &ans){
        if(root == NULL) return;
        
        // push only leaf nodes
        if(root->left == NULL && root->right == NULL) 
            ans.push_back(root->data);
        
        leafBoundary(root->left, ans);
        leafBoundary(root->right, ans);
    }
    
     void rightBoundary(Node *root, vector<int> &ans){
        if(root == NULL) return;
        
        if(root->left == NULL && root->right == NULL) return;
        
        // check right first and only check left when no right child
        if(root->right != NULL)
            rightBoundary(root->right, ans);
        else
            rightBoundary(root->left, ans);
        // push after recursive call bcoz we want nodes from bottom to top 
        ans.push_back(root->data);
    }

    vector<int> boundary(Node *root)
    {
        vector<int> ans;
        // root
        ans.push_back(root->data);
        // left nodes excluding leaf node
        leftBoundary(root->left, ans);
        // calling leaf boundary twice instead of once for single elm in subtree case eg: root has only left child or only right child
        leafBoundary(root->left, ans);
        leafBoundary(root->right, ans);
        // right nodes excluding leaf
        rightBoundary(root->right, ans);
        return ans;
    }