#include<iostream>
using namespace std;

char keypad[][10] = {"","","ABC","DEF","GHI","JKL",
"MNO","PQRS","TUV","WXYZ"};

void generate_keypad_strings(char number[],char output[],int i,int j){
	//base case
	if(number[i]=='\0'){
	    output[j] = '\0';
		cout<<output<<endl;
		return;
	}
	int digit = number[i] - '0';
	if(digit==1 or digit==0){
	    generate_keypad_strings(number,output,i+1,j);
	}
	for(int k=0;keypad[digit][k]!='\0';k++){
		char ch = keypad[digit][k];
		output[j] = ch;
		//call on the remaning part
		generate_keypad_strings(number,output,i+1,j+1);
	}
}

int main(){
	char number[10];
	char output[10];
	cin>>number;
	generate_keypad_strings(number,output,0,0);

	return 0;
}



