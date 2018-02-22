#include <iostream>
#include <vector>
#include <list>
using namespace std;
class graph {
  int vertex;
  list<int> *adj;
  void ap_aux(int, int, int&, vector<bool> &, vector<int> &, vector<int> &);
public:
  graph(int);
  void add_edge(int, int);
  void print_all_articulation_points();
};
graph::graph(int v) {
  vertex = v;
  adj = new list<int>[v];
}
void graph::add_edge(int source, int dest) {
  adj[source].push_back(dest);
  adj[dest].push_back(source);
}
void graph::ap_aux(int curr, int parent, int &assign, vector<bool> &visited,
		   vector<int> &dfs_num, vector<int> &min_num) {
  visited[curr] = true;
  dfs_num[curr] = min_num[curr] = ++assign;
  bool is_ap = false;
  cout << "$" << curr << "$" << endl;
  for(list<int>::iterator it = adj[curr].begin(); it != adj[curr].end(); ++it) {
    if(*it != parent) {
      if(!visited[*it]) {
	ap_aux(*it, curr, assign, visited, dfs_num, min_num);      
	if(min_num[*it] > dfs_num[curr])
	  cout << curr << " ";
      }      
      min_num[curr] = min(min_num[curr], min_num[*it]);
    }
  }
}
void graph::print_all_articulation_points() {
  int assign = 0;
  vector<bool> visited(vertex, false);
  vector<int> dfs_num(vertex);
  vector<int> min_num(vertex);
  visited[0] = true;
  dfs_num[0] = min_num[vertex] = ++assign;
  int child = 0;
  for(list<int>::iterator it = adj[0].begin(); it != adj[0].end(); ++it) {
    if(!visited[*it]) {
      ap_aux(*it, 0, assign, visited, dfs_num, min_num);
      ++child;
    }
  }
  if(child > 1)
    cout << "0" << endl;
  else cout << endl;
}
int main() {
  cout << "\nArticulation points in first graph \n";
  graph g1(8);
  g1.add_edge(1, 0);
  g1.add_edge(0, 2);
  g1.add_edge(3, 1);
  g1.add_edge(1, 4);
  g1.add_edge(2, 4);
  g1.add_edge(2, 5);
  g1.add_edge(4, 7);
  g1.add_edge(6, 4);
  g1.print_all_articulation_points();
  
  cout << "\nArticulation points in second graph \n";
  graph g2(4);
  g2.add_edge(0, 1);
  g2.add_edge(1, 2);
  g2.add_edge(2, 3);
  g2.print_all_articulation_points();
  
  cout << "\nArticulation points in third graph \n";
  graph g3(7);
  g3.add_edge(0, 1);
  g3.add_edge(1, 2);
  g3.add_edge(2, 0);
  g3.add_edge(1, 3);
  g3.add_edge(1, 4);
  g3.add_edge(1, 6);
  g3.add_edge(3, 5);
  g3.add_edge(4, 5);
  g3.print_all_articulation_points();
}
