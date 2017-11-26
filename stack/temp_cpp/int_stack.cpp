#include <iostream>
#include "int_stack.h"
bool Stack::is_empty() {
	return (top == -1);
}
void Stack::push(char n) {
	Listnode *newnode = new Listnode(n);
	newnode->next = head;
	head = newnode;
	top ++;
}
char Stack::pop() {
	if (is_empty()) {
		std::cerr << "Stack Empty." << std::endl;
		return 0x80000000;
	}
	int temp_data = head->data;
	Listnode *temp = head;
	head = head->next;
	top --;
	delete temp;
	return temp_data;
}
int Stack::get_size() {
	return top + 1;
}
char Stack::get_top() {
	return head->data;
}
