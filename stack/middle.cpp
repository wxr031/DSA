#include <iostream>
class stack {
	struct listnode *head, *mid;
	bool even; 
public:
	stack(): even(true) {
		struct listnode dummy_head(INT_MIN);
		struct listnode dummy_tail(INT_MIN);
		new_head->right = dummy_tail;
		dummy_tail->left = dummy_head;
		mid = dummy_head;
		head = dummy_tail;
	}
	void push(int);
	int pop();
	int find_middle();
	void delete_middle();
};
void stack::push(int data) {
	head.insert_head(data);
	if (even) mid = mid->right;
	else mid = mid->left;;
	even = !even;
}
int stack::pop() {
	struct listnode *temp = head;
	int ret = temp->data;
	if (even) mid = mid->right;
	else mid = mid->left;
	even = !even;
	head = head->right;
	head->left = temp->left;
	head->left->right = head;
	delete temp;
	return ret;
}
int stack::find_middle() {
	return mid->data;
}
void stack::delete_min() {
	struct listnode *temp = mid;
	if (even) {
		mid = mid->right;
		mid->left = temp->left;
		mid->left->right = mid;
	}
	else {
		mid = mid->left;
		mid->right = temp->right;
		temp->right->left = mid;
	}
	even = !even;
	delete temp;
}
int main() {
	stack S;
	S.push(11);
	S.push(22);
	S.push(33);
	S.push(44);
	S.push(55);
	S.push(66);
	S.push(77);
	std::cout << S.pop() << std::endl;
	std::cout << S.pop() << std::endl;
	std::cout << S.pop() << std::endl;
}
