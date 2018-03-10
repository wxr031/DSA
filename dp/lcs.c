#include <stdio.h>
#include <string.h>

#define MAXLEN 60000

int table[2][MAXLEN];
char str1[MAXLEN + 2], str2[MAXLEN + 2];

int lcs() {
	int len1 = strlen(str1), len2 = strlen(str2);
	int parity = 0, oppos = 1;
	memset(table[oppos], 0, (len2 + 1) * sizeof(int));
	for(int i = len1 - 1; i >= 0; --i) {
		table[parity][len2] = 0;
		for(int j = len2 - 1; j >= 0; --j) {
			if(str1[i] == str2[j])
				table[parity][j] = table[oppos][j + 1] + 1;
			else if(table[parity][j + 1] > table[oppos][j])
				table[parity][j] = table[parity][j + 1];
			else table[parity][j] = table[oppos][j];
		}
		parity ^= 1;
		oppos ^= 1;
	}
	return table[oppos][0];
}

int main() {
	while(scanf("%s%s", str1, str2) == 2)
		printf("%d\n", lcs());
	return 0;
}
