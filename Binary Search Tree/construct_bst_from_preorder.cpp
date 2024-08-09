#include <iostream>
using namespace std;


/*
Brute force: For each elm in array, create node and put it in it's correct pos bcoz it is bst. time: O(n^2)
better: sort preorder to get inorder and make tree from these two traversals time: O(nlogn)+O(n) and extra space for array

optimized: traverse preorder and make node for each elm and specify range for each node and make recursive call time: O(n)
*/

 TreeNode * construct(vector<int>& preorder, int &preIndex, int minm, int maxm){
        if(preIndex >= preorder.size()){
            return NULL;
        }

        TreeNode *root = NULL;
         if (preorder[preIndex] > minm && preorder[preIndex] < maxm) {
            root = new TreeNode(preorder[preIndex++]);  // don't forget to increment
            root->left = construct(preorder, preIndex, minm, root->val);  // update range
            root->right = construct(preorder, preIndex, root->val, maxm);
        }
        
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int preIndex=0, minm=INT_MIN, maxm=INT_MAX;
        return construct(preorder, preIndex, minm, maxm);
    }