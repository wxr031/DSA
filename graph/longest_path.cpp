#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <limits>
using Pair = std::pair<int, int>;
class graph {
	int vtx;
	std::list<Pair> *adj;
	std::vector<int> result;
	void dfs_util(int ,int&, std::vector<bool> &, std::vector<int> &);
public:
	graph(int);
	void add_edge(int, int, int);
	void topological_sort();
	int longest_path(int);
};
graph::graph(int V) {
	vtx = V;
	adj = new std::list<Pair>[V];
	result.resize(vtx);
}
void graph::add_edge(int src, int dest, int weight) {
	adj[src].push_back(std::make_pair(weight, dest));
}
void graph::dfs_util(int id, int &assign, std::vector<bool> &visited,
		std::vector<int> &result) {
	visited[id] = true;
	std::list<Pair>::iterator it;
	for(it = adj[id].begin(); it != adj[id].end(); ++it)
		if(!visited[(*it).second])
			dfs_util((*it).second, assign, visited, result);
	result[--assign] = id;
}
void graph::topological_sort() {
	std::vector<bool> visited(vtx, false);
	int assign = vtx;
	for(int i = 0; i < vtx; i ++)
		if(!visited[i])
			dfs_util(i, assign, visited, result);
}
int graph::longest_path(int start) {
	topological_sort();
	std::vector<int> dist(vtx, std::numeric_limits<int>::min());
	dist[start] = 0;
	int tmp;
	for(int i = 0; i < vtx; ++i)
		if(result[i] == start) {
			tmp = i;
			break;
		}
	int max = std::numeric_limits<int>::min();
	for(int i = tmp; i < vtx; ++i) {
		std::list<Pair>::iterator it;
		for(it = adj[i].begin(); it != adj[i].end(); ++it)
			if(dist[i] + (*it).first > dist[(*it).second]) {
				dist[(*it).second] = dist[i] + (*it).first;
				max = (dist[(*it).second] > max)
					? dist[(*it).second] : max;
			}
	}
	for(int i = tmp; i < vtx; ++i)
		std::cout << dist[i] << " \n"[i == vtx - 1];
	return max;
}
int main() {
	graph g(6);
    g.add_edge(0, 1, 5);
    g.add_edge(0, 2, 3);
    g.add_edge(1, 3, 6);
    g.add_edge(1, 2, 2);
    g.add_edge(2, 4, 4);
    g.add_edge(2, 5, 2);
    g.add_edge(2, 3, 7);
    g.add_edge(3, 5, 1);
    g.add_edge(3, 4, -1);
    g.add_edge(4, 5, -2);
	std::cout << g.longest_path(1) << std::endl;
	return 0;
}
