void linkdelete(struct Node  *head, int m, int n)
    {
        if(head == NULL)
            return;
            
       Node * temp = head;
       for(int i=0;i<m-1;i++){
           if(temp == NULL)
            return;
            
            temp = temp->next;
       }
       
       if(temp == NULL)
        return;
       
       // save mth node to link it with next node after deleting n nodes
       Node * prevLink = temp; 

       // skip n nodes and make temp point after n nodes
       for(int i=0;i<n+1;i++){
           if(temp == NULL)
                break;
                
            temp = temp->next;
       }
       // skip n nodes and link prevLink node to node after n nodes
        prevLink->next = temp;

        // recursively do this until end of list 
        linkdelete(temp, m, n);
    }

    // eg: m=1, n=2, [8 10 1 3]  output-> 8 3