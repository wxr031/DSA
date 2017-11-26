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
	Listnode(char n): data(n), next(NULL) {}

	friend class Stack;
};
class Stack {
private:
	int top;
	Listnode *head;
public:
	Stack(): top(-1) {}
	bool is_empty();
	void push(int);
	char pop();
	int get_size();
	char get_top();

	friend class Listnode;
};
#endif
