#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n){
	//base case
	if(n==1){
		return;
	}
	//on entire array
	for(int i=0;i<=n-2;i++){
		if(arr[i]>arr[i+1]){
			swap(arr[i],arr[i+1]);
		}
	}
	bubbleSort(arr,n-1);

}

void bubbleSort2(int arr[],int i,int n){
	//base case
	if(n==1){
		return;
	}
	if(i==n-1){
		 bubbleSort2(arr,0,n-1);
		 return;
	}
	if(arr[i]>arr[i+1]){
		swap(arr[i],arr[i+1]);
	}
	bubbleSort2(arr,i+1,n);
	return;
}

int main(){
	int arr[] = {5,4,3,1,0};
	int n  = sizeof(arr)/sizeof(int);
	bubbleSort2(arr,0,n);

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}


	return 0;
}