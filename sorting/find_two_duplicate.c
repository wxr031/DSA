#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void find_duplicate(int *arr, int num, int *dup1, int *dup2) {
	int xor_res = 0;
	for(int i = 0; i < num + 2; ++i)
		xor_res ^= arr[i];
	for(int i = 1; i <= num; ++i)
		xor_res ^= i;
	int last_1_bit = xor_res & (~xor_res + 1);
	int last_0 = 0, last_1 = 0;
	for(int i = 0; i < num + 2; ++i) {
		if(arr[i] & last_1_bit)
			last_1 ^= arr[i];
		else
			last_0 ^= arr[i];
	}
	for(int i = 1; i <= num; ++i) {
		if(i & last_1_bit)
			last_1 ^= i;
		else
			last_0 ^= i;
	}
	*dup1 = last_0;
	*dup2 = last_1;
}

int main() {
	int num;
	scanf("%d", &num);
	int *arr = (int *)malloc((num + 2) * sizeof(int));
	for(int i = 0; i < num + 2; ++i)
		scanf("%d", &arr[i]);
	int dup1, dup2;
	find_duplicate(arr, num, &dup1, &dup2);
	printf("%d %d\n", dup1, dup2);
	return 0;
}
