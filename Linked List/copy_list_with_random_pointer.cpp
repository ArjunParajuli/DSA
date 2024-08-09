#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

/*
// refer to striver 
Time: O(n)+O(n)+O(n)
*/

 Node* copyRandomList(Node* head) {
        Node * temp = head;
        Node * cloneHead = NULL;
        // step 1: make a deep copy of the original list
        while(temp != NULL){
            Node * newnode = new Node(temp->val);
            if(temp == head)
                cloneHead = newnode;
            // each original node's next will now point to deep copy nodes
            newnode->next = temp->next;
            temp->next = newnode;
            temp = temp->next->next;
        }
        // step 2: point the random pointers to their appropriate deep copy nodes
        Node * curr = head;  // curr node points to original list's head
        while(curr != NULL){
            if(curr->random != NULL)
                curr->next->random = curr->random->next;
            else 
                curr->next->random = NULL;
            curr = curr->next->next;
        }
        // step 3: point next pointer of both list to their appropriate nodes
        Node * ogTemp = head; // points to original nodes
        Node * clTemp = cloneHead; // points to deep copy nodes
        while(ogTemp != NULL){
            ogTemp->next = clTemp->next;
            ogTemp = ogTemp->next;
            if(ogTemp != NULL)
                clTemp->next = ogTemp->next;
            clTemp = clTemp->next;
        }
        return cloneHead;
    }
 