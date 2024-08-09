 int length(ListNode * head){
        ListNode * temp = head;
        int len=0;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        return len;
    }


    ListNode* recursiveReverse(ListNode* &prev, ListNode * &current){
        if(current == NULL){
            return prev;    // previous is the head node at the last step
        }
        ListNode * nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;

        return recursiveReverse(prev, current);
    }

    ListNode* reverseList(ListNode* &head) {
        ListNode * prev = NULL;
        ListNode * current = head;
        return recursiveReverse(prev, current);
    }

     ListNode* middleNode(ListNode* head) {
       ListNode * slow = head;
       ListNode * fast = head;
        while(fast->next != NULL){
            fast = fast->next;
            if(fast->next != NULL){
                fast = fast->next;
                slow = slow->next;
            }
            
        }
        return slow;
    }

    bool isPalindrome(ListNode* head) {

        int n = length(head);
        ListNode * start = head;
        // find mid
        ListNode * mid = middleNode(head);
        if(n == 1)
            return true;
        // reverse the list from mid
        ListNode * secondStart = mid->next;
        secondStart = reverseList(secondStart);
        // after breaking list in two halves
        // check between two lists now
        int i=0;
        while(i < n/2){
            if(start->val == secondStart->val){
                start = start->next;
                secondStart = secondStart->next;
                i++;
            }else{
                return false;
            }
        }
        return true;
    }