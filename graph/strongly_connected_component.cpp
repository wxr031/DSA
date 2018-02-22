#include <iostream>
#include <vector>
#include <list>
class graph {
	int vtx;
	std::list<int> *ord_adj, *rev_adj;
	void dfs(int, std::vector<bool>, std::list<int> *, int &);
public:
	graph(int);
	~graph();
	void add_edge(int, int);
	bool SCC();
};
graph::graph(int V) {
	vtx = V;
	ord_adj = new std::list<int>[V];
	rev_adj = new std::list<int>[V];
}
graph::~graph() {
	delete[] ord_adj;
	delete[] rev_adj;
}
void graph::add_edge(int src, int dest) {
	ord_adj[src].push_back(dest);
	rev_adj[dest].push_back(src);
}
void graph::dfs(int curr, std::vector<bool> visited,
		std::list<int> *adj, int &count) {
	visited[curr] = true;
	++count;
	std::list<int>::iterator it;
	for(it = adj[curr].begin(); it != adj[curr].end(); ++it)
		if(!visited[*it])
			dfs(*it, visited, adj, count);
}
bool graph::SCC() {
	std::vector<bool> visited(vtx, false);
	int count(0);
	dfs(0, visited, ord_adj, count);
	if(count != vtx)	
		return false;
	std::fill(visited.begin(), visited.end(), false);
	count = 0;
	dfs(0, visited, rev_adj, count);
	return count == vtx;
}
int main() {
	graph g1(5);
	g1.add_edge(0, 1);
	g1.add_edge(1, 2);
	g1.add_edge(2, 3);
	g1.add_edge(3, 0);
	g1.add_edge(2, 4);
	g1.add_edge(4, 2);
	g1.SCC() ? std::cout << "Yes\n" : std::cout << "No\n";

	graph g2(4);
	g2.add_edge(0, 1);
	g2.add_edge(1, 2);
	g2.add_edge(2, 3);
	g2.SCC() ? std::cout << "Yes\n" : std::cout << "No\n";
	return 0;
}
