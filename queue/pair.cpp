#include<iostream>
#include<cstring>
using namespace std;

class Triplet{
	int a;
	int b;
	int c;
};

bool compare(pair<string,int> p1,pair<string int> p2){
	return p1.second < p2.second;
}

int main(){

	//Constructor
	pair<int,int> p(10,20);

	cout<<p.first<<" and "<<p.second<<endl;

	//Values assign
	pair<string,int> p1,p2;
	p1.first = "Mango";
	p1.second = 100;

	cout<<p1.first<<endl;
	cout<<p1.second + 1 <<endl;

	//Make Pair Fun
	p2 = make_pair("Guava",100);
	cout<<p2.first<<" and "<<p2.second<<endl;

	vector<pair<string,int> > v;
	v.push_back(p1);
	v.push_back(p2);

	//sort(...)

}