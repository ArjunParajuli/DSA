

/*
brute force: use any traversal and visit every node and increment sum, time:O(n) for both avg and worst 
optimized: worst will be O(n) but avg time will be O(height) 
*/

 void solve(TreeNode* root, int &low, int &high, int &sum){
        if(root == NULL) return;
        if(root->val >= low && root->val <= high){
            sum += root->val;
            solve(root->left, low, high, sum);
            solve(root->right, low, high, sum);
        }else if(root->val < low){
            solve(root->right, low, high, sum);
        }else{
            solve(root->left, low, high, sum);
        }
        
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        solve(root, low, high, sum);
        return sum;
    }