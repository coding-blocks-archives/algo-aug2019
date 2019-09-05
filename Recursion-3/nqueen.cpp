#include<iostream>
using namespace std;

bool isSafe(int board[][10],int i,int j,int n){
	//column queen
	for(int k=0;k<i;k++){
		if(board[k][j]==1)
			return false;
	}
	//diagonal 
	int x=i,y=j;
	while(x>=0 and y>=0){
		if(board[x][y]==1)
			return false;
		x--;
		y--;
	}
	//right diagonal
	x=i,y=j;
	while(x>=0 and y<n){
		if(board[x][y]==1)
			return false;
		x--;
		y++;
	}
	return true;
}


int nqueen(int board[][10],int i,int n){
	//base case
	if(i==n){
		//Print the board
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				cout<<board[x][y]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return 1;
	}
	//Try all columns in the current row
	int ans = 0;
	for(int j=0;j<n;j++){
		if(isSafe(board,i,j,n)){
			board[i][j] = 1;
			int remainingBoardWays = nqueen(board,i+1,n);
			ans += remainingBoardWays;
			board[i][j] = 0; //backtracking

		}
	}
	return ans;
}

int main(){
	int n;
	int board[10][10]={0};

	cin>>n;
	cout<<nqueen(board,0,n)<<endl;;

}