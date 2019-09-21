#include<iostream>
#include<string>
using namespace std;


int main(){

	char a[1000];
	/*
	char ch = cin.get();
	int i = 0;
	while(ch!='\n'){
		//cout<<ch;
		a[i++] = ch;
		ch = cin.get();
	}
	*/
	cin.getline(a,1000,'\n');
	cout<<a;

	char *b = strtok(a," ");
	cout<<b<<endl;
	while(b!=NULL){
		b = strtok(NULL," ");
		cout<<b<<endl;
	}
	

	//Guava 10 Mango 20 Banana 50 



	return 0;
}