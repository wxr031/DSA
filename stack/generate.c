#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	FILE *fp = fopen("input", "w");
	int num = 1024;
	fprintf(fp, "%d\n", num);
	srand(time(NULL));
	for (int i = 0; i < num; i ++) {
		int cmd = rand() % 3;
		switch(cmd) {
		case 0: {
			int stack_n = rand() % num;
			int val = rand() % 32768;
			fprintf(fp, "%d %d %d\n", cmd, stack_n, val);
			}
			break;
		case 1: {
			int stack_n = rand() % num;
			fprintf(fp, "%d %d\n", cmd, stack_n);
			break;
			}
		case 2: {
			int stack_n = rand() % num;
			fprintf(fp, "%d %d\n", cmd, stack_n);
			}
			break;
		default:
			break;
		}
	}
	fclose(fp);
	return 0;
}
