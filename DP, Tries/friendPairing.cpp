#include<iostream>
using namespace std;
int dp[100] = {0};
int comb(int n) {
	if (n <= 2)
	{
		return n;
	}
	if (dp[n] != 0) {
		return dp[n];
	}

	dp[n] = comb(n - 1) + (n - 1) * comb(n - 2);
	return dp[n];
}


int main(int argc, char const *argv[])
{
	int n  = 4;
	cout << comb(n) << endl;
	return 0;
}