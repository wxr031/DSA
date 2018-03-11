#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max_dig(int *arr, int num, int base) {
	int max_num = -1;
	for(int i = 0; i < num; ++i) {
		if(arr[i] > max_num)
			max_num = arr[i];
	}
	int count = 0;
	while(max_num) {
		max_num /= base;
		++count;
	}
	return count;
}
void counting_sort(int *arr, int num, int exp, int base) {
	int *count = (int *)calloc(base, sizeof(int));
	int *aux = (int *)malloc(num * sizeof(int));
	for(int i = 0; i < num; ++i) {
		int rad = arr[i] / exp % base;
		++count[rad];
	}
	for(int i = 1; i < base; ++i) {
		count[i] += count[i - 1];
	}
	for(int i = num - 1; i >= 0; --i) {
		int rad = arr[i] / exp % base;
		aux[--count[rad]] = arr[i];
	}
	memcpy(arr, aux, num * sizeof(int));
}
void radix_sort(int *arr, int num) {
	int base = 10;
	int exp = 1;
	int dig = max_dig(arr, num, base);
	for(int i = 0; i < dig; ++i) {
		counting_sort(arr, num, exp, base);
		exp *= base;
	}
}

int main() {
	int num;
	scanf("%d", &num);
	int *arr = (int *)malloc(num * sizeof(int));
	for(int i = 0; i < num; ++i) {
		scanf("%d", &arr[i]);
	}
	radix_sort(arr, num);
	for(int i = 0; i < num; ++i) {
		printf("%d%c", arr[i], " \n"[i == num - 1]);
	}
	free(arr);
	return 0;
}
