#include <iostream>
#include <list>
class graph {
	int vtx;
	std::list<int> *adj;
public:
	graph(int);
	void add_edge(int, int);
	bool dfs(int, bool *, bool *);
	bool has_cycle();
};
graph::graph(int V) {
	vtx = V;
	adj = new std::list<int>[V];
}
void graph::add_edge(int src, int dest) {
	adj[src].push_back(dest);
}
bool graph::dfs(int id, bool *visited, bool *path_stack) {
	visited[id] = true;
	path_stack[id] = true;
	std::list<int>::iterator it;
	for(it = adj[id].begin(); it != adj[id].end(); ++it) {
		if((!visited[*it] && dfs(*it, visited, path_stack))
				|| path_stack[*it])
			return true;
	}
	return path_stack[id] = false;
}
bool graph::has_cycle() {
	bool *visited = new bool[vtx]();
	bool *path_stack = new bool[vtx]();
	for(int id = 0; id < vtx; ++id) {
		if(!visited[id] && dfs(id, visited, path_stack)) {
			delete[] visited;
			delete[] path_stack;
			return true;
		}
	}
	delete[] visited;
	delete[] path_stack;
	return false;
}
int main() {
	graph G(5);
	G.add_edge(0, 1);
	G.add_edge(0, 2);
	G.add_edge(1, 3);
	G.add_edge(2, 3);
	G.add_edge(3, 4);
	if(G.has_cycle())
		std::cout << "Graph contains cycle" << std::endl;
	else
		std::cout << "Graph does not contains cycle" << std::endl;
	return 0;
}
