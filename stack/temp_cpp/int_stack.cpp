#include <iostream>
#include "int_stack.h"
bool Stack::is_empty() {
	return (top == -1);
}
void Stack::push(int n) {
	Listnode *newnode = new Listnode(n);
	newnode->next = head;
	head = newnode;
	top ++;
}
int Stack::pop() {
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
