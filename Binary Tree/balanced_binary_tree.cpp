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
 
//  int height(TreeNode* root){
//         if(root == NULL)
//             return 0;

//         int leftHeight = height(root->left);
//         int rightHeight = height(root->right);
//         int totalHeight = max(leftHeight,rightHeight)+1;
//         return totalHeight;
//     }

    // time: O(n^2) bcoz we are calculationg height at every node
    // bool isBalanced(TreeNode* root) {
    //     // base case
    //     if(root == NULL)
    //         return true;
    //     if( abs(height(root->left)-height(root->right)) > 1 ){
    //         return false;
    //     }
    //     bool leftans = isBalanced(root->left);
    //     bool rightans = isBalanced(root->right);

    //     return leftans && rightans;
    // }



    /*
    optimized: inside height func har node par check karo if it is height balanced or not so takes O(n) time
    */

    int height(TreeNode* root, bool &ans){
        if(root == NULL) 
            return 0;
        int leftHeight = height(root->left, ans);
        int rightHeight = height(root->right, ans);
        if( ans && abs(leftHeight-rightHeight) > 1 ){
            ans = false;
        }
        return 1+max(rightHeight, leftHeight);
            
    }

    bool isBalanced(TreeNode* root) {
       bool ans = true;
       height(root, ans);
       return ans;
    }



    int main(){

        return 0;
    }