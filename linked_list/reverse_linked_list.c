#include <stdio.h>
typedef struct listnode {
	int data;
	struct listnode *next;
} Listnode;
// Time complexity: O(n)
// Space complexity: O(1)
Listnode *reverse(Listnode *head) {
	Listnode *prev = NULL, curr = head, *after = NULL;
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
	return 0;
}
