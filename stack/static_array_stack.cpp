#include <iostream>
#define MAX_CAP 1024
class ArrayStack {
private:
	int top, capacity;
	int array[MAX_CAP];
public:
	ArrayStack(): top(-1), capacity(1) {}
	bool is_full();
	bool is_empty();
	void push(int);
	int pop();
	int get_size();
};
bool ArrayStack::is_full() {
	return top == MAX_CAP - 1;
}
bool ArrayStack::is_empty() {
	return top == -1;
}
void ArrayStack::push(int n) {
	if (is_full()) {
		printf("Stack full.\n");
		return;
	}
	array[++ top] = n;
}
int ArrayStack::pop() {
	if (is_empty()) {
		printf("Stack empty.\n");
		return 0x80000000;
	}
	return array[top --];
}
int ArrayStack::get_size() {
	return top + 1;
}
int main() {
	/* Add code here */
	return 0;
}
