#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    if(!head) return head;
    LinkedListNode<int>*itr = head;
    LinkedListNode<int> *front=head;
    while(itr!=nullptr){
        front=itr->next;
        LinkedListNode<int> *copy = new LinkedListNode<int>(itr->data);
        itr->next=copy;
        copy->next=front;
        itr=front;
           if (front != nullptr) {
            front = front->next;
        }
    }
    itr=head;
    while(itr!=nullptr){
        if(itr->random!=nullptr)
        itr->next->random = itr->random->next;
        itr=itr->next->next;
    }
    LinkedListNode<int> *dummy = new LinkedListNode<int>(-1);
    itr=head;
    LinkedListNode<int> *res = dummy;
    while(itr!=nullptr){
        front = itr->next->next;
        res->next=itr->next;
        res=res->next;
        itr->next=front;
        itr=front;
    }
    return dummy->next;
}
