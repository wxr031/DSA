#include <iostream>
class ArrayStack {
private:
	int top, capacity;
	int *array;
	void double_array();
public:
	ArrayStack(): top(-1), capacity(1) {
		array = new int[capacity];
	}
	~ArrayStack() {
		delete [] array;
	};
	bool is_empty();
	void push(int);
	int pop();
	int get_size();
};
void ArrayStack::double_array() {
	capacity <<= 1;
	int *array_new = new int[capacity];
	for (int i = 0; i <= top; i ++)
		array_new[i] = array[i];
	delete [] array;
	array = array_new; // <- since array is a pointer, it's legal to do so.
}
bool ArrayStack::is_empty() {
	return top == -1;
}
void ArrayStack::push(int n) {
	if (top == capacity - 1)
		double_array();
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
	/* Add test code */
	return 0;
}
