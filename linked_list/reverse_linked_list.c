#include <stdio.h>
#include <stdlib.h>
typedef struct listnode {
	int data;
	struct listnode *next;
} Listnode;
// Time complexity: O(n)
// Space complexity: O(1)
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
int main() {
	/* Add test code */
	Listnode *head = (Listnode *)malloc(sizeof(Listnode));
	head->data = 0;
	head->next = (Listnode *)malloc(sizeof(Listnode));
	head->next->data = 1;
	head->next->next = (Listnode *)malloc(sizeof(Listnode));
	head->next->next->data = 2;
	head->next->next->next = (Listnode *)malloc(sizeof(Listnode));
	head->next->next->next->data = 3;
	head->next->next->next->next = NULL;
	head = reverse(head);
	for (Listnode *curr = head; curr != NULL; curr = curr->next)
		printf("%d\n", curr->data);
	return 0;
}
