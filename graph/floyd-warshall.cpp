#include <iostream>
#include <list>
#include <vector>

class Graph {
	constexpr static int INF = 0x7fffffff;
	int vertex;
	int **adj, **path;
public:
	Graph(int);
	void add_edge(int, int, int);
	int shortest_path(int, int);
};
Graph::Graph(int v) {
	vertex = v;
	// initialize adjacecy matrix
	adj = new int *[v];
	for(int i = 0; i < v; ++i) {
		adj[i] = new int[v];
		std::fill(adj[i], adj[i] + v, INF);
	}
	for(int i = 0; i < v; ++i)
		adj[i][i] = 0;
	// initialize path
	path = new int *[v];
	for(int i = 0; i < v; ++i) {
		path[i] = new int[v];
		std::fill(path[i], path[i] + v, INF);
	}
	for(int i = 0; i < v; ++i)
		path[i][i] = -1;
}
void Graph::add_edge(int source, int dest, int weight) {
	adj[source][dest] = weight;
	path[source][dest] = source;
}
int Graph::shortest_path(int source, int dest) {
	// shortest distance
	int **dist = new int *[vertex];
	for(int i = 0; i < vertex; ++i) {
		dist[i] = new int[vertex];
	}
	for(int i = 0; i < vertex; ++i) {
		for(int j = 0; j < vertex; ++j) {
			dist[i][j] = adj[i][j];
		}
	}
	// shortest path
	int **par = new int *[vertex];
	for(int i = 0; i < vertex; ++i) {
		par[i] = new int[vertex];
	}
	for(int i = 0; i < vertex; ++i) {
		for(int j = 0; j < vertex; ++j) {
			par[i][j] = path[i][j];
		}
	}
	// dynamic programming
	for(int k = 0; k < vertex; ++k) {
		for(int i = 0; i < vertex; ++i) {
			for(int j = 0; j < vertex; ++j) {
				if(dist[i][k] != INF && 
						dist[k][j] != INF && 
						dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = k;
				}
			}
		}
	}
	for(int i = 0; i < vertex; ++i) {
		for(int j = 0; j < vertex; ++j) {
			std::cout << dist[i][j] << " \n"[j == vertex - 1];
		}
	}
	return dist[source][dest];
}
int main() {
	Graph g(4);
	g.add_edge(0,3,10);
	g.add_edge(2,3,1);
	g.add_edge(0,1,5);
	g.add_edge(1,2,3);
	std::cout << g.shortest_path(2,3) << std::endl;
	return 0;
}
