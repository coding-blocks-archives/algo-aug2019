#include<iostream>
using namespace std;

int multiply(int a,int b){
	if(b==0){
		return 0;
	}
	return a + multiply(a,b-1);
}
int power(int a,int b){
	if(b==0){
		return 1;
	}
	return a*power(a,b-1);
}
int fastPower(int a,int b){
	if(b==0){
		return 1;
	}
	//Rec Case
	int subProb = fastPower(a,b/2);
	subProb = subProb*subProb;
	if(b%2==0){
		return subProb;
	}
	return a*subProb;

}

int main(){
	int a,b;
	cin>>a>>b;
	cout<<multiply(a,b)<<endl;
	cout<<power(a,b)<<endl;
	cout<<fastPower(a,b)<<endl;

	return 0;
}