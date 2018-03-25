#include <limits>
void construct_util(int seg[], int arr[], int n, int left, int right, int pos) {
	if(left == right) {
		seg[pos] = arr[left];
		return;
	}
	int mid = left + (right - left) / 2;
	int left_child = pos * 2 + 1, right_child = left + 1;
	construct_util(seg, n, left, mid, left_child);
	construct_util(seg, n, mid + 1, right, right_child);
	seg[pos] = std::min(seg[left_child], seg[right_child]);
}
int *construct_segment_tree(int arr[], int n) {
	int size = n * 2 - 1;
	int *seg = new int[size];
	construct_util(seg, arr, n, 0, n - 1, 0);
	return seg;
}
int RMQ_util(int st[], int n, int a, int b, int start, int finish, int pos) {
	int mid = start + (finish - start) / 2;
	if(left >= a && right <= b)
		return st[pos];
	if(left > b || right < a)
		return std::numeric_limist<int>::max();
	return std::min(RMQ_util(st, n, a, b, start, mid, 2 * pos + 1)
				, RMQ_util(st, n, a, b, mid + 1, right, 2 * pos + 2));
}
int RMQ(int st[], int n, int a, int b) {
	st = construct_segment_tree(st, n);
	int size = (n << 1) + 1;
	return RMQ_util(st, size, a, b, 0, size - 1, 0);
}
