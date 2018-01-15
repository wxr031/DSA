#include <iostream>
struct node {
	int data;
	node *next;
};
void print_node(node *head) {
	while (head) {
		std::cout << head->data << " \n"[!head->next];
		head = head->next;
	}
}
void quick_sort(node *&head, node *&tail) {
	if (!head || !head->next) {
		tail = head;
		return;
	}
	node *equal = head, *less = nullptr, *more = nullptr;
	node *less_head = nullptr, *more_head = nullptr;
	node *less_tail = nullptr, *more_tail = nullptr;
	node *temp = head->next;
	/* make equal node as pivot divide the whole linked list 
	into 'less list', of which all elements in the list are 
	less than pivot, and 'more list', of which all elements 
	in the list are greater than pivot, */
	while (temp) {
		if (temp->data <= equal->data) {
			if (!less_head)
				less_head = less = temp;
			else {
				less->next = temp;
				less = temp;
			}
		}
		else {
			if (!more_head)
				more_head = more = temp;
			else {
				more->next = temp;
				more = temp;
			}
		}
		temp = temp->next;
	}
	if (less)
		less->next = nullptr;
	if (more)
		more->next = nullptr;
#ifdef DEBUG
	print_node(less_head);
	std::cout << "---\n";
	print_node(more_head);
#endif
	// divide
	quick_sort(less_head, less_tail);
	quick_sort(more_head, more_tail);
	// connection
	if (less_tail)
		less_tail->next = equal;
	equal->next = more_head;
	// decide ref_ptr
#ifdef DEBUG2
	std::cout << "&&&&&&&&&\n";
	print_node((less_head) ? less_head : equal);
	std::cout << "&&&&&&&&&\n";
#endif
	head = (less_head) ? less_head : equal;
	tail = (more_tail) ? more_tail : equal;
}
void insert_node(node *&head, int pos, int data) {
	node *new_node = new node;
	new_node->data = data;
	if (!pos) {
		new_node->next = head;
		head = new_node;
		return;
	}
	node *curr = head;
	while (-- pos)
		curr = curr->next;
	new_node->next = curr->next;
	curr->next = new_node;
}
int main() {
	int num = 0;
	int data, pos;
	node *head = nullptr, *tail = nullptr;
	while (scanf("%d%d", &data, &pos) == 2)
		insert_node(head, pos, data);
#ifdef TESTING
	print_node(head);
#endif
	quick_sort(head, tail);
	print_node(head);
	return 0;
}
