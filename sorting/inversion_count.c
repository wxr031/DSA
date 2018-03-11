#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int merge_sort(int *arr, int ele_num) {
	if(ele_num <= 1)
		return 0;
	int lnum = ele_num >> 1, rnum = ele_num - lnum;
	int *larr = arr, *rarr = arr + lnum;
	int lcount = merge_sort(larr, lnum);
	int rcount = merge_sort(rarr, rnum);
	int count = 0, curr = 0;
	int *aux = (int *)malloc(ele_num * sizeof(int));
	int l = 0, r = 0;
	while(l < lnum && r < rnum) {
		if(larr[l] > rarr[r]) {
			aux[curr++] = rarr[r++];
			count += lnum - l;
		}
		else aux[curr++] = larr[l++];
	}
	while(l < lnum)
		aux[curr++] = larr[l++];
	while(r < rnum)
		aux[curr++] = rarr[r++];
	memcpy(arr, aux, ele_num * sizeof(int));
	free(aux);
	return lcount + rcount + count;
}
int main() {
	int test_num;
	scanf("%d", &test_num);
	while(test_num--) {
		int ele_num;
		scanf("%d", &ele_num);
		int *arr = (int *)malloc(ele_num * sizeof(int));
		for(int i = 0; i < ele_num; ++i)
			scanf("%d", arr + i);
		printf("%d\n", merge_sort(arr, ele_num));
	}
	return 0;
}
