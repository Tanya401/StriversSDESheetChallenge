#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
LinkedListNode<int>* reverse(LinkedListNode<int>*slow){
    LinkedListNode<int>*curr = slow;
    LinkedListNode<int>*prev = nullptr;
    while(curr){
        LinkedListNode<int>*next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(head==nullptr) return true;
   LinkedListNode<int>*slow=head;
   LinkedListNode<int>*fast=head;
   while(fast->next && fast->next->next){
       slow=slow->next;
       fast=fast->next->next;
   }
   if(fast->next) slow=slow->next;
   LinkedListNode<int>*temp=head;
   LinkedListNode<int>*rev = reverse(slow);
   while(temp && rev){
       if(temp->data != rev->data) return false;
    temp = temp->next;
    rev = rev->next;
   }
   return true;
}