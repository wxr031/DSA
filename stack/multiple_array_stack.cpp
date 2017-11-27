#include <iostream>
#define MAXN 10
using namespace std;

class multiple_stacks {
private:
	int *array; // store data
	int *top; // store top of the stack
	int *next; // store next free spot in array

	int array_size, stack_num;
	int free; // Store the start index of the free list;
public:
	multiple_stacks(int size, int num): free(0) {
		array_size = size;
		stack_num = num;
		array = new int[array_size];
		top = new int[stack_num];
		next = new int[stack_num];

		// Initialize top and next
		for (int i = 0; i < stack_num; i ++)
			top[i] = -1;
		for (int i = 0; i < array_size - 1; i ++)
			next[i] = i + 1;
		next[array_size - 1] = -1; // -1 represent the end of the array
	}
	bool is_full();
	bool is_empty(int);
	void push(int, int);
	int pop(int);
};
bool multiple_stacks::is_full() {
	return free == -1;
}
bool multiple_stacks::is_empty(int which_stack) {
	return top[which_stack] == -1;
}
void multiple_stacks::push(int data, int which_stack) {
	if (is_full()) {
		cout << "Stack full" << endl;
		return;
	}
	int free_temp = free;
	free = next[free_temp]; // seek for the next free spot
	next[free_temp] = top[which_stack]; // update next
	top[which_stack] = free_temp; // update top
	array[free_temp] = data; // put data into array
}
int multiple_stacks::pop(int which_stack) {
	if (is_empty(which_stack)) {
		cout << "Stack empty" << endl;
		return INT_MIN;
	}
	int pos_temp = top[which_stack];
	top[which_stack] = next[pos_temp];
	next[pos_temp] = free;
	free = pos_temp;
	return array[pos_temp];
}
int main() {
	/* Add test code */
    return 0;
}
