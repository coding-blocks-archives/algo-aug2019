#include<iostream>
using namespace std;

int fact(int n){
	//Base Case
	if(n==0){
		return 1;
	}
	//Rec Case 
	int subProb = fact(n-1); //Assuming
	return n*subProb;
}

int main(){
	int n;
	cin>>n;
	cout<<fact(n)<<endl;
	return 0;
}