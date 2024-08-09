#include<bits/stdc++.h>
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
  very similar to flatten_bst ques
  but here we don'tdo prev->left = NULL bcoz it will disrupt the structure of binary tree 
  since we are using preorder traversal here so root->left  must be done after the left call completed
  */
  
  void pre(TreeNode *root, TreeNode *&prev) {
    if (!root) return;

// don't do prev->left = NULL here bcoz we're using preorder here
    prev->right = root;
    prev = root;

    TreeNode *left = root->left;
    TreeNode *right = root->right;

    // Flatten the left subtree
    pre(left, prev);

    // Ensure left child is NULL after flattening
    root->left = NULL;              // diffn step from flattenBST

    // Flatten the right subtree
    pre(right, prev);
}


    void flatten(TreeNode* root) {
        TreeNode * dummy = new TreeNode(-1);
        TreeNode * prev = dummy;
        pre(root, prev);
        prev->left = prev->right = NULL;
        root = dummy->right;
    }