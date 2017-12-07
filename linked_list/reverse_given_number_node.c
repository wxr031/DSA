#include <stdio.h>
#include <stdlib.h>
typedef struct listnode {
	int data;
	struct listnode *next;
} Listnode;
Listnode *insert_node(Listnode *head, int data) {
	Listnode *new = (Listnode *)malloc(sizeof(Listnode));
	Listnode *temp = head;
	new->data = data;
	new->next = NULL;
	if (!head) return new;
	while (temp->next) temp = temp->next;
	temp->next = new;
	return head;
}
Listnode *reverse(Listnode *head) {
	Listnode *prev = NULL, *curr = head, *after = NULL;
	while (curr != NULL) {
		after = curr->next;
		curr->next = prev;
		prev = curr;
		curr = after;
	}
	return prev;
}
Listnode *reverse_number_node(Listnode *head, int num) {
	if (!num) return NULL;
	Listnode *prev = NULL, *curr = head, *temp;
	for (int i = 0; i < num; i ++) {
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	head->next = curr;
	return prev;
}
int main() {
	Listnode *head = NULL;
	head = insert_node(head, 1);
	head = insert_node(head, 2);
	head = insert_node(head, 3);
	head = insert_node(head, 4);
	head = insert_node(head, 5);
	head = insert_node(head, 6);
	head = insert_node(head, 7);
	head = reverse_number_node(head, 2);
	while (head) {
		printf("%d\n", head->data);
		head = head->next;
	}
	return 0;
}
