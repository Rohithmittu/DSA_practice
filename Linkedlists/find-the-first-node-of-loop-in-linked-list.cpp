/*struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
    public:
    Node* floyed(Node* head){
        if(head == NULL){
            return NULL;
        }
        
        Node* slow = head;
        Node* fast = head;
        
        while(slow != NULL && fast != NULL){
            
            slow = slow -> next;
            fast = fast -> next;
            
            if(fast -> next != NULL){
                fast = fast -> next;
            }
            
            if(slow == fast){
                return slow;
            }
            
        }
        
        return NULL;
    }
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head)
    {
        
        // if(head == NULL){
        //     return -1;
        // }
        
        // Node* intersect = floyed(head);
        
        // if(intersect == NULL){
        //     return -1;
        // }
        
        // Node* slow = head;
        
        // while(slow != intersect){
        //     intersect = intersect -> next;
        //     slow = slow -> next;
        // }
        
        // return slow -> data;
        
          if(head==NULL || head->next==NULL)
            return -1;
            
        Node *slow, *fast;
        slow=fast=head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast = fast->next->next;
            
            //if there exit a loop
            if(slow==fast)
            {
                slow=head;
                
                while(slow!=fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow->data;
            }
        }
        return -1;  //no loop found
        
    }
};