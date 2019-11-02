#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template<typename T>
class Graph{

	unordered_map<T,list<T> > m;
	int N;
public:
	Graph(int v){
		N = v;
	}
	void addEdge(T u,T v,bool bidir=true){
		m[u].push_back(v);
		if(bidir){
			m[v].push_back(u);
		}
	}
	void print(){
		for(auto p:m){
			T src = p.first;
			list<T> l = p.second;

			cout<<src<<"->";
			for(auto dest:l){
				cout<<dest<<",";
			}
			cout<<endl;
		}
	}
	//Depth First Search/Traversal
	int dfsVisit(T node,unordered_map<T,bool> &visited){
		//.....Define the DFS Logic........
		visited[node] = true;
		cout<<node<<" ";
		int ans = 1;

		for(auto nbr:m[node]){
			if(!visited[nbr]){
				ans += dfsVisit(nbr,visited);
			}
		}
		return ans;
	}

	int dfs(){
		unordered_map<T,bool> visited;
		int finalans = N*(N-1)/2;

		for(auto city_pair:m){
			T city = city_pair.first;
			if(!visited[city]){
				cout<<"Cluster : ";
				int ans = dfsVisit(city,visited);
				finalans -= ans*(ans-1)/2;
			}
		}
		return finalans;

	}
};


int main(){

	Graph<int> g(5);
	g.addEdge(0,1);
	g.addEdge(1,4);
	g.addEdge(2,3);

	cout<<g.dfs()<<endl;
    g.print();


	return 0;
}