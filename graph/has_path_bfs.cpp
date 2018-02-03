#include <iostream>
#include <vector>
#include <queue>
#include <list>
class graph {
	int vtx;
	std::list<int> *adj;
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
bool graph::has_path(int node1, int node2) {
	std::queue<int> iqueue;
	std::vector<bool> visited(vtx, false);
	iqueue.push(node1);
	visited[node1] = true;
	while(!iqueue.empty()) {
		int curr = iqueue.front();
		iqueue.pop();
		std::list<int>::iterator it;
		for(it = adj[curr].begin(); it != adj[curr].end(); ++it) {
			if(*it == node2)
				return true;
			if(!visited[*it]) {
				iqueue.push(*it);
				visited[*it] = true;
			}
		}
	}
	return false;
}
int main() {
	graph G(5);
	G.add_edge(0, 1);
	G.add_edge(0, 2);
	G.add_edge(1, 3);
	G.add_edge(2, 3);
	G.add_edge(3, 4);
	if(G.has_path(0, 4))
		std::cout << "There's path between the two vertices" << std::endl;
	else
		std::cout << "There's no path between the two vertices" << std::endl;
	return 0;
}
