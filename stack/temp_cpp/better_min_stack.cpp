#include <iostream>
#include "int_stack.h"
using namespace std;
int main() {
	Stack main_stack, min_stack;
	int data, min = 0x7fffffff;
	while (cin >> data) {
		main_stack.push(data);
		if (data <= min) {
			min = data;
			min_stack.push(min);
		}
	}
	int curr;
	min = min_stack.pop();
	while (!main_stack.is_empty()) {
		curr = main_stack.pop();
		cout << min << endl;
		if (curr == min && !min_stack.is_empty())
			min = min_stack.pop();
	}
	return 0;
}
