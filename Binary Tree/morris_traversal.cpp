#include <bits/stdc++.h>
using namespace std;

 struct Node {
    int data;
    Node* left;
    Node* right;
};

/*
(refer to codehelp binary tree assignment)
Morris Traversal: traversal with constant space.
- Morris traversal decreases space to O(1), it aims to achieve an in-order traversal of the tree.
- Basically, inorder traversal mai recursion k baad jaha wapas jata tha wo wala node ka link store karlo for every node(using inorder predecessor) 
using the right pointer to point to inorder successor
- to find inorder predecessor of a node: go left and go right all the way

other traversals take O(n) space due to recursion calls.
algo:
- if left child is null, visit curr node
- if left child not null:
    find inorder predecessor of curr node
    point the inorder predecessor's right to curr node (bcoz curr node is the inorder successor of inorder predecessor node)
    

*/

 vector<int> inOrderMorris(Node* root)
    {
        vector<int> ans;
        Node * curr = root;
        while(curr){
            // left child is null so visit curr and go right
            if(curr->left == NULL){
                ans.push_back(curr->data);
                curr = curr->right;  // parent par jata hai if link bana hua tha toh
            }else{  // left child present
                // find inp and point its right to curr node
                Node * inp = curr->left;
                while(inp->right != curr && inp->right != NULL){ // inp->right=curr means we already did our job so avoid infinite loop
                    inp = inp->right;
                }
                // found inp so point it to curr node
                if(inp->right == NULL){ // inp->right=null means link nahi hai so banana hai
                    inp->right = curr;
                    // go left after making link
                    curr = curr->left;
                }else{ // link already bana hua hai so link hatawo and go right
                    inp->right = NULL;
                    ans.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }

