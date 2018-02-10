#include <iostream>
struct Node {
	int data;
	Node *next;
	Node(int);
};
Node::Node(int val) {
	data = val;
	next = nullptr;
}
class List {
	Node *cache;
public:
	Node *head;
	List();
	void insert(int);
	Node *find_sqrt_node();
};
List::List() {
	head = cache = nullptr;
}
void List::insert(int val) {
	if(!head)
		head = cache = new Node(val);
	else {
		cache->next = new Node(val);
		cache = cache->next;
	}	
}
Node *List::find_sqrt_node() {
	if(!head)
		return nullptr;
	Node *ret_node = nullptr, *track = head;
	int spec = 1, id = 1;
	while(track) {
		if(spec * spec == id) {
			if(ret_node)
				ret_node = ret_node->next;
			else
				ret_node = head;
			++spec;
		}
		++id;
		track = track->next;
	}
	return ret_node;
}
int main() {
	/* Add test code */
	return 0;
}
