#include <iostream>
#include <string>
#include <map>
int sub_string(std::string mainstr, std::string substr) {
	std::map<char, int> table;
	int mlen = mainstr.length(), slen = substr.length();
	for(int i = 0; i < slen; ++i)
		table[substr[i]] = slen - i - 1;

	for(int i = slen - 1, j = 0; i < mlen;) {
		if(mainstr[i - j] == substr[slen - j - 1]) {
			if(++j == slen)
				return i - slen + 1;
		}
		else {
			i += (table.find(mainstr[i - j]) == table.end()) ? slen : table[mainstr[i - j]];
			j = 0;
		}
	}
	return -1;
}
int main() {
	std::string str, substr;
	std::cin >> str >> substr;
	std::cout << sub_string(str, substr) << std::endl;
	return 0;
}
