#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Fruit{
public:	
	string name;
	int price;
	Fruit(string f,int p){
		name = f;
		price = p;
	}
};

bool compare(Fruit a,Fruit b){
	 if(a.price==b.price){
	 	return a.name < b.name;
	 }
	 return a.price<b.price;

}

int main(){

	int n;
	cin>>n;
	vector<Fruit> v;

	for(int i=0;i<n;i++){
		string n;int p;
		cin>>n>>p;
		Fruit  f(n,p);
		v.push_back(f);
	}

	//sort
	sort(v.begin(),v.end(),compare);
	//print
	for(int i=0;i<v.size();i++){
		cout<<v[i].name<<" "<<v[i].price<<endl;
	}


	return 0;
}