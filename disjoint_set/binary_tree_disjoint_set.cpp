#include <iostream>
class disjoint_set {
	int *set;
	int size;
public:
	int Find(int);
	void Union(int);
};
disjoint_set::disjoint_set(int S) {
	set = new int[S];
	for (int i = 0; i < size; i ++)
		set[i] = i;
}
int disjoint_set::Find(int data) {
	if (data < 0 || data >= size)
		return INT_MIN;
	if (set[data] == data)
		return data;
	return Find(set[data]);
}
void Union(int root1, int root2) {
	if (root1 < 0 || root1 >= size || root2 < 0 || root2 >= size)
		return;
	if (Find(root1) == Find(root2))
		return;
	set[root1] = root2;
}
