#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template<typename T>
class Graph{

	unordered_map<T,list<pair<T,int> > > m;

public:
	Graph(){

	}
	void addEdge(T u,T v,int wt,bool bidir=true){
		m[u].push_back(make_pair(v,wt));
		if(bidir){
			m[v].push_back(make_pair(u,wt));
		}
	}
	void print(){
		for(auto p:m){
			T src = p.first;
			auto l = p.second;

			cout<<src<<"->";
			for(auto dest_p:l){
				cout<<dest_p.first<<"-"<<dest_p.second<<" ,";
			}
			cout<<endl;
		}
	}
};


int main(){

	Graph<string> g;
	g.addEdge("Delhi","Amritsar",1);
	g.addEdge("Delhi","Jaipur",2);
	g.addEdge("Delhi","Lucknow",3);
	g.addEdge("Lucknow","Patna",4);
	g.addEdge("Lucknow","Bhopal",4);
	g.addEdge("Jaipur","Bhopal",5);
    g.print();


	return 0;
}