#include <iostream>
#include <list>
#include <vector>

class Graph {
	int vertex;
	std::list<int> *adj;
	std::vector<int> indegree;
	void print_all_topo_util(std::vector<bool>, std::vector<int> &);
public:
	Graph(int);
	void add_edge(int, int);
	void print_all_topo();
};
Graph::Graph(int V) {
	vertex = V;
	adj = new std::list<int>[V];
	indegree.resize(V, 0);
}
void Graph::add_edge(int source, int dest) {
	adj[source].push_back(dest);
	++indegree[dest];
}
void Graph::print_all_topo_util(std::vector<bool> visited, std::vector<int> &result) {
	bool end = true;
	for(int i = 0; i < vertex; ++i) {
		if(!visited[i] && !indegree[i]) {
			visited[i] = true;
			result.push_back(i);
			for(std::list<int>::iterator it = adj[i].begin(); it != adj[i].end(); ++it) {
				--indegree[*it];
			}
			print_all_topo_util(visited, result);
			for(std::list<int>::iterator it = adj[i].begin(); it != adj[i].end(); ++it) {
				++indegree[*it];
			}
			result.pop_back();
			visited[i] = false;

			end = false;
		}
	}
	if(end) {
		for(std::vector<int>::iterator it = result.begin(); it != result.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << "\n";
	}
}
void Graph::print_all_topo() {
	std::vector<int> result;
	std::vector<bool> visited(vertex, false);
	print_all_topo_util(visited, result);
}
int main() {
	Graph g(6);
	g.add_edge(5, 2);
	g.add_edge(5, 0);
	g.add_edge(4, 0);
	g.add_edge(4, 1);
	g.add_edge(2, 3);
	g.add_edge(3, 1);
	
	g.print_all_topo();
	return 0;
}
