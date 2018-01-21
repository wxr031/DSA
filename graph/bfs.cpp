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
	void bfs_aux(int, bool *);
public:
	graph(int);
	void add_edge(int, int);
	void bfs();
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
int main() {
	graph G(4);
	G.add_edge(0, 1);
	G.add_edge(0, 2);
	G.add_edge(1, 2);
	G.add_edge(2, 0);
	G.add_edge(2, 3);
	G.add_edge(3, 3);
	G.bfs();
	return 0;
}
