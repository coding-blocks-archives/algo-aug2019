#include<iostream>
using namespace std;


int findUniq3(int *arr,int n){
	
	int freq[64] = {0};

	for(int i=0;i<n;i++){
		//Every bit of arr[i]
		int j = 0;
		int no = arr[i];
		while(no>0){
			int last_bit = (no&1);
			if(last_bit==1){
				freq[j]++;
			}
            j++;
			no = no>>1;
		}
	}
	//Take Mod 3
	int p=1;
	int ans=0;
	for(int i=0;i<64;i++){
		int digit= freq[i]%3;
		ans = ans + p*digit;
		p  = p<<1;
	}
	return ans;
}

int main(){

	int arr[] = {3,1,2,3,1,2,4,3,1,2};
	int n = sizeof(arr)/sizeof(int);
    cout<<findUniq3(arr,n);




	return 0;
}