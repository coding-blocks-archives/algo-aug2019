#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

bool compare(string s1,string s2){
	int l1 = s1.length();
	int l2 = s2.length();

	if(l1<l2){
		return true;
	}
	else if(l1==l2){
		return s1<s2;
	}
	else{
		return false;
	}

}

void subseq(char *input,char *output,int i,int j,vector<string> &v){
	//base case
	if(input[i]=='\0'){
		output[j] = '\0';
		//cout<<output<<endl;
		string s(output);
		v.push_back(s);
		return;
	}
	//rec case
	output[j] = input[i];
	subseq(input,output,i+1,j+1,v);
	//output[j] = '\0';
	subseq(input,output,i+1,j,v);

}

int main(){
	char input[100],output[100];
	vector<string> v;

	cin>>input;
	subseq(input,output,0,0,v);

	//All strings are stored in the vector
	sort(v.begin(),v.end(),compare);
	for(int i=0;i<v.size();i++){
		//cout<<v[i]<<" ";
	}

	//Print using a for each loop
	for(string s:v){
		cout<<s<<endl;
	}


	return 0;
}