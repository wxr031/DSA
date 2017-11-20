#include <stdio.h>
#include <stdlib.h>
typedef struct listnode {
	int data;
	struct listnode *next;
} Listnode;
// First Version: Build a hash table:
// Time complexity: O(n), since we need to traverse the whole linked list. 
// Space complexity: O(n), since we need to build a hash table of size n.
int find_from_end1(Listnode *head, int pos) {
	int hash[MAXN] = {}, N = 0;
	Listnode *curr = head;
	while (curr != NULL) {
		hash[N ++] = curr->data;
		curr = curr->next;
	}
	return hash[N - pos - 1];
}
//Second Version: Find N (total number of linked list), the find N - pos - 2 one
// Time complexity: O(n)
// Spaxe complexity: O(1)
int find_from_end2(Listnode *head, int pos) {
	int N = 0;
	Listnode *curr = head;
	while (curr != NULL) {
		N ++;
		curr = curr->next;
	}
	for (int i = 0; i < N - pos - 1; i ++)
		head = head->next;
	return head->data;
}
//Third Version: Single traversal
// If head is NULL, return INT_MIN
// Time complexity: O(n)
// Spaxe complexity: O(1)
int find_from_end3(Listnode *head, int pos) {
	Listnode *temp = head, *curr = head;
	for (int i = 0; i <= pos; i ++)
		temp = temp->next;
	while (temp != NULL) {
		curr = curr->next;
		temp = temp->next;
	}
	return curr->data;
}
int main() {
	/*Add test code*/
	return 0;
}
