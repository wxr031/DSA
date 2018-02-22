#include <iostream>
#include <queue>
#include <limits>
#include <utility>
typedef std::pair<int, int> Pair;
struct listnode {
	int dest, weight;
	listnode *next;
	listnode(int dest, int weight): dest(dest), weight(weight)
		, next(nullptr) {}
};
struct compare {
	bool operator() (const Pair &p1, const Pair &p2) {
		return p1.second > p2.second;
	}
};
class graph {
	int V;
	listnode **head;
	int *dist, *path;
	listnode **path_aux;
public:
	graph(int);
	void add_edge(int, int, int);
	int spanning_tree();
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

	listnode *temp2 = new listnode(source, weight);
	temp2->next = head[dest];
	head[dest] = temp2;
}
int graph::spanning_tree() {
	bool *visited = new bool[V]();
	dist = new int[V];
	path = new int[V];
	std::fill(dist, dist + V, std::numeric_limits<int>::max());
	dist[0] = 0;
	path[0] = 0;
	std::priority_queue<Pair, std::vector<Pair>, compare > PQ;
	PQ.push(std::make_pair(0, 0));
	while(!PQ.empty()) {
		int curr = PQ.top().first;
		PQ.pop();
		visited[curr] = true;
		std::cout << curr << std::endl;
		for(listnode *lptr = head[curr]; lptr; lptr = lptr->next) {
			if(!visited[lptr->dest] && lptr->weight < dist[lptr->dest]) {
				PQ.push(std::make_pair(lptr->dest, lptr->weight));
				dist[lptr->dest] = lptr->weight;
				path[lptr->dest] = curr;
			}
		}
	}
	int total = 0;
	for(int i = 0; i < V; i ++)
		total += dist[i];
	return total;
}
void graph::print() {
	for(int i = 0; i < V; i ++)
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
	std::cout << G.spanning_tree() << std::endl;
	G.print();
	return 0;
}
