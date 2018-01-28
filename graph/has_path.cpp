#include <iostream>
#include <vector>
#include <list>
class graph {
	int vtx;
	std::list<int> *adj;
	bool dfs(int, int, std::vector<bool>);
public:
	graph(int);
	void add_edge(int, int);
	bool has_path(int, int);
};
graph::graph(int V) {
	vtx = V;
	adj = new std::list<int>[V];
}
void graph::add_edge(int src, int dest) {
	adj[src].push_back(dest);
}
bool graph::dfs(int node1, int node2, std::vector<bool> visited) {
	std::cout << "here" << std::endl;
	visited[node1] = true;
	std::list<int>::iterator it;
	for(it = adj[node1].begin(); it != adj[node1].end(); ++it)
		if(*it == node2 || (!visited[*it] && dfs(*it, node2, visited)))
			return true;
	return false;
}
bool graph::has_path(int node1, int node2) {
	if(node1 == node2)
		return true;
	std::vector<bool> visited(vtx, false);
	return dfs(node1, node2, visited);
}
int main() {
	graph G(5);
	G.add_edge(0, 1);
	G.add_edge(0, 2);
	G.add_edge(1, 3);
	G.add_edge(2, 3);
	G.add_edge(3, 4);
	if(G.has_path(3, 2))
		std::cout << "There's path between the two vertices" << std::endl;
	else
		std::cout << "There's no path between the two vertices" << std::endl;
	return 0;
}
