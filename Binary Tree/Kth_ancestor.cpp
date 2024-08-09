
// use preorder traversal to search for the node, if found then return 1 and decrement k, when k becomes 0 return that node   

int solve(Node *root, int &k, int node, int &ans) {
    if (root == nullptr) return 0; // Indicates node not found

    if (root->data == node) {
        k--; // Decrement k once when node is found
        return 1; // Indicates node found
    }

    int leftFound = solve(root->left, k, node, ans);
    if (leftFound) { // If node found in the left subtree
        if (k == 0) // If k becomes zero after traversing left subtree
            ans = root->data; // Update ans
        k--; // Decrement k
        return 1; // Indicates node found
    }

    int rightFound = solve(root->right, k, node, ans);
    if (rightFound) { // If node found in the right subtree
        if (k == 0) // If k becomes zero after traversing right subtree
            ans = root->data; // Update ans
        k--; // Decrement k
        return 1; // Indicates node found
    }

    return 0; // Indicates node not found
}

int kthAncestor(Node *root, int k, int node)
{
    int ans = -1;
    int res = solve(root, k, node, ans);
    return res==0 ? -1 : ans;
}