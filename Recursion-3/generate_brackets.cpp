#include<iostream>
using namespace std;

void generate_brackets(char *output,int open,int close,int i,int n){
	if(i==2*n){
		cout<<output<<endl;
		return;
	}
	//Open
	if(open<n){
		output[i] = '(';
		generate_brackets(output,open+1,close,i+1,n);

	}

	//Close
	if(close<open){
		output[i] = ')';
		generate_brackets(output,open,close+1,i+1,n);
	}

}

int main(){
	int n;
	cin>>n;
	char output[100];
	generate_brackets(output,0,0,0,n);


	return 0;
}