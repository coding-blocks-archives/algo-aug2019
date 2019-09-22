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



int main(){
	Node* root = NULL;
	root = buildTree(root);
	preorderPrint(root);

	PairH p = isHtBalanced(root);
	if(p.balance){
		cout<<"Tree is height balanced";
	}
	else{
		cout<<"Not Height Balanced!";
	}
	cout<<endl;
	//printLevelWise(root);
	levelOrder(root);


	return 0;
}