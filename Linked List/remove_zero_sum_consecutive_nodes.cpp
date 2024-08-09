

/*
prefixSum-sum upto the curr node
- store a prefixSum and its curr node in a map for each node, agar aisa koi prefixSum miljaye jo hame pehle milchuka hai, then zero sum waley nodes milgaye hai
eg: 3+0=3, ek val par kuch add karneke baad vi wahi val milra hai, iska matlab jo add kiya gaya tha uska value 0 tha.
*/

ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> mp;
        // if head node is also to be removed then 0 must be present in map
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        mp[0] = dummy;
        ListNode * curr=head;
        int prefixSum = 0;
        while(curr){
            prefixSum += curr->val;
            // found in map so erase sum 0 nodes
            if(mp.find(prefixSum) != mp.end()){
                ListNode * temp = mp[prefixSum];
                ListNode * start = mp[prefixSum];
                int pSum = prefixSum;
                // erase the nodes from map whose sum makes 0
                while(temp != curr){
                    temp = temp->next;
                    pSum += temp->val;

                    if(temp != curr)
                        mp.erase(pSum);
                }
                start->next = curr->next;
            }else{
                mp[prefixSum] = curr;
            }
            curr = curr->next;
        }
        return dummy->next;
    }