 void findAns(ListNode * &head, int &carry){
        if(head == NULL)
            return;

        findAns(head->next, carry);
        int num = head->val*2 + carry;
        head->val = num%10;
        carry = num/10; 
    }

    ListNode * insertAtBegining(ListNode * &head, int &carry){
        if(!head) return head;

        ListNode * newnode = new ListNode(carry);
        newnode->next = head;
        head = newnode;
        return head;
    }

    ListNode* doubleIt(ListNode* head) {
       int carry = 0;
        findAns(head, carry);
        if(carry){
            head = insertAtBegining(head, carry);
        }
        return head;
    }