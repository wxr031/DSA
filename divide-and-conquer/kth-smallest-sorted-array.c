#include <stdio.h>
#include <stdlib.h>

int kth_smallest(int *arr1, int *arr2, int num1, int num2, int k) {
	if(num1 == 0)
		return arr2[k - 1];
	if(num2 == 0)
		return arr1[k - 1];
	int mid1 = num1 >> 1;
	int mid2 = num2 >> 1;
	if(mid1 + mid2 + 1 >= k) {
		if(arr1[mid1] < arr2[mid2])
			return kth_smallest(arr1, arr2, num1, mid2, k);
		else
			return kth_smallest(arr1, arr2, mid1, num2, k);
	}
	else {
		if(arr1[mid1] < arr2[mid2])
			return kth_smallest(arr1 + mid1 + 1, arr2, num1 - mid1 - 1, num2, k - mid1 - 1);
		else
			return kth_smallest(arr1, arr2 + mid2 + 1, num1, num2 - mid2 - 1, k - mid2 - 1);
	}
}

int main() {
	int test_num;
	scanf("%d", &test_num);
	while(test_num--) {
		int num1, num2, k;
		scanf("%d%d%d", &num1, &num2, &k);
		int *arr1 = (int *)malloc(num1 * sizeof(int));
		int *arr2 = (int *)malloc(num2 * sizeof(int));
		for(int i = 0; i < num1; ++i)
			scanf("%d", &arr1[i]);
		for(int i = 0; i < num2; ++i)
			scanf("%d", &arr2[i]);
		printf("%d\n", kth_smallest(arr1, arr2, num1, num2, k));
	}
	return 0;
}
