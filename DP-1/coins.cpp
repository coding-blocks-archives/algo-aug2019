#include<iostream>
#include<climits>
using namespace std;


int minCoinsChange(int coins[],int m,int n,int *dp){
	//Base Case
	if(n==0){
		return 0;
	}
	//Rec Case
	if(dp[n]!=0){
		return dp[n];
	}
	int ans = INT_MAX;
	//Let make a call every subprob
	for(int j=0;j<m;j++){
		if(n-coins[j]>=0){
			int subprob = minCoinsChange(coins,m,n-coins[j],dp) + 1;
			if(subprob<ans){
				ans = subprob;
			}
		}
	}
	return dp[n] = ans;
}

int bottomUpCoins(int coins[],int m,int N){
	int dp[100]  = {0};

	for(int n=1;n<=N;n++){
		int ans = INT_MAX;
		for(int j=0;j<m;j++){
			if(n-coins[j]>=0){
				int subprob = dp[n-coins[j]]+1;
				if(subprob<ans){
					ans = subprob;
				}
			}
		}
		dp[n] = ans;
	}

	for(int i=0;i<=N;i++){
		cout<<dp[i]<<" ";
	}
	return dp[N];
}


int main(){
	int coins[] = {1,7,10};
	int n = 15;
	int m  = 3;
	int dp[100] = {0};
	//cout<<minCoinsChange(coins,m,n,dp)<<endl;
	bottomUpCoins(coins,m,n);
	
	return 0;
}