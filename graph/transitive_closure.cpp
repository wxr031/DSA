#include <iostream>
#include <vector>
#include <list>
class graph {
	int vertex;
	std::list<int> *adj;
	void dfs(int, int, std::vector<std::vector<int> > &);
public:
	graph(int);
	void add_edge(int, int);
	void transitive_closure();
};
graph::graph(int v) {
	vertex = v;
	adj = new std::list<int>[v];
}
void graph::add_edge(int source, int dest) {
	adj[source].push_back(dest);
}
void graph::dfs(int curr, int reach, 
		std::vector<std::vector<int> > &matrix) {
	for(std::list<int>::iterator it = adj[reach].begin();
			it != adj[reach].end(); ++it) {
		if(!matrix[curr][*it]) {
			matrix[curr][*it] = 1;
			dfs(curr, *it, matrix);
		}
	}
}
void graph::transitive_closure() {
	std::vector<std::vector<int> >
		matrix(vertex, std::vector<int>(vertex, 0));
	for(int i = 0; i < vertex; ++i)
		dfs(i, i, matrix);
	for(int i = 0; i < vertex; ++i)
		for(int j = 0; j < vertex; ++j)
			std::cout << matrix[i][j] << " \n"[j == vertex - 1];
}
int main() {
	graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);

	g.transitive_closure();
    return 0;
}
