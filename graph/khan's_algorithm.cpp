#include <iostream>
#include <vector>
#include <list>
class graph {
	int vtx;
	std::vector<int> indegree;
	std::list<int> *adj;
	void backtrack(std::vector<int>, std::vector<bool>);
public:
	graph(int);
	void add_edge(int, int);
	void debug();
	void print_all_topological_sort();
};
graph::graph(int V) {
	vtx = V;
	adj = new std::list<int>[V];
	for(int i = 0; i < V; i ++)
		indegree.push_back(0);
}
void graph::add_edge(int src, int dest) {
	adj[src].push_back(dest);
	++indegree[dest];
}
void graph::backtrack(std::vector<int> result, std::vector<bool> visited) {
	if(result.size() == vtx) {
		std::vector<int>::iterator it;
		for(it = result.begin(); it != result.end() - 1; ++it)
			std::cout << *it << " ";
		std::cout << *it << std::endl;
		return;
	}
	for(int v = 0; v < vtx; ++v)
		if(!visited[v] && indegree[v] == 0) {
			result.push_back(v);
			visited[v] = true;
			std::list<int>::iterator it;
			for(it = adj[v].begin(); it != adj[v].end(); ++it)
				--indegree[*it];
			backtrack(result, visited);
			for(it = adj[v].begin(); it != adj[v].end(); ++it)
				++indegree[*it];
			visited[v] = false;
			result.pop_back();
		}
}
void graph::print_all_topological_sort() {
	std::vector<int> result;
	std::vector<bool> visited(vtx, false);
	backtrack(result, visited);
}
int main() {
	graph G(6);
	G.add_edge(5, 2);
	G.add_edge(5, 0);
	G.add_edge(4, 0);
	G.add_edge(4, 1);
	G.add_edge(2, 3);
	G.add_edge(3, 1);
	G.print_all_topological_sort();
	return 0;
}
