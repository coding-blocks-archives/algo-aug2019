#include<iostream>
using namespace std;


int ways(int n,int k){
	if(n==0){
		return 1;
	}
	if(n<0){
		return 0;
	}
	int ans = 0;
	for(int jump=1;jump<=k;jump++){
		ans += ways(n-jump,k);
	}
	return ans;
}

int main(){
	int n,k;
	cin>>n>>k;
	cout<<ways(n,k)<<endl;

	return 0;
}