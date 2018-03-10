#include <iostream>
#include <limits>
class mul_stack {
	const int max_size = 16384;
	int num, curr;
	int *data, *top, *next;
public:
	mul_stack(int n): num(n), curr(0) {
		data = new int[max_size];
		top = new int[num];
		next = new int[max_size];
		std::fill_n(top, num, -1);
		for (int i = 0; i < max_size; i ++)
			next[i] = i + 1;
	}
	void push(int, int);
	int pop(int);
	int get_top(int);
};
void mul_stack::push(int stack_n, int val) {
	if(curr == max_size) {
		std::cerr << "Stack Overflow" << std::endl;
		return;
	}
	if (stack_n >= num || stack_n < 0) {
		std::cerr << "Stack DNE" << std::endl;
		return;
	}
	int temp = next[curr];
	data[curr] = val;
	next[curr] = top[stack_n];
	top[stack_n] = curr;
	curr = temp;
}
int mul_stack::pop(int stack_n) {
	if(top[stack_n] == -1) {
		std::cerr << "Stack Underflow" << std::endl;
		return std::numeric_limits<int>::min();
	}
	if (stack_n >= num || stack_n < 0) {
		std::cerr << "Stack DNE" << std::endl;
		return std::numeric_limits<int>::min();
	}
	int temp = next[top[stack_n]];
	next[top[stack_n]] = curr;
	curr = top[stack_n];
	top[stack_n] = temp;
	return data[curr];
}
int mul_stack::get_top(int stack_n) {
	if(top[stack_n] == -1) {
		std::cerr << "Stack Underflow" << std::endl;
		return std::numeric_limits<int>::min();
	}
	if (stack_n >= num || stack_n < 0) {
		std::cerr << "Stack DNE" << std::endl;
		return std::numeric_limits<int>::min();
	}
	return data[top[stack_n]];
}
int main() {
	int num;
	std::cin >> num;
	mul_stack S(num);
	int cmd;
	int stack_n, val;
	while(std::cin >> cmd) {
		switch(cmd) {
		case 0:
			std::cin >> stack_n >> val;
			S.push(stack_n, val);
			break;
		case 1:
			std::cin >> stack_n;
			std::cout << S.pop(stack_n) << std::endl;
			break;
		case 2:
			std::cin >> stack_n;
			std::cout << S.get_top(stack_n) << std::endl;
			break;
		default:
			break;
		}
	}
	return 0;
}
