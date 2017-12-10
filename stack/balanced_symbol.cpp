#include <iostream>
#include "char_stack.h"
using namespace std;
int main() {
	char c;
	bool balanced = true;
	Stack stack;
	while ((cin >> c) && balanced) {
		if (c == '(' || c == '[' || c == '{')
			stack.push(c);
		else if (c == ')') {
			char cmp = stack.pop();
			if (cmp != '(') balanced = false;
		} else if (c == ']') {
			char cmp = stack.pop();
			if (cmp != '[') balanced = false;
		} else if (c == '}') {
			char cmp = stack.pop();
			if (cmp != '{') balanced = false;
		}
	}
	int remain = stack.get_size();
	cout << ((balanced && !remain)? "balanced": "not balanced") << endl;
	return 0;
}
