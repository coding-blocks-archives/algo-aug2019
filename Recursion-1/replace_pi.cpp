#include<iostream>
using namespace std;

void replacePi(char a[],int i){
	//Base Case
	if(a[i]=='\0'){
		return;
	}
	//Rec Case
	if(a[i]=='p' and a[i+1]=='i'){
		int j=i+2;
		while(a[j]!='\0'){
			j++;
		}
		//Shifting 
		while(j>=i+2){
			a[j+2] = a[j];
			j--;
		}
		a[i] = '3';
		a[i+1] ='.';
		a[i+2] = '1';
		a[i+3] = '4';
		replacePi(a,i+4);	
		return;
	}
	replacePi(a,i+1);
	return;
	
}

int main(){
	char a[100];
	cin>>a;
	replacePi(a,0);
	cout<<a<<endl;
	return 0;
}