#include <iostream>
#include <queue>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

/*
use level order traversal and if null is found before any node left in the queue, the return false
*/

bool isCompleteTree(TreeNode* root) {
         queue<TreeNode*> q;
        bool nullFound = false;
        q.push(root);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            // null found so mark it
            if(front==NULL){
                nullFound = true;
            }else{
                // curr node is not null but null was already found before it hence return false
                if(nullFound)
                    return false;
                q.push(front->left);
                q.push(front->right);
            }
        }
        return true;
    }


// another method: if index > numberOfNodes then it is not a complete binary tree

int numOfNodes(TreeNode * root){
        if(!root) return 0;

        int leftans = numOfNodes(root->left);
        int rightans = numOfNodes(root->right);

        return leftans+rightans+1;
    }

    bool checkCBT(TreeNode* root, int i, int &n){
        if(!root) return true;
        if(i > n) return false;

        bool leftans = checkCBT(root->left, 2*i, n);
        bool rightans = checkCBT(root->right, 2*i+1, n);

        return leftans && rightans;
    }

    bool isCompleteTree(TreeNode* root) {
         int i=1;
         int n = numOfNodes(root);
         return checkCBT(root, i, n);
    }