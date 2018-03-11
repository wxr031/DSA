#include <stdio.h>
#include <stdlib.h>
#define MAXN 300
#define min(a,b) ((a) < (b)) ? (a) : (b)
int dp[MAXN + 1];
int main() {
	int test;
	scanf("%d", &test);
	while(test--) {
		int num;
		scanf("%d", &num);
		int *arr = (int *)malloc(num * sizeof(int));
		int start = 0x7fffffff;
		for(int i = 0; i < num; ++i) {
			scanf("%d", &arr[i]);
			dp[arr[i]] = 1;
			if(arr[i] < start)
				start = arr[i];
		}
		int total;
		scanf("%d", &total);

		for(int i = start + 1; i <= total; ++i) {
			dp[i] = 0x7fffffff;
			for(int j = 0; j < num; ++j) {
				if(i >= arr[j]) {
					dp[i] = min(dp[i], dp[i - arr[j]] + 1);
				}
			}
			//printf("%d\n", dp[i]);
		}
		printf("%d\n", dp[total]);
	}
}
