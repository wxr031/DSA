#include <stdio.h>
#include <stdlib.h>
typedef struct treenode {
	int data;
	struct treenode *left, *right;
} treenode;

typedef struct listnode {
	treenode *data;
	struct listnode *next;
} listnode;
/* Stack */
void init_stack(Stack *s) {
	s->top = -1;
	s->head = NULL;
}
int is_empty_stack(Stack *s) {
	return s->top == -1;
}
void push(Stack *s, Treenode *data) {
	Listnode *new = (Listnode *)malloc(sizeof(Listnode));
	new->data = data;
	new->next = s->head;
	s->head = new;
	s->top ++;
}
Treenode *pop(Stack *s) {
	if (is_empty_stack(s)) {
		printf("Stack Underflow.\n");
		return NULL;
	}
	Listnode *temp = s->head;
	s->head = s->head->next;
	Treenode *pop_data = temp->data;
	free(temp);
	s->top --;
	return pop_data;
}
int get_size(Stack *s) {
	return s->top + 1;
}
Treenode *top(Stack *s) {
	return s->head->data;
}
void delete_stack(Stack *s) {
	if (is_empty_stack(s))
		return;
	Listnode *track = NULL;
	while (s->head) {
		track = s->head;
		s->head = s->head->next;
		free(track);
	}
}
int find_leave_num_iteration(Treenode *root) {
// Pick whatever traversal you like.
// leaf means root->left == root->right == NULL
	Stack s;
	init_stack(&s);
	int leafN = 0;
	while (1) {
		if (root) {
			push(&s, root);
			root = root->left;
		} else if (!is_empty_stack(&s)) {
			root = pop(&s);
			if (!root->left && !root->right)
				leafN ++;
			root = root->right;
		} else break;
	}
	return leafN;
}
