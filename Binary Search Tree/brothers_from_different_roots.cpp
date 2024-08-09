#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

/*
brute force: for each node in root1, search x-(root1->data) in root2, if found, cnt++. Time: O(n1logn2) average in case of root2 balanced else O(n1n2) incase root2 unbalanced
better: store inorder of bst1 and reverse inorder of bst2 and (bst1[i]+bst2[j] == x), cnt++; else if(bst1[i]+bst2[j] < x)i++; else j++; (time: O(n), space: 2O(n)) 
This method also takes recursive stack space and also two vectors for inorder traversals. Isme pehle traverse karke fir ans k liye firse traverse hora hai

optimal: isme sath sath traverse vi karo and ans vi nikalte jawo. using stack to do traversal(inorder traversal using stack)
- inorder traverse root1 and reverse inorder traverse root2

*/

int countPairs(Node* root1, Node* root2, int x)
    {
        stack<Node *> s1, s2;
        Node * a = root1;
        Node * b = root2;
        int ansCnt = 0;
        while(1){
            
            // inorder in first tree so go to left first
            // --- Left for first tree
            while(a){
                s1.push(a);
                a = a->left;
            }
            
            // reverse inorder in second tree so go to right first
            // --- Right for second tree
            while(b){
                s2.push(b);
                b = b->right;
            }
            
            // anyone of the stack is empty then no way to get a pair, so stop
            if(s1.empty() || s2.empty()){
                break;
            }
            
            Node * atop = s1.top();
            Node * btop = s2.top();
            int sum = atop->data + btop->data;
            // pair found so continue inorder in both trees
            if(sum == x){ 
                // --- Node
                ansCnt++;
                s1.pop();
                s2.pop();
                
                // --- Right for first tree
                a = atop->right;
                
                // --- left for second tree
                b = btop->left;  
            }else if(sum < x){  // we need to increase sum to equal it to x 
                s1.pop();
                // --- Right for first tree
                a = atop->right;
            }else{              // we need to decrease sum to equal it to x 
                s2.pop();
                // --- left for second tree
                b = btop->left;
            }
        }
        return ansCnt;
    }