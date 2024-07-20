//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
   Node* reverse_list(Node* head)
    {
        Node* prev = NULL;     
        Node* curr = head;   
        Node* next; 
        
        while(curr)
        {
            next = curr->next; 
            curr->next = prev;    
            prev = curr;         
            curr = next; 
        }
        return prev;
        
    }
    
    //Function to check whether two lists are identical.
    bool is_identical(Node* n1, Node* n2)
    {
        //iterating over both lists and returning 0 if data at any node
        //is not equal in both lists.
        for(  ; n1 && n2 ; n1=n1->next, n2=n2->next )
            if( n1->data != n2->data )
                return 0;
                
        //returning 1 if data at all nodes are equal.
        return 1;
    }
    
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        int size=0;
        Node* ptr;
        //finding number of nodes in the list.
        for( ptr=head ; ptr ; ptr=ptr->next )
            size++;
            
        
        if(size<2) return 1;
        
        //now, we split list into 2 halves. In case of odd number of elements, 
        //first half will have the middle element.
        
        ptr = head;
        int mid_pt = (size-1)/2;
        
        //using a pointer to get to middle element to get the second half of list.
        while(mid_pt--)
            ptr = ptr->next;
            
        //ptr now holds address of last element of first half.
        
        //storing the elements of second half separately in head2.
        Node* head2 = ptr->next;
        ptr->next = NULL;     
        
        //we reverse the second half of list.
        head2 = reverse_list(head2);
        
        //we check whether both halves are identical (for odd number of elements
        //first half will have one extra element).
        bool ret = is_identical(head, head2);
        
    }

//      bool ispalin(string s){
//       int e = s.size() - 1;
//       int st = 0;
      
//       while(st<=e){
//           if(s[st] == s[e]){
//               st++;
//               e--;
//           }else{
//               return false;
//           }
//       }
      
//       return true;
      
//   }
//     //Function to check whether the list is palindrome.
//     bool isPalindrome(Node *head)
//     {
//         Node* temp = head;
//         string s;
//         while(temp != NULL){
//             s.append(to_string(temp-> data));
//             temp = temp -> next;
//         }
//         return ispalin(s);
//     }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends