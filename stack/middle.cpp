#include <iostream>
struct listnode {
	int data;
	struct listnode *left, *right;
	listnode(int D): data(D) {
		left = right = nullptr;
	}
};
class DLL {
	struct listnode *head, *dummy_head, *dummy_tail, *mid;
public:
	DLL() {
		head = dummy_head = dummy_tail = mid = nullptr;
	}
	void insert_head(int D) {
		struct listnode *new_head = new struct listnode(D);
		new_head->right = head;
		new_head->left = dummy_head;
		dummy_head->right = new_head;
		head->left = new_head;
		head = new_head;
	}
	friend class stack;

#ifdef DEBUG
	friend void debug();
#endif

};
class stack {
	DLL list;
	bool even; 
public:
	stack(): even(true) {
		list.dummy_head = new struct listnode(INT_MIN);
		list.dummy_tail = new struct listnode(INT_MIN);
		list.dummy_head->right = list.dummy_tail;
		list.dummy_tail->left = list.dummy_head;
		list.mid = list.dummy_head;
		list.head = list.dummy_tail;
	}
	void push(int);
	int pop();
	int find_middle();
	void delete_middle();
};
void stack::push(int data) {
	list.insert_head(data);
	if (list.mid->data == INT_MIN) list.mid = list.head;
	else if (!even) list.mid = list.mid->left;
	even = !even;
}
int stack::pop() {
	struct listnode *temp = list.head;
	int ret = temp->data;
	list.head = list.head->right;
	list.head->left = temp->left;
	list.head->left->right = list.head;
	delete temp;
	if (even) list.mid = list.mid->right;
	else if (list.head->data == INT_MIN) list.mid = list.head->left;
	even = !even;
	return ret;
}
int stack::find_middle() {
	return list.mid->data;
}
void stack::delete_middle() {
	struct listnode *temp = list.mid;
	if (even) {
		list.mid = list.mid->right;
		list.mid->left = temp->left;
		list.mid->left->right = list.mid;
	}
	else {
		list.mid = list.mid->left;
		list.mid->right = temp->right;
		temp->right->left = list.mid;
	}
	even = !even;
	if (list.mid->data == INT_MIN) list.head = list.mid->right;
	delete temp;
}
int main() {
	/* Add test code */
	return 0;
}
