#include<iostream>
using namespace std;
//Top Down DP - Recursion + Memoisation
int fib(int n,int dp[]){
	//base case
	if(n==0 or n==1){
		return n;
	}
	//already computed 
	if(dp[n]!=0){
		return dp[n];
	}

	//recursive case
	int ans = fib(n-1,dp) + fib(n-2,dp);
	return dp[n] = ans;
}

//Bottom Up DP - Iterative 
int fibBU(int n){
	int dp[100] = {0};
	dp[1] = 1;

	for(int i=2;i<=n;i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];
}



int main(){
	int dp[100] = {0};
	int n;
	cin>>n;
	cout<<fib(n,dp);



	return 0;
}