 vector<int> ans={-1,-1};
        ListNode* prev=head;
        if(!prev) return ans;
        ListNode* curr=prev->next;
        if(!curr) return ans;
        ListNode* next=curr->next;
        if(!next) return ans;

        int first=-1;
        int last=-1;
        int minDiff=INT_MAX;
        int i=1;
        while(next){
            
            bool iscriticalPoint=((curr->val>prev->val && curr->val>next->val)||(curr->val<prev->val&&curr->val<next->val))?true:false;
            if(iscriticalPoint&&first==-1){
                first=i;
                last=i;
            }
            else if(iscriticalPoint){
                minDiff=min(minDiff,i-last);
                last=i;
            }
            i++;
            prev=curr;
            curr=next;
            next=next->next;
        }
        if(first==last)
         return ans;
         else
         {
             ans[0]=minDiff;
             ans[1]=last-first;
         }
         return ans;