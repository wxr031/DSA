#include <stdio.h>
#include <stdlib.h>
typedef struct listnode {
	struct listnode *next;
} Listnode;
// Check if the given list contains loop or not.
// If there is a loop in the list, find the start of the loop. Else, return NULL.
// Time complexity: O(n)
// Space complexity: O(1)
Listnode *find_loop_start(Listnode *head, int *count) {
	if (head == NULL || head->next == NULL)
		return NULL;
	Listnode *slow = head, *fast = head;
	int has_loop = 0;
	while (fast && !has_loop) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			has_loop = 1;
	}
	if (has_loop) {
		slow = head;
		*count = 0;
		while (slow != fast) {
			slow = slow->next;
			fast = fast->next;
			++ *count;
		}
		return slow;
	}
	else return NULL;
}
int main() {
	/*add test code*/
	int count = 0;
	Listnode *head = (Listnode *)malloc(sizeof(Listnode));
	head->next = (Listnode *)malloc(sizeof(Listnode));
	head->next->next = (Listnode *)malloc(sizeof(Listnode));
	head->next->next->next = (Listnode *)malloc(sizeof(Listnode));
	head->next->next->next->next = (Listnode *)malloc(sizeof(Listnode));;
	head->next->next->next->next->next = (Listnode *)malloc(sizeof(Listnode));;
	head->next->next->next->next->next->next = (Listnode *)malloc(sizeof(Listnode));;
	head->next->next->next->next->next->next->next = (Listnode *)malloc(sizeof(Listnode));;
	head->next->next->next->next->next->next->next->next = (Listnode *)malloc(sizeof(Listnode));;
	head->next->next->next->next->next->next->next->next->next = (Listnode *)malloc(sizeof(Listnode));;
	head->next->next->next->next->next->next->next->next->next->next = (Listnode *)malloc(sizeof(Listnode));;
	head->next->next->next->next->next->next->next->next->next->next->next = head->next->next->next;
	printf("%p =? %p\n", head->next->next->next, find_loop_start(head, &count));
	printf("%d\n", count);
	return 0;
}
