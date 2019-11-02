#include<iostream>
using namespace std;

int ways(int n,int k,int dp[]){
	//base case
	if(n==0){
		return 1;
	}
	//--
	if(dp[n]!=0){
		return dp[n];
	}

	//rec case
	int ans = 0;
	for(int jump=1;jump<=k;jump++){
		ans += (n-jump>=0? ways(n-jump,k,dp):0);
	}
	return dp[n] = ans;
}

//DP Optimised -HW
/*
dp[n] = 2*dp[n-1] - dp[n-k-1] if n>=k+1 e
	  = 2*dp[n-1] otherwise for n>=2
dp[0] = dp[1] = 1
*/


int main(){

	int n;
	int k;
	int dp[100] = {0};
	cin>>n>>k;
	cout<<ways(n,k,dp)<<endl;

	return 0;
}