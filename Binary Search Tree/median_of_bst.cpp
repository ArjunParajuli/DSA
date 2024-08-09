#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

/*
brute force: find inorder traversal array and get median using the formula:- ((n+1)/2)th term for odd and average of mid two elms for even no. of elms

optimized: O(n) time and constant space, first morris traversal and find no. of nodes, 
again moris traversal to reach the particular nodes(n+1/2 and (n/2)+1 th nodes) to calculate median
*/

int countNodes(Node* root)
    {
        int ans=0;
        Node * curr = root;
        while(curr){
            // left child is null so visit curr and go right
            if(curr->left == NULL){
                ans++;
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
                    ans++;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
    
    float findMedianNodes(struct Node *root, int n){
        int i=0;
        int odd = (n+1)/2, oddVal = -1;
        int even1 = n/2, even1Val = -1;
        int even2 = (n/2) + 1, even2Val = -1;
        Node * curr = root; 
        while(curr){
            // left child is null so visit curr and go right
            if(curr->left == NULL){
                // instead of visiting node, we check these
                i++;
                if(i == odd) oddVal = curr->data;
                if(i == even1) even1Val = curr->data;
                if(i == even2) even2Val = curr->data;
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
                    // instead of visiting node, we check these
                    i++;
                    if(i == odd) oddVal = curr->data;
                    if(i == even1) even1Val = curr->data;
                    if(i == even2) even2Val = curr->data;
                    curr = curr->right;
                }
            }
        }
        float med = 0.0;
         if((n % 2) == 0){ 
            med = (even1Val + even2Val) / 2.0;
        }else{
             med = oddVal;
        }
        return med;
    }

float findMedian(struct Node *root)
{
   int n = countNodes(root);
   return findMedianNodes(root, n);
}