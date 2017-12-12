#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
typedef struct treenode {
	int data;
	struct treenode *left, *right;
} Treenode;
void find_ceiling(Treenode *root, int num, int *rem) {
	if (!root) return;
	if (root->data > num) {
		*rem = root->data;
		find_ceiling(root->left, num, rem);
	}
	else if (root->data < num)
		find_ceiling(root->right, num, rem);
	else *rem = root->data;
}
void find_floor(Treenode *root, int num, int *rem) {
	if (!root) return;
	if (root->data > num)
		find_ceiling(root->left, num, rem);
	else if (root->data < num) {
		*rem = root->data;
		find_ceiling(root->right, num, rem);
	}
	else *rem = root->data;
}
void find_ceil_floor(Treenode *root, int num, int *floor, int *ceiling) {
	/* There may be conditions that the ceiling / floor value of num
	does not exist. For instance, if the BST consists of entities
	4, 5, 8, 10. Then the ceiling value of 11 and the floor value of
	3 does not exist. Hence, we need an additional value INT_MIN to indicate
	the non-existing condition. */

	*floor = INT_MIN, *ceiling = INT_MIN;
	find_floor(root, num, floor);
	find_ceiling(root, num, ceiling);
}
Treenode *insert(Treenode *root, int data) {
	if (!root) {
		Treenode *new = (Treenode *)malloc(sizeof(Treenode));
		assert(new);
		new->data = data;
		new->right = new->left = NULL;
		return new;
	}
	if (root->data > data)
		root->left = insert(root->left, data);
	else if (root->data < data)
		root->right = insert(root->right, data);
	return root;
}
int main() {
	Treenode *root = NULL;
	root = insert(root, 10);
	root = insert(root, 4);
	root = insert(root, 17);
	root = insert(root, 2);
	root = insert(root, 5);
	root = insert(root, 12);
	root = insert(root, 20);
	int ceiling, floor;
	int num;
	while (scanf("%d", &num) == 1) {
		find_ceil_floor(root, num, &floor, &ceiling);
		if (ceiling != INT_MIN) printf("ceiling = %d\n", ceiling);
		else printf("ceiling value does not exist\n");
		if (floor != INT_MIN) printf("floor = %d\n", floor);
		else printf("floor value does not exist\n");
	}
	return 0;
}
