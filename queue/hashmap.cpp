#include<iostream>
#include<unordered_map>
#include<cstring>
using namespace std;


int main(){

	unordered_map<string,int> m;
	//1. Insert
	m["Apple"]  = 100;
	//2. Way
	m.insert(make_pair("Mango",120));

	//3. Way
	pair<string,int> p("Gauva",30);
	m.insert(p);

	//LookUp
	cout<<m["Apple"]<<endl;

	//Delete 
	m.erase("Apple");

	//Key may not be present
	string key = "Apple";
	if(m.count(key)){
		cout<<m[key];
	}
	else{
		cout<<key<<" not present";
	}
	//iterate all over all key value pairs
	for(auto p:m){
		cout<<p.first<<" "p.second<<endl;
	}






	return 0;
}


