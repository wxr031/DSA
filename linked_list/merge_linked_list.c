#include <stdio.h>
#include <stdlib.h>
typedef struct listnode {
	int data;
	struct listnode *next;
} Listnode;
Listnode *insert_node(Listnode *head, int pos, int data) { 
	Listnode *new = (Listnode *)malloc(sizeof(Listnode));
	new->data = data;
	if (head == NULL) {
		new->next = NULL;
		return new;
	}
	if (pos == 0) {
		new->next = head;
		return new;
	}
	Listnode *prev = NULL, *curr = head;
	while (pos --) {
		prev = curr;
		curr = curr->next;
	}
	prev->next = new;
	new->next = curr;
	return head;
}
Listnode *delete_node(Listnode *head, int pos) {
	if (head == NULL || head->next == NULL)
		return NULL;
	if (pos == 0) {
		Listnode *temp = head->next;
		free(head);
		return temp;
	}
	Listnode *prev = NULL, *curr = head;
	while (pos --) {
		prev = curr;
		curr = curr->next;
	}
	prev->next = curr->next;
	free(curr);
	return head;
}
Listnode *delete_whole_list(Listnode *head) {
	Listnode *iterator = head, *temp = NULL;
	while (iterator != NULL) {
		temp = iterator;
		iterator = iterator->next;
		free(temp);
	}
	return NULL;
}
Listnode *merge_linked_list(Listnode *head1, Listnode *head2) {
	if (!head1) return head2;
	if (!head2) return head1;
	if (head1->data < head2->data) {
		head1->next = merge_linked_list(head1->next, head2);
		return head1;
	} else {
		head2->next = merge_linked_list(head1, head2->next);
		return head2;
	}
}
int main() {
	/* Add test code */
	return 0;
}
