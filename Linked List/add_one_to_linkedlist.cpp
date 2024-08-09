 #include<bits/stdc++.h>
 using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
 
 Node * rev(Node * &head){
        Node * prev = NULL;
        Node * curr = head;
        Node * nextPtr = head;
        while(nextPtr != NULL){
            nextPtr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextPtr;
        }
        return prev;
    }

    // algo:-
    // reverse
    // add one 
    // reverse
    
    Node* addOne(Node *head) 
    {
        head = rev(head);
        int carry = 1;
        Node * temp = head;
        while(temp->next != NULL){
            int sum = (temp->data + carry);
            int digit = sum % 10;
            carry = sum / 10;
            
            temp->data = digit;
            temp = temp->next;
            if(carry == 0)
                break;
        }
        // for last node 
        if(carry != 0){
            int sum = temp->data + carry;
            int digit = sum % 10;
            carry = sum / 10;
            
            temp->data = digit;
        }

        // if carry remain after last node eg: 99+1=100 case
        
        if(carry != 0){
            Node * newNode = new Node(carry);
            newNode->next = NULL;
            temp->next = newNode;
        }
        head = rev(head);
        return head;
    }