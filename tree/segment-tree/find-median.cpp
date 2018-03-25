#include <iostream>
constexpr int MAXN = 16384;
int seg[MAXN];

void insert_util(int index, int left, int right, int pos) {
	if(index < left || index > right)
		return;
	if(index == left && index == right) {

	}
	int mid = left + ((right - left) >> 1);
	insert_util(index, left, mid, (pos << 1) + 1);
	insert_util(index, mid+1, right, (pos << 1) + 2);
	seg[pos] = seg[(pos << 1) + 1] + seg[(pos << 1) + 2];
}
void insert(int index, int num) {
	insert_util(index, 0, num-1)
}
void build_tree_util(int arr[], int num, int left, int right, int pos) {
	if(left == right) {
		seg[pos] = arr[left];
		return;
	}
	int mid = left + ((right - left) >> 1);
	build_tree_util(arr, num, left, mid, (pos << 1) + 1);
	build_tree_util(arr, num, mid1+1, right, (pos << 1) + 2);
	seg[pos] = seg[(pos << 1) + 1] + seg[(pos << 1) + 2];
}
void build_tree(int arr[], int num) {
	build_tree_util(arr, num, 0, num - 1, 0);
}

int main() {
	int num;
	
}
