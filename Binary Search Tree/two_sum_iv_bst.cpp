

/*
- find inorder traversal and apply two pointer approach bcoz inorder gives sorted order
*/


    void inorderT(TreeNode* root, vector<int> &inorder){
        if(root == NULL) return;
        inorderT(root->left, inorder);
        inorder.push_back(root->val);
        inorderT(root->right, inorder);
    }

bool findTarget(TreeNode* root, int k) {
    vector<int> inorder;
    inorderT(root, inorder);
    int i=0, j=inorder.size()-1;
    while(i < j){
        if(inorder[i]+inorder[j] == k)
            return true;
        else if(inorder[i]+inorder[j] > k){
            j--;
        }else
            i++;
    }
    return false;
}