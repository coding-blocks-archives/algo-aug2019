#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node*next;

	Node(int d){
		data = d;
		next = NULL;
	}
	~Node(){
		if(next!=NULL){
			delete next;
		}	

	}
};


//Linked List
/*
class LinkedList{
	Node*head;
	LinkedList(){
		head = NULL;
	}
	void addNode(){
		...
	}

}
*/

void insertAtHead(Node* &head,int d){
	if(head==NULL){
		head = new Node(d);
		return;
	}
	Node* n = new Node(d);
	n->next = head;
	head = n;
}
void print(Node *head){
	while(head!=NULL){
		cout<<head->data<<"-->";
		head = head->next;
	}
	cout<<endl;
}
void insertInMiddleNode(Node* &head,int d,int p){
	if(p==0){
		insertAtHead(head,d);
		return;
	}
	//take p-1 jumps
	Node*t = head;
	for(int jump=1;jump<=p-1;jump++){
		t = t->next;
	}
	Node*n = new Node(d);
	n->next = t->next;
	t->next = n;
	return;
}

void deleteInMiddle(Node*&head,int d,int p){


	//Hint - 
	//

}

void reverse(Node*&head){
	Node*C = head;
	Node*P = NULL;
	Node* N = C->next;

	while(C!=NULL){
		N = C->next;
		C->next = P;
		P = C;
		C = N;
	}
	head = P;
	return;
}
//Recursively Reverse (O(N))
Node* reverseRec(Node*head){
	//Base Case
	if(head->next==NULL){
		return head;
	}
	//Rec Case
	Node*chotaHead = reverseRec(head->next);
	
	head->next->next = head;
	head->next = NULL;
	return chotaHead;
}

// MidPoint
Node*midpoint(Node*head){
	Node*slow = head;
	Node* fast =head->next;

	while(fast!=NULL and fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
// Merge Two LinkedLists
Node* merge(Node*a,Node*b){
	if(a==NULL){
		return b;
	}
	if(b==NULL){
		return a;
	}
	//rec case
	Node* t;
	if(a->data < b->data){
		t = a;
		t->next = merge(a->next,b);
	}
	else{
		t = b;
		t->next = merge(a,b->next);
	}
	return t;
}

Node* mergeSort(Node *l){
	//base case
	if(l==NULL or l->next==NULL){
		return l;
	}
	//mid 
	Node *mid = midpoint(l);
	Node*a = l;
	Node*b = mid->next;
	mid->next = NULL;

	a = mergeSort(a);
	b = mergeSort(b);

	return merge(a,b);
}



ostream& operator<<(ostream &o,Node*&head){
	print(head);
	return o;
}

int main(){
	
	Node *head = NULL;
	insertAtHead(head,5);
	insertAtHead(head,14);
	insertAtHead(head,2);
	insertAtHead(head,10);
	insertInMiddleNode(head,3,2);
	cout<<head;
	//reverse(head);
	head =reverseRec(head);
	cout<<head;
	head = mergeSort(head);
	cout<<head;

	delete head;


	return 0;
}