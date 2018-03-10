#include <iostream>
class Graph {
	int vertex;
	std::list<int> *adj;
	std::vector<int> indegree;
public:
	Graph(int);
	~Graph();
	void add_edge(int, int);
	void dfs();
};
Graph::Graph(int v) {
	vertex = v;
	adj = new std::list<int>[v];
	indegree.resize(v, 0);
}
Graph::~Graph() {
	delete[] adj;
}
void Graph::add_edge(int source, int dest) {
	adj[source].push_back(dest);
}
bool Graph::color(int curr, int v, int label, std::vector<int> &ancestor, std::vector<bool> &visited) {
	if(curr == v) return true;
	visited[curr] = true;
	for(std::list<int>::iterator it = adj[curr].begin();
			it != adj[curr].end(); ++it) {
		if(!visited[*it]) {
			if(dfs(*it, v, label, ancestor, visited)) {
				
			}
		}
	}
}
void Graph::LCA(int v1, int v2) {
	std::vector<bool> visited(vertex, false);
	std::vector<int> ancestor(vertex, 0);
	enum {
		v1_anc = 1, cmn_anc
	};
	dfs()
}
