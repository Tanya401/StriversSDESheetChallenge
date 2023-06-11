/****************************************************************

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


*****************************************************************/
//position of the cycle->next
Node *firstNode(Node *head)
{
    //Write your code here.
    Node*fast=head,*slow=head;
    bool hascycle = false;
    while(fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            hascycle = true;
            break;
        }
    }
   if(hascycle){
       slow = head;
       while(slow!=fast){
           slow=slow->next;
           fast=fast->next;
       }
       return slow;
   }
    return nullptr;
}