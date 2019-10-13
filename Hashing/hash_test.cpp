#include<iostream>
#include "hashtable.h"
using namespace std;

int main(){
	Hashtable<int> h;
	h.insert("Mango",100);
	h.insert("Apple",50);
	h.insert("Guava",40);
	h.insert("banana",30);
	h.insert("litchi",20);
	h.insert("kiwi",10);

	int * price = h.search("banana");
	if(price==NULL){
		cout<<"banana not found";
	}
	else{
		cout<<"Banana costs "<<*price<<endl;
	}

	h.print();

	cout<<"Insert";
	h["Pineapple"] = 120;
	cout<<h["Pineapple"];
	cout<<"Update";
	h["Pineapple"] = 80;
	cout<<h["Pineapple"];
	
	return 0;
}