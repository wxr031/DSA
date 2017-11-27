#include <stdio.h>
#include <stdlib.h>
#include "listnode_stack.h"
Listnode *find_merge(Listnode *head1, Listnode *head2) {
	Stack stack1, stack2;
	init(&stack1);
	init(&stack2);
	while (head1 != NULL) {
		push(&stack1, head1);
		head1 = head1->next;
	} 
	while (head2 != NULL) {
		push(&stack2, head2);
		head2 = head2->next;
	}
	Listnode *res, *buf;
	while ((buf = pop(&stack1)) == pop(&stack2))
		res = buf;
	return res;
}
int main() {
	Listnode *head = (Listnode *)malloc(sizeof(Listnode));
	head->next = (Listnode *)malloc(sizeof(Listnode));
	head->next->next = (Listnode *)malloc(sizeof(Listnode));
	head->next->next->next = (Listnode *)malloc(sizeof(Listnode));
	head->next->next->next->next = (Listnode *)malloc(sizeof(Listnode));
	head->next->next->next->next->next = NULL;
	Listnode *head_ = (Listnode *)malloc(sizeof(Listnode));
	head_->next = (Listnode *)malloc(sizeof(Listnode));
	head_->next->next = head->next->next->next;
	printf("result: %p\n", find_merge(head, head_));
	printf("answer: %p\n", head_->next->next);
	return 0;
}
