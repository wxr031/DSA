#include <stdio.h>
#include <stdlib.h>
typedef struct listnode {
	int data;
	struct listnode *prev, *next;
} Listnode;
/* The functions below assert all positions are valid */
Listnode *insert_node(Listnode *head, int data, int pos) {
	Listnode *new = (Listnode *)malloc(sizeof(Listnode));
	new->data = data;
	if (head == NULL) {
		new->prev = new->next = NULL;
		return new;
	}
	if (pos == 0) {
		new->prev = NULL;
		new->next = head;
		head->prev = new;
		return new;
	}
	Listnode *curr = head;
	pos --; // <- we need to track the previous node, thus pos must minus 1
	while (pos --) curr = curr->next;
	new->next = curr->next;
	new->prev = curr;
	curr->next = new;
	if (new->next != NULL) 
		new->next->prev = new;
	return head;
}
Listnode *delete_node(Listnode *head, int pos) {
	if (head == NULL) return NULL;
	Listnode *curr = head;
	if (pos == 0) {
		Listnode *temp = curr->next;
		free(curr);
		if (temp != NULL) temp->prev = NULL; // <- to be careful here
		return temp;
	}
	while (pos --) curr = curr->next;
	Listnode *temp = curr->prev;
	temp->next = curr->next;
	free(curr);
	if (temp->next != NULL)
		temp->next->prev = temp;
	return head;
}
Listnode *delete_node(Listnode *head) {
	Listnode *temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
	return NULL;
}
int main() {
	/*Add test code here*/
	return 0;
}
//Insertion and Deletion:
//Time complexity: O(n), since we may need to insert/delete a new node to the end of the list in the worst case.
//Space complexity: O(1).
