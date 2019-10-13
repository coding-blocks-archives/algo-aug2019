#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;

void printHeap(priority_queue<int,vector<int>, greater<int> > h){
	//Copy Empty Print
	while(!h.empty()){
		cout<<h.top()<<" ";
		h.pop();
	}
	cout<<endl;
}

int main(){

	int no;
	int k = 3;
	//min heap
	priority_queue<int,vector<int>, greater<int> > h;
	int cs = 0;

	while(scanf("%d",&no)!=EOF){
		if(no==-1){
			//Query
			printHeap(h);
			continue;
		}

		if(cs<k){
			h.push(no);
			cs += 1;
		}
		else if(no > h.top()){
			//Push by Replacement
			h.pop();
			h.push(no);
		}		
	}
	return 0;
}