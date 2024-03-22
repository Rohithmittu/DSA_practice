 //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        
        if(head == NULL){
            return NULL;
        }
        
        Node* prev = NULL;
        Node* curr = head;
        
        unordered_map<int,bool>visited;
        
        while(curr != NULL){
            if(!visited[curr -> data]){
                visited[curr -> data] = true;
                prev = curr;
                curr = curr-> next;
                
            }else{
                prev -> next = curr -> next;
                delete(curr);
            }
            curr = prev -> next;
        }
        
        return head;
        
    }