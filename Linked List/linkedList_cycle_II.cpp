// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.


/* algo:
    first check if there is a cycle or not
    if yes then set slow = head
    move slow and fast both a step at a time and they'll meet at the starting of the loop
*/ 

/*
why this algo work?
-> since slow & fast are moving one step at a time after they meet
    so distance between head and cycle start point = a. distance betn point where slow & fast meet
*/

 ListNode *detectCycle(ListNode *head) {
        ListNode * fast = head;
        ListNode * slow = head;
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
            return NULL;
        }

        slow = head;
        // now move slow and fast both a step at a time and they'll meet at the starting of the loop 
        
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;

    }