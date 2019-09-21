#include<iostream>
#include "queue.h"
using namespace std;

class Person{
public:

};

int main(){

	Queue<Person> qp;
	Queue<char> q;
	for(int i=0;i<=7;i++){
		q.push(65+i);
	}

	q.pop();
	q.push(65+8);

	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}

	return 0;
}		

