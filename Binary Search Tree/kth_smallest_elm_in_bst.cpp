

/*
Brute force: store inorder traversal in array and from there return kth elm of array but takes space

optimized: use inorder and decrement k after returning from a recursive call. when k=0, that root is the ans
*/

 void solve(TreeNode* root, int &k, int &ans){
        if(root == NULL) 
            return;
        
        // go to left most node first 
        //L
        solve(root->left, k, ans);
        // after reaching leftmost node, start decrementing k and check for answer
        // N
        k-=1;
        if(k == 0){
            ans = root->val;
            return;
        }

        // go to right after left call
        // R
        solve(root->right, k, ans);

    }

    int kthSmallest(TreeNode* root, int k){
        int ans = -1;
        solve(root, k, ans);
        return ans;
    }