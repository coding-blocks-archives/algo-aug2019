#include<iostream>
using namespace std;

//Array - > Sorted or Not!

bool isSorted(int a[],int n){
	if(n==1){
		return true;
	}
	//Rec Case
	if(a[0]<a[1] and isSorted(a+1,n-1)){
		return true;
	}
	return false;
}

int main(){
	int arr[] = {1,3,2,5,7};
	if(isSorted(arr,5)){
		cout<<"SOrted";
	}
	else{
		cout<<"Unsorted!";
	}
	return 0;
}