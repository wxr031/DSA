#include <iostream>
#include <queue>
struct listnode {
	int dest;
	listnode *next;
	listnode(int dest): dest(dest), next(nullptr) {};
};
class graph {
	int V;
	listnode **head;
	bool *ancestor;
	void bfs_aux(int, bool *);
public:
	graph(int);
	void add_edge(int, int);
	void bfs();
	int *topological_sort();
	void print_result(int *);
};
graph::graph(int V) {
	this->V = V;
	ancestor = new bool[V]();
	head = new listnode *[V]();
}
void graph::add_edge(int source, int dest) {
	ancestor[dest] = true;
	listnode *node = new listnode(dest);
	node->next = head[source];
	head[source] = node;
}
void graph::bfs_aux(int curr, bool *visited) {
	std::queue<int> Q;
	Q.push(curr);
	while (!Q.empty()) {
		curr = Q.front();
		Q.pop();
		std::cout << curr << std::endl;
		visited[curr] = true;
		for (listnode *lptr = head[curr]; lptr; lptr = lptr->next)
			if (!visited[lptr->dest])
				Q.push(lptr->dest);
	}
}
void graph::bfs() {
	bool *visited = new bool[V]();
	for (int i = 0; i < V; i ++)
		if (!visited[i])
			bfs_aux(i, visited);
}
int *graph::topological_sort() {
	std::queue<int> Q;
	bool *visited = new bool[V]();
	int *result = new int[V];
	int curr, num = 0;
	for (int i = 0; i < V; i ++)
		if (!ancestor[i])
			Q.push(i);
	while (!Q.empty()) {
		curr = Q.front();
		std::cout << curr << std::endl;
		Q.pop();
		result[num ++] = curr;
		for (listnode *lptr = head[curr]; lptr; lptr = lptr->next)
			if (!visited[lptr->dest]) {
				visited[lptr->dest] = true;
				Q.push(lptr->dest);
			}
	}
	return result;
}
void graph::print_result(int *result) {
	for (int i = 0; i < V; i ++)
		std::cout << result[i] << " \n"[i == V - 1];
}
int main() {
	graph G(8);
	G.add_edge(7, 4);
	G.add_edge(5, 1);
	G.add_edge(7, 1);
	G.add_edge(3, 4);
	G.add_edge(3, 6);
	G.add_edge(1, 0);
	G.add_edge(1, 2);
	G.add_edge(4, 0);
	G.add_edge(1, 6);
	G.bfs();
	int *result = G.topological_sort();
	G.print_result(result);
	return 0;
}
