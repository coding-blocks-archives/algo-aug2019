#include<iostream>
#include<queue>
using namespace std;


int main(){

	
	queue<char> q;
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

