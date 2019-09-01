#include<iostream>
using namespace std;

void merge(int arr[],int s,int e){
	int mid = (s+e)/2;
	int i=s;
	int j = mid+1;
	int k = s;
	int temp[100];

	while(i<=mid and j<=e){
		if(arr[i]<arr[j]){
			temp[k] = arr[i];
			i++; k++;
		}
		else{
			temp[k] = arr[j];
			j++; k++;
		}
	}
	while(i<=mid){
		temp[k] = arr[i];
		k++; i++;
	}
	while(j<=e){
		temp[k] = arr[j];
		j++; k++;
	}
	//Temp -> A (Copy back to original array a)
	for(int x=s;x<=e;x++){
		arr[x] = temp[x];
	}	
	return;
}

void mergeSort(int arr[],int s,int e){
	//base case
	if(s>=e){
		return;
	}
	
	//rec case
	//1. Divide into parts
	int mid = (s+e)/2;

	//2. Rec Sort the Two Parts
	mergeSort(arr,s,mid);
	mergeSort(arr,mid+1,e);

	//3. Merge the two parts
	return merge(arr,s,e);
}

int main(){
	int arr[] = {5,4,3,1,0};
	int n  = sizeof(arr)/sizeof(int);
	mergeSort(arr,0,n-1);

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}


	return 0;
}