#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

int main() {
	int num;
	std::cin >> num;
	std::vector<int> vec(num);
	for(int i = 0; i < num; i++) {
		std::cin >> vec[i];
	}
	int width = (sizeof(int) << 3) - __builtin_clz(num);
	std::cout << width << std::endl;
	std::vector<std::vector<int>> table(num, std::vector<int>(width, std::numeric_limits<int>::min()));
	for(int i = 0; i < num; i++) {
		table[i][0] = vec[i];
	}
	for(int power = 2, j = 1; power-1 < num; power <<= 1, j++) {
		for(int i = 0; i + power-1 < num; i++) {
			table[i][j] = std::min(table[i][j-1], table[i+(power>>1)][j-1]);
		}
	}
	for(int i = 0; i < num; i++) {
		for(int j = 0; j < width; j++) {
			std::cout << std::setw(10) << table[i][j] << " \n"[j == width-1];
		}
	}
	int left, right;
	int query;
	std::cin >> query;
	while(query--) {
		std::cin >> left >> right;

		int min_num = std::numeric_limits<int>::max();
		while(left < right) {
			int gap = (sizeof(int) << 3) - __builtin_clz(right-left+1) - 1;
			//std::cout << left << " " << gap << std::endl;
			//std::cout << table[left][gap] << std::endl;
			min_num = std::min(min_num, table[left][gap]);
			left += (1 << gap);
		}
		if(left == right) min_num = std::min(min_num, table[left][0]);
		std::cout << min_num << std::endl;
	}
	return 0;
}
