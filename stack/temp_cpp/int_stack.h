#ifndef CHAR_STACK_H
#define CHAR_STACK_H

class Listnode;
class Stack;

class Listnode {
private:
	int data;
	Listnode *next;
public:
	Listnode(): next(NULL) {}
	Listnode(int n): data(n), next(NULL) {}

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
	int pop();
	int get_size();

	friend class Listnode;
};
#endif
