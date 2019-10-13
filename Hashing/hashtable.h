#include<iostream>
#include<cstring>
using namespace std;

template<typename T>
class Node{
public:
	string key;
	T value;
	Node* next;

	Node(string k,T v){
		key = k;
		value = v;
		next = NULL;
	}
	~Node(){
		if(next!=NULL){
			delete next;
		}
	}
};

template<typename T>
class Hashtable{
	Node<T> **table;
	int cs;
	int ts;
	int hashfn(string key){
		int idx = 0;
		int c = 1;

		for(int j=0;j<key.size();j++){
			idx = (idx + key[j]*c)%ts;
			c = (c*29)%ts;
		}
		return idx;
	}
	void rehash(){
		//Save the ptr to old table and make a new table
		Node<T>** oldTable = table;
		table = new Node<T>*[2*ts+1]; //Prime - HW
		int oldts = ts;
		ts = 2*ts+1;
		cs = 0;
		//init the new table with null ptrs
		for(int i=0;i<ts;i++){
			table[i] = NULL;
		}
		//Copy the elements from old table to new table
		for(int i=0;i<oldts;i++){
			Node<T>*temp = oldTable[i];

			while(temp!=NULL){
				string k = temp->key;
				T v = temp->value;
				insert(k,v);
				temp = temp->next; 
			}
			//remove the ith linked list
			if(oldTable[i]!=NULL){
				delete  oldTable[i];
			}
		}
		delete [] oldTable;
	}

public:
	Hashtable(int ds=7){
		cs = 0;
		ts = ds;
		table = new Node<T>*[ts];
		//Init 
		for(int i=0;i<ts;i++){
			table[i]  = NULL;
		}
	}
	void insert(string k,T val){
		int idx = hashfn(k);
		Node<T>* n = new Node<T>(k,val);

		//Insert at head of linked list at idx position
		n->next = table[idx];
		table[idx] = n;

		cs++;
		float load_factor = cs/float(ts);
		if(load_factor>0.7){
			rehash();
		}

	}
	void print(){
		//Iterate over buckets
		for(int i=0;i<ts;i++){
			cout<<i<<"->";
			Node<T>* temp = table[i];
			while(temp!=NULL){
				cout<<temp->key<<"->";
				temp = temp->next;
			}
			cout<<endl;
		}
	}
	void search(string key){

			

	}

};

