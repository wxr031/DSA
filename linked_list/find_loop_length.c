#include <stdio.h>
#include <stdlib.h>
typedef struct listnode {
	struct listnode *next;
} Listnode;
// Find the length of the loop contained in the list
// Assert that the linked list contains loop
// Time complexity: O(n)
// Space complexity: O(1)
int find_loop_len(Listnode *head) {
	if (head == NULL || head->next == NULL)
		return 0;
	Listnode *slow = head, *fast = head;
	int has_loop = 0;
	while (fast && !has_loop) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			has_loop = 1;
	}
	int count = 0;
	if (has_loop) {
		slow = head;
		/* Find the start of the loop */
		while (slow != fast) {
			slow = slow->next;
			fast = fast->next;
		}
		/* use a counter to increment one after it moves to the next node*/
		do {
			slow = slow->next;
			count ++;
		} while (fast != slow);
		return count;
	}
	else return 0;
}
int main() {
	/*add test code*/
	return 0;
}
