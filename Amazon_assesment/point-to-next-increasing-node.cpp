#include <bits/stdc++.h> 
/****************************************************************
	Following is the Linked list node structure already written:

	template <typename T>
	class LinkedListNode {
	public:
		T data;
		LinkedListNode* next;
		LinkedListNode* arbit;

		LinkedListNode(T data) {
			this->next = NULL;
			this-> arbit = NULL;
			this->data = data;
		}
	};

*****************************************************************/

LinkedListNode<int>* populateArbit(LinkedListNode<int>* head)
{
     LinkedListNode<int>* curr = head;

     while(curr -> next != NULL){

          LinkedListNode<int>* temp  = curr -> next;
           LinkedListNode<int>* maxNode = NULL;

           int max = INT_MIN;

           while(temp != NULL){

               if(temp -> data > max){
                   max = temp -> data;
                   maxNode = temp;
               }

            temp = temp -> next;


           }

           curr -> arbit = maxNode;

           curr = curr -> next;


     }

     return head;
}