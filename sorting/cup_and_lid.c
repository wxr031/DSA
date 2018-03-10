#include <stdio.h>
#define MAXN 131072
#define MAXL 32
typedef struct cup {
	int radius;
	char name[MAXL];
} Cup;
typedef struct lid {
	int radius;
	char name[MAXL];
} Lid;
typedef struct pair {
	char cup_name[MAXL];
	char lid_name[MAXL];
} Pair;
Cup cups[MAXN];
Lid lids[MAXN];
Pair *match(int *result, int num) {
	
}
int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i ++)
		scanf("%d%s", &cups[i].radius, cups[i].name);
	for (int i = 0; i < num; i ++)
		scanf("%d%s", &lids[i].radius, lids[i].name);
	Pair result = (Pair *)malloc(num * sizeof(Pair));
	result = match(num);
}
