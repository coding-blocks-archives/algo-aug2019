#include<iostream>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
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

void root2Leaf(Node*root,vector<int> &v){
	//Base Case
	if(root==NULL){
		return;
	}
	//Leaf Node
	if(root->left==NULL and root->right==NULL){
		v.push_back(root->data);
		for(int i=0;i<v.size();i++){
			cout<<v[i]<<",";
		}
		cout<<endl;
		v.pop_back();
		return;
	}
	//Non Leaf Node
	v.push_back(root->data);
	root2Leaf(root->left,v);
	root2Leaf(root->right,v);
	//Backtracking
	v.pop_back();	
	return;
}

void verticalOrderPrint(Node*root,int d,map<int,vector<int> > m){
	//base case
	if(root==NULL){
		return;
	}
	m[d].push_back(root->data);
	verticalOrderPrint(root->left,d-1,m);
	verticalOrderPrint(root->right,d+1,m);
	return;
}

Node* levelInputToTree(){
	int data;
	cin>>data;
	Node*root = new Node(data);
	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		Node*f = q.front();
		q.pop();

		int c1,c2;
		cin>>c1>>c2;

		if(c1!=-1){
			f->left = new Node(c1);
			q.push(f->left);
		}
		if(c2!=-1){
			f->right = new Node(c2);
			q.push(f->right);
		}
	}
	return root;
}

int printAtKDist(Node*root,int target_data,int k){
	//Leaf Node
	if(root==NULL){
		return -1;
	}

	if(root->data==target_data){
		printAtLevelK(root,k);
		return 0;
	}
	//Search for the Node in the Left Substree
	int l = printAtKDist(root->left,target_data,k);
	if(l!=-1){
		int d = l;
		if(d+1==k){
			cout<<root->data<<" ";
		}
		else{
			printAtLevelK(root->right,k-d-2);
		}
		return d+1;
	}
	int r = printAtKDist(root->left,target_data,k);
	else if(r!=-1){
		int d = r;
		if(d+1==k){
			cout<<root->data<<" ";
		}
		else{
			printAtLevelK(root->left,k-d-2);
		}
		return d+1;
	}
	return -1;
}

class Pair{
public:
	int inc;
	int exc;

	Pair(){
		inc = exc = 0;
	}
}

Pair maxSumSubset(Node*root){
	//base case
	Pair p;
	if(root==NULL){
		return p;
	}
	//rec case
	Pair L = maxSumSubset(root->left);
	Pair R = maxSumSubset(root->right);

	p.inc = root->data + L.exc + R.exc;
	p.exc = max(L.inc,L.exc) + max(R.inc,R.exc);
	return p;
}



int main(){
	Node* root = NULL;
	root = buildTree(root);
	printLevelWise(root);

	vector<int> v;
	root2Leaf(root,v);

	//Hashmap
	map<int,vector<int> > m;

	verticalOrderPrint(root,0,m);

	//Iterate over all keys of hashmap from min to max
	for(auto p:m){
		int key = p.first;

		cout<<key<<"->";
		for(auto element:p.second){
			cout<<element<<",";
		}
		cout<<endl;
	}
	return 0;
}