#include<iostream>
using namespace std;

void findUniq2(int *arr,int n){
	//First Step
	int xor_res = 0;
	for(int i=0;i<n;i++){
		xor_res = xor_res^arr[i];
	}
	//find the last set bit position in xor
	int temp = xor_res;
	int j = 0;
	while((temp&1)!=1){
		j++;
		temp = temp>>1;
	}
	//seprte those numbers from array which have 1 in jth position
	int mask = (1<<j);
	int a = 0;
	for(int i=0;i<n;i++){
		if((arr[i]&mask)>0){
			a = a^arr[i];
		}
	}
	//finally
	int b = xor_res^a;
	cout<<a<<" and "<<b<<endl;	
}


int main(){

	int arr[] = {1,2,3,4,4,5,2,1,7,3};
	int n = sizeof(arr)/sizeof(int);
	findUniq2(arr,n);

	return 0;
}