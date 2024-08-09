 #include<bits/stdc++.h>
 using namespace std;

 struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
 };

/*
Approach 1: 
- count all 0s 1s and 2s
- traverse the LL and update according to counts 

Approach 2(previous approach traverses LL twice, so do in one traversal):
- we should change the links
- traverse each node and point it to its appropriate node 
*/

 Node* segregate(Node *head) {
       Node * h1=nullptr, * h2=nullptr, * h0=nullptr, * c1=nullptr, * c2=nullptr, *c0=nullptr;
        Node * temp = head;
        while(temp){
            if(temp->data == 1){
                if(!h1){
                    h1 = temp;
                    c1 = temp;
                }else{
                c1->next = temp;
                c1 = c1->next;
                }
            }else if(temp->data == 2){
                if(!h2){
                    h2 = temp;
                    c2 = temp;
                }else{
                c2->next = temp;
                c2 = c2->next;
                }
            }else{
                if(!h0){
                    h0 = temp;
                    c0 = temp;
                }else{
                c0->next = temp;
                c0 = c0->next;
                }
            }
            temp = temp->next;
        }
        
        // terminate each list so that there wont be circular list formed
        if(c0) c0->next = nullptr;
        if(c1) c1->next = nullptr;
        if(c2) c2->next = nullptr;
        
        // link them
        if(c0){
            c0->next = h1 ? h1 : h2; // if h1 not null then link 1 nodes else directly link 2 nodes
        }
        if(c1){
            c1->next = h2;
        }
            
        // check proper head and return
        if(c0) return h0;
        if(c1) return h1;
        else return h2;
    }


 int main(){

    return 0;
 }