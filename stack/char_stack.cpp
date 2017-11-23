#include <iostream>
#include "char_stack.h"
bool Stack::is_empty() {
	return (top == -1);
}
void Stack::push(char c) {
	Listnode *newnode = new Listnode(c);
	newnode->next = head;
	head = newnode;
	top ++;
}
char Stack::pop() {
	char temp_data = head->data;
	Listnode *temp = head;
	head = head->next;
	top --;
	delete temp;
	return temp_data;
}
int Stack::get_size() {
	return top + 1;
}
