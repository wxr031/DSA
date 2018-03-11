#include <iostream>
#include <vector>

int main() {
	int test;
	std::cin >> test;
	while(test--) {
		int num, capacity;
		std::cin >> num >> capacity;
		std::vector<int> val(num);
		std::vector<int> wei(num);
		for(int i = 0; i < num; ++i) {
			std::cin >> val[i] >> wei[i];
		}
		std::vector<int> dp(capacity + 1, 0);
		for(int i = 0; i <= capacity; ++i) {
			for(int j = 0; j < num; ++j) {
				if(i >= wei[j]) {
					dp[i] = std::max(dp[i - 1], dp[i - wei[j]] + val[j]);
				}
			}
		}
		std::cout << dp[capacity] << std::endl;
	}
	return 0;
}
