#include <stdio.h>
#include <stdlib.h>
#define MAXN 100
#define MAXSUM 100000
int arr[MAXN + 1];
int dp[MAXN + 1][MAXSUM + 1];

int main() {
	int test;
	scanf("%d", &test);
	while(test--) {
		int num;
		scanf("%d", &num);
		for(int i = 0; i < num; ++i)
			scanf("%d", &arr[i]);
		
	}
	return 0;
}

