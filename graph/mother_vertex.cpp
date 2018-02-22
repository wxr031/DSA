#include <iostream>
#include <list>
#include <vector>
class Graph {
	int vertex;
	std::list<int> *adj;
	void dfs_util(int, std::vector<bool> &);
public:
	Graph(int);
	void add_edge(int, int);
	int find_mother_vertex();
};
Graph::Graph(int vnum) {
	vertex = vnum;
	adj = new std::list<int>[vnum];
}
void Graph::add_edge(int source, int dest) {
	adj[source].push_back(dest);
}
void Graph::dfs_util(int curr, std::vector<bool> &visited) {
	visited[curr] = true;
	std::list<int>::iterator it;
	for(it = adj[curr].begin(); it != adj[curr].end(); ++it)
		if(!visited[*it])
			dfs_util(*it, visited);
}
int Graph::find_mother_vertex() {
	std::vector<bool> visited(vertex, false);
	int last;
	for(int i = 0; i < vertex; ++i) {
		if(!visited[i]) {
			last = i;
			dfs_util(i, visited);
		}
	}
	std::fill(visited.begin(), visited.end(), false);
	dfs_util(last, visited);
	for(int i = 0; i < vertex; ++i)
		if(!visited[i])
			return -1;
	return last;
}
int main() {
	Graph g(4);
	g.add_edge(0, 2);
	g.add_edge(1, 2);
	g.add_edge(2, 3);
	std::cout << "A mother vertex is " << g.find_mother_vertex() << std::endl;
	return 0;
}
