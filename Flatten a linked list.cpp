/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
Node*merge(Node*a,Node*b){
	if(b==nullptr) return a;
	if(a==nullptr) return b;
	Node*res = new Node(-1);
	Node*temp=res;
	while(a!=nullptr && b!=nullptr){
		if(a->data < b->data){
			temp->child = a;
			temp = temp->child;
			a=a->child;
		}
		else{
			temp->child= b;
			temp = temp->child;
			b = b->child;
		}
	}
	if(a) temp->child = a;
	else temp->child = b;
	return res->child;
}
Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if(head == nullptr) return head;

	
	Node* left = head;

	Node* sorted = flattenLinkedList(head -> next);

	left->next = NULL;

	Node* ans = merge(left, sorted);

	return ans;
}
