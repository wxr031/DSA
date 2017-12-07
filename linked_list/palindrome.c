#include <stdio.h>
#include <stdlib.h>
typedef struct listnode {
	char data;
	struct listnode *next;
} Listnode;
Listnode *insert_node(Listnode *head, char data) {
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
int palindrome(Listnode *head) {
	if (!head || !head->next)
		return 1;
	Listnode *fast = head, *slow = head;
	while (fast->next && fast->next->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	Listnode *head2 = reverse(slow->next);
	slow->next = NULL;
	while (head2) {
		if (head->data != head2->data)
			return 0;
		head = head->next;
		head2 = head2->next;
	}
	return 1;
}
int main() {
	char str[64];
	scanf("%s", str);
	Listnode *head = NULL;
	for (int i = 0; str[i]; i ++)
		head = insert_node(head, str[i]);
	printf("%d\n", palindrome(head));
	return 0;
}
