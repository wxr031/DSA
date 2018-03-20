#include <iostream>
using LL = long long;

struct Node {
	int data;
	Node *ptrdiff;
	Node();
	Node(int);
};
Node::Node() {
	data = 0;
	ptrdiff = nullptr;
}
Node::Node(int val) {
	data = val;
	ptrdiff = nullptr;
}

class XLL {
	Node *head;
	public:
	XLL();
	void insert(int);
	void print();
};
XLL::XLL() {
	head = nullptr;
}
void XLL::insert(int val) {
	if(!head) {
		head = new Node(val);
		return;
	}
	Node *prev = nullptr;
	Node *curr = head;
	while(curr && curr->data < val) {
		Node *next = reinterpret_cast<Node *>(
				reinterpret_cast<LL>(curr->ptrdiff)
				^ reinterpret_cast<LL>(prev)
				);
		prev = curr;
		curr = next;
	}
	Node *new_node = new Node(val);
	if(prev) {
		prev->ptrdiff = reinterpret_cast<Node *>
			(
			 reinterpret_cast<LL>(prev->ptrdiff)
			 ^ reinterpret_cast<LL>(curr)
			 ^ reinterpret_cast<LL>(new_node)
			);
	}
	else {
		head = new_node;
	}
	if(curr) {
		Node *next = reinterpret_cast<Node *>
			(
			 reinterpret_cast<LL>(curr->ptrdiff)
			 ^ reinterpret_cast<LL>(prev)
			);
		curr->ptrdiff = reinterpret_cast<Node *>
			(
			 reinterpret_cast<LL>(curr->ptrdiff)
			 ^ reinterpret_cast<LL>(prev)
			 ^ reinterpret_cast<LL>(new_node)
			);
	}
	new_node->ptrdiff = reinterpret_cast<Node *>
		(
		 reinterpret_cast<LL>(prev)
		 ^ reinterpret_cast<LL>(curr)
		);
}
void XLL::print() {
	if(!head)
		return;
	Node *prev = nullptr;
	Node *curr = head;
	Node *next;
	while(curr) {
		std::cout << curr->data << " ";
		next = reinterpret_cast<Node *>
			(
			 reinterpret_cast<LL>(curr->ptrdiff)
			 ^ reinterpret_cast<LL>(prev)
			);
		prev = curr;
		curr = next;
	}
	std::cout << std::endl;
}
int main() {
	int num;
	std::cin >> num;
	XLL list;
	for(int i = 0; i < num; ++i) {
		int get;
		std::cin >> get;
		list.insert(get);
	}
	list.print();
	return 0;
}
