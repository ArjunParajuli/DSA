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

  // VVVV IMP Ques
  /*
  four cases:
  i) not found then return null
  ii) left retruns not null and right returns null then ans is left one
  eg: 
            50
           /  \
          p    60
         /
        q

 iii)left retruns null and right returns not  null then ans is right one
  eg: 
            50
           /  \
          9    p
                \
                  q

    iv) both left and right return not null then root is the ans
    eg: 
        50
       /  \
      p    q
  */


  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if(root == NULL)
            return NULL;
         if(root == p)
            return p;
         if(root == q)
            return q;

        TreeNode* leftans = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightans = lowestCommonAncestor(root->right, p, q);

        if(leftans == NULL && rightans == NULL)
            return NULL;
        if(leftans == NULL && rightans != NULL)
            return rightans;
        if(leftans != NULL && rightans == NULL)
            return leftans;
        else
            return root;
    }

  int main(){

        return 0;
    }