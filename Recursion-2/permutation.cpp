#include<iostream>
#include<set>
using namespace std;

void permute(char *input,int i,set<string> &s){
	//Base Case
	if(input[i]=='\0'){
		string temp(input);
		s.insert(temp);
		//cout<<input<<endl;
		return;
	}
	//Rec Case
	for(int j=i;input[j]!='\0';j++){
		swap(input[i],input[j]);
		permute(input,i+1,s);
	}
}


int main(){

	set<string> s;

	char input[100];
	cin>>input;
	permute(input,0,s);

	for(string k:s){
		cout<<k<<endl;
	}

	return 0;
}