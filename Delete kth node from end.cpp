/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
     Node*temp=head;
     int total = 0;
     while(temp){
         temp=temp->next;
         total++;
     }
     if(total == K) return head->next;
     int diff = total - K;
     temp=head;
     while(diff-->1 && temp){
         temp=temp->next;
     }
     if(temp->next)
     temp->next = temp->next->next;
     else temp->next = nullptr;
  return head;
}
