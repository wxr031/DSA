#include <iostream>
using namespace std;

class Listnode;
class stack;

class Listnode {
private:
	char data;
	Listnode *next;
public:
	Listnode(char n, Listnode *next): data(n), next(next) {}
	friend class Stack;
};
class Stack {
private:
	int top;
	Listnode *head;
public:
	Stack(): top(-1), head(NULL) {}
	bool is_empty();
	void push(char);
	char pop();
	int get_size();
	friend class Listnode;
};

bool Stack::is_empty() {
	return top == -1;
}
void Stack::push(char n) {
	Listnode *newnode = new Listnode(n, head);
	head = newnode;
	top ++;
}
char Stack::pop() {
	if (is_empty()) return '\0';
	char get = head->data;
	Listnode *temp = head;
	head = head->next;
	delete temp;
	top --;
	return get;
}
int Stack::get_size() {
	return top + 1;
}
int main() {
	char c;
	bool balanced = true;
	Stack stack;
	while ((cin >> c) && balanced) {
		if (c == '(' || c == '[' || c == '{')
			stack.push(c);
		else if (c == ')') {
			char cmp = stack.pop();
			if (cmp != '(') balanced = false;
		} else if (c == ']') {
			char cmp = stack.pop();
			if (cmp != '[') balanced = false;
		} else if (c == '}') {
			char cmp = stack.pop();
			if (cmp != '{') balanced = false;
		}
	}
	int remain = stack.get_size();
	cout << ((balanced && !remain)? "balanced": "not balanced") << endl;
	return 0;
}
