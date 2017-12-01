#include <stdio.h>
#include <ctype.h>
#include "char_stack.h"
int to_int(char *str, int *num_ptr) {
	int neg, sum;
	if (str[*num_ptr] == '-') {
		neg = 1, sum = 0;
	} else {
		neg = 0, sum = str[*num_ptr] - '0';
	}
	while (isdigit(str[++ *num_ptr]))
		sum = (sum << 3) + (sum << 1) + str[*num_ptr] - '0';
	return (neg)? -sum: sum;
}
int is_sign(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}
int prior_higher(char sign, char cmp) {
	if (sign == '+' || sign == '-') {
		if (cmp == '+' || cmp == '-' || cmp == '*' || cmp == '/') return 1;
		else return 0;
	} else if (sign == '*' || sign == '/') {
		if (cmp == '*' || cmp == '/') return 1;
		else return 0;
	} else return 0;
}
int main() {
	Stack stack;
	init(&stack);
	char str[65536];
	while (fgets(str, 65536, stdin)) {
		int num, first = 1;
		for (num = 0; str[num]; num ++) {
			if (isdigit(str[num]) || (str[num] == '-' && isdigit(str[num + 1]))) {
				printf("%c%d", " "[first], to_int(str, &num));
				first = 0;
			} else if (is_sign(str[num])) {
				while (!is_empty(&stack) && prior_higher(str[num], stack.head->data))
					printf(" %c", pop(&stack));
				push(&stack, str[num]);
			} else if (str[num] == '(') {
				push(&stack, str[num]);
			} else if (str[num] == ')') {
				char temp;
				while ((temp = pop(&stack)) != '(')
					printf(" %c", temp);
			} 		
		}
		while (!is_empty(&stack))
			printf(" %c", pop(&stack));
		putchar('\n');
	}
}
