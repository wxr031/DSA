#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
int main() {
	FILE *fp = fopen("input", "w");
	assert(fp);
	int data, pos;
	int num = 1;
	srand(time(NULL));
	for (int i = 0; i < 1024; i ++) {
		data = rand() % 1024;
		pos = rand() % num;
		fprintf(fp, "%d %d\n", data, pos);
		num ++;
	}
	fclose(fp);
	return 0;
}
