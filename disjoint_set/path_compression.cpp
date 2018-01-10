#include <iostream>
class disjoint_set {
	int *parent, *rank;
	int size;
public:
	disjoint_set(int);
	disjoint_set() {
		size = 0;
		parent = rank = nullptr;
	}
	int Find(int);
	void Union(int, int);
};
disjoint_set::disjoint_set(int size_val) {
	size = size_val;
	parent = new int[size];
	rank = new int[size];
	for (int i = 0; i < size; i ++) {
		parent[i] = i;
		rank[i] = 0;
	}
}
int disjoint_set::Find(int num) {
	if (parent[num] == num)
		return num;
	int parent_get = Find(parent[num]); // <- path compression
	parent[num] = parent_get; // <- path compression
	return parent_get;
}
void disjoint_set::Union(int num1, int num2) {
	int parent1 = Find(num1);
	int parent2 = Find(num2);
	if (rank[parent1] > rank[parent2])
		parent[parent2] = parent1;
	else if (rank[parent1] < rank[parent2])
		parent[parent1] = parent2;
	else {
		parent[parent1] = parent2;
		rank[parent2] ++;
	}
}
int main() {
	disjoint_set DS(5);
	DS.Union(0, 2);
	DS.Union(4, 2);
	DS.Union(3, 1);
	if (DS.Find(4) == DS.Find(0))
		std::cout << "Yes" << std::endl;
	else std::cout << "No" << std::endl;
	if (DS.Find(1) == DS.Find(0))
		std::cout << "Yes" << std::endl;
	else std::cout << "No" << std::endl;
	return 0;	
}
