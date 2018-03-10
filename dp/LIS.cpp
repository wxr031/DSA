a#include <iostream>
#include <vector>


int main() {
	int test;
	std::cin >> test;
	while(test--) {
		int num;
		std::cin >> num;
		std::vector<int> vec(num + 1);
		for(int i = 1; i <= num; ++i) {
			std::cin >> vec[i];		
		}
		std::vector<int> dp(num + 1, 1);
		for(int i = 1; i <= num; ++i) {
			for(int j = 1; j < i; ++j) {
				if(vec[j] <= vec[i] && dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
				}
			}
		}
		std::cout << dp[num] << std::endl;
	}
	return 0;
}
