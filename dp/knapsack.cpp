#include <stdio.h>
#include <stdlib.h>
#define MAXN 100
#define MAXW 100
int dp[MAXN][MAXW + 1];

#define max(a,b) (((a) > (b) )? (a) : (b))

int main() {
  int test;
  scanf("%d", &test);
  while(test--) {
    int num, cap;
    scanf("%d%d", &num, &cap);
    int *val = (int *)malloc(num * sizeof(int));
    int *wei = (int *)malloc(num * sizeof(int));
    for(int i = 0; i < num; ++i) {
      scanf("%d", &val[i]);
    }
    for(int i = 0; i < num; ++i) {
      scanf("%d", &wei[i]);
    }
    /* base case */
    for(int j = 0; j < wei[0]; ++j) {
      dp[0][j] = 0;
    }
    for(int j = wei[0]; j <= cap; ++j) {
      dp[0][j] = val[0];
    }
    /* general case */
    for(int i = 1; i < num; ++i) {
      for(int j = 0; j <= cap; ++j) {
	if(j >= wei[i]) {
	  dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wei[i]] + val[i]);
	}
	else {
	  dp[i][j] = dp[i - 1][j];
	}
      }
    }
    printf("%d\n", dp[num - 1][cap]);
  }
  return 0;
}
