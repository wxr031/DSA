#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

bool is_heap(int *arr, int num) {
	int last_leaf = (num - 2) >> 1;
	for(int curr = 0; curr <= last_leaf; ++curr) {
		int left = (curr << 1) + 1, right = left + 1;
		if(arr[curr] < arr[left] || arr[curr] < arr[right]) {
			return false;
		}
	}
	return true;
}

int main() {
	int test_num;
	scanf("%d", &test_num);
	while(test_num--) {
		int ele_num;
		scanf("%d", &ele_num);
		int *arr = (int *)malloc((ele_num + 1) * sizeof(int));
		for(int i = 0; i < ele_num; ++i) {
			scanf("%d", &arr[i]);
		}
		if(ele_num & 1) {
			arr[ele_num++] = INT_MIN;
		}
		printf("%d\n", is_heap(arr, ele_num));
	}
	return 0;
}
