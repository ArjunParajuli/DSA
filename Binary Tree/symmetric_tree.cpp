#include <bits/stdc++.h>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

  // time for both ques: O(n)
 
 // if both are null, true. else check their values, if vals same do the same for all other nodes 
 
 // three possible cases: 
 bool isSameTree(TreeNode* p, TreeNode* q) {
    // both are null
         if(p == NULL && q == NULL)
            return true;
    // both not null so check their values and do the same for their child nodes also
        else if(p!=NULL && q!=NULL){
            if(p->val == q->val){
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            }
        }
    // if any one of them is not null and other is null
    return false; // also reaches here when (p->val != q->val)
    }



// check if a tree is symmetric(mirror of itself)
// algo: divide the tree into left and right tree and
// just call isSameTree() function for left and right part of tree with a slight change
bool solve(TreeNode* p, TreeNode* q) {
         if(p == NULL && q == NULL)
            return true;
        else if(p!=NULL && q!=NULL){
            if(p->val == q->val){
                return solve(p->left, q->right) && solve(p->right, q->left); // opposite nodes must be same
            }
        }
    return false;
    }

    bool isSymmetric(TreeNode* root) {
        return solve(root->left, root->right);
    }