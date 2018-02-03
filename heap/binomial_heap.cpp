#include <iostream>
#include <limits>
struct node {
	int data, degree;
	node *parent, *child, *sibling;
public:
	node(int key): data(key), degree(0), 
		parent(nullptr), child(nullptr), sibling(nullptr) {};
	node(): data(0), degree(0), parent(nullptr), 
		child(nullptr), sibling(nullptr) {};
};
class binomial_heap {
	node *head;
public:
	binomial_heap(): head(nullptr) {};
	binomial_heap(int key) {
		head = new node(key);
	}
	void merge_tree(node *, node *);
	void union_heap(binomial_heap);
	void merge_heap(binomial_heap);
	node *get_min_node();
	void insert(int);
	int extract();
	int get_min();
	int get_size();
};
void binomial_heap::merge_tree(node *head1, node *head2) {
	if (!head1 || !head2)
		return;
	head2->sibling = head1->child;
	head2->parent = head1;
	head1->child = head2;
	head1->degree ++;
}
void binomial_heap::union_heap(binomial_heap bh) {
	node *head2 = bh.head;
	if (!head2)
		return;
	if (!head) {
		head = head2;
		return;
	}
	node dummy;
	node *temp = &dummy;
	node *head1 = head;
	while (head1 && head2) {
		if (head1->degree <= head2->degree) {
			temp->sibling = head1;
			head1 = head1->sibling;
		}
		else {
			temp->sibling = head2;
			head2 = head2->sibling;
		}
		temp = temp->sibling;
	}
	if (!head1)
		temp->sibling = head2;
	if (!head2)
		temp->sibling = head1;
	head = dummy.sibling;
}
void binomial_heap::merge_heap(binomial_heap bh) {
	if (!bh.head)
		return;
	if (!head) {
		head = bh.head;
		return;
	}
	union_heap(bh);
	node *prev = nullptr;
	node *curr = head;
	while (curr->sibling) {
		if ((curr->degree != curr->sibling->degree) || 
		  (curr->sibling->sibling && curr->sibling->
		  sibling->degree == curr->degree)) {
			prev = curr;
			curr = curr->sibling;
		}
		else if (curr->data <= curr->sibling->data) {
			curr->sibling = curr->sibling->sibling;
			merge_tree(curr->sibling, curr);
		}
		else {
			node *next = curr->sibling;
			if (!prev)
				head = curr;
			else prev->sibling = next;
			merge_tree(curr->sibling, curr);
			curr = next;
		}
	}
}
void binomial_heap::insert(int key) {
	binomial_heap temp(key);
	merge_heap(temp);
}
int binomial_heap::get_min() {
	node *curr = head;
	int min = std::numeric_limits<int>::max();
	while (curr) {
		if (curr->data < min)
			min = curr->data;
		curr = curr->sibling;
	}
	return min;
}
node *binomial_heap::get_min_node() {
	node *curr = head;
	node *min_node;
	int min = std::numeric_limits<int>::max();
	while (curr) {
		if (curr->data < min) {
			min = curr->data;
			min_node = curr;
		}
		curr = curr->sibling;
	}
	return min_node;
}
int binomial_heap::extract() {
	node *temp = get_min_node();
	node *prev = temp->child;
	node *curr = nullptr;
	int ret = temp->data;
	delete temp;
	while (prev) {
		prev->parent = nullptr;
		prev->sibling = curr;
		curr = prev;
		prev = prev->sibling;
	}
	binomial_heap bh;
	bh.head = curr;
	merge_heap(bh);
	return ret;
}
int binomial_heap::get_size() {
	int size = 0;
	node *curr = head;
	while (curr) {
		size += 1 << curr->degree;
		curr = curr->sibling;
	}
	return size;
}

int main() {
	binomial_heap bh;
	return 0;
}
