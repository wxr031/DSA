#include <iostream>
#include <limits>
#include <queue>
struct listnode {
	int dest, weight;
	listnode *next;
	listnode(int dest, int weight): dest(dest), weight(weight)
		, next(nullptr) {}
};
class graph {
	int V;
	int *dist, *path;
	listnode **head;
public:
	graph(int);
	void add_edge(int, int, int);
	void shortest_path(int);
	void print_solution();
};
graph::graph(int V) {
	this->V = V;
	for (int i = 0; i < V; i ++)
		head[i] = new listnode(i, 0);
}
void graph::add_edge(int source, int dest, int weight) {
	listnode *temp = new listnode(dest, weight);
	temp->next = head[source]->next;
	head[source]->next = temp;
}
void graph::shortest_path(int start) {
	listnode *source = head[start];
	dist = new int[V];
	path = new int[V];
	bool *visited = new bool[V]();
	std::fill(dist, dist + V, std::numeric_limits<int>::max());
	std::queue<listnode *> Q;
	Q.push(source);
	dist[source->dest] = 0;
	path[source->dest] = source->dest;
	while(!Q.empty()) {
		source = Q.front();
		Q.pop();
		visited[source->dest] = true;
		for(listnode *curr = head[source->dest]->next;
		  curr; curr = curr->next) {
			if(dist[source->dest] + curr->weight < dist[curr->dest]) {
				dist[curr->dest] = dist[source->dest] + curr->weight;
				path[curr->dest] = source->dest;
			}
			if(!visited[curr->dest])
				Q.push(curr);
		}
	}
}
void graph::print_solution() {
	for (int i = 0; i < V; i ++)
		std::cout << "dist: " << dist[i] << " path: " << path[i] << std::endl;
}
int main() {
	int N;
	std::cin >> N;
	graph G(N);
	int source, dest, weight;
	while(std::cin >> source >> dest >> weight) {
		G.add_edge(source, dest, weight);
	}
	G.shortest_path(0);
	G.print_solution();
	return 0;
}
