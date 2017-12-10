#include <stdio.h>
#include <stdlib.h>
typedef struct generic_treenode {
	int data;
	struct generic_treenode *child, *sibling;
} Generic_Treenode;
Generic_Treenode *newnode(int data) {
	Generic_Treenode *new = (Generic_Treenode *)malloc(sizeof(Generic_Treenode));
	new->data = data;
	new->child = new->sibling = NULL;
	return new;
}
int find_sibling_num(Generic_Treenode *root, int data, int count) {
	if (!root) return 0;
	if (root->data == data) {
		int count_next_sib = 0;
		while (root->sibling) {
			count_next_sib ++;
			root = root->sibling;
		}
		return count + count_next_sib;
	}
	int sib_temp, child_temp;
	if (sib_temp = find_sibling_num(root->sibling, data, count + 1))
		return sib_temp;
	if (child_temp = find_sibling_num(root->child, data, 0))
		return child_temp;
	return 0;
}
int main() {
	/* Add test code */
	return 0;
}
