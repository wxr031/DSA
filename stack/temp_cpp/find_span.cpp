#include <iostream>
#include "int_stack.h"
using namespace std;
int *span(int *InputArr, int n) {
	Stack stack;
	int *SpanArr = new int[n];
	for (int i = 0; i < n; i ++) {
		while (!stack.is_empty() && InputArr[stack.get_top()] < InputArr[i])
			stack.pop();
		int end;
		if (stack.is_empty()) end = -1;
		else end = stack.get_top();
		SpanArr[i] = i - end;
		stack.push(i);
	}
	return SpanArr;
}
int main() {
	Stack stack;
	int InputArr[5], *SpanArr;
	for (int i = 0; i < 5; i ++)
		cin >> InputArr[i];
	SpanArr = span(InputArr, 5);
	for (int i = 0; i < 5; i ++)
		printf("%d\n", SpanArr[i]);
	return 0;
}
