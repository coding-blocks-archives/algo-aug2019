#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){

	//-->Vector
	vector<int> v;
	for(int i=0;i<=10;i++){
		v.push_back(i);
	}
	v[0] = 100;

	// Print
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	//Sort
	sort(v.begin(),v.end());

	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}

	return 0;
}