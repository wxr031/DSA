#include <iostream>
struct node {
	int data;
	node *next;
};
void split(node *head, node *&head1, node *&head2) {
	if (!head) {
		head1 = head2 = nullptr;
		return;
	}
	node *slow = head, *fast = head;
	while (fast->next && fast->next->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	head1 = head;
	head2 = slow->next;
	slow->next = nullptr;
}
node *merge(node *head1, node *head2) {
	if (!head1) return head2;
	if (!head2) return head1;
	if (head1->data <= head2->data) {
		head1->next = merge(head1->next, head2);
		return head1;
	}
	else {
		head2->next = merge(head1, head2->next);
		return head2;
	}
}
node *merge_sort(node *head) {
	if (!head || !head->next)
		return head;
	node *head1, *head2;
	split(head, head1, head2);
	head1 = merge_sort(head1);
	head2 = merge_sort(head2);
	return merge(head1, head2);
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
void print_node(node *head) {
	while (head) {
		std::cout << head->data << " \n"[!head->next];
		head = head->next;
	}
}
int main() {
	int num = 0;
	int data, pos;
	node *head = nullptr;
	while (scanf("%d%d", &data, &pos) == 2)
		insert_node(head, pos, data);
#ifdef TESTING
	print_node(head);
#endif
	head = merge_sort(head);
	print_node(head);
	return 0;
}
