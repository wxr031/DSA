#include <iostream>
#include <string>
#include <vector>

int expand(std::string &str, int len, int left, int right);

int main() {
	int test;
	std::cin >> test;
	while(test--) {
		std::string str;
		std::cin >> str;
		int len = str.length(), new_len = len*2+1;

		std::vector<int> palindrome_len(new_len);
		std::string new_str(new_len, '?');
		
		for(int i = 0; i < len; ++i) {
			new_str[2*i+1] = str[i];
		}
#ifdef DEBUGGING
		std::cout << new_str << std::endl;
#endif

		int center = 1;
		int distance = 1;

		palindrome_len[0] = 0;
		palindrome_len[1] = 1;
		int max_palindrome_len = 1;
		for(int i = 2; i < new_len; ++i) {
			int mirror = center * 2 - i;
			int n = center + distance - i;
			if(i > center + distance) {
				palindrome_len[i] = expand(new_str, new_len, 0, i);
				center = i;
				distance = palindrome_len[i];
			} else if(palindrome_len[mirror] == n) {
				palindrome_len[i] = expand(new_str, new_len, n, i);
				center = i;
				distance = palindrome_len[i];
			} else {
				palindrome_len[i] = std::min(palindrome_len[mirror], n);
			}
			if(palindrome_len[i] > max_palindrome_len) {
				max_palindrome_len = palindrome_len[i];
			}
		}
#ifdef DEBUGGING2
		for(int i = 0; i < new_len; ++i) {
			std::cout << palindrome_len[i] << " \n"[i == new_len-1];
		}
#endif
		std::cout << max_palindrome_len << std::endl;
	}
	return 0;
}

int expand(std::string &str, int len, int dist, int center) {
	int left = center-dist-1, right = center+dist+1;
	while(left >= 0 && right < len && str[left] == str[right]) {
		--left;
		++right;
	}
	return center - left - 1;
}
