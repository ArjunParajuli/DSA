// Given a linked list of N nodes such that it may contain a loop.
// Remove the loop from the linked list, if it is present, i.e. unlink the last node which is forming the loop.

void removeLoop(Node* head)
    {
        Node * fast = head;
        Node * slow = head;
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }
            if(slow == fast){
              break;
            }
        }
        // if we're out of loop and fast = NULL then there's no cycle
        // else we found cycle so set slow to head

        if(fast == NULL){
            return ;
        }
        slow = head;

        // now move slow and fast both a step at a time and they'll meet at the starting of the loop 
        while(slow != fast){
            fast = fast->next;
            slow = slow->next;
        }
        
        // set curr to cycle start point
        Node * curr = slow;
        while(curr->next != fast){
            curr = curr->next;
        }
        // curr is before the cycle start position
        curr->next = NULL;
        
    }