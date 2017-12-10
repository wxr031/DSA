#include <iostream>
#include <string>
#include "char_stack.h"
using namespace std;
int main() {
	string str;
	cin >> str;
	int len = str.size();
	string str_left = str.substr(0, len >> 1);
	string str_right = str.substr((len + 1) >> 1, len >> 1);
	Stack stack;
	for (char c: str_left)
		stack.push(c);
	bool is_pal = true;
	for (char c: str_right)
		if (c != stack.pop()) {
			is_pal = false;
			break;
		}
	cout << ((is_pal)? "palindrome": "not palindrome") << endl;
	return 0;
}
