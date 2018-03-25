#include <iostream>
using namespace std;
constexpr int MAXN = 1024;
struct Node {
	int data;
	Node *left, *right;
};

Node *version[MAXN];

void upgrade(Node *root, Node *prev, int start, int finish, int index, int value) {
	if(start == finish) {
		root->data = prev->data + value;
		return;
	}
	int mid = start + ((finish - start) >> 1);
	std::cout << start << " " << finish << std::endl;
	if(index >= start && index <= mid) {
		root->left = new Node;
		upgrade(root->left, prev->left, start, mid, index, value);
	} else {
		root->left = prev->left;
	}

	if(index >= mid+1 && index <= finish) {
		root->right = new Node;
		upgrade(root->right, prev->right, mid+1, finish, index, value);
	} else {
		root->right = prev->right;
	}
	root->data = root->left->data + root->right->data;
}

void build(Node *root, int arr[], int start, int finish) {
	if(start == finish) {
		root->data = arr[start];
		return;
	}
	root->left = new Node;
	root->right = new Node;
	int mid = start + ((finish - start) >> 1);
	build(root->left, arr, start, mid);
	build(root->right, arr, mid + 1, finish);
	root->data = root->left->data + root->right->data;
}

int query(Node* n, int low, int high, int l, int r) {
    if (l > high or r < low or low > high)
       return 0;
    if (l <= low and high <= r)
       return n->data;
    int mid = (low+high) / 2;
    int p1 = query(n->left,low,mid,l,r);
    int p2 = query(n->right,mid+1,high,l,r);
    return p1+p2;
}

int main(int argc, char const *argv[]) {
	int arr[] = {1,2,3,4,5};
	int n = sizeof(arr) / sizeof(int);
 
	// creating Version-0
	version[0] = new Node;
	build(version[0], arr, 0, n-1);
	// upgrading to version-1
	version[1] = new Node;
	upgrade(version[1], version[0], 0, n-1, 4, 1);
 
	// upgrading to version-2
	version[2] = new Node;
	upgrade(version[2], version[1], 0, n-1, 2, 10);
 
	cout << "In version 1 , query(0,4) : ";
	cout << query(version[1], 0, n-1, 0, 4) << endl;
 
	cout << "In version 2 , query(3,4) : ";
	cout << query(version[2], 0, n-1, 0, 5) << endl;
 
	cout << "In version 0 , query(0,3) : ";
	cout << query(version[0], 0, n-1, 0, 3) << endl;
	return 0;
}
