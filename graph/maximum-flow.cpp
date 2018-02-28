#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <utility>

class Graph {
	int vertex;
	/* adjacency list */
	int **adj;

	bool bfs(int, int, std::vector<int> &);
public:
	Graph(int);
	void add_edge(int, int, int);
	int max_flow(int, int);
};

Graph::Graph(int v) {
	vertex = v;
	/* create adjacency matrix */
	adj = new int *[v];
	int *aux = new int[v * v](); // initialize to zero
	for(int i = 0; i < v; ++i, aux += v)
		adj[i] = aux;
}
void Graph::add_edge(int source, int dest, int cap) {
	adj[source][dest] = cap;
}
bool Graph::bfs(int source, int sink, std::vector<int> &path) {
	std::vector<bool> visited(vertex, false);
	std::queue<int> iqueue;
	iqueue.push(source);
	visited[source] = true;
	path[source] = -1;
	while(!iqueue.empty()) {
		int curr = iqueue.front();
		iqueue.pop();

		if(curr == sink)
			return true;
		for(int i = 0; i < vertex; ++i) {
			if(!visited[i] && adj[curr][i]) {
				
				/* mark node as visited */
				visited[i] = true;
				
				/* update parent node */
				path[i] = curr;
				
				iqueue.push(i);
			}
		}
	}
	return false;
}
int Graph::max_flow(int source, int sink) {
	std::vector<int> path(vertex);
	int max_flow = 0;
	while(bfs(source, sink, path)) {
		
		int min_flow = std::numeric_limits<int>::max();
		for(int i = sink; path[i] != -1; i = path[i]) {
			min_flow = std::min(min_flow, adj[path[i]][i]);
		}
		for(int i = sink; path[i] != -1; i = path[i]) {
			adj[path[i]][i] -= min_flow;
			adj[i][path[i]] += min_flow;
		}
		max_flow += min_flow;
	}
	return max_flow;
}
int main() {
	int v, e;
	std::cin >> v >> e;
	Graph graph(v);
	for(int i = 0, src, dst, wei; i < e; ++i) {
		std::cin >> src >> dst >> wei;
		graph.add_edge(src, dst, wei);
	}
	int s, t;
	std::cin >> s >> t;
	std::cout << graph.max_flow(s, t) << std::endl;
	return 0;
}
