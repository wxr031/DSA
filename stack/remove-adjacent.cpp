#include <iostream>
#include <stack>
#include <string>

std::string remove_adjacent(std::string str) {
	std::string aux_str = "";
	for(char c : str) {
		if(!aux_str.empty() && aux_str.back() == c) {
			aux_str.pop_back();
		}
		else {
			aux_str.push_back(c);
		}
	}
	return aux_str;
}

int main() {
	std::string str;
	std::getline(std::cin, str);
	std::cout << remove_adjacent(str) << std::endl;
	return 0;
}
