#include <iostream>
#include <vector>
void tug_of_war(std::vector<int> &, int);
int main() {
	int num, val;
	std::cin >> num;
	std::vector<int> array(num);
	for(int i = 0; i < num; ++i) {
		std::cin >> num;
		array[i] = num;
	}
	tug_of_war(array, num);
}
void tug_of_war(std::vector<int> &array, int num, int &min) {
	
}
