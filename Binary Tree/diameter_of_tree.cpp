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
 
/*
ans is either in left subtree or in right subtree or the sum of left height+right height
time: O(n^2)  bcoz, we are visiting each node(O(n)) and for each node we are finding the height (O(n))
*/

//  int height(TreeNode* root){
//         if(root == NULL)
//             return 0;
        
//         int leftHeight = height(root->left);
//         int rightHeight = height(root->right);
//         int totalHeight = max(leftHeight, rightHeight)+1;
//         return totalHeight;
//     }


    // int diameterOfBinaryTree(TreeNode* root) {
    //      if(root == NULL)
    //         return 0;

    //     int option1 = diameterOfBinaryTree(root->left);
    //     int option2 = diameterOfBinaryTree(root->right);
    //     int option3 = height(root->left)+height(root->right);
    //     int diameter = max(option1, max(option2,option3));
    //     return diameter;
    // }



/*
optimized: call height func once and modify it such that at each node find current diameter and update maximum diameter (height nikalte waqt hi diameter update karte raho)
diameter is basically the sum of left height and right height for every node, 
O(n) time bcoz visiting every node only once
*/ 
int height(TreeNode* root, int &diameter){
        if(root == NULL)
            return 0;
        
        int leftHeight = height(root->left, diameter);
        int rightHeight = height(root->right, diameter);
        // find currdiameter and update max diameter at every node
        int currDiameter = leftHeight+rightHeight;
        diameter = max(currDiameter, diameter);
        int totalHeight = max(leftHeight, rightHeight)+1;
        return totalHeight;
    }

    int diameterOfBinaryTree(TreeNode* root) {
         int diameter=0;
         height(root, diameter);  // it is not mandatory to store the result of a function with a return type when calling it in C++.
         return diameter;
    }

      int main(){

        return 0;
    }