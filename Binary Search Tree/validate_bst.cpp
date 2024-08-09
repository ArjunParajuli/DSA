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

  /*
  - for each node, check check if node->val > lowerbound && node->val < upperbound 
  - each node->val must lie between lb and ub 
  - update lowerbound and upperbound accordingly for each recursive call
  */
 
 bool solve(TreeNode* root, long long lb, long long ub) {
        if(root == NULL) return true;

        bool leftans = solve(root->left, lb, root->val); // sent upper bound value as root->val bcoz left subtree must have all vals less than root->val
        bool rightans = solve(root->right, root->val, ub); // sent lower bound value as root->val

        // root->val betn lb & ub and both fet and right subtree must also be bst 
        if(root->val > lb && root->val < ub && leftans && rightans){
            return true;
        }
    return false;
    }

    bool isValidBST(TreeNode* root) {
       long long lb = LLONG_MIN, ub = LLONG_MAX;

        return solve(root, lb, ub);
    }