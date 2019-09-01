#include<iostream>
using namespace std;

void subseq(char *input,char *output,int i,int j){
	//base case
	if(input[i]=='\0'){
		output[j] = '\0';
		cout<<output<<endl;
		return;
	}
	//rec case
	output[j] = input[i];
	subseq(input,output,i+1,j+1);
	//output[j] = '\0';
	subseq(input,output,i+1,j);

}

int main(){
	char input[100],output[100];
	cin>>input;
	subseq(input,output,0,0);


	return 0;
}