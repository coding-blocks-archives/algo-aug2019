#include<iostream>
using namespace std;

void inc(int n){
	if(n==0){
		return;
	}
	inc(n-1);
	cout<<n<<" ";
	return;
}
void dec(int n){
	//Base Case
	if(n==0){
		return;
	}
	cout<<n<<" ";
	dec(n-1);
	return;
}

int main(){

	int n;
	cin>>n;
	inc(n);
	dec(n);


	return 0;
}