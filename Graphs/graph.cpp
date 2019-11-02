#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

template<typename T>
class Graph{

	unordered_map<T,list<T> > m;

public:
	Graph(){

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
	void dfsVisit(T node,unordered_map<T,bool> &visited){
		//.....Define the DFS Logic........
		visited[node] = true;
		cout<<node<<" ";

		for(auto nbr:m[node]){
			if(!visited[nbr]){
				dfsVisit(nbr,visited);
			}
		}
	}

	void dfs(){
		unordered_map<T,bool> visited;
		

		for(auto city_pair:m){
			T city = city_pair.first;
			if(!visited[city]){
				cout<<"Cluster : "
				dfsVisit(city,visited);
				cout<<endl;
			}
		}
	}
	void bfs(T start){
		queue<T> q;
		q.push(start);
		unordered_map<T,bool> visited;
		visited[start] = true;

		while(!q.empty()){
			T front = q.front();
			cout<<front<<" ,";
			q.pop();

			for(auto nbr:m[front]){
				if(!visited[nbr]){
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
	}
};


int main(){

	Graph<string> g;
	g.addEdge("Delhi","Amritsar");
	g.addEdge("Delhi","Jaipur");
	g.addEdge("Delhi","Lucknow");
	g.addEdge("Lucknow","Patna");
	g.addEdge("Lucknow","Bhopal");
	g.addEdge("Jaipur","Bhopal");
    g.addEdge("Mumbai","Pune")
	g.addEdge("Mumbai","Nagpur")


	g.bfs("Delhi");
	

	//g.dfs();
    g.print();


	return 0;
}