#include <stdio.h>
typedef struct listnode {
	int data;
	struct listnode *next;
} Listnode;
// Counting Node:
//Time Complexity: O(n)
//Space Complexity: O(1)
int count_length(Listnode *head) {
	if (head == NULL) return 0;
	Listnode *temp = head->next;
	int count = 0;
	do {
		temp = temp->next;
		count ++;
	} while (temp != head);
	return count;
}

int main() {
	/*Add test code*/
}
