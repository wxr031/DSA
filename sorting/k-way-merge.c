#include <stdio.h>
#define READ_MAX 16384
int main() {
	int n;
	int arr[READ_MAX];
	FILE *fp = fopen("input", "r");
	scanf("%d", &n);
	int r_num;
	while (r_num = fread(arr, sizeof(int), r_max, fp)) {
		
	}
}
