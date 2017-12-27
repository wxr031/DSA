#ifndef LISTNODE_STACK_H
#define LISTNODE_STACK_H

typedef struct treenode {
	int data;
	struct treenode *left, *right;
} Treenode;
typedef struct listnode {
	Treenode *data;
	struct listnode *next;
} Listnode;

typedef struct stack {
	int top;
	struct listnode *head;
} Stack;
void init_stack(Stack *);
int is_empty_stack(Stack *);
void push(Stack *, Treenode *);
Treenode *pop(Stack *);
int get_size(Stack *);
Treenode *top(Stack *);
void delete_stack(Stack *);

#endif
