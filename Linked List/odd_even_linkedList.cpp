// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices,
//  and return the reordered list.
// Input: head = [2,1,3,5,6,4,7]
// Output: [2,3,6,7,1,5,4]
 

ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;

        ListNode * headOdd = head;
        ListNode * headEven = head->next;
        ListNode * lastOdd = head;
        ListNode * lastEven = head->next;
        while(lastOdd->next && lastEven->next){
            lastOdd->next = lastOdd->next->next;
            lastEven->next = lastEven->next->next;
            lastOdd = lastOdd->next;
            lastEven = lastEven->next;
        }
        lastOdd->next = headEven;
        lastEven->next = NULL;

        return headOdd;
    }