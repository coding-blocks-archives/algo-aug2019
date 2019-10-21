#include<iostream>
using namespace std;

int Knapsack(int n,int W,int* wt,int* val){

	int K[100][100] = {0};

	for (int i = 0; i <= n; ++i)//for items
	{
		for (int j = 0; j <= W ; j++)//for weight
		{
			if(i==0 || j==0){
				K[i][j]=0;
			}
			else if(wt[i-1] <= j){
			K[i][j] = max(K[i-1][j], //excluding (i-1)th item
						  val[i-1]+K[i-1][j-wt[i-1]]); //including (i-1)th item
			}
			else{ // weight of (i-1)th item > curr weight j
				K[i][j] = K[i-1][j];
			}
		}
	}

	return K[n][W];

}
int main(int argc, char const *argv[])
{	int n = 4;
	int W = 8;
	int wt[10] = {5,2,1,3};
	int val[10] = {100,70,50,80};

	cout<<Knapsack(n,W,wt,val)<<endl;

	return 0;
}