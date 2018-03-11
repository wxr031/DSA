#include <iostream>
#include <vector>
#include <limits>

class compare {
	public:
		bool operator() (const int &a, const int &b) {
			return std::abs(a) > std::abs(b);
		}
} cmp;

bool is_same_sign(int n1, int n2) {
	return (n1 > 0 && n2 > 0) || (n1 < 0 && n2 < 0) || (n1 == 0 && n2 == 0);
}

int main() {
	int test;
	std::cin >> test;
	while(test--) {
		int element;
		std::cin >> element;
		std::vector<int> ivec;
		for(int i = 0, num; i < element; ++i) {
			std::cin >> num;
			ivec.push_back(num);
		}
		std::sort(ivec.begin(), ivec.end(), cmp);
		constexpr int INF = std::numeric_limits<int>::max();
		int closest = INF;

		/* condition when all elements are positive or negative */
		for(int i = 0; i < element - 1; ++i) {
			int j = i;
			while(j < element && is_same_sign(ivec[i], ivec[j])) {
				++j;
			}
			int get;
			if(j < element) {
				get = ivec[j] + ivec[i];
			} else {
				get = ivec[i] + ivec[i + 1];
			}
			closest = (std::abs(closest) > std::abs(get))
				? get : closest;

		}
		std::cout << closest << std::endl;
	}
	return 0;
}
