#include <iostream>
#include <vector>
#include <list>
class graph {
	int vertex;
	std::list<int> *adj;
	void dfs_util(int, int, int &, std::vector<bool> &,
			std::vector<int> &, std::vector<int> &);
	public:
	graph(int vtx_num) {
		vertex = vtx_num;
		adj = new std::list<int>[vtx_num];
	}
	void add_edge(int, int);
	void bridge();
};
void graph::add_edge(int source, int dest) {
	adj[source].push_back(dest);
	adj[dest].push_back(source);
}
void graph::dfs_util(int id, int par, int &count, std::vector<bool> &visited
		,std::vector<int> &dfs_num, std::vector<int> &min_num) {
	visited[id] = true;
	dfs_num[id] = min_num[id] = ++count;
	std::list<int>::iterator it;
	for(it = adj[id].begin(); it != adj[id].end(); ++it) {
		if(par != *it) {
			if(!visited[*it]) {
				dfs_util(*it, id, count, visited, dfs_num, min_num);
				if(min_num[*it] > dfs_num[id])
					std::cout << id << " -- " << *it << std::endl;
			}
			min_num[id] = std::min(min_num[*it], min_num[id]);
		}
	}
}
void graph::bridge() {
	std::vector<bool> visited(vertex, false);
	std::vector<int> dfs_num(vertex);
	std::vector<int> min_num(vertex);
	int count = 0;
	dfs_util(0, -1, count, visited, dfs_num, min_num);
}
int main() {
	std::cout << "\nBridges in first graph \n";
	graph g1(5);
	g1.add_edge(1, 0);
	g1.add_edge(0, 2);
	g1.add_edge(2, 1);
	g1.add_edge(0, 3);
	g1.add_edge(3, 4);
	g1.bridge();

	std::cout << "\nBridges in second graph \n";
	graph g2(4);
	g2.add_edge(0, 1);
	g2.add_edge(1, 2);
	g2.add_edge(2, 3);
	g2.bridge();

	std::cout << "\nBridges in third graph \n";
	graph g3(7);
	g3.add_edge(0, 1);
	g3.add_edge(1, 2);
	g3.add_edge(2, 0);
	g3.add_edge(1, 3);
	g3.add_edge(1, 4);
	g3.add_edge(1, 6);
	g3.add_edge(3, 5);
	g3.add_edge(4, 5);
	g3.bridge();
	return 0;
}
