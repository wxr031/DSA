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
		int num, sum = 0;
		scanf("%d", &num);
		for(int i = 1; i <= num; ++i) {
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		if(sum & 1) {
			puts("NO");
			continue;
		}
		int find = sum >> 1;
		int flag = 1;
		dp[0][0] = 1;
		for(int i = 1; i <= num && flag; ++i) {
			for(int j = 1; j <= find && flag; ++j) {
				dp[i][j] = dp[i - 1][j];
				if(!dp[i][j] && j >= arr[i])
					dp[i][j] = dp[i - 1][j - arr[i]];
			}
			if(dp[i][find]) {
				puts("YES");
				flag = 0;
			}
		}
		if(flag) {
			for(int i = 1; i <= num; ++i) {
				for(int j = 1; j <= find; ++j) {
					printf("%d%c", dp[i][j], " \n"[j == find]);
				}
			}
			puts("NO");
		}
	}
	return 0;
}

