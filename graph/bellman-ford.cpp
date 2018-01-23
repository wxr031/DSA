#include <iostream>
#include <limits>
struct listnode {
	int dest, weight;
	listnode *next;
	listnode(int dest, int weight): dest(dest), weight(weight)
		, next(nullptr) {}
};
class graph {
	int V;
	listnode **head;
	int *dist, *path;
	listnode **path_aux;
public:
	graph(int);
	void add_edge(int, int, int);
	int shortest_path(int);
	void print();
};
graph::graph(int V) {
	this->V = V;
	head = new listnode *[V]();
}
void graph::add_edge(int source, int dest, int weight) {
	listnode *temp = new listnode(dest, weight);
	temp->next = head[source];
	head[source] = temp;
}
int graph::shortest_path(int source) {
	dist = new int[V];
	path = new int[V];
	path_aux = new listnode *[V];
	std::fill(dist, dist + V, std::numeric_limits<int>::max());
	dist[source] = 0;
	path[source] = source;
	path_aux[source] = nullptr;
	bool flag = true;
	for(int i = 0; i < V && flag; i ++) {
		flag = false;
		for(int curr = 0; curr < V; curr ++) {
			for(listnode *lptr = head[curr]; lptr; lptr = lptr->next) {
				if(dist[curr] != std::numeric_limits<int>::max()
						&& dist[curr] + lptr->weight < dist[lptr->dest]) {
					dist[lptr->dest] = dist[curr] + lptr->weight;
					path[lptr->dest] = curr;
					path_aux[lptr->dest] = lptr;
					flag = true;
				}
			}
		}
	}
	// check negative cycle
	for(int i = 0; i < V; i ++)
		for(listnode *lptr = head[i]; lptr; lptr = lptr->next)
			if(path_aux[i] && 
					dist[path[i]] + path_aux[i]->weight < dist[i])
				return 1;
	return 0;
}
void graph::print() {
	for (int i = 0; i < V; i ++)
		std::cout << i << " dist: " << dist[i] << " path: " << path[i] << std::endl;
}
int main() {
	int N;
	std::cin >> N;
	graph G(N);
	int source, dest, weight;
	while(std::cin >> source >> dest >> weight) {
		G.add_edge(source, dest, weight);
	}
	if(G.shortest_path(0))
		std::cerr << "negative cycle" << std::endl;
	else G.print();
	return 0;
}
