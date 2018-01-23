#include <iostream>
#include <limits>
#include <utility>
#include <queue>
typedef std::pair<int, int> Pair;
struct listnode {
	int dest, weight;
	listnode *next;
	listnode(int dest, int weight): dest(dest), weight(weight), next(nullptr) {};
};
struct cmp {
	int operator() (const Pair &p1, const Pair &p2) {
		return p1.second > p2.second;
	}
};
class graph {
	int V;
	listnode **head;
	int *dist, *path;
	void bfs_aux(int, bool *);
	public:
	graph(int);
	void add_edge(int, int, int);
	void shortest_path(int);
	void print();
};
graph::graph(int V) {
	this->V = V;
	head = new listnode *[V]();
	dist = new int[V];
	std::fill(dist, dist + V, std::numeric_limits<int>::max());
	path = new int[V];
}
void graph::add_edge(int source, int dest, int weight) {
	listnode *node = new listnode(dest, weight);
	node->next = head[source];
	head[source] = node;
}
void graph::shortest_path(int source) {
	bool *visited = new bool[V]();
	std::priority_queue<Pair, std::vector<Pair>, cmp> PQ;
	PQ.push(std::make_pair(source, 0));
	dist[source] = 0;
	path[source] = source;
	while(!PQ.empty()) {
		int curr = PQ.top().first;
		PQ.pop();
		for(listnode *lptr = head[curr]; lptr; lptr = lptr->next) {
			if (!visited[lptr->dest])
				PQ.push(std::make_pair(lptr->dest, dist[curr] + 
							lptr->weight));
			if (dist[curr] + lptr->weight < dist[lptr->dest]) {
				dist[lptr->dest] = dist[curr] + lptr->weight;
				path[lptr->dest] = curr;
			}
		}
	}
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
	G.shortest_path(0);
	G.print();
	return 0;
}
