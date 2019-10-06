#include<iostream>
#include<cmath>
#include<queue>
using namespace std;


class Node{
public:
	int data;
	Node*left;
	Node*right;

	Node(int d){
		data = d;
		left = right = NULL;
	}

};
//Recursively Build the Tree
Node* buildTree(Node*root){
	int d;
	cin>>d;
	//Base Case
	if(d==-1){
		return NULL;
	}

	
	//Rec Case
	root = new Node(d);
	root->left = buildTree(root->left);
	root->right = buildTree(root->right);
	return root;
}
//Print
void preorderPrint(Node*root){
	//Base Case
	if(root==NULL){
		return;
	}

	//Rec Case
	cout<<root->data<<" ";
	preorderPrint(root->left);
	preorderPrint(root->right);

}
int height(Node*root){
	return root==NULL?0: 1+max(height(root->left),height(root->right));
}
int sum(Node*root){
	return root==NULL?0: root->data + sum(root->left) + sum(root->right);
}

int replaceBySum(Node*root){
	//Base Case
	if(root==NULL){
		return 0;
	}
	if(root->left==NULL and root->right==NULL){
		return root->data;
	}
	int temp = root->data;
	root->data = replaceBySum(root->left) + replaceBySum(root->right);
	return root->data + temp;
}
int diameter(Node*root){
	//Base Case
	if(root==NULL){
		return 0;
	}

	//Rec Case
	int op1 = height(root->left) + height(root->right);
	int op2 = max(diameter(root->left),diameter(root->right));
	return max(op1,op2);
}
class Pair{
public:
	int height;
	int diam;
};

Pair diameterOpt(Node*root){
	//Base Case
	Pair p;
	if(root==NULL){
		p.height = p.diam = 0;
		return p;
	}

	//rec case
	Pair L,R;
	L = diameterOpt(root->left);
	R = diameterOpt(root->right);

	p.height = max(L.height,R.height) + 1;
	int op1 = L.height + R.height;
	int op2 = max(L.diam,R.diam);
	p.diam = max(op1,op2);
	return p;
}

class PairH{
public:
	int height;
	bool balance;
};

PairH isHtBalanced(Node*root){
	//Base Case
	PairH p;
	if(root==NULL){
		p.height = 0;
		p.balance = true;
		return p;
	}
	//Rec Case
	PairH L,R;
	L = isHtBalanced(root->left);
	R = isHtBalanced(root->right);

	p.height = max(L.height,R.height) + 1;
	if(abs(L.height-R.height)<=1 and L.balance and R.balance){
		p.balance = true;
	}
	else{
		p.balance = false;
	}
	return p;
};

void printAtLevelK(Node*root,int k){
	//Base Case
	if(root==NULL){
		return;
	}
	if(k==1){
		cout<<root->data<<" ";
		return;
	}	
	//rec cas
	printAtLevelK(root->left,k-1);
	printAtLevelK(root->right,k-1);
	return;
}
void printLevelWise(Node*root){
	int ht = height(root);
	for(int i=1;i<=ht;i++){
		printAtLevelK(root,i);
		cout<<endl;
	}
	return;
}

void levelOrder(Node*root){
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){

		Node* f = q.front();
		if(f==NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}

		}
		else{
			cout<<f->data<<" ";
			q.pop();
			if(f->left!=NULL){
				q.push(f->left);
			}
			if(f->right!=NULL){
				q.push(f->right);
			}
		}
	}
}
Node* insertInBST(Node*root,int d){
	if(root==NULL){
		root = new Node(d);
		return root;
	}
	//otherwise
	if(d<root->data){
		root->left = insertInBST(root->left,d);
	}
	else{
		root->right = insertInBST(root->right,d);
	}
	return root;
}


Node* buildTree(){
	Node* root = NULL;
	int d;
	cin>>d;
	while(d!=-1){
		root = insertInBST(root,d);
		cin>>d;
	}
	return root;
}

Node*arr2bst(int a[],int s,int e){
	//Base Case
	if(s>e){
		return NULL;
	}
	int mid = (s+e)/2;
	Node*root = new Node(a[mid]);
	root->left = arr2bst(a,s,mid-1);
	root->right = arr2bst(a,mid+1,e);
	return root;
}

bool search(Node*root,int key){
	//base case
	if(root==NULL){
		return false;
	}
	if(root->data==key){
		return true;
	}
	if(key<root->data){
		return search(root->left,key);
	}
	return search(root->right,key);
}

class LL{
	public: 
		Node*head;
		Node*tail;
};

LL tree2LL(Node*root){
	
	LL l;
	if(root==NULL){
		l.head = l.tail = NULL;
		return l;
	}
	if(root->left==NULL and root->right==NULL){
		l.head = l.tail = root;
	}
	else if(root->left!=NULL and root->right==NULL){
		LL leftLL = tree2LL(root->left);
		leftLL.tail->right = root;
		l.head = leftLL.head;
		l.tail = root;
	}
	else if(root->left==NULL and root->right!=NULL){
		LL rightLL = tree2LL(root->right);
		root->right = rightLL.head;
		l.head = root;
		l.tail = rightLL.tail;
	}
	else{
		LL leftLL = tree2LL(root->left);
		LL rightLL = tree2LL(root->right);
		leftLL.tail->right = root;
		root->right = rightLL.head;
		l.head = leftLL.head;
		l.tail = rightLL.tail;
	}
	return l;

}



Node* removeNode(Node*root,int key){
	if(root==NULL){
		return NULL;
	}
	if(root->data==key){
		//This is the node to be deleted
		//3 cases - 0 , 1, 2 children
		//1. leaf node 
		if(root->left ==NULL and root->right==NULL){
			delete root;
			return NULL;
		}
		else if(root->left!=NULL and root->right==NULL){
			Node*temp = root->left;
			delete root;
			return temp;
		}
		else if(root->right!=NULL and root->left==NULL){
			Node*temp = root->right;
			delete root;
			return temp;
		}
		else{
			//find inorder successor
			Node*temp = root->right;
			while(temp->left!=NULL){
				temp = temp->left;
			}
			//copy the temp data to root
			root->data = temp->data;
			//rec delete the temp->data from right subtree
			root->right = removeNode(root->right,temp->data);
			return root;
		}

	}
	else if(key<root->data){
		root->left = removeNode(root->left,key);
	}
	else{
		root->right = removeNode(root->right,key);
	}
	return root;





}


int main(){


	Node* root = NULL;
	//root = buildTree();
	//levelOrder(root);
	int arr[] = {1,2,3,4,5,6,7};
	int n = sizeof(arr)/sizeof(int);

	root = arr2bst(arr,0,n-1);
	levelOrder(root);
	LL l = tree2LL(root);
	Node*temp = l.head;
	while(temp!=NULL){
		cout<<temp->data<<"-->";
		temp = temp->right;
	}

	//root = removeNode(root,5);
	//root = removeNode(root,4);




	return 0;
}