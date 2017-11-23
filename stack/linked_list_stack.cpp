#include <iostream>

class Listnode;
class LinkedListStack;

class Listnode {
private:
	int data;
	Listnode *next;
public:
	Listnode(): next(nullptr) {}
	Listnode(int n): data(n), next(nullptr) {}

	friend class LinkedListStack;
};
class LinkedListStack {
private:
	int top;
	Listnode *head;
public:
	LinkedListStack(): top(-1) {}
	bool is_empty();
	void push(int);
	int pop();
	int get_size();
};

bool LinkedListStack::is_empty() {
	return (top == -1);
}
void LinkedListStack::push(int n) {
	Listnode *newnode = new Listnode(n);
	newnode->next = head;
	head = newnode;
	top ++;
}
int LinkedListStack::pop() {
	int temp_data = head->data;
	Listnode *temp = head;
	head = head->next;
	top --;
	delete temp;
	return temp_data;
}
int LinkedListStack::get_size() {
	return top + 1;
}
int main() {
	/* Add test code */
	return 0;
}
