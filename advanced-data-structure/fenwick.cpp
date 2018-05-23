#include <iostream>
#include <vector>

int fenwick_sum(std::vector<int> &fenwick, int index) {
	int sum = 0;
	for(int i = index; i > 0; i -= i & (i & (-i))) {
		sum += fenwick[i];
	}
	return sum;
}

int main() {
	int num;
	std::cin >> num;
	std::vector<int> fenwick(num+1, 0);
	int value;
	for(int i = 1; i <= num; i++) {
		std::cin >> value;
		for(int j = i; j <= num; j += (j & (-j))) {
			fenwick[j] += value;
		}
	}
	std::cout << "here" << std::endl;
	int query;
	std::cin >> query;
	while(query--) {
		int left, right;
		std::cin >> left >> right;
		std::cout << (fenwick_sum(fenwick, right) - fenwick_sum(fenwick, left-1)) << std::endl;
	}
	return 0;
}
