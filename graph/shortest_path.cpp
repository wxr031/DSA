#include <iostream>
#include <queue>
struct listnode {
	int data;
	listnode *next;
	listnode(int data): data(data), next(nullptr) {};
};
class graph {
	int V;
	listnode **head;
	int *dist, *path;
	void bfs_aux(int, bool *);
public:
	graph(int);
	void add_edge(int, int);
	void shortest_path(int);
	void print();
};
graph::graph(int V) {
	this->V = V;
	head = new listnode *[V]();
	dist = new int[V];
	std::fill_n(dist, V, -1);
	path = new int[V];
}
void graph::add_edge(int source, int data) {
	listnode *node = new listnode(data);
	node->next = head[source];
	head[source] = node;
}
void graph::shortest_path(int source) {
	std::queue<int> Q;
	Q.push(source);
	dist[source] = 0;
	while (!Q.empty()) {
		int vtx = Q.front();
		Q.pop();
		for (listnode *lptr = head[vtx]; lptr; lptr = lptr->next)
			if (dist[lptr->data] == -1) {
				Q.push(lptr->data);
				dist[lptr->data] = dist[vtx] + 1;
				path[lptr->data] = vtx;
			}
	}
}
void graph::print() {
	for (int i = 0; i < V; i ++)
		std::cout << i << " dist: " << dist[i] << " path: " << path[i] << std::endl;
}
int main() {
	graph G(7);
	G.add_edge(0, 1);
	G.add_edge(0, 2);
	G.add_edge(1, 4);
	G.add_edge(1, 3);
	G.add_edge(3, 6);
	G.add_edge(6, 5);
	G.add_edge(3, 4);
	G.add_edge(4, 2);
	G.add_edge(5, 2);
	G.add_edge(4, 5);
	G.shortest_path(0);
	G.print();
	return 0;
}
