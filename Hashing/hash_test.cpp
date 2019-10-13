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

	h.print();


}