#include <stdio.h>
#include <stdlib.h>
typedef struct listnode {
	int data;
	struct listnode *next;
} Listnode;
//Insertion and Deletion:
//Time complexity: O(n), since we may need to insert/delete a new node to the end of the list in the worst case.
//Space complexity: O(1).

//The functions below assert all positions are valid
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
Listnode *delete_whole_list(Listnode *head) {
	Listnode *iterator = head, *temp = NULL;
	while (iterator != NULL) {
		temp = iterator;
		iterator = iterator->next;
		free(temp);
	}
	return NULL;
}
int main() {
	/*Add test code*/
	return 0;
}
