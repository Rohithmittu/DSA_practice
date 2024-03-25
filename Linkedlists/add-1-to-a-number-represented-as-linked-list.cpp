Node* newNode(int carry){
        Node* newNode = new Node(carry);
        newNode -> data = carry;
        newNode -> next  = NULL;
        return newNode;
    }
    Node* reverse(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        Node* next;
        
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    Node* addone(Node* head){
        Node* res = head;
        Node* temp;
        
        int carry = 1;
        int sum;
        
        while(head != NULL){
            sum = carry + head -> data;
            
            if(sum >= 10){
                carry = 1;
            }else{
                carry = 0;
            }
            sum = sum % 10;
            
            head -> data = sum;
            
            temp = head;
            head = head -> next;
        }
        
        if(carry > 0){
            temp -> next = newNode(carry);
        }
        
        return res;
        
        
        
    }
    public:
    Node* addOne(Node *head) 
    {
        
        head = reverse(head);
        
        head = addone(head);
        
        return reverse(head);
    }