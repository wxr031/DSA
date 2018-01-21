#include <iostream>
struct listnode {
	int dest;
	listnode *next;
	listnode(): dest(0), next(nullptr) {};
	listnode(int dest): dest(dest), next(nullptr) {};
};
class graph {
	int V;
	listnode **head;
	void dfs_aux(int curr, bool *);
public:
	graph(int);
	void add_edge(int, int);
	void dfs();
#ifdef DEBUG
	void print();
#endif
};
graph::graph(int V) {
	this->V = V;
	head = new listnode *[V]();
}
void graph::add_edge(int source, int dest) {
	listnode *node = new listnode(dest);
	node->next = head[source];
	head[source] = node;
}
void graph::dfs_aux(int curr, bool *visited) {
	std::cout << curr << std::endl;
	visited[curr] = true;
	listnode *temp = head[curr];
	while (temp) {
		if (!visited[temp->dest])
			dfs_aux(temp->dest, visited);
		temp = temp->next;
	}
}
void graph::dfs() {
	bool *visited = new bool[V]();
	for (int i = 0; i < V; i ++)
		if (!visited[i])
			dfs_aux(i, visited);
	delete[] visited;
}
#ifdef DEBUG
void graph::print() {
	for (int i = 0; i < V; i ++) {
		listnode *temp = head[i];
		while (temp) {
			std::cout << temp->dest << " \n"[!temp->next];
			temp = temp->next;
		}
	}
}
#endif
int main() {
	graph G(4);
	G.add_edge(0, 1);
	G.add_edge(0, 2);
	G.add_edge(1, 2);
	G.add_edge(2, 0);
	G.add_edge(2, 3);
	G.add_edge(3, 3);
#ifdef DEBUG
	G.print();
#endif
	G.dfs();
	return 0;
}
