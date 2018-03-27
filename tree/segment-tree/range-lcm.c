#include <stdio.h>
#define MAXN 100
#define MAXL 256

int gcd(int n1, int n2) {
	return (!n2) ? n1 : gcd(n2, n1 % n2);
}

int lcm(int n1, int n2) {
	return n1 / gcd(n1, n2) * n2;
}

void build_segment_tree(int *array, int *segment, int left, int right, int pos) {
	if(left == right) {
		segment[pos] = array[left];
		return;
	}
	int left_child = (pos << 1) + 1, right_child = left_child + 1;
	int mid = left + ((right - left) >> 1);
	build_segment_tree(array, segment, left, mid, left_child);
	build_segment_tree(array, segment, mid+1, right, right_child);
	array[pos] = lcm(segment[left_child], segment[right_child]);
}
int result(int *segment, int start, int finish, int left, int right, int pos) {
	if(left >= start && right <= finish)
		return segment[pos];
	if(left > finish || right < start)
		return 1;
	int mid = left + ((right - left) >> 1);
	int left_child = (pos << 1) + 1, right_child = left_child + 1;
	int left_result = result(segment, start, finish, left, mid, left_child);
	int right_result = result(segment, start, finish, mid+1, right, right_child);
	return lcm(left_result, right_result);
}
int main() {
	int test;
	scanf("%d", &test);
	int array[MAXN];
	int segment[MAXL];
	while(test--) {
		int size, query;
		scanf("%d%d", &size, &query);
		for(int i = 0; i < size; ++i) {
			scanf("%d", &array[i]);
		}
		build_segment_tree(array, segment, 0, size-1, 0);
		while(query--) {
			int start, finish;
			scanf("%d%d", &start, &finish);
			printf("%d%c", result(segment, start, finish, 0, size-1, 0), " \n"[!query]);
		}
	}
	return 0;
}
