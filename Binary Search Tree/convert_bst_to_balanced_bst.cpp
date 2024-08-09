

/*
- store inorder traversal in array, now make a node for mid elm and attach left part of arr to its left child and right to its right child, do this recursively 
- dry run for array 1,2,3,4,5,6,7,8,9,10
*/

 void inorderT(TreeNode* root, vector<int> &inorder){
        if(root == NULL) return;

        inorderT(root->left, inorder);
        inorder.push_back(root->val);
        inorderT(root->right, inorder);
    }

    TreeNode * construct(vector<int> &inorder, int s, int e){
        if(s > e) return NULL; // base condition

        int mid = (s+e)/2;
        TreeNode * root = new TreeNode(inorder[mid]); // make node for mid elm
        root->left = construct(inorder, s, mid-1); // left call
        root->right = construct(inorder, mid+1, e); // right ca;;

        return root; 
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        inorderT(root, inorder);
        return construct(inorder, 0, inorder.size()-1);
    }