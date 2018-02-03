#include <iostream>
#include <list>
enum color {black, grey, white};
class graph {
	int vtx;
	std::list<int> *adj;
public:
	graph(int);
	void add_edge(int, int);
	bool dfs(int, enum color *);
	bool has_cycle();
};
graph::graph(int V) {
	vtx = V;
	adj = new std::list<int>[V];
}
void graph::add_edge(int src, int dest) {
	adj[src].push_back(dest);
}
bool graph::dfs(int id, enum color *visited) {
	visited[id] = grey;
	std::list<int>::iterator it;
	for(it = adj[id].begin(); it != adj[id].end(); ++it) {
		if((visited[*it] == grey) || 
			(visited[*it] == white && dfs(*it, visited)))
				return true;
	}
	visited[id] = black;
	return false;
}
bool graph::has_cycle() {
	enum color *visited = new enum color[vtx];
	std::fill(visited, visited + vtx, white);
	for(int id = 0; id < vtx; id ++) {
		if(visited[id] == white && dfs(id, visited)) {
			delete[] visited;
			return true;
		}
	}
	delete[] visited;
	return false;
}
int main() {
	graph G1(5);
	G1.add_edge(1, 0);
	G1.add_edge(0, 2);
	G1.add_edge(2, 0);
	G1.add_edge(0, 3);
	G1.add_edge(3, 4);

	graph G2(3);
	G2.add_edge(0, 1);
	G2.add_edge(1, 2);

	if(G1.has_cycle())
		std::cout << "Graph contains cycle" << std::endl;
	else
		std::cout << "Graph does not contain cycle" << std::endl;

	if(G2.has_cycle())
		std::cout << "Graph contains cycle" << std::endl;
	else
		std::cout << "Graph does not contain cycle" << std::endl;
	return 0;
}
