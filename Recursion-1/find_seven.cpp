#include<iostream>
using namespace std;

int first_7(int arr[],int n){
	//Base Case
	if(n==0){
		return -1;
	}
	//Current Or Remaning Array
	if(arr[0]==7){
		return 0;
	}

	int idx = first_7(arr+1,n-1);
	if(idx!=-1){
		return idx+1;
	}
	return -1;
}
int last_7(int arr[],int n){
	if(n==0){
		return -1;
	}
	//Current Or Remaning Array
	int idx= last_7(arr+1,n-1);
	if(idx!=-1){
		return idx + 1;	
	}

	if(arr[0]==7){
		return 0;
	}
	return -1;
}

int main(){

	int arr[] = {7,7,7,7,7};
	int n = sizeof(arr)/sizeof(int);
	cout<<first_7(arr,n)<<endl;
	cout<<last_7(arr,n)<<endl;
	
	return 0;
}