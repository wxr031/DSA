#include <stdio.h>
#include <stdlib.h>
#define MAXN 1024
typedef struct listnode {
	int data;
	struct listnode *next;
} Listnode;
// First version: Build a hash table and remember every node that has been traveled. 
// If the current node has benn traveled before, then return 1. Else if the traversal ends at NULL, return 0.
// Time complexity: O(n) for scanning the whoe list.
// Space complexity: O(n), since we need to build a hash table of size n. 
int lame_has_loop(Listnode *head) {
	int count = 0;
	Listnode *hash[MAXN] = {};
	while (1) {
		if (head == NULL) {
			return 0;
		}
		else {
			for (int i = 0; i < count; i ++)
				if (hash[i] == head)
					return 1;
			hash[count ++] = head;
		}
		head = head->next;
	}
}
// Second version: Known as the 'Floyd Cycle', 'Tortoise and Hare Algorithm'.
// We can make two pointers traverse the linked list at different speed.
// Therefore, if the list contains a loop, two pointers will eventually meed together.
// Time complexity: O(n)
// Space complexity: O(1)
int Floyd(Listnode *head) {
	Listnode *fast = head, *slow = head;
	while (fast) {
		fast = fast->next;
		if (fast == NULL)
			return 0;
		if (fast == slow)
			return 1;
		fast = fast->next;
		if (fast == slow)
			return 1;
		slow = slow->next;
	}
	return 0;
}
int main() {
	/* Add test code*/
	Listnode *head1 = (Listnode *)malloc(sizeof(Listnode));
	head1->next = (Listnode *)malloc(sizeof(Listnode));
	head1->next->next = (Listnode *)malloc(sizeof(Listnode));
	head1->next->next->next = (Listnode *)malloc(sizeof(Listnode));
	head1->next->next->next->next = head1->next->next;
	printf("%d\n", Floyd(head1));

	Listnode *head2 = (Listnode *)malloc(sizeof(Listnode));
	head2->next = (Listnode *)malloc(sizeof(Listnode));
	head2->next->next = (Listnode *)malloc(sizeof(Listnode));
	head2->next->next->next = (Listnode *)malloc(sizeof(Listnode));
	head2->next->next->next->next = NULL;
	printf("%d\n", Floyd(head2));
	return 0;
}
