void moveToFront(Node* head) 
{ 
  
  if(head == NULL || head -> next == NULL){

    return ;
  }

  Node* last = head;
  Node* secon_last = NULL:

  while(last -> next != NULL){
    secon_last = last;
    last = last -> next;

  }

  secon_last -> next = NULL;
  last -> next = head;

  head = last;
} 