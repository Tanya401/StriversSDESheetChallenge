/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.
     int n = 0;
     if(!head || !head->next) return head;
     Node*temp=head;
     while(temp){
          temp=temp->next;
          n++;
     }
     if(k>n) k=k%n;
     if(k==0)return head;
     temp=head;
     int diff = n-k;
     while(diff--){
          temp=temp->next;
     }
     Node*ans = temp;
     while(temp->next!=nullptr) temp=temp->next;
     temp->next=head;
     while(head->next!=ans) head=head->next;
     head->next=nullptr;
     return ans;
}