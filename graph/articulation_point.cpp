#include <iostream>
#include <vector>
#include <list>
class graph {
	int vertex;
	std::list<int> *adj;
	bool ap_util(int, int, std::vector<bool> &, std::vector<bool> &,
			std::vector<int> &);
public:
	graph(int);
	~graph();
	void add_edge(int, int);
	void find_articulation_point();
};
graph::graph(int v) {
	vertex = v;
	adj = new std::list<int>[v];
}
graph::~graph() {
	delete[] adj;
}
void graph::add_edge(int source, int dest) {
	adj[source].push_back(dest);
	adj[dest].push_back(source);
}
bool graph::ap_util(int v, int p, std::vector<bool> &visited,
		std::vector<bool> &ancestor, std::vector<int> &result) {
	visited[v] = true;
	ancestor[v] = true;
	bool is_ap = false;
	bool has_ans = false;
	std::list<int>::iterator it;
	for(it = adj[v].begin(); it != adj[v].end(); ++it) {
		if(*it != p) {
			if(ancestor[*it])
				has_ans = true;
			if (!visited[*it]) {
				if(ap_util(*it, v, visited, ancestor, result))
					has_ans = true;
				else
					is_ap = true;
			}
		}
	}
	if(is_ap)
		result.push_back(v);
	ancestor[v] = false;
	return has_ans;
}
void graph::find_articulation_point() {
	std::vector<bool> visited(vertex, false);
	std::vector<bool> ancestor(vertex, false);
	std::vector<int> result;
	std::list<int>::iterator it;
	visited[0] = true;
	ancestor[0] = true;
	int count = 0;
	for(it = adj[0].begin(); it != adj[0].end(); ++it) {
		if(!visited[*it])
			ap_util(*it, 0, visited, ancestor, result);
		++count;
	}
	if(count > 1)
		result.push_back(0);
	std::sort(result.begin(), result.end());
	for(int i : result)
		std::cout << i << std::endl;
}
int main() {
	std::cout << "\nArticulation points in first graph \n";
    graph g1(5);
    g1.add_edge(1, 0);
    g1.add_edge(0, 2);
    g1.add_edge(2, 1);
    g1.add_edge(0, 3);
    g1.add_edge(3, 4);
    g1.find_articulation_point();
 
    std::cout << "\nArticulation points in second graph \n";
    graph g2(4);
    g2.add_edge(0, 1);
    g2.add_edge(1, 2);
    g2.add_edge(2, 3);
    g2.find_articulation_point();
 
    std::cout << "\nArticulation points in third graph \n";
    graph g3(7);
    g3.add_edge(0, 1);
    g3.add_edge(1, 2);
    g3.add_edge(2, 0);
    g3.add_edge(1, 3);
    g3.add_edge(1, 4);
    g3.add_edge(1, 6);
    g3.add_edge(3, 5);
    g3.add_edge(4, 5);
    g3.find_articulation_point();
 
    return 0;
}
