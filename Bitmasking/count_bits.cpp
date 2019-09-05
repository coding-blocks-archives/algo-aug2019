#include<iostream>
using namespace std;

int cntBits(int n){
	int cnt = 0;
	while(n>0){
		cnt = cnt + (n&1);
		n = n>>1;
	}
	return cnt;
}

int cntBitsFast(int n){
	int cnt=0;
	while(n>0){
		n = n&(n-1);
		cnt++;
	}
	return cnt;
}
int getIthBit(int n,int i){
	return (n>>i)&1;
}
void setIthBit(int &n,int i){
	n = (n|(1<<i));
}


int main(){
	int n;
	cin>>n;
	cout<<cntBits(n)<<endl;
	cout<<cntBitsFast(n)<<endl;
	setIthBit(n,1);
	cout<<n<<endl;

	return 0;
}
