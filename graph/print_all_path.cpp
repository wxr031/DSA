#include <iostream>
#include <vector>
#include <list>
class Graph {
	int vertex;
	std::list<int> *adj;
	void print_path_util(int, int, std::vector<bool> &, int &);	
public:
	Graph(int);
	~Graph();
	void add_edge(int, int);
	void print_all_path(int, int);
};
Graph::Graph(int v) {
	vertex = v;
	adj = new std::list<int>[v];
}
Graph::~Graph() {
	delete[] adj;
}
void Graph::add_edge(int source, int dest) {
	adj[source].push_back(dest);
}
void Graph::print_path_util(int v1, int v2, std::vector<bool> &visited,
		int &count) {
	if(v1 == v2) {
		++count;
		return;
	}
	if(adj[v1].empty())
		return;
	visited[v1] = true;
	for(std::list<int>::iterator it = adj[v1].begin(); 
			it != adj[v1].end(); ++it) {
		if(!visited[*it]) {
			print_path_util(*it, v2, visited, count);
		}
	}
	visited[v1] = false;
}
void Graph::print_all_path(int v1, int v2) {
	std::vector<bool> visited(vertex, false);
	int count = 0;
	print_path_util(v1, v2, visited, count);
	std::cout << count << std::endl;
}
int main() {
	int test_num;
	std::cin >> test_num;
	while(test_num--) {
		int vertex, edge;
		std::cin >> vertex >> edge;
		Graph graph(edge);
		for(int i = 0, source, dest; i < edge; ++i) {
			std::cin >> source >> dest;
			graph.add_edge(source, dest);
		}
		int v1, v2;
		std::cin >> v1 >> v2;
		graph.print_all_path(v1, v2);
	}
	return 0;
}
