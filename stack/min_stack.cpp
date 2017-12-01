#include <iostream>
#include "int_stack.h"
using namespace std;
int main() {
	Stack main_stack, min_stack;
	int data, min = 0x7fffffff;
	while (cin >> data) {
		main_stack.push(data);
		if (data < min) min = data;
		min_stack.push(min);
	}
	while (!min_stack.is_empty())
		cout << min_stack.pop() << endl;
	return 0;
}
