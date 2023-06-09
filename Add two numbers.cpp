/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    Node*temp1 = num1, *temp2 = num2;
    Node*dummy = new Node(-1);
    Node*temp = dummy;
        int carry = 0;
        while(temp1 || temp2 || carry){
            int sum = (temp1?temp1->data:0) + (temp2?temp2->data:0) + carry;
            temp->next = new Node(sum%10);
            carry = sum/10;
            temp=temp->next;
            temp1 = (temp1?temp1->next:temp1);
            temp2 = (temp2?temp2->next:temp2);
        }
        return dummy->next;
}
