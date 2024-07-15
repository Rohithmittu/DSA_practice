//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    struct Node * reverse(struct Node * node) {
        Node * prev = nullptr;
        Node * next = nullptr;
        
        while (node) {
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        
        return prev;
    }
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        num1 = reverse(num1), num2 = reverse(num2);
        
        Node * res = new Node((num1->data + num2->data) % 10), *temp = res;
        int r = (num1->data + num2->data) / 10;
        num1 = num1->next, num2 = num2->next;
        
        while (num1 and num2) {
            temp->next = new Node((num1->data + num2->data + r) % 10);
            r = (num1->data + num2->data + r) / 10;
            temp = temp->next;
            num1 = num1->next, num2 = num2->next;
        }
        
        while (num1) {
            temp->next = new Node((num1->data + r) % 10);
            r = (num1->data + r) / 10;
            num1 = num1->next;
            temp = temp->next;
        }
        
        while (num2) {
            temp->next = new Node((num2->data + r) % 10);
            r = (num2->data + r) / 10;
            num2 = num2->next;
            temp = temp->next;
        }
        
        if (r) temp->next = new Node(r);
        
        res = reverse(res);
        
        while (res->data == 0 and res->next) res = res->next;
        
        return res;
    }
    
    
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends