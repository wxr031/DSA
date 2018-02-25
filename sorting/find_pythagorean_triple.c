#include <stdio.h>
#include <stdlib.h>

int cmp(const void *p1, const void *p2) {
	long long num1 = *(long long *)p1, num2 = *(long long *)p2;
	return num1 > num2;
}

int has_pyth_tri(long long *arr, long long num) {
	if(num < 3)
		return 0;
	qsort(arr, num, sizeof(long long), cmp);
	for(int i = 0; i < num; ++i)
		printf("%lld%c", arr[i]," \n"[i == num - 1]);
	for(int i = 0; i < num; ++i)
		arr[i] *= arr[i];
	for(int i = 2; i < num; ++i) {
		int j = 0, k = i - 1;
		while(j < k) {
			if(arr[j] + arr[k] < arr[i]) {
				++j;
			}
			else if(arr[j] + arr[k] > arr[i]) {
				--k;
			}
			else {
				return 87;
			}
		}
	}
	return 0;
}

int main() {
	int test_num;
	scanf("%d", &test_num);
	while(test_num--) {
		int num;
		scanf("%d", &num);
		long long *arr = (long long*)malloc(num * sizeof(long long));
		for(int i = 0; i < num; ++i) {
			scanf("%lld", &arr[i]);
		}
		puts((has_pyth_tri(arr, num)) ? "Yes" : "No");
	}
	return 0;
}
