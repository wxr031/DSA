#include <iostream>
#include <limits>
#include <stack>
#include <vector>
int main() {
	int num;
	std::cin >> num;
	std::vector<std::stack<int> > SV(1024);
	int cmd;
	while(std::cin >> cmd) {
		switch(cmd) {
			case 0: {
				int val, stack_n;
				std::cin >> stack_n >> val;
				if(stack_n >= num or stack_n < 0) {
					std::cerr << "Stack DNE" << std::endl;
				}
				else {
					SV[stack_n].push(val);
				}
				}
				break;
			case 1: {
				int stack_n;
				std::cin >> stack_n;
				if(SV[stack_n].empty()) {
					std::cerr << "Stack Underflow" << std::endl;
					std::cout <<  std::numeric_limits<int>::min() << std::endl;
				}
				else if (stack_n >= num || stack_n < 0) {
					std::cerr << "Stack DNE" << std::endl;
					std::cout <<  std::numeric_limits<int>::min() << std::endl;
				}
				else {
					std::cout << SV[stack_n].top() << std::endl;
					SV[stack_n].pop();
				}
				}
				break;
			case 2: {
				int stack_n;
				std::cin >> stack_n;
				if(SV[stack_n].empty()) {
					std::cerr << "Stack Underflow" << std::endl;
					std::cout <<  std::numeric_limits<int>::min() << std::endl;
				}
				else if (stack_n >= num || stack_n < 0) {
					std::cerr << "Stack DNE" << std::endl;
					std::cout <<  std::numeric_limits<int>::min() << std::endl;
				}
				else {
				std::cout << SV[stack_n].top() << std::endl;
				}
				}
				break;
			default:
				break;
		}
	}
	return 0;
}
