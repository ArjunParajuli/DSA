 #include<iostream>
 using namespace std;
 
 bool isSameTree(TreeNode* p, TreeNode* q) {
         if(p == NULL && q == NULL)
            return true;
        else if(p!=NULL && q!=NULL){
            if(p->val == q->val){
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            }
        }
    return false;
    }