#include <iostream>
struct listnode {
	int data;
	listnode *next;
	listnode(int val): data(val), next(nullptr) {};
};
class graph {
	int V;
	listnode **head;
	int topological_sort_aux(int, bool *, int *, int);
	void dfs_aux(int curr, bool *);
public:
	graph(int V);
	void add_edge(int, int);
	int *topological_sort();
	void dfs();
	void print_result(int *);
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
int graph::topological_sort_aux(int curr, bool *visited, int *result, int num) {
	visited[curr] = true;
	for (listnode *track = head[curr]; track; track = track->next)
		if (!visited[track->data])
			num = topological_sort_aux(track->data, visited, result, num);
	result[num] = curr;
	return num - 1;
}
int *graph::topological_sort() {
	bool *visited = new bool[V]();
	int *result = new int[V];
	int num = V - 1;
	for (int i = 0; i < V; i ++)
		if (!visited[i])
			num = topological_sort_aux(i, visited, result, num);
	return result;
}
void graph::dfs_aux(int curr, bool *visited) {
	std::cout << curr << std::endl;
	visited[curr] = true;
	listnode *temp = head[curr];
	while (temp) {
		if (!visited[temp->data])
			dfs_aux(temp->data, visited);
		temp = temp->next;
	}
}
void graph::dfs() {
	bool *visited = new bool[V]();
	for (int i = 0; i < V; i ++)
		if (!visited[i])
			dfs_aux(i, visited);
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
	G.dfs();
	int *arr = G.topological_sort();
	G.print_result(arr);
	return 0;
}
