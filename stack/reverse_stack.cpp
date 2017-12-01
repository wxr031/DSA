#include <iostream>
#include "int_stack.h"
using namespace std;
int main() {
	int temp;
	Stack org_stack;
	while (cin >> temp)
		org_stack.push(temp);
	
	Stack rev_stack;
	while (!org_stack.is_empty())
		rev_stack.push(org_stack.pop());
	
	/* Test Code */
	while (!rev_stack.is_empty())
		cout << rev_stack.pop() << endl;
	return 0;
}

