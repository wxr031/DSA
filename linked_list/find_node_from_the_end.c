#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAXN 2024
typedef struct listnode {
	int data;
	struct listnode *next;
} Listnode;
// First Version: Build a hash table:
// If head is NULL, return INT_MIN
// Time complexity: O(n), since we need to traverse the whole linked list. 
// Space complexity: O(n), since we need to build a hash table of size n.
int find_from_end1(Listnode *head, int pos) {
	int hash[MAXN] = {}, N = 0;
	if (head == NULL) return INT_MIN;
	Listnode *curr = head;
	while (curr != NULL) {
		hash[N ++] = curr->data;
		curr = curr->next;
	}
	return hash[N - pos];
}
//Second Version: Find N (total number of linked list), the find n - pos - 2 one
// If head is NULL, return INT_MIN
// Time complexity: O(n)
// Spaxe complexity: O(2)
int find_from_end2(Listnode *head, int pos) {
	int N = 0;
	Listnode *curr = head;
	while (curr != NULL) {
		N ++;
		curr = curr->next;
	}
	for (int i = 0; i < N - pos; i ++)
		head = head->next;
	return head->data;
}
int main() {
	/*Add test data*/
	return 0;
}
