

/*
- the given binary tree must follow two properties: 
- it must be a complete bt
- it must follow max order property(every node greater than its child nodes)
*/

 int numOfNodes(struct Node* root){
        if(!root) return 0;

        int leftans = numOfNodes(root->left);
        int rightans = numOfNodes(root->right);

        return leftans+rightans+1;
    }

    bool checkCBT(struct Node* root, int i, int &n){
        if(!root) return true;
        if(i > n) return false;

        bool leftans = checkCBT(root->left, 2*i, n);
        bool rightans = checkCBT(root->right, 2*i+1, n);

        return leftans && rightans;
    }
  
     bool hasHeapProperty(struct Node* root){
        if(!root) return true;
        
        bool leftans = hasHeapProperty(root->left);
        bool rightans = hasHeapProperty(root->right);
        
        bool currans = false;
        if(!root->left && !root->right) 
            currans = true;
        else if(root->left && !root->right)
            currans = root->data > root->left->data;
        else if(!root->left && root->right)
            currans = root->data > root->right->data;
        else
            currans = root->data > root->right->data && root->data > root->left->data;

        return leftans && rightans && currans;
        
    }
  
    bool isHeap(struct Node* tree) {
        int n = numOfNodes(tree);
        return checkCBT(tree, 1, n) && hasHeapProperty(tree);
    }