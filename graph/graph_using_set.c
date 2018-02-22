#include <stdio.h>
#include <stdlib.h>
#define MAXN 1024
typedef struct set {
	int size;
	int *parent, *rank;
} Set;
void init_set(Set *s, int size) {
	s->size = size;
	s->parent = (int *)malloc(size * sizeof(int));
	s->rank = (int *)malloc(size * sizeof(int));
	for(int i = 0; i < size; i ++) {
		s->parent[i] = i;
		s->rank[i] = 0;
	}
}
int find_set(Set *s, int data) {
	if(s->parent[data] == data)
		return data;
	return s->parent[data] = find_set(s, s->parent[data]);
}
int union_set(Set *s, int data1, int data2) {
	int root1 = find_set(s, data1);
	int root2 = find_set(s, data2);
	if(root1 != root2) {
		if(s->rank[root1] < s->rank[root2])
			s->parent[root1] = root2;
		else if(s->rank[root1] > s->rank[root2])
			s->parent[root2] = root1;
		else {
			s->parent[root1] = root2;
			s->rank[root2] ++;
		}
		return 1;
	}
	return 0;
}
typedef struct node {
	int source, dest, weight;
} Node;
typedef struct graph {
	int V, num;
	Node *data;
	Set set;
} Graph;
void init_graph(Graph *g, int V) {
	init_set(&g->set, V);
	g->V = V;
	g->num = 0;
	g->data = (Node *)malloc(MAXN * sizeof(Node));
}
void insert(Graph *g, int source, int dest, int weight) {
	g->data[g->num].source = source;
	g->data[g->num].dest = dest;
	g->data[g->num].weight = weight;
	g->num ++;
}
int cmp(const void *n1, const void *n2) {
	Node *p1 = (Node *)n1, *p2 = (Node *)n2;
	return (p1->weight > p2->weight) ? 1 : -1;
}
int main() {
	int source, dest, weight;
	int V;
	Graph graph;
	scanf("%d", &V);
	init_graph(&graph, V);
	while(scanf("%d%d%d", &source, &dest, &weight) == 3)
		insert(&graph, source, dest, weight);
	qsort(graph.data, graph.num, sizeof(Node), cmp);
#ifdef DEBUG
	for(int i = 0; i < graph.num; i ++)
		printf("%d %d %d\n", graph.data[i].source, graph.data[i].dest, graph.data[i].weight);
#endif
	int count = 0;
	Node *result = (Node *)malloc(graph.V * sizeof(Node));
	for(int i = 0; i < graph.num - 1 && count < V; i ++)
		if(union_set(&graph.set, graph.data[i].source, graph.data[i].dest))
			result[count ++] = graph.data[i];
	for(int i = 0; i < graph.V - 1; i ++)
		printf("%d -- %d | weight: %d\n", result[i].source, result[i].dest, result[i].weight);
	return 0;
}
