#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#ifdef TEST
	#include <time.h>
#endif
typedef struct thread_treenode {
	int data;
	struct thread_treenode *left, *right;
	int Lthread, Rthread;
} Threaded_Treenode;
Threaded_Treenode *inorder_successor(Threaded_Treenode *root) {
	if (root->Rthread) 
		return root->right;
	root = root->right;
	while (!root->Lthread)
		root = root->left;
	return root;
}
void inorder(Threaded_Treenode *root) {
	Threaded_Treenode *temp = inorder_successor(root);
	while (temp != root) {
		printf("%d\n", temp->data);
		temp = inorder_successor(temp);
	}
}
Threaded_Treenode *preorder_successor(Threaded_Treenode *root) {
	if (!root->Lthread)
		return root->left;
	while (root->Rthread)
		root = root->right;
	return root->right;
}
void preorder(Threaded_Treenode *root) {
	Threaded_Treenode *temp = preorder_successor(root);
	while (temp != root) {
		printf("%d\n", temp->data);
		temp = preorder_successor(temp);
	}
}
Threaded_Treenode *newnode(void) {
	Threaded_Treenode *new = (Threaded_Treenode *)malloc(sizeof(Threaded_Treenode));
	new->data = INT_MAX;
	new->Lthread = 1;
	new->Rthread = 0;
	new->right = new;
	new->left = new;
	return new;
}
void insert(Threaded_Treenode *root, int data) {
	if (data <= root->data) {
		if (root->Lthread) {
			Threaded_Treenode *new = (Threaded_Treenode *)malloc(sizeof(Threaded_Treenode));
			new->data = data;
			new->Lthread = new->Rthread = 1;
			new->left = root->left;
			new->right = root;
			root->Lthread = 0;
			root->left = new;
			return;
		}
		else insert(root->left, data);
	}
	else if (data > root->data) {
		if (root->Rthread) {
			Threaded_Treenode *new = (Threaded_Treenode *)malloc(sizeof(Threaded_Treenode));
			new->data = data;
			new->Rthread = new->Lthread = 1;
			new->right = root->right;
			new->left = root;
			root->Rthread = 0;
			root->right = new;
			return;
		}
		insert(root->right, data);
	}
}
Threaded_Treenode *delete(Threaded_Treenode *root, int data, Threaded_Treenode *prev) {
	if (root->right == root)
		return root;
	if (root->data == data) {
		if (root->Lthread && root->Rthread) {
			Threaded_Treenode *temp;
			if (prev->left == root) {
				prev->Lthread = 1;
				temp = root->left;
			}
			else if (prev->right == root) {
				prev->Rthread = 1;
				temp = root->right;
			}
			free(root);
			return temp;
		}
		else if (root->Rthread) {
			Threaded_Treenode *temp = root->left;
			while (!temp->Rthread)
				temp = temp->right;
			temp->right = root->right;
			Threaded_Treenode *ret = root->left;
			free(root);
			return ret;
		}
		else if (root->Lthread) {
			Threaded_Treenode *temp = root->right;
			while (!temp->Lthread)
				temp = temp->left;
			temp->left = root->left;
			Threaded_Treenode *ret = root->right;
			free(root);
			return ret;
		}
		else {
			Threaded_Treenode *temp = root->left;
			while (!temp->Rthread)
				temp = temp->right;
			root->data = temp->data;
			root->left = delete(root->left, root->data, root);
			return root;
		}
	}
	else if (data < root->data)
		root->left = delete(root->left, data, root);
	else
		root->right = delete(root->right, data, root);
	return root;
}
int main() {
	Threaded_Treenode *root = newnode(); // construct dummy node
	Threaded_Treenode *dummy = root;
	srand(time(NULL));
	char c;
	int rem[1024], put_num = 0;
	while ((c = getchar()) != EOF && c != '\n') {
		if (c == 'i') {
			int n = rand() % 1024;
			insert(root, n);
			rem[put_num ++] = n;
		}
		else if (c == 'd') {
			if (put_num > 0) {
				int n = rand() % put_num;
				delete(root, rem[put_num])
			}
		}
	}
	insert(root, 6);
	insert(root, 2);
	insert(root, 7);
	insert(root, 1);
	insert(root, 5);
	insert(root, 3);
	insert(root, 4);
	delete(root->left, 4, root);
	printf("success\n");
	preorder(root);
	printf("--------------------------------\n");
	inorder(root);
	return 0;
}
