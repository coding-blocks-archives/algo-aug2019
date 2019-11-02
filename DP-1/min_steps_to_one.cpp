#include<iostream>
#include<climits>
using namespace std;

int minSteps(int n,int dp[]){
	//base case
	if(n==1){
		return 0;
	}
	//rec case
	if(dp[n]!=0){
		return dp[n];
	}
	int op1,op2,op3;
	op1 = minSteps(n-1,dp);
	op2 = n%2==0? minSteps(n/2,dp):INT_MAX;
	op3 = n%3==0? minSteps(n/3,dp):INT_MAX;
	int ans = min(op1,min(op2,op3)) + 1;
	return dp[n] = ans;
}
//Try to make bottom up code!

int minStepsBU(int n){
	int dp[100] = {0};
	dp[1] = 0;
	//Loop
	for(int i=2;i<=n;i++){
		int op1 = dp[i-1];
		int op2 = i%2==0?dp[i/2]:INT_MAX;
		int op3 = i%3==0?dp[i/3]:INT_MAX;
		int ans = min(op1,min(op2,op3)) + 1;
		dp[i] = ans;
	}
	return dp[n];
}

int main(){
	int dp[100] = {0};
	int n;
	cin>>n;
	cout<<minSteps(n,dp)<<endl;
	cout<<minStepsBU(n)<<endl;

	return 0 ;
}