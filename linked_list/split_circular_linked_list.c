#include <stdio.h>
#include <stdlib.h>
typedef struct listnode {
	int data;
	struct listnode *next;
} Listnode;
Listnode *insert_node(Listnode *head, int data) {
	Listnode *newnode = (Listnode *)malloc(sizeof(Listnode));
	head->data = data;
	if (!head) {
		head->next = head;
		return newnode;
	}
	Listnode *track = head;
	while (track->next != head)
		track = track->next;
	track->next = newnode;
	newnode->next = head;
	return head;
}
typedef struct two_new_list {
	Listnode *head1, *head2;
} Two_new_list;
Two_new_list *split_node(Listnode *head) {
	Listnode *fast = head, *slow = head;
	Listnode *another_head, *another_tail;
	/* find middle position */
	while (1) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast->next == head) {
			another_head = slow->next;
			another_tail = fast;
			break;
		} else if (fast->next->next == head) {
			another_head = slow->next;
			another_tail = fast->next;
			break;
		}
	}
	/* link tail to head */
	slow->next = head;
	another_tail->next = another->head;
	/* wrap up 'head' and 'another_head' into a structure */
	Two_new_list ret_list = {head, another_head};
	/* return the structure */
	return &new;
}
int main() {

}}
