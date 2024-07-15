//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
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
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends