#include<iostream>
using namespace std;

int nqueen(int n,int row,int ld,int rd){
	//base case
	DONE = (1<<n)-1;
	if(row==DONE){
		return 1;
	}
	int pos = DONE & (~(row|ld|rd));


	//rec case
	int ans = 0;
	while(pos>0){
		int p = pos&(-pos);
		pos -= p;
		ans += nqueen(n,row|p,(ld|p)<<1,(rd|p)>>1);
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	cout<<nqueen(8,0,0,0)<<endl;

	return 0;
}