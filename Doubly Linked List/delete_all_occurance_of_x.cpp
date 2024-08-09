#include<iostream>
using namespace std;

 struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; 


 
 void deleteAllOccurOfX(struct Node** head, int x) {
       struct Node * temp = *head;
       while(temp != NULL){
           if(temp->data == x){
            // set prevnode and nextnode just before and after temp
                struct Node * prevnode = temp->prev;
                struct Node * nextnode = temp->next;
            // prevnode is null when first elm is to be removed
                if(prevnode != NULL)
                    prevnode->next = nextnode;
             // nextnode is null when first elm is to be removed
                if(nextnode != NULL)
                    nextnode->prev = prevnode;
            // if head and temp are at same posn move head to nextnode for m
                if(temp == *head)
                    *head = nextnode;
            // delete the node 
                struct Node * tobedeleted = temp;
                temp = temp->next;
                delete(tobedeleted);
            }else
                temp = temp->next;
       }
}