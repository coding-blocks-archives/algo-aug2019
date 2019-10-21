#include<iostream>
using namespace std;

int editDis(string str1, string str2) {
	int m = str1.length();
	int n = str2.length();
	int dp[100][100] = {0};

	for (int i = 0; i <= m ; ++i)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0) {// if str1 is empty, insert all elements of str2
				dp[i][j] = j;
			}
			else if (j == 0) {// if str2 is empty, delete all elements of str1
				dp[i][j] = i;
			}
			else if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = 1 + min(dp[i][j - 1], // insert operation in str1
				                   min(dp[i - 1][j], // delete operation in str1
				                       dp[i - 1][j - 1]));// replace operation in str1
			}
		}
	}
	return dp[m][n];
}

int main(int argc, char const *argv[])
{
	string str1 = "friday";
	string str2 = "funabcdday";

	cout << editDis(str1, str2) << endl;
	return 0;
}