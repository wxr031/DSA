#include <iostream>
class disjoint_set {
	int *set, *rank;
	int size;
public:
	disjoint_set(int S);
	int find(int);
	void union_by_rank(int data1, int data2);
};
disjoint_set::disjoint_set(int S) {
	size = S;
	set = new int[size];
	rank = new int[size];
	for (int i = 0; i < set; i ++) {
		set[i] = i;
		rank[i] = 0;
	}
}
int disjoint_set::find(int data) {
	if (data < 0 || data >= size)
		return -1;
	if (data == size[data])
		return data;
	return find(size[data]);
}
void disjoint_set::union_by_rank(int data1, int data2) {
	int root1 = find(data1);
	int root2 = find(data2);
	if (root1 == root2)
		return;
	else if (rank[root1] < rank[root2])
		set[root1] = root2;
	else if (rank[root1] > rank[root2])
		set[root2] = root1;
	else {
		set[root1] = root2;
		rank[root2] ++
	}
}
