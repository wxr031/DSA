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
Listnode *reverse_iteration(Listnode *head) {
	if (!head || !head->next) return head;
	Listnode *prev = head, *curr = head->next, *after = NULL;
	Listnode *return_head = curr;
	while (prev) {
		after = curr->next;
		curr->next = prev;
		if (!after || !after->next) {
			prev->next = after;
			prev = NULL; // jump out of the loop
		} else {
			prev->next = after->next;
			prev = after;
			curr = prev->next;
		}
	}
	return return_head;
}
Listnode *reverse_iteration2(Listnode *head) {
	if (!head || !head->next) return head;
	Listnode *curr = head, *after = head->next;
	while (curr && after) {
		int temp = curr->data;
		curr->data = after->data;
		after->data = temp;
		curr = after->next;
		if (curr)
			after = curr->next;
	}

}
int main() {
	/* Add test code */
	Listnode *head = NULL;
	head = reverse_iteration(head);
	while (head) {
		printf("%d\n", head->data);
		head = head->next;
	}
	return 0;
}
