#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    Node<int>*temp1 = first, *temp2 = second;
  Node<int>* dummy = new Node<int>(-1);
    Node<int>*temp = dummy;

    while(temp1 && temp2){
        if(temp1->data < temp2->data){
            temp->next=temp1;
            temp1=temp1->next;
            temp=temp->next;
        }
        else{
            temp->next=temp2;
            temp2=temp2->next;
            temp=temp->next;
        }
    }

    while(temp1){
        temp->next=temp1;
        temp1=temp1->next;
        temp=temp->next;
    }

    while(temp2){
        temp->next=temp2;
        temp2=temp2->next;
        temp=temp->next;
    }

    return dummy->next;
}
