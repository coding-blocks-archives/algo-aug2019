#include<iostream>
using namespace std;

int gridWays(char board[][10],int i,int j,int m,int n){
	//BASE CASE
	if(i==m-1 and j==n-1){
		board[m-1][n-1] = '1';
		for(int x=0;x<m;x++){
			for(int y=0;y<n;y++){
				cout<<board[x][y]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		board[m-1][n-1] = '0';
		return 1;
	}
	if(i>=m or j>=n){
		return 0;
	}
	if(board[i][j]=='X'){
		return 0;
	}
	//Mark the currently visited cell
	board[i][j] = '1';

	int x = gridWays(board,i,j+1,m,n);
	int y = gridWays(board,i+1,j,m,n);

	//Unmark the currently visited cell (Backtracking)
	board[i][j] = '0';
	return x+y;
}

int main(){
	int m,n;
	char board[10][10] = { "0000X",
	                       "00X00",
	                       "000XX",
	                       "XX000",
	                     }; 
	
	cout<<gridWays(board,0,0,4,5)<<endl;

	return 0;
}