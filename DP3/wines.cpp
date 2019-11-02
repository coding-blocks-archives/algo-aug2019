#include<iostream>
using namespace std;

int dp[10][10] = {0};

int wines(int n,int arr[],int i,int j,int y){
	//base case
	if(i>j){
		return 0;
	}
	if(dp[i][j]!=0){
		return dp[i][j];
	}
	//rec case
	int op1  = arr[i]*y + wines(n,arr,i+1,j,y+1);
	int op2 = arr[j]*y  + wines(n,arr,i,j-1,y+1);
	return dp[i][j] = max(op1,op2);
}


int main(){
	int win[ ] = {3,1,5};
	int n = 3;
	wines(n,win,0,n-1,1);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}