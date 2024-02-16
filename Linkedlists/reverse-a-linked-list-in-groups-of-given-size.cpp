struct node *reverseIt (struct node *head, int k)
    { 
        if(head == NULL){
            return head;
        }
        
        node* curr = head;
        node* next = NULL;
        node* prev = NULL;
        int count = 0;
        
        while(curr != NULL && count < k){
            
            next = curr->next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count++;
            
            
        }
        
        if(next != NULL){
            head -> next = reverseIt(next,k);
            
        }
        return prev;
    }