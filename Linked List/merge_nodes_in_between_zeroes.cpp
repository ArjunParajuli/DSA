// You are given the head of a linked list, which contains a series of integers separated by 0's. 
// The beginning and end of the linked list will have Node.val == 0.
// For every two consecutive 0's, merge all the nodes lying in between them into a single node
//  whose value is the sum of all the merged nodes. The modified list should not contain any 0's.

// Input: head = [0,3,1,0,4,5,2,0]
// Output: [4,11]


ListNode* mergeNodes(ListNode* head) {
        ListNode * fast = head->next;
        ListNode * slow = head;
        ListNode * newLast = slow;
        int sum = 0;
        while(fast){
            if(fast->val != 0){
                sum += fast->val;
                fast = fast->next;
            }else{
                slow->val = sum;
                sum = 0;
                newLast = slow;
                slow = slow->next;
                
                fast = fast->next;
            }
        }
        newLast->next = NULL;
        return head;
    }