#include<iostream>
using namespace std;

int totalSetBits(int n){
	int setBits[100] = {0};
	setBits[1] = 1;
	int total =1;
	for (int i = 2; i <= n ; ++i)
	{
		if(i&1){ // one extra bit if no. is odd
			setBits[i] = setBits[i/2] + 1;
		}
		else{ // same no. of bits if no. is even
			setBits[i] = setBits[i/2];
		}
		total+=setBits[i];
	}
	return total;

}
int main(int argc, char const *argv[])
{
	int n = 5;
	cout<<totalSetBits(n)<<endl;
	return 0;
}