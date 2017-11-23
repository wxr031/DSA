#ifndef CHAR_STACK_H
#define CHAR_STACK_H

class Listnode;
class Stack;

class Listnode {
private:
	char data;
	Listnode *next;
public:
	Listnode(): next(NULL) {}
	Listnode(char c): data(c), next(NULL) {}

	friend class Stack;
};
class Stack {
private:
	int top;
	Listnode *head;
public:
	Stack(): top(-1) {}
	bool is_empty();
	void push(char);
	char pop();
	int get_size();

	friend class Listnode;
};
#endif
