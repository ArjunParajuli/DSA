#include <iostream>
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

  int maxDepth(TreeNode* root) {  // height
        if(root == NULL)
            return 0;
        
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        int totalHeight = 1 + max(leftHeight, rightHeight);
        return totalHeight; 
    }

    int main(){

        return 0;
    }