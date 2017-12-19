#include <iostream>
#include <limits>
using namespace std;

class Treenode;
class Tree;
class Queue;

class Treenode {
	int data;
	Treenode *left, *right, *next;
public:
	Treenode(): data(0), left(NULL), right(NULL), next(NULL) {};
	Treenode(int D): data(D), left(NULL), right(NULL), next(NULL) {};

	friend class Tree;
};

class Tree {
public:
	Treenode *root;
	Tree(): root(NULL) {};
	Treenode *insert(Treenode *, int);
	void sibling();
};

class Queue {
	int front, rear, capacity;
	Treenode **array;
	void double_size();
	bool is_full();
public:
	Queue(): front(-1), rear(-1), capacity(1) {
		array = new Treenode *[capacity];
	}
	bool is_empty();
	void enqueue(Treenode *);
	Treenode *dequeue();
};
bool Queue::is_full() {
	return rear + 1 == front || front == 0 && rear == capacity - 1;
}
bool Queue::is_empty() {
	return front == -1;
}
void Queue::double_size() {
	int pre_cap = capacity;
	capacity *= 2;
	Treenode **new_arr = new Treenode*[capacity];
	if (front <= rear) {
		for (int i = front; i <= rear; i ++)
			new_arr[i] = array[i];
	}
	else {
		for (int i = front; i < pre_cap; i ++)
			new_arr[i] = array[i];
		for (int i = 0; i <= rear; i ++)
			new_arr[pre_cap + i] = array[i];
		rear += pre_cap;
	}
	delete [] array;
	array = new_arr;
}
void Queue::enqueue(Treenode *data) {
	if (is_full())
		double_size();
	if (rear == capacity - 1) rear = 0;
	else rear ++;
	array[rear] = data;
	if (front == -1) front = 0;
}
Treenode *Queue::dequeue() {
	if (is_empty()) {
		cout << "Stack Undderflow" << endl;
		return NULL;
	}
	Treenode *ret = array[front];
	if (front == rear) front = rear = -1;
	else if (front == capacity - 1) front = 0;
	else front ++;
	return ret;
}
Treenode *Tree::insert(Treenode *root, int data) {
	if (root == NULL) {
		Treenode *newnode = new Treenode(data);
		return newnode;
	}
	if (data < root->data)
		root->left = insert(root->left, data);
	else if (data > root->data)
		root->right = insert(root->right, data);
	return root;
}
void Tree::sibling() {
	Queue q;
	q.enqueue(root);
	Treenode *prev = NULL, *leftmost = NULL;
	int curr_nodeN = 1, next_nodeN = 0;
	while (!(q.is_empty())) {
		Treenode *temp = q.dequeue();
		if (temp->left) {
			q.enqueue(temp->left);
			next_nodeN ++;
		}
		if (temp->right) {
			q.enqueue(temp->right);
			next_nodeN ++;
		}
		if (prev != NULL)
			prev->next = temp;
		else leftmost = temp;
		prev = temp;
		curr_nodeN --;
		if (!curr_nodeN) {
			temp->next = leftmost;
			curr_nodeN = next_nodeN;
			next_nodeN = 0;
			prev = NULL;
		}
	}
}
int main() {
	/* Add test code */
	return 0;
}
