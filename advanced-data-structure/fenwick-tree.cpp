#include <iostream>
#include <vector>

int suffix_sum(std::vector<int> tree, int index) {
	int sum = 0;
	for(int i = index; i > 0; i -= (i & (-i))) {
		sum += tree[i];
	}
	return sum;
}

int add_range(std::vector<int> tree, int start, int finish) {
	return suffix_sum(tree, finish+1) - suffix_sum(tree, start);
}

int main() {
	int num;
	std::cin >> num;
	std::vector<int> tree(num+1, 0);
	for(int i = 1, ele; i <= num; i++) {
		std::cin >> ele;
		for(int j = i; j <= num; j += (j & (~j + 1))) {
			tree[j] += ele;
		}
	}
	for(int num : tree) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
	int query;
	std::cin >> query;
	while(query--) {
		int start, finish;
		std::cin >> start >> finish;
		std::cout << add_range(tree, start, finish) << std::endl;
	}
	return 0;
}
